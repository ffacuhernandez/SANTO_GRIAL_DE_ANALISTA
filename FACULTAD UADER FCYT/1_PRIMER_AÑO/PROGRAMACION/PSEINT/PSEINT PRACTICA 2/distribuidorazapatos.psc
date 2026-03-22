Algoritmo distribuidorazapatos
	Definir n, ndistribuidora, forr Como Caracter;
	Definir precioz, cant, forma, total Como Real;
	Escribir "dime el nombre de la distribuidora";
	leer ndistribuidora;
	Escribir "dime tu nombre";
	leer n;
	Escribir "dime el precio del zapato";
	leer precioz;
	Escribir "dime la cantidad";
	leer cant;
	Escribir "dime la forma de pago";
	leer forma;
	si forma=1 Entonces
		forr="10% menos sobre el total";
	SiNo
		si forma=2 Entonces
			forr="No se hace ningun descuento o recargo";
		SiNo
			si forma=3 Entonces
				forr="23% mas sobre el total";
			FinSi
		FinSi
	FinSi
	segun forma hacer
		1: forma=0.9;
		2: forma=1;
		3: forma=1.23;
		De Otro Modo:
			Escribir "no eligio un metodo de pago correcto, es de 1 a 3";
	FinSegun
	total=(precioz*cant)*forma;
	Escribir ndistribuidora," ", n;
	Escribir cant," ", precioz;
	Escribir "Forma de pago elegida: ",forma;
	Escribir "Le corresponde un descuento/recargo de ",forr;
	Escribir "El total es de:$", total;
	
	
FinAlgoritmo
