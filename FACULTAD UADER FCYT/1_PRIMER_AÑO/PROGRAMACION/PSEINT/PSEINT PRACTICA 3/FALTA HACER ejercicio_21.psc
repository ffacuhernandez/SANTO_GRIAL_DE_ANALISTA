Algoritmo empresaconstructora_ejercicio21
	Definir cod, cos1, cos2, cos3, cos4, tot Como Entero;
	Definir mat Como Caracter;
	Escribir "Ingrese el costo de los materiales (LADRILLO, CEMENTO, OTROS)";
	leer cos1, cos2, cos3, cos4;
	Repetir
		Escribir "ingrese el codigo de la obra";
		leer cod;
		Escribir "Ingrese el tipo de material (L - ladrillo, C - cemento, O - otros.)";
		leer mat;
		Segun cod Hacer
			1: tot=mat;
			2: tot=mat;
			3: tot=mat;
			4: tot=mat;
		FinSegun
		total1=total1+tot;
		total2=total2+tot;
		total3=total3+tot;
		total4=total4+tot;
	Hasta Que cod=9
FinAlgoritmo
