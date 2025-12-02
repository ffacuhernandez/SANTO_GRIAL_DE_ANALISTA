/* Script de normalización y carga del TP Final.
Este archivo está organizado en etapas claramente delimitadas para facilitar
su lectura por todo el equipo:
 1. Definición de tablas del modelo normalizado.
 2. Tabla de staging que recibe el CSV crudo.
 3. Funciones utilitarias para limpiar y convertir datos.
 4. Poblado de catálogos base (países, ciudades, conferencias, divisiones).
 5. Carga de entidades principales (equipos, jugadores, temporadas, partidos).
 6. Inserción de estadísticas por jugador y partido.
 7. Consultas solicitadas en el trabajo.
 Todas las secciones incluyen comentarios que explican qué hace cada bloque.
 Si es necesario volver a ejecutar el script, las operaciones están pensadas
 para ser idempotentes mediante el uso de ON CONFLICT/IF NOT EXISTS. */

-- ============================================================================
-- 1. DEFINICIÓN DEL MODELO NORMALIZADO
-- ============================================================================
CREATE TABLE IF NOT EXISTS pais (
  pais_id BIGSERIAL PRIMARY KEY,
  nombre  TEXT NOT NULL UNIQUE
);

CREATE TABLE IF NOT EXISTS ciudad (
  ciudad_id BIGSERIAL PRIMARY KEY,
  nombre    TEXT NOT NULL UNIQUE
);

CREATE TABLE IF NOT EXISTS conferencia (
  conferencia_id BIGSERIAL PRIMARY KEY,
  nombre         TEXT NOT NULL UNIQUE
);

CREATE TABLE IF NOT EXISTS division (
  division_id    BIGSERIAL PRIMARY KEY,
  nombre         TEXT NOT NULL UNIQUE,
  conferencia_id BIGINT NOT NULL REFERENCES conferencia(conferencia_id)
);

CREATE TABLE IF NOT EXISTS equipo (
  equipo_id   BIGSERIAL PRIMARY KEY,
  codigo      TEXT UNIQUE,
  nombre      TEXT NOT NULL,
  sigla       CHAR(3) UNIQUE,
  ciudad_id   BIGINT REFERENCES ciudad(ciudad_id),
  division_id BIGINT REFERENCES division(division_id)
);

CREATE TABLE IF NOT EXISTS temporada (
  temporada_id BIGSERIAL PRIMARY KEY,
  descripcion  TEXT UNIQUE
);


CREATE TABLE IF NOT EXISTS jugador (
  jugador_id BIGSERIAL PRIMARY KEY,
  player_code TEXT UNIQUE,
  nombre      TEXT NOT NULL,
  apellido    TEXT NOT NULL,
  posicion    TEXT,
  draft_year  SMALLINT,
  pais_id     BIGINT REFERENCES pais(pais_id),
  peso_kg     NUMERIC(6,2),
  altura_m    NUMERIC(5,2) 
);

CREATE TABLE IF NOT EXISTS partido (
  partido_id           BIGSERIAL PRIMARY KEY,
  temporada_id         BIGINT NOT NULL REFERENCES temporada(temporada_id),
  fecha                DATE   NOT NULL,
  equipo_local_id      BIGINT NOT NULL REFERENCES equipo(equipo_id),
  equipo_visitante_id  BIGINT NOT NULL REFERENCES equipo(equipo_id),
  puntos_local         SMALLINT,
  puntos_visitante     SMALLINT,
  equipo_ganador_id    BIGINT REFERENCES equipo(equipo_id),
  game_code            TEXT UNIQUE,
  CONSTRAINT chk_partido_distintos_equipos
    CHECK (equipo_local_id <> equipo_visitante_id),
  CONSTRAINT chk_ganador_valido
    CHECK (
      equipo_ganador_id IS NULL
      OR equipo_ganador_id IN (equipo_local_id, equipo_visitante_id)
    )
);

-- Roster histórico de jugadores por temporada --------------------------------
CREATE TABLE IF NOT EXISTS roster (
  roster_id        BIGSERIAL PRIMARY KEY,
  jugador_id       BIGINT NOT NULL REFERENCES jugador(jugador_id),
  equipo_id        BIGINT NOT NULL REFERENCES equipo(equipo_id),
  temporada_id     BIGINT NOT NULL REFERENCES temporada(temporada_id),
  numero_camiseta  SMALLINT,
  fecha_desde      DATE,
  fecha_hasta      DATE,
  CONSTRAINT chk_roster_rango_fechas
    CHECK (fecha_desde IS NULL OR fecha_hasta IS NULL OR fecha_desde <= fecha_hasta)
);

CREATE TABLE IF NOT EXISTS estadistica (
  estadistica_id BIGSERIAL PRIMARY KEY,
  codigo         TEXT NOT NULL UNIQUE,
  descripcion    TEXT
);

CREATE TABLE IF NOT EXISTS jugador_partido_estad (
  partido_id     BIGINT NOT NULL REFERENCES partido(partido_id),
  jugador_id     BIGINT NOT NULL REFERENCES jugador(jugador_id),
  estadistica_id BIGINT NOT NULL REFERENCES estadistica(estadistica_id),
  cantidad       NUMERIC(6,2) NOT NULL,
  PRIMARY KEY (partido_id, jugador_id, estadistica_id)
);

