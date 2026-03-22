Algoritmo Ejer18_P4
	definir nummes,  ingreso, egreso, salmen, salfin, cont Como real;
	definir mes como caracter;
	nummes = 0;
	salfin = 0;
	Repetir
		escribir "Mes";
		leer mes;
		Escribir "ingreso de este mes";
		leer ingreso;
		escribir "Egreso";
		leer egreso;
		Salmen = ingreso - egreso;
	    salfin = salfin + Salmen;
		
		Escribir "En el Mes de: ",mes;
		Escribir"Ingreso: ",ingreso;
		Escribir "Egreso: ", egreso;
		Escribir "Y el Saldo mensual fue de: ", Salmen;
		nummes = nummes + 1;
	Hasta Que nummes = 12;
	
	Escribir "Saldo Final fue de: ",Salfin;
	Si salfin >= 0 entonces 
		Escribir "El balance fue Positivo";
		sino escribir "El Balance Fue Negativo";
	FinSi
FinAlgoritmo
