Algoritmo nadadores_ejercicio19
	Definir n, mta, c, tiem, best, cracks, petes Como Entero;
	Definir nya, mejor Como Caracter;
	Escribir "ingrese la cantidad de participantes";
	leer n;
	Escribir "ingrese el mejor tiempo de la edicion anterior (en minutos)";
	leer mta;
	c=0;
	best=999;
	cracks=0;
	petes=0;
	Repetir
		Escribir "ingrese el nombre y apellido del competidor ";
		leer nya;
		Escribir "ingrese el tiempo empleado en la carrera";
		leer tiem;
		si tiem=0 Entonces
			petes=petes+1;
		SiNo
			si tiem<best Entonces
				best=tiem;
				mejor=nya;
			FinSi
		FinSi
		si tiem<mta y tiem>0 Entonces
			cracks=cracks+1;
		FinSi
		c=c+1;
	Hasta Que c=n
	Escribir "El ganador de la competencia es: ", mejor;
	Escribir "Nadadores que abandonaron la competencia: ", petes;
	Escribir "Nadadores que mejoraron el tiempo respecto a la edicion anterior: ", cracks; 
	
FinAlgoritmo
