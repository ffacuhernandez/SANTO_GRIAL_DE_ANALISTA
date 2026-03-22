Algoritmo empresaporhoras
	Definir mporh, ht Como Real;
	Escribir "dime el monto por hora";
	Leer mporh;
	Escribir "dime la cantidad de horas trabajadas";
	leer ht;
	si ht=40 Entonces
		Escribir "el salario es de: ", mporh*ht;
	SiNo
		si ht>40 Entonces
			Escribir "el salario es de: ", ht*(mporh*1.5) ;
		SiNo
			Escribir "no le corresponde un salario ya que no cumplio las 40 horas";
		FinSi
	FinSi
	
FinAlgoritmo
