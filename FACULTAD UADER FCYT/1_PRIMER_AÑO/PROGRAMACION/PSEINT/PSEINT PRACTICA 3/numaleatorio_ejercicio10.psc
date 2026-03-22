Algoritmo numaleatorio_ejercicio10
	Definir num1, num2, contador Como Entero;
	contador=0;
	Repetir
		num1=Aleatorio(0,999);
		num2=Aleatorio(0,999);
		Escribir num1; Escribir num2;
		contador=contador+2;
	Hasta Que num1==num2
	Escribir "la cantidad de numeros generados fueron de: ", contador;
FinAlgoritmo
