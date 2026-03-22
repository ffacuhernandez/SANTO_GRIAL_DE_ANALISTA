Algoritmo mediaxnumero_ejercicio9
	Definir nume, total Como Entero;
	Definir sum Como Real;
	sum=0;
	total=-1;
	Repetir
		Escribir "ingrese un numero";
		leer nume;
		sum=sum+nume;
		total=total+1;
	Hasta Que nume=0
	Escribir "Media: ",(sum/total), ". Cantidad de numeros ingresados: ",total;
	
	
FinAlgoritmo
