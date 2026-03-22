Algoritmo sabersinumeroceronegativopositivo
	Definir num Como Entero;
	Escribir "dime un numero";
	leer num;
	si num>0 Entonces
		Escribir "el numero es positivo";
	sino si num<0 Entonces
			Escribir "el numero es negativo";
		sino 
			Escribir "el numero es cero";
		FinSi
	FinSi
	
	si (num%2=0) Entonces
		Escribir "el numero es par";
	SiNo
		Escribir "el numero es impar";
	FinSi
	si (num%5=0) y (num%3=0) Entonces
		Escribir "el numero es multiplo de 5 y 3";
	SiNo
		Escribir "el numero no es multiplo de 5 y 3";
		
	FinSi
FinAlgoritmo
