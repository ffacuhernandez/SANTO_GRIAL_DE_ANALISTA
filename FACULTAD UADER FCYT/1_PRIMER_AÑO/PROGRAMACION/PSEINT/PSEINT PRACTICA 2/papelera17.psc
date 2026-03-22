Algoritmo papelera17
	Definir p1, p2, p3, p4, tipo, cant, price, des,totalitario como real;
	Definir men, xd Como Caracter;
	Escribir "Ingrese precio de tipo de papel 1";
	leer p1;
	Escribir "ingrese precio de tipo de papel 2";
	leer p2;
	Escribir "ingrese precio de tipo de papel 3";
	leer p3;
	Escribir "ingrese precio de tipo papel 4";
	leer p4;
	Escribir "ingrese tipo de papel";
	leer tipo;
	Escribir "dime la cantidad comprada";
	leer cant;
	segun tipo hacer
		1: price=p1;
		2: price=p2;
		3: price=p3;
		De Otro Modo:
			Escribir "ingrese el color";
			leer xd;
			si xd <> "blanco" Entonces
				price=p4*1.05;
			sino 
				price=p4;
			FinSi
	FinSegun
	totalitario=price*cant;
	si cant>10 Entonces
		price=price*0.85;
	FinSi
	Escribir "Papelera papelitos";
	Escribir "Tipo de papel: ", tipo;
	Escribir "Precio de referencia: ", price;
	Escribir "Total: ", price, " Descuento: ", price;
	Escribir "Total a abonar: ", totalitario;
FinAlgoritmo
