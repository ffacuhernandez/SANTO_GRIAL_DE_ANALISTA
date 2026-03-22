Algoritmo parcial2018
	Definir camion, dia, toneladas, preciosorgo, c, c2, toneladasentotal, toneladascamion Como Real;
	Escribir "Ingrese el costo de venta de la tonelada de sorgo";
	leer preciosorgo;
	Escribir "Ingrese el codigo de camion";
	leer camion;
	c=0;
	toneladasentotal=0;
	Mientras camion<>0 Hacer
		c2=0;
		toneladascamion=0;
		Escribir "Ingrese el dia";
		leer dia;
		Repetir
			c2=c2+1;
			Escribir "Ingrese la cantidad de toneladas del dia ", c2;
			leer toneladas;
			toneladascamion=toneladascamion+toneladas;
		Hasta Que c2=dia
		Escribir "CODIGO CAMION: ", camion;
		Escribir "CANTIDAD DE TONELADAS DE SORGO ", toneladascamion; 
		Escribir "CANTIDAD DE DIAS QUE DESCARGO EL CAMION ", c2;
		Escribir "-------------------------------------";
		Escribir "Ingrese el codigo de camion";
		leer camion;
		c=c+1;
		toneladasentotal=toneladasentotal+toneladascamion;
	FinMientras
	Escribir "TOTAL DE CAMIONES: ", c;
	Escribir "TOTAL DE TONELADAS DE SORGO EN EL PRIMER TRIMESTRE 2019: ", toneladasentotal; 
	Escribir "COSTO ESTIMADO DE GANANCIA: ", (toneladasentotal*preciosorgo);
FinAlgoritmo
