Algoritmo aniobisiesto
	Definir anio Como Entero;
	Escribir "dime el año";
	leer anio;
	si (anio%4=0 y anio%100<>0) o (anio%100=0 y anio%400=0) Entonces
		Escribir "el anio es bisiesto";
	sino 
		Escribir "el anio no es bisiesto";
	FinSi
	
FinAlgoritmo
