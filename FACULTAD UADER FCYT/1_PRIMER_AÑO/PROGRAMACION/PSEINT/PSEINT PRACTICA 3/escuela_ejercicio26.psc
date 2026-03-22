Algoritmo escuela_ejercicio26
	Definir nya, materia Como Caracter;
	Definir materiasaprobadas, nota, notalumnos, c, c2, c3 Como Entero;
	c2=0;
	c3=0;
	Escribir "Ingrese el nombre y apellido";
	leer nya;
	Mientras nya<>"zzz" Hacer
		c=0;
		notalumnos=0;
		Escribir "Ingrese la cantidad de materias aprobadas";
		Leer materiasaprobadas;
		Repetir
			Escribir "Ingrese el nombre de la materia aprobada";
			Leer materia;
			Escribir "Ingrese la nota que tuvo en esa materia";
			Leer nota;
			si materia="ingles" Entonces
				c3=c3+1;
			FinSi
			notalumnos=notalumnos+nota;
			c=c+1;
		Hasta Que c=materiasaprobadas
		Escribir "El promedio del alumno ",nya, " es de: ", (notalumnos/materiasaprobadas);
		si materiasaprobadas>10 Entonces
			c2=c2+1;
		FinSi
		Escribir "Ingrese el nombre y apellido";
		leer nya;
	FinMientras
	Escribir "Los cantidad de alumnnos que han aprobado mas de 10 materias es de: ", c2;
	Escribir "El porcentaje de alumnos que aprobaron Ingles es: ", (100/c3), "%";
FinAlgoritmo
