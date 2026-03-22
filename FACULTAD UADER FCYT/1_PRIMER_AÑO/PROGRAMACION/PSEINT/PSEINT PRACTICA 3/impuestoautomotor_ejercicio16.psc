Algoritmo impuestoautomotor_ejercicio16
	definir val, tot, c, cat Como Real;
	Definir pat,  marca Como Caracter;
	c=0;
	Repetir
		Escribir "dime la patente del auto";
		Leer pat;
		Escribir "dime la marca del auto";
		Leer marca;
		Escribir "dime el valor del auto";
		leer val;
		Escribir "dime la categoria";
		leer cat;
		segun cat Hacer
			1: tot=val*0.10;
			2: tot=val*0.20;
			3: tot=val*0.25;
			4: tot=val*0.40;
		FinSegun
		Escribir "el vehiculo con patente ",pat, " con un valor de ", val, " con la suma de impuestos un total de: $",tot;
		c=c+1;
	Hasta Que c=5
	
FinAlgoritmo
