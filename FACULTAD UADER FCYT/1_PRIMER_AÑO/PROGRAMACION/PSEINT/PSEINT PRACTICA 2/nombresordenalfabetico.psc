Algoritmo nombresordenalfabetico
	definir nom1, nom2, nom3 Como Caracter;
	Escribir "dime el primer nombre";
	leer nom1;
	Escribir "dime el segundo nombre";
	leer nom2;
	Escribir "dime el tercer nombre";
	leer nom3;
	si (nom1<nom2) y (nom1<nom3) Entonces
		si (nom2<nom3) Entonces
			Escribir "el orden es: ", nom1, "/", nom2, "/", nom3;
		SiNo
			si (nom3<nom2) Entonces
				Escribir "el orden es: ", nom1, "/", nom3, "/", nom2;
			FinSi
		FinSi
		
	FinSi
	si (nom2<nom1) y (nom2<nom3) Entonces
		si (nom1<nom3) Entonces
			Escribir "el orden es: ", nom2, "/", nom1, "/", nom3;
		SiNo
			si (nom3<nom1) Entonces
				Escribir "el orden es: ", nom2, "/", nom3, "/", nom1;
			FinSi
		FinSi
		
	FinSi
	si (nom3<nom1) y (nom3<nom2) Entonces
		si (nom2<nom1) Entonces
			Escribir "el orden es: ", nom3, "/", nom2, "/", nom1;
		SiNo
			si (nom1<nom2) Entonces
				Escribir "el orden es: ", nom3, "/", nom1, "/", nom2;
			FinSi
		FinSi
		
	FinSi
FinAlgoritmo
