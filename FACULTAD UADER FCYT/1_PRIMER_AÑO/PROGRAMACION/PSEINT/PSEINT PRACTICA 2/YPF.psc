Algoritmo YPF
	Definir importe, cod Como Entero;
	Escribir "dime el importe cargado";
	leer importe;
	Escribir "dime el codigo de combustible";
	leer cod;
	Segun cod hacer
		1: cod=80;
		2: cod=75;
		3: cod=40;
		4: cod=40;
		5: cod=35;
		De Otro Modo:
			Escribir "debe elegir entre los combustibles del 1 al 5, no contamos con mas de esos";
	FinSegun
	si importe>=3500 Entonces
		Escribir "a usted le corresponden ", (cod*3), " puntos";
	SiNo
		Escribir "le corresponden ", cod, " puntos";
	FinSi
	
FinAlgoritmo
