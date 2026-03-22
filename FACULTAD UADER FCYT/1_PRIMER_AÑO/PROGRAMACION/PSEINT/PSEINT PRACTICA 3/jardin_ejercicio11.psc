Algoritmo jardin_ejercicio11
	Definir alumnos, contador Como Entero;
	Definir nya Como Caracter;
	Definir peso, altura, pesomin, alturamax Como Real;
	Escribir "Ingrese la cantidad de alumnos: ";
	leer alumnos;
	contador=0;
	pesomin=1000;
	alturamax=0;
	Repetir
		Escribir "ingrese nombre y apellido";
		leer nya;
		Escribir "ingrese peso del alumno";
		leer peso;
		si peso<pesomin Entonces
			pesomin=peso;
		FinSi
		Escribir "ingrese la altura del alumno";
		leer altura;
		si altura>alturamax Entonces
			alturamax=altura;
		FinSi
		contador=contador+1;
	Hasta Que contador=alumnos
	Escribir "el alumno mas alto mide: ", alturamax, " y el alumno mas flaco pesa: ", pesomin;
	
FinAlgoritmo
