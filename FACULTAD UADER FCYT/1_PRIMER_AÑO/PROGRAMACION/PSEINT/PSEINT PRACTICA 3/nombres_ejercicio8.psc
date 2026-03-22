Algoritmo nombres_ejercicio8
	Definir nombre, aux Como Caracter;
	Definir contador Como Entero;
	Escribir "ingrese un nombre";
	leer nombre;
	contador=1;
	Repetir
		aux=nombre;
		escribir "ingrese otro nombre";
		leer nombre;
		contador=contador+1;
	Hasta Que nombre=aux
	Escribir "La cantidad de nombres ingresados fue: ", contador;
FinAlgoritmo
