Algoritmo fibonacciejer2
	//ver clase del tomi schlotahuer que muestra el excell para entender que hace la tabla
	//La C es la correcta, no hace falta hacer este ejercicio, era deducir el programa leyendo el PDF de la guia 3
	definir ult, n, ant, aux Como Entero;
	ult=1;
	n=3;
	ant=1;
	Escribir "1", ant;
	Escribir "2", ult;
	Repetir
		aux=ult;
		ult=ult+ant;
		ant=aux;
		Escribir n, ult;
		n=n+1;
	Hasta Que n>10 y ant>34 
FinAlgoritmo
