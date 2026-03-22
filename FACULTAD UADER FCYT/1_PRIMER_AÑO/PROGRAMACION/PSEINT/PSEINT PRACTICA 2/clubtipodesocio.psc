Algoritmo clubsocios
	Definir vbase, numsocio, total Como entero;
	definir nclub, nya, tipo Como Caracter;
	Escribir "ingrese el valor base de la cuota";
	leer vbase;
	Escribir "ingrese el nombre del club";
	Leer nclub;
	Escribir "ingrese su nombre y apellido";
	leer nya;
	Escribir "ingrese su numero de socio";
	leer numsocio;
	Escribir "ingrese su tipo de socio";
	leer tipo;
	si tipo="activo" Entonces
		total=vbase;
	sino 
		si tipo="familiar" Entonces
			total=vbase*1.5;
		sino
			si tipo="cadete" Entonces
				total=vbase*0.8;
			FinSi
		FinSi
	FinSi
	Escribir "CLUB: ", nclub, " NRO DE SOCIO: ", numsocio, " NOMBRE DEL SOCIO: ", nya, " TIPO DE SOCIO: ", tipo, " TOTAL A PAGAR:$",total;
FinAlgoritmo
