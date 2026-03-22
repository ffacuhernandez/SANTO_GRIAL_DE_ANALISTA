Algoritmo precioarticulos_ejercicio13
	Definir p1, p2, p3, p4, p5, canti, codigo, precif, xd Como Real;
	Definir nya Como Caracter;
	Escribir "dime los precios unitarios de los cinco articulos (1 al 5)";
	leer p1, p2, p3, p4, p5;
	cont=0;
	xd=0;
	Repetir
		Escribir "ingrese su nya";
		leer nya;
		Escribir "dime la cantidad comprada";
		leer canti;
		Escribir "dime el codigo del articulo";
		leer codigo;
		segun codigo hacer
			1: precif=p1*canti;
			2: precif=p2*canti;
			3: precif=p3*canti;
			4: precif=p4*canti;
			5: precif=p5*canti;
		FinSegun
		xd=precif;
		aux=precif;
		totalventas=totalventas+aux;
		cont=cont+1;
	Hasta Que nya="zzz"
	Escribir "monto total de ventas: ", totalventas;
	Escribir "venta total de cada articulo: ";
	Escribir "cantidad de ventas realizadas: ", cont;
FinAlgoritmo
