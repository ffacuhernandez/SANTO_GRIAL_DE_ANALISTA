Algoritmo IMC_GUIA2
	Definir peso, est, imc Como Real;
	Escribir "dime tu peso en KG";
	leer peso;
	Escribir "dime tu altura";
	leer est;
	imc=peso/(est*est);
	si imc=0 o imc<18.5 Entonces
		Escribir "SU IMC es: ", imc, " y esta debajo del normal";
	FinSi
	
	si imc>=18.5 y imc<25 Entonces
		Escribir "Su IMC es: ", imc, " y es normal";
	FinSi
	
	si imc>=25 y imc<30 Entonces
		Escribir "Su IMC es: ", imc, " y tiene Sobrepeso";
	FinSi
	
	si imc>=30 Entonces
		Escribir "Su IMC es: ", imc, " y tiene obesidad";
	FinSi
FinAlgoritmo