-- ============================================================================
-- 2. TABLA DE STAGING
-- ============================================================================
-- La tabla recibe los datos crudos importados desde el CSV de la API.
-- Si el archivo CSV se carga manualmente desde una herramienta no interfiere
-- con el resto del script: simplemente debe apuntar a esta tabla y respetar
-- los nombres de columnas listados.
DROP TABLE IF EXISTS staging_stats;
CREATE TABLE staging_stats (
  OPcity                  TEXT,
  OPcode                  TEXT,
  OPsigla                 TEXT,
  OPConference            TEXT,
  OPdivision              TEXT,
  OPid                    TEXT,
  OPname                  TEXT,
  stat_asistencias_id     TEXT,
  stat_asistencias_nombre TEXT,
  stat_asistencias_valor  TEXT,
  stat_blocks_id          TEXT,
  stat_blocks_nombre      TEXT,
  stat_blocks_valor       TEXT,
  city                    TEXT,
  codeJug                 TEXT,
  country                 TEXT,
  stat_defrebs_id         TEXT,
  stat_defrebs_nombre     TEXT,
  stat_defrebs_valor      TEXT,
  sigla                   TEXT,
  Conference              TEXT,
  NamePlayer              TEXT,
  division                TEXT,
  draftYear               TEXT,
  fecha                   TEXT,
  stat_fga_id             TEXT,
  stat_fga_nombre         TEXT,
  stat_fga_valor          TEXT,
  stat_fgm_id             TEXT,
  stat_fgm_nombre         TEXT,
  stat_fgm_valor          TEXT,
  fgpct                   TEXT,
  firstName               TEXT,
  stat_fouls_id           TEXT,
  stat_fouls_nombre       TEXT,
  stat_fouls_valor        TEXT,
  stat_fta_id             TEXT,
  stat_fta_nombre         TEXT,
  stat_fta_valor          TEXT,
  stat_ftm_id             TEXT,
  stat_ftm_nombre         TEXT,
  stat_ftm_valor          TEXT,
  ftpct                   TEXT,
  gameId                  TEXT,
  height                  TEXT,
  isHome                  TEXT,
  jerseyNo                TEXT,
  lastName                TEXT,
  stat_mins_id            TEXT,
  stat_mins_nombre        TEXT,
  stat_mins_valor         TEXT,
  name                    TEXT,
  stat_offrebs_id         TEXT,
  stat_offrebs_nombre     TEXT,
  stat_offrebs_valor      TEXT,
  oppTeamScore            TEXT,
  playerId                TEXT,
  stat_points_id          TEXT,
  stat_points_nombre      TEXT,
  stat_points_valor       TEXT,
  position                TEXT,
  rebs                    TEXT,
  seasonId                TEXT,
  stat_secs_id            TEXT,
  stat_secs_nombre        TEXT,
  stat_secs_valor         TEXT,
  stat_steals_id          TEXT,
  stat_steals_nombre      TEXT,
  stat_steals_valor       TEXT,
  teamCode                TEXT,
  teamScore               TEXT,
  teamid                  TEXT,
  stat_tpa_id             TEXT,
  stat_tpa_nombre         TEXT,
  stat_tpa_valor          TEXT,
  stat_tpm_id             TEXT,
  stat_tpm_nombre         TEXT,
  stat_tpm_valor          TEXT,
  tppct                   TEXT,
  stat_turnovers_id       TEXT,
  stat_turnovers_nombre   TEXT,
  stat_turnovers_valor    TEXT,
  weight                  TEXT,
  winOrLoss               TEXT,
  yearDisplay             TEXT,
  idPais                  TEXT,
  idCity                  TEXT,
  OPidCity                TEXT
);

-- ============================================================================
-- 3. FUNCIONES UTILITARIAS
-- ============================================================================
--capitaliza y normaliza espacios en textos descriptivos.
CREATE OR REPLACE FUNCTION limpiar_texto(txt text)
RETURNS text
LANGUAGE sql
IMMUTABLE
AS $$
  SELECT CASE
           WHEN $1 IS NULL THEN NULL
           ELSE INITCAP(regexp_replace(btrim($1), '\s+', ' ', 'g'))
         END;
$$;

--parse_num: extrae dígitos (y punto decimal) de un texto y lo devuelve como número.
CREATE OR REPLACE FUNCTION parse_num(txt text)
RETURNS numeric
LANGUAGE sql
IMMUTABLE
AS $$
  SELECT NULLIF(regexp_replace(btrim(COALESCE(txt, '')), '[^0-9\.]', '', 'g'), '')::numeric;
$$;

--interpreta distintos formatos (lb, kg o sin unidad).
CREATE OR REPLACE FUNCTION convertir_peso_a_kg(peso_raw text)
RETURNS numeric
LANGUAGE sql
IMMUTABLE
AS $$
  WITH datos AS (
    SELECT lower(btrim(peso_raw)) AS raw,
           parse_num(peso_raw)    AS valor
  )
  SELECT CASE
           WHEN raw IS NULL OR raw = '' OR valor IS NULL THEN NULL
           WHEN raw LIKE '%lb%' OR raw LIKE '%lbs%' THEN ROUND(valor * 0.45359237, 2)
           WHEN raw LIKE '%kg%' THEN ROUND(valor, 2)
           WHEN valor > 180 THEN ROUND(valor * 0.45359237, 2) -- probablemente libras
           ELSE ROUND(valor, 2)
         END
  FROM datos;
