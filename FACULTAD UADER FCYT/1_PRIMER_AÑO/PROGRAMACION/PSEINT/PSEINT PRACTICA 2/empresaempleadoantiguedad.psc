Algoritmo empresaempleadoantiguedad
	Definir ayn, mont Como Caracter;
	Definir cat, anti, cat2, total Como Entero;
	Escribir Sin Saltar "ingrese su nombre y apellido";
	leer ayn;
	Escribir Sin Saltar"dime tu categoria";
	Leer cat;
	Escribir Sin Saltar "dime tu antiguedad";
	leer anti;
	cat2=cat;
	Segun cat2 hacer
		1: cat2=60000;
		2: cat2=50000;
		3: cat2=40000;
		4: cat2=30000;
			
		De Otro Modo:
			Escribir "no cumple con una categoria de la empresa";
	FinSegun
	si anti>=0 y anti<=10 Entonces
		total=cat2*1.2;
	SiNo
		si anti>=11 y anti<=15 Entonces
			total=cat2*1.5;
		sino 
			si anti>=16 y anti<=20 Entonces
				total=cat2*1.8;
			sino 
				si anti>=20 Entonces
					total=cat2*2;
				FinSi
			FinSi
		FinSi
	FinSi
	si anti>0 y anti<=10 Entonces
		mont= "20%";
	SiNo
		si anti>=11 y anti<=15 Entonces
			mont="50%";
		sino 
			si anti>=16 y anti<=20 Entonces
				mont="80%";
			sino 
				si anti>=20 Entonces
					mont="100%";
				FinSi
			FinSi
		FinSi
	FinSi
	Escribir "el/la señor/a: ", ayn, ", de categoria ",cat, ", con un sueldo basico de ", cat2, ", con una antiguedad de ", anti, " años, y un monto de antiguedad de ",mont, ", tiene un sueldo total de:$",total; 
FinAlgoritmo
