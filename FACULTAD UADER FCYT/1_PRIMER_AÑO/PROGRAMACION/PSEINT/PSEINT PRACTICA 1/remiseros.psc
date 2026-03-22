Algoritmo remiseria
	//datos: nombre y apellido de los dos remiseros, sueldo basico y km en el mes.
	Definir nya1, nya2 Como Caracter;
	Definir sueldo1, sueldo2, km1, km2, total, fercho1, fercho2 Como Real;
	Escribir "dime el nombre del primer remisero";
	Leer nya1;
	Escribir "dime el nombre del segundo remisero";
	Leer nya2;
	Escribir "dime el sueldo basico del primer remisero";
	Leer sueldo1;
	Escribir "dime el sueldo basico del segundo remisero";
	leer sueldo2;
	Escribir "dime los km del primer remis";
	Leer km1;
	escribir "dime los km del segundo remis";
	Leer km2;
	fercho1= km1*50;
	fercho2= km2*50;
	total= (sueldo1+sueldo2+km1+km2);
	Escribir "el primer remisero ",nya1, " tiene un total a cobrar: ", fercho1, ". Y el segundo remisero ", nya2, " tiene un total a cobrar de: ", fercho2, ". El total a cobrar es de: ", total;
	
	
FinAlgoritmo
