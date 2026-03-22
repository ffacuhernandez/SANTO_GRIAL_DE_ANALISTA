Algoritmo numerosazar_ejercicio17
	Definir n, blackbull, c Como Entero;
	blackbull=0;
	c=0;
	Repetir
		n= Aleatorio(0,1000000);
		mientras n>blackbull Hacer
			blackbull=n;
			Escribir n;
			c=c+1;
		FinMientras
	Hasta Que c=10

FinAlgoritmo
