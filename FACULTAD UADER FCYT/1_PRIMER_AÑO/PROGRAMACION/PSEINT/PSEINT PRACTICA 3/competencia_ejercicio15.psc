//15) En un triatlón participaron N competidores y por cada uno de ellos se tienen: el número de
//competidor y los 3 pares de datos con la siguientes información:
//	- Código de Deporte (1= natación, 2=carrera, 3=bicicleta)
//	- Tiempo que hizo en ese deporte (en minutos)
//Los pares de datos no vienen ordenados por código de deporte. 

//Se desea obtener:
// - Por cada competidor: tiempo total.
// - El tiempo total del ganador.
//- La hora (en horas y minutos) en que dio por terminada la competencia (momento en que
//   llegó el último), sabiendo que la largada fue a las 17:00 hs. 
//- El tiempo promedio utilizado por los competidores en cada deporte.
//	La cantidad de competidores N se ingresa como primer dato.
//Nota: Todos los competidores completaron las 3 pruebas.

Algoritmo ej15
	Definir N, ncomp, cod, tiempo, c Como Entero;	//c= contador; N= cantidad de participantes
	Definir tmax,tmin,tiempototal, ttotalcomp, ttotal1, ttotal2, ttotal3 Como Entero;
	Definir hora,min Como real;

	Escribir "Ingrese la cantidad de competidores:";
	Leer N;
	
	c=0; tmax=0; tmin=99999;
	ttotal1=0;ttotal2=0;ttotal3=0;
	
	Repetir
		c=c+1;
		cod<-1;
		ttotalcomp=0;
		Repetir
			Escribir "Código de competencia: ", cod;
			Escribir "1= natación, 2=carrera, 3=bicicleta";
			Escribir "Ingrese tiempo (en minutos) en el que hizo ese deporte: ";
			Leer tiempo;
			ttotalcomp=ttotalcomp+tiempo;
			Segun cod Hacer
				1: ttotal1= ttotal1+tiempo;
				2: ttotal2= ttotal2+tiempo;
				3: ttotal3= ttotal3+tiempo;
			FinSegun
			cod=cod+1;
		Hasta Que cod>3;
		
		si ttotalcomp<tmin Entonces
			tmin=ttotalcomp;
		SiNo
			si ttotalcomp>tmax Entonces
				tmax=ttotalcomp;
			FinSi
		FinSi
		
		Escribir "Tiempo total del competidor ",c,": ", ttotalcomp," min";
		Escribir "===============================";
	hasta que c==N
	
	Escribir "El tiempo total del ganador fue: ", tmin;			
	si tmax<60 Entonces
		Escribir "La competencia finalizó a las: 17:",tmax," hs";
	SiNo
		hora=tmax/60;		
		min= REDON((hora-trunc(hora))*60);
		Escribir "La competencia finalizó a las: ", 17+TRUNC(hora),":",min;
	FinSi
	Escribir "El tiempo promedio de la competencia 1 fue:", ttotal1/N;
	Escribir "El tiempo promedio de la competencia 2 fue:", ttotal2/N;
	Escribir "El tiempo promedio de la competencia 3 fue:", ttotal3/N;
FinAlgoritmo
