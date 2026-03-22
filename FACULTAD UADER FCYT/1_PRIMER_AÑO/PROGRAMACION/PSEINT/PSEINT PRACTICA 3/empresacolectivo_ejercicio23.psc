Algoritmo empresacolectivo_ejercicio23
	Definir pbolet, ncole, bestu, bcomun, bjubila, maspete Como Entero;
	Definir tdeldia, testudian, tjubilado, totalmasbajo, totalfinal Como Real;
	Escribir "Ingrese el precio del boleto comun";
	leer pbolet;
	totalmasbajo=99999;
	testudian=0;
	tjubilado=0;
	tdeldia=0;
	totalfinal=0;
	Repetir
		Escribir "ingrese el numero de colectivo";
		leer ncole;
		Escribir "Ingrese la cantidad de boletos estudiantiles";
		leer bestu;
		Escribir "Ingrese la cantidad de boletos comunes";
		leer bcomun;
		Escribir "Ingrese la cantidad de boletos jubilados";
		leer bjubila;
		si ncole=99 Entonces
			bestu=0;
			bcomun=0;
			bjubila=0;
		FinSi
		testudian=bestu*bcomun*0.8;
		tjubilado=bjubila*bcomun*0.6;
		tdeldia=testudian+tjubilado+bcomun;
		si tdeldia<totalmasbajo y tdeldia>0 Entonces
			totalmasbajo=tdeldia;
			maspete=ncole;
		FinSi
		Escribir "El total recaudado del colectivo nro ",ncole, " es de: ", tdeldia;
		Escribir "El total de boletos estudiantiles vendidos es: ", bestu;
		Escribir "---------------------------------------------------";
		totalfinal=totalfinal+tdeldia;
	Hasta Que ncole=99
	Escribir "El total recaudado de todos los recorridos ingresados es de: ",totalfinal;
	Escribir "El colectivo que menos recaudó fue el numero ",maspete, " y recaudo un monto de ",totalmasbajo;
FinAlgoritmo
