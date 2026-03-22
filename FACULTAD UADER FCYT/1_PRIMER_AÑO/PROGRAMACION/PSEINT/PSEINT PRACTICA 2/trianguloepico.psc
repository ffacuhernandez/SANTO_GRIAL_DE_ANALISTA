Algoritmo trianguloepico
	Definir l1, l2, l3, perimetro Como Real;
	Definir tipotriangulo como caracter;
	Escribir "ingrese el primer lado";
	Leer l1;
	Escribir "ingrese el segundo lado";
	leer l2;
	Escribir "ingrese el tercer lado";
	leer l3;
	si l1=l2 y l2=l3 Entonces
		tipotriangulo= "Triangulo equilatero";
	sino 
		si l1=l2 o l1=l3 o l2=l3 Entonces
			tipotriangulo="Triangulo isoceles" ;
		SiNo
			tipotriangulo="Triangulo escaleno";
		FinSi
	FinSi
	Escribir "Tipo de triangulo: ",tipotriangulo;
	Escribir "Perimetro del triangulo: ",(l1+l2+l3);
FinAlgoritmo
