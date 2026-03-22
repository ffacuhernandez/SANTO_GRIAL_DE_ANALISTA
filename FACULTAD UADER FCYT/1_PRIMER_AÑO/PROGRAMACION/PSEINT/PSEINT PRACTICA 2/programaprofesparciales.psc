Algoritmo programaprofesparciales
	Definir n1, n2, n3, l1, l2, p, p2 Como Real;
	Definir conce Como Caracter;
	Escribir "dime la nota del primer parcial";
	leer n1;
	Escribir "dime la nota del segundo parcial";
	leer n2;
	Escribir "dime la nota del tercer parcial";
	leer n3;
	Escribir "dime el valor minimo de promedio para regularizar";
	leer l1;
	Escribir "dime el valor minimo de promedio para promocionar";
	leer l2;
	p=(n1+n2+n3)/3;
	p2= redon((p-l2)*6/(100-l2)+4);
	si p2=40 o p2<=59 Entonces
		conce="Aprobado";
	SiNo
		si p2>=60 y p2<=70 Entonces
			conce="Bueno";
		SiNo
			si p2>=80 y p2<=90 Entonces
				conce="Distinguido";
			SiNo
				si p2=100 Entonces
					conce="Sobresaliente";
				SiNo
					si p2<40 Entonces
						conce="Sin concepto";
					FinSi
				FinSi
			FinSi
		FinSi
	FinSi
	si p>=l1 y p<l2 Entonces
		Escribir "usted regularizo la materia";
	SiNo
		si p<l1 Entonces
			Escribir "usted tiene la materia libre";
		SiNo
			si p>=l2 Entonces
				Escribir "Usted promociono la materia con una nota de ", p2, " y concepto ", conce;
			FinSi
		FinSi
	FinSi
FinAlgoritmo

