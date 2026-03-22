Algoritmo programanumeros_ejercicio12
	Definir num, suma, feka, toro, cont Como Entero;
	num=0;
	suma=0;
	toro=0;
	cont=0;
	Repetir
		Escribir "ingrese un numero";
		feka=0;
		leer num;
		cont=cont+1;
		feka=feka+num;
		toro=toro+feka;
		
	Hasta Que cont=10 o toro=100
	si cont=10 Entonces
		Escribir "se han introducido 10 numeros";
	sino 
		si toro=100 Entonces
			Escribir "la suma de los numeros llega a 100";
		FinSi
	FinSi
	
FinAlgoritmo
