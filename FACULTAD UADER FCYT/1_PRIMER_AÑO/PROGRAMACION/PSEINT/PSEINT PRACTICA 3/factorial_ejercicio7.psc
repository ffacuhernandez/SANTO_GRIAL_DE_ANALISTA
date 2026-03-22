Algoritmo factorial_ejercicio7
	definir num, aux, k Como Entero;
	Repetir
		Escribir "ingrese un numero entero positivo";
		leer num;
	Hasta Que num>=0
	aux=1;
	k=1;
	mientras num>=aux Hacer
		k=k*aux;
		aux=aux+1;
	FinMientras
	Escribir "el factorial del numero es: ", k;
FinAlgoritmo
