###### **Socio(id\_socio(PK), nombre, DNI, calle, numero, piso, dpto, FechaIngreso)**

###### **Embarcación(matricula(PK), nombre, dimensión, tipoembarcacion(FK), id\_socio(FK), num\_amarre(FK), fechadesde)**

###### **Amarre(numero(pk), LecturaAgua, LecturaLuz, Mantenimiento, id\_socio(FK), letra\_zona(FK), fechadesde)**

###### **TipoEmbarcación(codigo(PK), descripcion)**

###### **Zona(letra(PK), profundidad, AnchoAmarres, tipoembarcacion(FK))**

###### **Empleado(código(PK), nombre, telefono)**

###### **Empleado\_Zona(cod\_emp(PK)(FK), letra\_zona(PK)(FK), horario)**

###### **Empleado\_Amarre(cod\_emp(PK)(FK), num\_amarre(PK)(FK), horario)**

