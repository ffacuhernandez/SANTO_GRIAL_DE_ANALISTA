Algoritmo parcial_ejercicio25
	Definir comision, alumnos, nota, c, notas, totalumnos, totnotas Como Entero;
	Escribir "Ingrese el numero de la comision";
	leer comision;
	totnotas=0;
	totalumnos=0;
	notas=0;
	Mientras comision<>999 Hacer
		c=0;
		notas=0;
		Escribir "Ingrese la cantidad de alumnos";
		Leer alumnos;
		totalumnos=totalumnos+alumnos;
		Repetir
			c=c+1;
			Escribir "Ingrese la nota del alumno ", c;
			Leer nota;
			notas=notas+nota;
			totnotas=totalumnos+notas;
		Hasta Que c=alumnos 
		Escribir "El promedio de la comision ",comision, " es de: ", (notas/alumnos);
		Escribir "Ingrese el numero de la comision";
		Leer comision;
	FinMientras
	Escribir "El promedio total es de: ", (totnotas/totalumnos);
FinAlgoritmo
