Algoritmo inmobiliaria
	Definir palquiler, zona, total Como Real;
	Definir comi Como Caracter;
	Escribir "ingrese el precio del alquiler";
	leer palquiler;
	Escribir "ingrese la zona de vivienda";
	leer zona;
	segun zona hacer
		1: total=palquiler*1.15;
		2: total=palquiler*1.1;
		3: total=palquiler*1.08;
		De Otro Modo:
			Escribir "usted a ingresado una zona la cual la inmobiliaria no posee";
	FinSegun
	
	Escribir "el precio base del aquiler es de ", palquiler;
	si zona=1 Entonces
		comi="15%";
	SiNo
		si zona=2 Entonces
			comi="10%";
		SiNo
			si zona=3 Entonces
				comi="8%";
			FinSi
		FinSi
	FinSi
	Escribir "El precio base del alquiler es ",palquiler, " el monto de impuestos es ",comi, " y el total a pagar es: $", total;
FinAlgoritmo
