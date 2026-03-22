Algoritmo ejrciciosfechadf
	Definir fecha, mes, dia, anio, cal1, cal2 Como Entero;
	Escribir "dime la fecha en formato mmddaa";
	Leer fecha;
	mes=trunc(fecha/10000);
	cal1=fecha-(mes*10000);
	dia=trunc(cal1/100);
	anio=cal1-(dia*100);
	Escribir dia, "/", mes, "/", anio;
	
FinAlgoritmo
