Algoritmo tablademultiplicar_ejercicio3
	Definir num, c Como Entero;
	Escribir "ingrese un numero el cual desea saber su tabla de multiplicar del 1 al 10: ";
	leer num;
	si num>0 Entonces
		c=1;
		Repetir
			Escribir num*c;
			c=c+1;
		Hasta Que c>10 
	SiNo
		Escribir "el numero ingresado no es positivo";
	FinSi
FinAlgoritmo
