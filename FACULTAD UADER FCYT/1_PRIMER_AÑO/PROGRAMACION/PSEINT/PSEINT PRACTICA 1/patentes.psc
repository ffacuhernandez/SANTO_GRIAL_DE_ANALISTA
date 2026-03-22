Algoritmo POLICIASYPATENTES
	//dos puestos de policias que reciben la siguiente informacion 	del primero: patente, hora, minutos, segundos.
	//															 	del segunod: hora, minutos, segundos.
	Definir patente Como Caracter;
	Definir hora1, minutos1, segundos1, hora2, minutos2, segundos2, cal1, cal2, promedio, promedio2 Como Real;
	Escribir "numero de patente";
	Leer patente;
	Escribir "dime la hora del primer patrullero";
	Leer hora1;
	Escribir "dime los minutos del primer patrullero";
	Leer minutos1;
	Escribir "dime los segundos del primer patrullero";
	Leer segundos1;
	Escribir "dime las horas del segundo patrullero";
	Leer hora2;
	Escribir "dime los minutos del segundo patrullero";
	Leer minutos2;
	Escribir "dime los segundos del segundo patrullero";
	Leer segundos2;
	hora1=hora1*3600;
	minutos1=minutos1*60;
	hora2=hora2*3600;
	minutos2=minutos2*60;
	cal1=hora1+minutos1+segundos1;
	cal2=hora2+minutos2+segundos2;
	promedio=cal2-cal1;
	promedio2= 7.5/promedio; //formula velocidad media
	Escribir "el auto con la patente: ", patente, " paso a la velocidad promedio de: ", promedio2;
	
	
	
	
FinAlgoritmo
