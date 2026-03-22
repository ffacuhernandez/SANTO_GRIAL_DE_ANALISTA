Algoritmo barrabrava_ejercicio14
	Definir apodo, mono Como Caracter;
	Definir c, cont, w1, w2, w3, w4, aux, detenmax Como Entero;
	cont=0;
	w1=0;
	w2=0;
	w3=0;
	w4=0;
	detenmax=1;
	Repetir
		aux=0;
		Escribir "dime el apodo del barrabrava y la cantidad de veces que a sido detenido";
		leer apodo, c;
		cont=cont+1;
		si c=1 Entonces
			w1=w1+1;
		FinSi
		si c>=2 y c<=4 Entonces
			w2=w2+1;
		FinSi
		si c>=5 y c<=10 Entonces
			w3=w3+1;
		FinSi
		si c>10 Entonces
			w4=w4+1;
		FinSi
		si c>detenmax Entonces
			c=detenmax;
			mono=apodo;
		FinSi
	Hasta Que apodo="zzz"
	Escribir "CANTIDAD DE DETENCIONES ------------------- CANTIDAD DE INTEGRANTES";
	Escribir "			1: ", w1; 
	Escribir "			2-4: ", w2; 
	Escribir "			5-10: ", w3; 
	Escribir "			mas de 10: ", w4; 
	Escribir "Cantidad de integrantes encuestados: ", cont;
	Escribir "Maximo integrante con detenciones: ", mono;
FinAlgoritmo
