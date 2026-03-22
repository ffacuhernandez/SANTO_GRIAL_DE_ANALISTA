Algoritmo eldelabueloo
	Definir sueldoabuelo, edad1, edad2, edad3, cal1, cal2, cal3 Como Real;
	Escribir  "abuelo, decime tu sueldo";
	Leer sueldoabuelo;
	Escribir "decime la edad de tu primer nieto";
	Leer edad1;
	Escribir  "decime la edad de tu segundo nieto";
	leer edad2;
	Escribir "decime la edad de tu tercer nieto";
	Leer edad3;
	sueldoabuelo = sueldoabuelo*0.15;
	Escribir "el total a repartir sera: ", sueldoabuelo;
	Escribir "se divide el mayor 50%, el del medio 30% y el menor 20%";
	si (edad1>edad2) y (edad1>edad3) Entonces
		si (edad2>edad3) Entonces
			cal1= sueldoabuelo*0.5;//edad1
			cal2= sueldoabuelo*0.3;//edad2
			cal3= sueldoabuelo*0.2;//edad3
			Escribir "el mayor es: ", edad1, " y este sacara un total de ", cal1;
			Escribir "el mediano es: ", edad2, " y este sacara un total de ", cal2;
			Escribir "el mas chico es: ", edad3, " y este sacara un total de ", cal3;
		SiNo
			si (edad3>edad2) Entonces
				cal1= sueldoabuelo*0.5;//edad
				cal2= sueldoabuelo*0.2;//edad2
				cal3= sueldoabuelo*0.3;//edad3
				Escribir "el mayor es: ", edad1, " y este sacara un total de ", cal1;
				Escribir "el mediano es: ", edad3, " y este sacara un total de ", cal3;
				Escribir "el mas chico es: ", edad2, " y este sacara un total de ", cal2;
			FinSi
		FinSi
		
	FinSi
	
	si (edad2>edad1) y (edad2>edad3) Entonces
		si (edad1>edad3) Entonces
			cal1= sueldoabuelo*0.3;//edad
			cal2= sueldoabuelo*0.5;//edad2
			cal3= sueldoabuelo*0.2;//edad3
			Escribir "el mayor es: ", edad2, " y este sacara un total de ", cal2;
			Escribir "el mediano es: ", edad1, " y este sacara un total de ", cal1;
			Escribir "el mas chico es: ", edad3, " y este sacara un total de ", cal3;
		SiNo
			si (edad3>edad1) Entonces
				cal1= sueldoabuelo*0.2;//edad
				cal2= sueldoabuelo*0.5;//edad2
				cal3= sueldoabuelo*0.3;//edad3
				Escribir "el mayor es: ", edad2, " y este sacara un total de ", cal2;
				Escribir "el mediano es: ", edad3, " y este sacara un total de ", cal3;
				Escribir "el mas chico es: ", edad1, " y este sacara un total de ", cal1;
			FinSi
		FinSi
	FinSi
	si (edad3>edad1) y (edad3>edad2) Entonces
		si (edad1>edad2) Entonces
			cal1= sueldoabuelo*0.3;//edad
			cal2= sueldoabuelo*0.2;//edad2
			cal3= sueldoabuelo*0.5;//edad3
			Escribir "el mayor es: ", edad3, " y este sacara un total de ", cal3;
			Escribir "el mediano es: ", edad1, " y este sacara un total de ", cal1;
			Escribir "el mas chico es: ", edad2, " y este sacara un total de ", cal2;
		SiNo
			si (edad2>edad1) Entonces
				cal1= sueldoabuelo*0.2;//edad
				cal2= sueldoabuelo*0.3;//edad2
				cal3= sueldoabuelo*0.5;//edad3
				Escribir "el mayor es: ", edad3, " y este sacara un total de ", cal3;
				Escribir "el mediano es: ", edad2, " y este sacara un total de ", cal2;
				Escribir "el mas chico es: ", edad1, " y este sacara un total de ", cal1;
			FinSi
		FinSi
	FinSi
	
FinAlgoritmo
