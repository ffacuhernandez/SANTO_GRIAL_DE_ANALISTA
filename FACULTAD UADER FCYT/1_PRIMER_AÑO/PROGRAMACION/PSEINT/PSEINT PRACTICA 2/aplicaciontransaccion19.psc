Algoritmo aplicaciontransaccion19
	Definir codigob, cant, preciou, primert, cuota, truncado, valorcuotarda Como Real;
	Definir cartel Como Caracter;
	Escribir "ingrese el codido de barras";
	leer codigob;
	Escribir "ingrese la cantidad de productos";
	leer cant;
	Escribir "ingrese el preciou";
	leer preciou;
	primert=preciou*cant;
    truncado=trunc(codigob/10000000000);
	si truncado=779 Entonces
		Escribir "ingrese la cantidad de cuotas (Ahora 3, Ahora 6, 1 cuota)";
		leer cuota;
		segun cuota hacer
			1: cartel= "En una cuota";
			3: cartel= "Ahora 3";
			6: cartel= "Ahora 6";
				valorcuotarda=primert/cuota;
				Escribir "Producto: ", codigob;
				Escribir "Cantidad: ", cant, "      Precio Unitario: $",preciou;
				Escribir "Total: $", primert;
				Escribir "Cantidad de cuotas: ", cuota, "  Comprado con el plan: ", cartel;
				Escribir "Valor de la cuota: $", valorcuotarda;
		FinSegun
	SiNo
		Escribir "Producto: ", codigob;
		Escribir "Cantidad: ", cant, "  Precio Unitario: $", preciou;
		Escribir "Total: $", primert;
	FinSi
FinAlgoritmo
