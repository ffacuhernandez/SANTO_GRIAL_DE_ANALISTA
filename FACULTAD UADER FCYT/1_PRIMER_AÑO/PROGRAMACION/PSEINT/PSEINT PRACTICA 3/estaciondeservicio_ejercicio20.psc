Algoritmo estacionservicio_ejercicio20
	Definir sup, prem, di, codi, total, litros, c1, c2, c3, totalitario Como Real;
	Definir patente, tipo Como Caracter;
	Escribir "dime le precio por litro de la nafta Super, Premium y Diesel";
	leer sup, prem, di;
	totalitario=0;
	c1=0;
	c2=0;
	c3=0;
	Repetir
		Escribir "ingrese la patente del auto";
		leer patente;
		Escribir "ingrese el codigo del empleado";
		leer codi;
		Escribir "ingrese el tipo de combustible (super, premium, diesel)";
		leer tipo;
		Escribir "ingrese la cantidad de litros";
		leer litros;
		si patente="xxx" Entonces
			total=0;
			litros=0;
			tipo=".";
		FinSi
		si tipo="super" Entonces
			total=litros*sup;
			c1=c1+litros;
		SiNo
			si tipo="premium" Entonces
				total=litros*prem;
				c2=c2+litros;
			SiNo
				si tipo="diesel" Entonces
					total=litros*di;
					c3=c3+litros;
				FinSi
			FinSi
		FinSi
		totalitario=totalitario+total;
	Hasta Que patente="xxx" 
	Escribir "La cantidad de litros vendidos de Super fueron: ",c1;
	Escribir "La cantidad de litros vendidos de Premium fueron: ", c2;
	Escribir "La cantidad de litros vendidos de Diesel fueron: ",c3;
	Escribir "El monto total recaudado por la estacion fueron de: ", totalitario;
	
FinAlgoritmo
