Algoritmo colectivooss
	//colectivo tiene: comun, estudiante y trabajador.
	//	COMUN: 100%
	//  ESTUDIANTES: 50%
	//  TRABAJADORES: 40%
	Definir comun, estudiantes, trabajadores, totalboletos, general, cal1, cal2, cal3, recaudado Como Entero;
	Escribir "dime cuantos boletos comunes hay";
	leer comun;
	Escribir "dime cuantos boletos estudiantes";
	Leer estudiantes;
	Escribir "dime cuantos boletos de laburantes";
	leer trabajadores;
	totalboletos= comun+estudiantes+trabajadores;
	Escribir "el total de boletos vendidos fueron: ", totalboletos;
	Escribir "dime el precio del boleto general";
	Leer general;
	cal1= comun*general;
	cal2= (estudiantes*general)/0.5;
	cal3= (trabajadores*general)/0.4;
	recaudado= cal1+cal2+cal3;
	Escribir "el total recaudado de los boletos es: ", recaudado;
FinAlgoritmo