$$;

--soporta formatos 6'7", 6-7, 6 7, 6.7ft, etc.
CREATE OR REPLACE FUNCTION convertir_altura_a_m(altura_raw text)
RETURNS numeric
LANGUAGE sql
IMMUTABLE
AS $$
  SELECT CASE
      --maneja los formatos en pies y pulgadas (ej 6'7" o 6-7)
      WHEN altura_raw IS NULL OR btrim(altura_raw) = '' THEN NULL
      WHEN altura_raw ~ '^[0-9]+''[0-9]*"?$' THEN
        ROUND(((split_part(altura_raw, '''', 1)::numeric * 12)
             + COALESCE(regexp_replace(split_part(altura_raw, '''', 2), '[^0-9]', '', 'g')::numeric, 0))
             * 2.54 / 100, 2)
      WHEN altura_raw ~ '^[0-9]+[- ][0-9]+$' THEN
        ROUND(((split_part(regexp_replace(altura_raw, '\s+', '-', 'g'), '-', 1)::numeric * 12)
             + split_part(regexp_replace(altura_raw, '\s+', '-', 'g'), '-', 2)::numeric) * 2.54 / 100, 2)
      WHEN lower(altura_raw) LIKE '%ft%' THEN
        ROUND(parse_num(altura_raw) * 0.3048, 2)

      --si es número simple, asume que YA ESTÁ en metros.
      WHEN parse_num(altura_raw) < 3 THEN
        ROUND(parse_num(altura_raw), 2)

      -- si el número es grande, asume que son cm y lo convierte a metros.
      WHEN parse_num(altura_raw) >= 3 THEN
        ROUND(parse_num(altura_raw) / 100, 2)
        
      ELSE NULL
    END;
$$;

--acepta YYYYMMDD, YYYY-MM-DD y DD/MM/YYYY.
CREATE OR REPLACE FUNCTION parse_fecha(txt text)
RETURNS date
LANGUAGE sql
IMMUTABLE
AS $$
  SELECT CASE
           WHEN txt IS NULL OR btrim(txt) = ''                   THEN NULL
           WHEN txt ~ '^[0-9]{8}$'                               THEN to_date(txt, 'YYYYMMDD')
           WHEN txt ~ '^[0-9]{4}-[0-9]{2}-[0-9]{2}$'             THEN to_date(txt, 'YYYY-MM-DD')
           WHEN txt ~ '^[0-9]{2}/[0-9]{2}/[0-9]{4}$'             THEN to_date(txt, 'DD/MM/YYYY')
           ELSE NULL
         END;
$$;

--interpreta valores tipo true, 1, yes, si como booleano.
CREATE OR REPLACE FUNCTION parse_bool_true(txt text)
RETURNS boolean
LANGUAGE sql
IMMUTABLE
AS $$
  SELECT CASE
           WHEN txt IS NULL THEN NULL
           WHEN lower(btrim(txt)) IN ('true','t','1','yes','y','s','si','sí') THEN TRUE
           WHEN lower(btrim(txt)) IN ('false','f','0','no','n')               THEN FALSE
           ELSE NULL
         END;
$$;

--Carga los datos desde el csv a la tabla staging_stats
COPY staging_stats 
FROM 'C:\Tp BD\datos_grupo5.csv'
WITH (FORMAT CSV, HEADER TRUE, DELIMITER ',');

-- ============================================================================
-- 4. POBLADO DE CATÁLOGOS BASE
-- ============================================================================
INSERT INTO estadistica (codigo, descripcion) VALUES
  ('PTS', 'Puntos'),
  ('AST', 'Asistencias'),
  ('BLK', 'Bloqueos (Tapones)'),
  ('REB_DEF', 'Rebotes Defensivos'),
  ('REB_OFF', 'Rebotes Ofensivos'),
  ('REB', 'Rebotes Totales'),
  ('FGA', 'Tiros de Campo Intentados'),
  ('FGM', 'Tiros de Campo Convertidos'),
  ('FTA', 'Tiros Libres Intentados'),
  ('FTM', 'Tiros Libres Convertidos'),
  ('FOULS', 'Faltas Personales'),
  ('STL', 'Robos'),
  ('TOV', 'Pérdidas de Balón (Turnovers)'),
  ('MINS', 'Minutos Jugados'),
  ('SECS', 'Segundos Jugados')
ON CONFLICT (codigo) DO NOTHING;

INSERT INTO pais (nombre)
SELECT DISTINCT limpiar_texto(country)
FROM staging_stats
WHERE country IS NOT NULL AND btrim(country) <> ''
ON CONFLICT (nombre) DO NOTHING;

INSERT INTO ciudad (nombre)
SELECT DISTINCT limpiar_texto(city)
FROM staging_stats
WHERE city IS NOT NULL AND btrim(city) <> ''
ON CONFLICT (nombre) DO NOTHING;

INSERT INTO ciudad (nombre)
SELECT DISTINCT limpiar_texto(OPcity)
FROM staging_stats
WHERE OPcity IS NOT NULL AND btrim(OPcity) <> ''
ON CONFLICT (nombre) DO NOTHING;

INSERT INTO conferencia (nombre)
SELECT DISTINCT limpiar_texto(Conference)
FROM staging_stats
WHERE Conference IS NOT NULL AND btrim(Conference) <> ''
ON CONFLICT (nombre) DO NOTHING;

INSERT INTO conferencia (nombre)
SELECT DISTINCT limpiar_texto(OPConference)
FROM staging_stats
WHERE OPConference IS NOT NULL AND btrim(OPConference) <> ''
ON CONFLICT (nombre) DO NOTHING;

INSERT INTO division (nombre, conferencia_id)
SELECT DISTINCT limpiar_texto(s.division) AS div_nom,
       c.conferencia_id
FROM staging_stats s
JOIN conferencia c ON limpiar_texto(s.Conference) = c.nombre
WHERE s.division IS NOT NULL AND btrim(s.division) <> ''
ON CONFLICT (nombre) DO NOTHING;

INSERT INTO division (nombre, conferencia_id)
SELECT DISTINCT limpiar_texto(s.OPdivision) AS div_nom,
       c.conferencia_id
FROM staging_stats s
JOIN conferencia c ON limpiar_texto(s.OPConference) = c.nombre
WHERE s.OPdivision IS NOT NULL AND btrim(s.OPdivision) <> ''
ON CONFLICT (nombre) DO NOTHING;

-- ============================================================================
-- 5. CARGA DE ENTIDADES PRINCIPALES
-- ============================================================================
INSERT INTO equipo (codigo, nombre, sigla, ciudad_id, division_id)
SELECT DISTINCT
  NULLIF(btrim(s.teamCode), '')                                         AS codigo,
  COALESCE(NULLIF(limpiar_texto(s.name), ''), limpiar_texto(s.teamCode)) AS nombre,
  CASE
    WHEN s.sigla IS NULL OR btrim(s.sigla) = '' THEN NULL
    ELSE UPPER(btrim(s.sigla))
  END                                                                   AS sigla,
  ciu.ciudad_id,
  divi.division_id
FROM staging_stats s
LEFT JOIN ciudad   ciu  ON limpiar_texto(s.city)     = ciu.nombre
LEFT JOIN division divi ON limpiar_texto(s.division) = divi.nombre
ON CONFLICT (sigla) DO NOTHING;

INSERT INTO equipo (codigo, nombre, sigla, ciudad_id, division_id)
SELECT DISTINCT
  NULLIF(btrim(s.OPcode), '')                                             AS codigo,
  COALESCE(NULLIF(limpiar_texto(s.OPname), ''), limpiar_texto(s.OPcode))   AS nombre,
  CASE
    WHEN s.OPsigla IS NULL OR btrim(s.OPsigla) = '' THEN NULL
    ELSE UPPER(btrim(s.OPsigla))
  END                                                                     AS sigla,
  ciu.ciudad_id,
  divi.division_id
FROM staging_stats s
LEFT JOIN ciudad   ciu  ON limpiar_texto(s.OPcity)     = ciu.nombre
LEFT JOIN division divi ON limpiar_texto(s.OPdivision) = divi.nombre
ON CONFLICT (sigla) DO NOTHING;

ALTER TABLE jugador ADD COLUMN IF NOT EXISTS player_code TEXT UNIQUE;
CREATE UNIQUE INDEX IF NOT EXISTS ux_jugador_player_code ON jugador(player_code);

INSERT INTO jugador (player_code, nombre, apellido, posicion, draft_year, pais_id, peso_kg, altura_m)
SELECT DISTINCT ON (s.playerId)
    s.playerId AS player_code,
    limpiar_texto(s.firstName) AS nombre,
    limpiar_texto(s.lastName)  AS apellido,
    NULLIF(btrim(s.position), '') AS posicion,
    CASE WHEN s.draftYear ~ '^[0-9]+$' THEN s.draftYear::smallint ELSE NULL END AS draft_year,
    p.pais_id,
    convertir_peso_a_kg(s.weight) AS peso_kg,
    convertir_altura_a_m(s.height) AS altura_m
FROM staging_stats s
LEFT JOIN pais p ON limpiar_texto(s.country) = p.nombre
WHERE s.playerId IS NOT NULL AND btrim(s.playerId) <> ''
  AND s.firstName IS NOT NULL AND btrim(s.firstName) <> ''
  AND s.lastName  IS NOT NULL AND btrim(s.lastName)  <> ''
ON CONFLICT (player_code) DO NOTHING;

INSERT INTO temporada (descripcion)
SELECT DISTINCT seasonId
FROM staging_stats
WHERE seasonId IS NOT NULL AND btrim(seasonId) <> ''
ON CONFLICT (descripcion) DO NOTHING;

WITH partidos_distintos AS (
  SELECT DISTINCT s.gameId
  FROM staging_stats s
  WHERE s.gameId IS NOT NULL AND btrim(s.gameId) <> ''
), datos AS (
  SELECT
    p.gameId,
    MAX(parse_fecha(s.fecha))                                   AS fecha,
    MAX(s.seasonId)                                             AS season_id_raw,
    MAX(CASE WHEN parse_bool_true(s.isHome) = TRUE
             THEN UPPER(NULLIF(btrim(s.sigla), '')) END)        AS sigla_local,
    MAX(CASE WHEN parse_bool_true(s.isHome) = TRUE
             THEN UPPER(NULLIF(btrim(s.OPsigla), '')) END)      AS sigla_visitante,
    MAX(CASE WHEN parse_bool_true(s.isHome) = TRUE
             THEN parse_num(s.teamScore)
             WHEN parse_bool_true(s.isHome) = FALSE
             THEN parse_num(s.oppTeamScore) END)                AS puntos_local,
    MAX(CASE WHEN parse_bool_true(s.isHome) = TRUE
             THEN parse_num(s.oppTeamScore)
             WHEN parse_bool_true(s.isHome) = FALSE
             THEN parse_num(s.teamScore) END)                   AS puntos_visitante
  FROM partidos_distintos p
  JOIN staging_stats s ON s.gameId = p.gameId
  GROUP BY p.gameId
)
INSERT INTO partido (
  game_code, temporada_id, fecha,
  equipo_local_id, equipo_visitante_id,
  puntos_local, puntos_visitante, equipo_ganador_id
)
SELECT
  d.gameId AS game_code,
  t.temporada_id,
  d.fecha,
  e_local.equipo_id,
  e_visit.equipo_id,
  d.puntos_local::smallint,
  d.puntos_visitante::smallint,
  CASE
    WHEN d.puntos_local IS NULL OR d.puntos_visitante IS NULL THEN NULL
    WHEN d.puntos_local >= d.puntos_visitante                 THEN e_local.equipo_id
    ELSE e_visit.equipo_id
  END AS equipo_ganador_id
FROM datos d
JOIN temporada t ON t.descripcion = d.season_id_raw
JOIN equipo e_local ON e_local.sigla = d.sigla_local
JOIN equipo e_visit ON e_visit.sigla = d.sigla_visitante
WHERE d.fecha IS NOT NULL
  AND d.sigla_local IS NOT NULL
  AND d.sigla_visitante IS NOT NULL
ON CONFLICT (game_code) DO NOTHING;

-- ============================================================================
-- 6. CARGA DE ESTADÍSTICAS POR JUGADOR Y PARTIDO
-- ============================================================================
INSERT INTO jugador_partido_estad (partido_id, jugador_id, estadistica_id, cantidad)
SELECT p.partido_id, j.jugador_id, e.estadistica_id, parse_num(s.stat_points_valor)
FROM staging_stats s
JOIN jugador j  ON j.player_code = s.playerId
JOIN partido p  ON p.game_code   = s.gameId
JOIN estadistica e ON e.codigo   = 'PTS'
WHERE parse_num(s.stat_points_valor) IS NOT NULL
ON CONFLICT DO NOTHING;

INSERT INTO jugador_partido_estad
SELECT p.partido_id, j.jugador_id, e.estadistica_id, parse_num(s.stat_asistencias_valor)
FROM staging_stats s
JOIN jugador j  ON j.player_code = s.playerId
JOIN partido p  ON p.game_code   = s.gameId
JOIN estadistica e ON e.codigo   = 'AST'
WHERE parse_num(s.stat_asistencias_valor) IS NOT NULL
ON CONFLICT DO NOTHING;

INSERT INTO jugador_partido_estad
SELECT p.partido_id, j.jugador_id, e.estadistica_id, parse_num(s.stat_blocks_valor)
FROM staging_stats s
JOIN jugador j  ON j.player_code = s.playerId
JOIN partido p  ON p.game_code   = s.gameId
JOIN estadistica e ON e.codigo   = 'BLK'
WHERE parse_num(s.stat_blocks_valor) IS NOT NULL
ON CONFLICT DO NOTHING;

INSERT INTO jugador_partido_estad
SELECT p.partido_id, j.jugador_id, e.estadistica_id, parse_num(s.stat_defrebs_valor)
FROM staging_stats s
JOIN jugador j ON j.player_code = s.playerId
JOIN partido p ON p.game_code   = s.gameId
JOIN estadistica e ON e.codigo  = 'REB_DEF'
WHERE parse_num(s.stat_defrebs_valor) IS NOT NULL
ON CONFLICT DO NOTHING;

INSERT INTO jugador_partido_estad
SELECT p.partido_id, j.jugador_id, e.estadistica_id, parse_num(s.stat_offrebs_valor)
FROM staging_stats s
JOIN jugador j ON j.player_code = s.playerId
JOIN partido p ON p.game_code   = s.gameId
JOIN estadistica e ON e.codigo  = 'REB_OFF'
WHERE parse_num(s.stat_offrebs_valor) IS NOT NULL
ON CONFLICT DO NOTHING;

INSERT INTO jugador_partido_estad
SELECT p.partido_id, j.jugador_id, e.estadistica_id, parse_num(s.rebs)
FROM staging_stats s
JOIN jugador j ON j.player_code = s.playerId
JOIN partido p ON p.game_code   = s.gameId
JOIN estadistica e ON e.codigo  = 'REB'
WHERE parse_num(s.rebs) IS NOT NULL
ON CONFLICT DO NOTHING;

INSERT INTO jugador_partido_estad
SELECT p.partido_id, j.jugador_id, e.estadistica_id, parse_num(s.stat_fga_valor)
FROM staging_stats s
JOIN jugador j ON j.player_code = s.playerId
JOIN partido p ON p.game_code   = s.gameId
JOIN estadistica e ON e.codigo  = 'FGA'
WHERE parse_num(s.stat_fga_valor) IS NOT NULL
ON CONFLICT DO NOTHING;

INSERT INTO jugador_partido_estad
SELECT p.partido_id, j.jugador_id, e.estadistica_id, parse_num(s.stat_fgm_valor)
FROM staging_stats s
JOIN jugador j ON j.player_code = s.playerId
JOIN partido p ON p.game_code   = s.gameId
JOIN estadistica e ON e.codigo  = 'FGM'
WHERE parse_num(s.stat_fgm_valor) IS NOT NULL
ON CONFLICT DO NOTHING;

INSERT INTO jugador_partido_estad
SELECT p.partido_id, j.jugador_id, e.estadistica_id, parse_num(s.stat_fta_valor)
FROM staging_stats s
JOIN jugador j ON j.player_code = s.playerId
JOIN partido p ON p.game_code   = s.gameId
JOIN estadistica e ON e.codigo  = 'FTA'
WHERE parse_num(s.stat_fta_valor) IS NOT NULL
ON CONFLICT DO NOTHING;

INSERT INTO jugador_partido_estad
SELECT p.partido_id, j.jugador_id, e.estadistica_id, parse_num(s.stat_ftm_valor)
FROM staging_stats s
JOIN jugador j ON j.player_code = s.playerId
JOIN partido p ON p.game_code   = s.gameId
JOIN estadistica e ON e.codigo  = 'FTM'
WHERE parse_num(s.stat_ftm_valor) IS NOT NULL
ON CONFLICT DO NOTHING;

INSERT INTO jugador_partido_estad
SELECT p.partido_id, j.jugador_id, e.estadistica_id, parse_num(s.stat_fouls_valor)
FROM staging_stats s
JOIN jugador j ON j.player_code = s.playerId
JOIN partido p ON p.game_code   = s.gameId
JOIN estadistica e ON e.codigo  = 'FOULS'
WHERE parse_num(s.stat_fouls_valor) IS NOT NULL
ON CONFLICT DO NOTHING;

INSERT INTO jugador_partido_estad
SELECT p.partido_id, j.jugador_id, e.estadistica_id, parse_num(s.stat_steals_valor)
FROM staging_stats s
JOIN jugador j ON j.player_code = s.playerId
JOIN partido p ON p.game_code   = s.gameId
JOIN estadistica e ON e.codigo  = 'STL'
WHERE parse_num(s.stat_steals_valor) IS NOT NULL
ON CONFLICT DO NOTHING;

INSERT INTO jugador_partido_estad
SELECT p.partido_id, j.jugador_id, e.estadistica_id, parse_num(s.stat_turnovers_valor)
FROM staging_stats s
JOIN jugador j ON j.player_code = s.playerId
JOIN partido p ON p.game_code   = s.gameId
JOIN estadistica e ON e.codigo  = 'TOV'
WHERE parse_num(s.stat_turnovers_valor) IS NOT NULL
ON CONFLICT DO NOTHING;

INSERT INTO jugador_partido_estad
SELECT p.partido_id, j.jugador_id, e.estadistica_id, parse_num(s.stat_mins_valor)
FROM staging_stats s
JOIN jugador j ON j.player_code = s.playerId
JOIN partido p ON p.game_code   = s.gameId
JOIN estadistica e ON e.codigo  = 'MINS'
WHERE parse_num(s.stat_mins_valor) IS NOT NULL
ON CONFLICT DO NOTHING;

INSERT INTO jugador_partido_estad
SELECT p.partido_id, j.jugador_id, e.estadistica_id, parse_num(s.stat_secs_valor)
FROM staging_stats s
JOIN jugador j ON j.player_code = s.playerId
JOIN partido p ON p.game_code   = s.gameId
JOIN estadistica e ON e.codigo  = 'SECS'
WHERE parse_num(s.stat_secs_valor) IS NOT NULL
ON CONFLICT DO NOTHING;

-- ============================================================================
-- 7. CONSULTAS SOLICITADAS EN EL TRABAJO
-- ============================================================================
--1. Cantidad de equipos que jugaron de local el 1 de diciembre.
SELECT COUNT(DISTINCT equipo_local_id) AS cantidad_equipos
FROM partido
WHERE EXTRACT(MONTH FROM fecha) = 12 AND EXTRACT(DAY FROM fecha) = 1;

--2. Cantidad de partidos jugados en noviembre de 2022.
SELECT COUNT(*) AS cantidad_partidos
FROM partido
WHERE EXTRACT(YEAR FROM fecha) = 2022 AND EXTRACT(MONTH FROM fecha) = 11;

--3. Cantidad de jugadores que jugaron para los Bulls.
SELECT COUNT(DISTINCT j.jugador_id) AS cantidad_jugadores
FROM jugador AS j
INNER JOIN staging_stats AS s ON j.player_code = s.playerId
INNER JOIN equipo AS e ON s.sigla = e.sigla
WHERE e.nombre LIKE '%Bulls%';

--4. Listado de partidos que se jugaron en noviembre indicando id de partido, fecha, equipo local, equipo visitante y los puntos obtenidos por cada uno.
SELECT
    p.partido_id,
    p.fecha,
    e_local.nombre AS equipo_local,
    p.puntos_local,
    e_visit.nombre AS equipo_visitante,
    p.puntos_visitante
FROM partido AS p
INNER JOIN equipo AS e_local ON p.equipo_local_id = e_local.equipo_id
INNER JOIN equipo AS e_visit ON p.equipo_visitante_id = e_visit.equipo_id
WHERE EXTRACT(MONTH FROM p.fecha) = 11;

--5. Cantidad de partidos que perdieron los Bucks jugando como local.
SELECT COUNT(*) AS partidos_perdidos_de_local
FROM partido AS p
INNER JOIN equipo AS e ON p.equipo_local_id = e.equipo_id
WHERE e.nombre LIKE '%Bucks' AND p.equipo_ganador_id = p.equipo_visitante_id;

--6. Listar los 5 equipos con mayor promedio de rebotes por partido.
WITH TeamReboundsPerGame AS (
    SELECT
        eq.equipo_id,
        p.partido_id,
        SUM(jpe.cantidad) AS total_rebotes
    FROM jugador_partido_estad AS jpe
    INNER JOIN jugador AS j ON jpe.jugador_id = j.jugador_id
    INNER JOIN partido AS p ON jpe.partido_id = p.partido_id
    INNER JOIN staging_stats AS s ON j.player_code = s.playerId AND p.game_code = s.gameId
    INNER JOIN equipo AS eq ON s.sigla = eq.sigla
    WHERE jpe.estadistica_id = (SELECT estadistica_id FROM estadistica WHERE codigo = 'REB')
    GROUP BY eq.equipo_id, p.partido_id
)
SELECT
    e.nombre,
    AVG(trpg.total_rebotes) AS promedio_rebotes
FROM TeamReboundsPerGame AS trpg
INNER JOIN equipo AS e ON trpg.equipo_id = e.equipo_id
GROUP BY e.nombre
ORDER BY promedio_rebotes DESC
LIMIT 5;

--7. Promedio de puntos por partido de los jugadores agrupados por conferencia.
SELECT
    c.nombre AS conferencia,
    AVG(jpe.cantidad) AS promedio_puntos_por_jugador_partido
FROM jugador_partido_estad AS jpe
INNER JOIN estadistica AS e_stat ON jpe.estadistica_id = e_stat.estadistica_id
INNER JOIN jugador AS j ON jpe.jugador_id = j.jugador_id
INNER JOIN partido AS p ON jpe.partido_id = p.partido_id
INNER JOIN staging_stats AS s ON j.player_code = s.playerId AND p.game_code = s.gameId
INNER JOIN equipo AS eq ON s.sigla = eq.sigla
INNER JOIN division AS d ON eq.division_id = d.division_id
INNER JOIN conferencia AS c ON d.conferencia_id = c.conferencia_id
WHERE e_stat.codigo = 'PTS'
GROUP BY c.nombre;

--8. Promedio de asistencias por partido de los equipos agrupados por división.
WITH TeamAssistsPerGame AS (
    SELECT
        eq.equipo_id,
        p.partido_id,
        SUM(jpe.cantidad) AS total_asistencias
    FROM jugador_partido_estad AS jpe
    INNER JOIN jugador AS j ON jpe.jugador_id = j.jugador_id
    INNER JOIN partido AS p ON jpe.partido_id = p.partido_id
    INNER JOIN staging_stats AS s ON j.player_code = s.playerId AND p.game_code = s.gameId
    INNER JOIN equipo AS eq ON s.sigla = eq.sigla
    WHERE jpe.estadistica_id = (SELECT estadistica_id FROM estadistica WHERE codigo = 'AST')
    GROUP BY eq.equipo_id, p.partido_id
)
SELECT
    d.nombre AS division,
    AVG(tapg.total_asistencias) AS promedio_asistencias_por_equipo
FROM TeamAssistsPerGame AS tapg
INNER JOIN equipo AS e ON tapg.equipo_id = e.equipo_id
INNER JOIN division AS d ON e.division_id = d.division_id
GROUP BY d.nombre;

--9. Indicar nombre del país y cantidad de jugadores, del país con más jugadores en el torneo (excluyendo Estados Unidos).
SELECT
    p.nombre,
    COUNT(j.jugador_id) AS cantidad_jugadores
FROM jugador AS j
INNER JOIN pais AS p ON j.pais_id = p.pais_id
WHERE p.nombre NOT IN ('Usa', 'United States')
GROUP BY p.nombre
ORDER BY cantidad_jugadores DESC
LIMIT 1;

--10. Promedio de minutos jugados por cada jugador, de los originarios del país del punto anterior. Se considera partido jugado si jugó al menos 1 minuto en el partido.
WITH PaisMasJugadores AS (
    SELECT p.pais_id
    FROM jugador AS j
    INNER JOIN pais AS p ON j.pais_id = p.pais_id
    WHERE p.nombre NOT IN ('Usa', 'United States')
    GROUP BY p.pais_id
    ORDER BY COUNT(j.jugador_id) DESC
    LIMIT 1
)
SELECT
    j.nombre,
    j.apellido,
    AVG(jpe.cantidad) AS promedio_minutos_jugados
FROM jugador AS j
INNER JOIN jugador_partido_estad AS jpe ON j.jugador_id = jpe.jugador_id
INNER JOIN estadistica AS e ON jpe.estadistica_id = e.estadistica_id
WHERE j.pais_id = (SELECT pais_id FROM PaisMasJugadores)
  AND e.codigo = 'MINS'
  AND jpe.cantidad >= 1
GROUP BY j.jugador_id, j.nombre, j.apellido
ORDER BY j.apellido, j.nombre;

--11. Cantidad de jugadores con más de 15 años de carrera.
SELECT COUNT(*) AS cantidad_jugadores
FROM jugador
WHERE draft_year IS NOT NULL
  AND (EXTRACT(YEAR FROM CURRENT_DATE) - draft_year) > 15;

--12. Cantidad de partidos en que los que al menos un jugador de los Suns obtuvo más de 18 puntos.
SELECT COUNT(DISTINCT p.partido_id)
FROM jugador_partido_estad AS jpe
INNER JOIN estadistica AS e_stat ON jpe.estadistica_id = e_stat.estadistica_id
INNER JOIN jugador AS j ON jpe.jugador_id = j.jugador_id
INNER JOIN partido AS p ON jpe.partido_id = p.partido_id
INNER JOIN staging_stats AS s ON j.player_code = s.playerId AND p.game_code = s.gameId
INNER JOIN equipo AS eq ON s.sigla = eq.sigla
WHERE e_stat.codigo = 'PTS'
  AND jpe.cantidad > 18
  AND eq.nombre LIKE '%Suns%';

--13. Listado con ID de partido, fecha, sigla y puntos realizados del equipo local y visitante, del partido en que el equipo de Matt Ryan ganó por mayor diferencia de puntos en la temporada.
WITH MattRyanGames AS (
    SELECT
        p.partido_id,
        p.fecha,
        p.puntos_local,
        p.puntos_visitante,
        e_local.sigla AS sigla_local,
        e_visit.sigla AS sigla_visitante,
        (SELECT eq.equipo_id FROM equipo eq WHERE eq.sigla = s.sigla) AS ryan_team_id,
        p.equipo_ganador_id,
        ABS(p.puntos_local - p.puntos_visitante) AS diferencia
    FROM partido AS p
    INNER JOIN staging_stats AS s ON p.game_code = s.gameId
    INNER JOIN jugador AS j ON s.playerId = j.player_code
    INNER JOIN equipo AS e_local ON p.equipo_local_id = e_local.equipo_id
    INNER JOIN equipo AS e_visit ON p.equipo_visitante_id = e_visit.equipo_id
    WHERE j.nombre = 'Matt' AND j.apellido = 'Ryan'
)
SELECT
    partido_id,
    fecha,
    sigla_local,
    puntos_local,
    sigla_visitante,
    puntos_visitante
FROM MattRyanGames
WHERE ryan_team_id = equipo_ganador_id
ORDER BY diferencia DESC
LIMIT 1;

--14. Listado con el Top 10 de goleadores, indicando nombre del jugador, cantidad de puntos, cantidad de partidos jugados, y promedio de puntos por partidos, ordenando por este último criterio para determinar los goleadores.
SELECT
    j.nombre,
    j.apellido,
    SUM(jpe.cantidad) AS puntos_totales,
    COUNT(jpe.partido_id) AS partidos_jugados,
    AVG(jpe.cantidad) AS promedio_puntos
FROM jugador_partido_estad AS jpe
INNER JOIN jugador AS j ON jpe.jugador_id = j.jugador_id
INNER JOIN estadistica AS e ON jpe.estadistica_id = e.estadistica_id
WHERE e.codigo = 'PTS'
GROUP BY j.jugador_id, j.nombre, j.apellido
ORDER BY promedio_puntos DESC
LIMIT 10;

--15. Tabla de posiciones finales de los equipos de la conferencia Oeste, indicando nombre del equipo, código, cantidad partidos ganamos, cantidad partidos perdidos, puntos a favor, puntos en contra y diferencia de puntos. Ordenando de mayor a menor por cantidad de partidos ganados y diferencia de puntos.
WITH LatestSeason AS (
    SELECT temporada_id
    FROM temporada
    ORDER BY descripcion DESC
    LIMIT 1
),
TeamGameStats AS (
    SELECT
        p.equipo_local_id AS equipo_id,
        CASE WHEN p.equipo_ganador_id = p.equipo_local_id THEN 1 ELSE 0 END AS win,
        p.puntos_local AS points_for,
        p.puntos_visitante AS points_against
    FROM partido p
    WHERE p.equipo_ganador_id IS NOT NULL
      AND p.temporada_id = (SELECT temporada_id FROM LatestSeason)
    SELECT
        p.equipo_visitante_id AS equipo_id,
        CASE WHEN p.equipo_ganador_id = p.equipo_visitante_id THEN 1 ELSE 0 END AS win,
        p.puntos_visitante AS points_for,
        p.puntos_local AS points_against
    FROM partido p
    WHERE p.equipo_ganador_id IS NOT NULL
      AND p.temporada_id = (SELECT temporada_id FROM LatestSeason)
),
Standings AS (
    SELECT
        equipo_id,
        SUM(win) AS partidos_ganados,
        COUNT(*) - SUM(win) AS partidos_perdidos,
        SUM(points_for) AS puntos_a_favor,
        SUM(points_against) AS puntos_en_contra,
        SUM(points_for) - SUM(points_against) AS diferencia_puntos
    FROM TeamGameStats
    GROUP BY equipo_id
)
SELECT
    e.nombre AS equipo,
    e.codigo,
    s.partidos_ganados,
    s.partidos_perdidos,
    s.puntos_a_favor,
    s.puntos_en_contra,
    s.diferencia_puntos
FROM Standings s
INNER JOIN equipo e ON s.equipo_id = e.equipo_id
INNER JOIN division d ON e.division_id = d.division_id
INNER JOIN conferencia c ON d.conferencia_id = c.conferencia_id
WHERE c.nombre = 'Oeste'
ORDER BY s.partidos_ganados DESC, s.diferencia_puntos DESC;