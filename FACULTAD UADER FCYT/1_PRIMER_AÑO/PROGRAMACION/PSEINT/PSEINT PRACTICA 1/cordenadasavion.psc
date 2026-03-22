Algoritmo avioncordenadas
	// avion parte del punto A, luego al B, luego al C, y culmina devuelta en A.
	// DATOS: 	PUNTO A: (Xa, Ya)
	//			PUNTO B: (Xb, Yb)
	// 			PUNTO C: (Xc, Yc)
	Definir a, b, c, xa, ya, xb, yb, xc, yc Como Real;
	Escribir "dime las cordenadas X y Y del punto A";
	Leer xa, ya;
	Escribir "dime las cordenadas X y Y del punto A";
	Leer xb, yb;
	Escribir "dime las cordenadas X y Y del punto B";
	Leer xc, yc;
	a= (xb^2-xa^2)^2+(yb^2-ya^2)^2;
	a= raiz(a);
	Escribir "su numero es ", a;
	
	
	
	
FinAlgoritmo
