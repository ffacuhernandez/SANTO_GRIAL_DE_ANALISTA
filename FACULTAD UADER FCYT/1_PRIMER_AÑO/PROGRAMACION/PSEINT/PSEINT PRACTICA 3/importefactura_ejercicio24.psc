Algoritmo importefactura_ejercicio24
	Definir cantidad, precio, calculo, total Como Entero;
	Escribir "Ingrese la cantidad de unidades vendidas";
	leer cantidad;
	calculo=0;
	total=0;
	Mientras cantidad<>0 Hacer
		Repetir
			Escribir "Ingrese el precio unitario";
			Leer precio;
		Hasta Que precio>0;
		calculo=precio*cantidad;
		total=total+calculo;
		Escribir "Ingrese la cantidad de unidades vendidas";
		Leer cantidad;
	FinMientras
	Escribir "El total de la factura es: ", total;
	
FinAlgoritmo
