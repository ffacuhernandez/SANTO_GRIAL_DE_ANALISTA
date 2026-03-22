Algoritmo ejercicio1guia3
	Definir N, X, TD, TC, C, tot Como Entero;
	Definir T Como Caracter;
	Escribir "dime el valor de n (ver en el ejercicio)";
	leer N;
	TD=0;
	TC=0;
	C=0;
	Repetir
		Escribir "dime los valores de t y x";
		leer T, X;
		si T="D" Entonces
			TD=TD+X;
		SiNo
			TC=TC+X;
		FinSi
		C=C+1;
	Hasta Que C=N
	tot=TC-TD;
	Escribir "Cantidad de movimientos: ", N;
	Escribir "Resultado: ", tot;
	
FinAlgoritmo
