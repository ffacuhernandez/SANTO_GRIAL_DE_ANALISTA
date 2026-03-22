Algoritmo empresabanco_ejercicio27
	Definir empleados, documento, extracciones, dia, montoretirado, c, c2, c3, recargo, tot, sueldototal, perdida, perdidatotal Como Entero;
	Definir nya, cajero Como Caracter;
	Definir sueldo Como Real;
	c=0;
	c2=0;
	c3=0;
	perdida=0;
	perdidatotal=0;
	Escribir "Ingrese la cantidad de empleados que tienen el sueldo depositado en el banco";
	leer empleados;
	Repetir
		tot=0;
		recargo=0;
		c2=0;
		Escribir "Ingrese el numero de documento";
		leer documento;
		Escribir "Ingrese el nombre y apellido";
		leer nya;
		Escribir "Ingrese el monto del sueldo depositado por la empresa";
		leer sueldo;
		Escribir "Ingrese la cantidad de extracciones realizadas en el mes";
		leer extracciones;
		Repetir
			Escribir "Ingrese el dia";
			leer dia;
			Escribir "Ingrese el monto retirado";
			leer montoretirado;
			Escribir "Ingrese el cajero (c=Contratado / nc= No contratado)";
			leer cajero;//1.02
			si cajero="c" Entonces
				recargo=0;
				tot=montoretirado;
			SiNo
				si cajero="nc" Entonces
					recargo=montoretirado*1.02;
					tot=tot+recargo;
				FinSi
			FinSi
			c2=c2+1;
			sueldototal=(sueldo-tot);
		Hasta Que c2=extracciones 
		Escribir "Nombre y apellido: ",nya, "                      DNI: ",documento;
		Escribir "Monto total retirado: $", montoretirado;
		Escribir "Monto total de recargo: $", recargo;
		Escribir "Saldo de la cuenta: ", sueldototal;
		si sueldototal=0 Entonces
			c3=c3+0;
		FinSi
		c=c+1;
		perdida=tot-montoretirado;
		perdidatotal=perdidatotal+perdida;
	Hasta Que c=empleados
	Escribir "La cantidad de empleados con salfo igual a cero son: ", c3;
	Escribir "El monto total retenido en concepto de recargo por utilizar cajeros no contratados es: ", perdidatotal;
	
FinAlgoritmo
