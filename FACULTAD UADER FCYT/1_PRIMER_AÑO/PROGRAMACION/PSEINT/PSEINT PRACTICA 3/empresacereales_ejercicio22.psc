Algoritmo empresacereales_ejercicio22
	Definir pat, ayn, tipoc Como Caracter;
	Definir toneladas, c, tsoja, ttotal Como Entero;
	c=0;
	tsoja=0;
	ttotal=0;
	Repetir
		Escribir "Ingrese la patente del camion";
		leer pat;
		Escribir "Ingrese el apellido y nombre del remitente";
		leer ayn;
		Escribir "Ingrese el tipo de cereal  (maiz, soja, girasol, etc)";
		leer tipoc;
		Escribir "Ingrese la cantidad de toneladas";
		leer toneladas;
		si pat="xyz 123" Entonces
			toneladas=0;
		FinSi
		si tipoc="soja" Entonces
			tsoja=tsoja+toneladas;
		FinSi
		ttotal=ttotal+toneladas;
		si pat<>"xyz 123" Entonces
			c=c+1;
		FinSi
	Hasta Que pat="xyz 123"
	Escribir "La cantidad de camiones que descargaron cereal durante el dia fueron: ", c;
	Escribir "La cantidad de toneladas de soja es: ", tsoja;
	Escribir "El total de toneladas acopiadas durante el dia es: ", ttotal;
FinAlgoritmo
