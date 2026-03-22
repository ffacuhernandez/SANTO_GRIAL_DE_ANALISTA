Algoritmo parcial2022_juegosevita
	Definir provincia, deporte, promastenista Como Caracter;
	Definir atletas, dni, edad, puesto, c, primeros, segundoss, terceros, ultimos, dnijoven, masjoven, tatletas, mastenistas Como Entero;
	Definir ppodio Como Real;
	c=0;
	masjoven=9999;
	primeros=0;
	segundoss=0;
	terceros=0;
	ultimos=0;
	dnijoven=0;
	tatletas=0;
	ppodio=0;
	mastenistas=0;
	promastenista=".";
	Escribir "Ingrese el nombre de la provincia";
	leer provincia;
	mientras provincia<>"xx" Hacer
		Escribir "Ingrese el deporte";
		leer deporte;
		Escribir "Ingrese la cantidad de atletas";
		leer atletas;
		tatletas=tatletas+atletas;
		Repetir
			Escribir "Ingrese el DNI del atleta";
			leer dni;
			Escribir "Ingrese la edad del atleta";
			leer edad;
			Escribir "Ingrese el puesto obtenido";
			leer puesto;
			si edad<masjoven Entonces
				masjoven=edad;
				dnijoven=dni;
			FinSi
			si puesto=1 Entonces
				primeros=primero+1;
				ppodio=ppodio+1;
			sino 
				si puesto=2 Entonces
					segundoss=segundoss+1;
					ppodio=ppodio+1;
				SiNo
					si puesto=3 Entonces
						terceros=terceros+1;
						ppodio=ppodio+1;
					SiNo
						si puesto=4 o puesto=5 Entonces
							ultimos=ultimos+1;
							ppodio=ppodio+1;
						FinSi
					FinSi
				FinSi
			FinSi
			c=c+1;
		Hasta Que c=atletas
		Escribir "JUEGOS EVITA";
		Escribir "Provincia: ", provincia, "		     Deporte: ", deporte;
		Escribir "DNI", "         Edad", "       Puesto";
		Escribir dni, "        ",edad, "          ", puesto;
		Escribir "Cantidad total de 1er Puesto: ", primeros, " 2do Puesto: ", segundoss, " 3er Puesto: ", terceros, " 4to y 5to Puestos: ",ultimos;
		Escribir "DNI del atleta mas joven: ", dnijoven;
		Escribir "-----------------------------------";
		si deporte= "TENIS" y atletas>mastenistas Entonces
			mastenistas=atletas;
			promastenista=provincia;
		FinSi
		Escribir "Ingrese el nombre de la provincia";
		leer provincia;
	FinMientras
	Escribir "Cantidad total de atletas participantes: ", tatletas;
	Escribir "Porcentaje de podios sobre el total de atletas: ", (ppodio/tatletas)*100, "%";
	Escribir "Provincia con mayor cantidad de tenistas: ", mastenistas;
FinAlgoritmo
