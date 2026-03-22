Algoritmo parcialbebes
	Definir cbebes,dni,panterior,pactual, c, relacion, bebestot, c1, c2, menora, bebesgod Como Real;;
	Definir centrosalud, localidad Como Caracter;
	c=0;
	c1=0;
	c2=0;
	bebesgod=0;
	menora=9999;
	bebestot=0;
	Escribir "ingrese el centro de salud";
	leer centrosalud;
	Mientras centrosalud<>"zzz" Hacer
		Escribir "ingrese la localidad";
		leer localidad;
		Escribir "ingrese la cantidad de bebes atendidos";
		leer cbebes;
		bebestot=bebestot+cbebes;
		si cbebes<menora Entonces
			menora=cbebes;
		FinSi
		repetir
			Escribir "Dime el DNI del bebe";
			leer dni;
			Escribir "Dime el peso anterior";
			leer panterior;
			Escribir "Dime el peso actual";
			leer pactual;
			si panterior>pactual Entonces
				relacion=(panterior*100)/(panterior+pactual); //calculo si bajo
				c1=c+1;
			sino 
				si panterior<pactual Entonces
					relacion=(panterior*100)/(panterior+pactual); //calculo si subio
					c2=c2+1;
				FinSi
			FinSi
			si pactual>panterior Entonces
				Escribir "DATOS E.R - Junio/Julio 2021";
				Escribir "Centro de salud: ",centrosalud, "Localidad", localidad;
				Escribir "DNI", "      Peso Ant", "  Peso actual","      RELACION";
				Escribir dni, "   ", panterior,"         ", pactual, "     ", relacion, " SUBIO"; 
			FinSi
			si panterior>pactual Entonces
				Escribir "DATOS E.R - Junio/Julio 2021";
				Escribir "Centro de salud: ",centrosalud, "Localidad", localidad;
				Escribir "DNI", "      Peso Ant", "  Peso actual","      RELACION";
				Escribir dni, "       ", panterior,", ", pactual, "     ", relacion, " BAJO";
			FinSi
			si panterior=pactual Entonces
				Escribir "DATOS E.R - Junio/Julio 2021";
				Escribir "Centro de salud: ",centrosalud, "Localidad", localidad;
				Escribir "DNI", "      Peso Ant", "  Peso actual","      RELACION";
				Escribir dni, "       ", panterior,"      ", pactual, "     ", relacion, " se mantuvo igual";
				bebesgod=bebesgod+1;
			FinSi
			c=c+1;
			Escribir "------------------------------------";
		Hasta Que c=cbebes
		Escribir "Cantidad de bebes atendidos: ", cbebes, " Cantidad de bebes que mantuvieron su peso: ", bebesgod;;
		Escribir "ingrese el centro de salud";
		leer centrosalud;
	FinMientras
	Escribir "Cantidad total de bebes atendidos en todo el periodo: ", bebestot;
	Escribir "Cantidad total de bebes que perdieron peso: ", c1 ;
	Escribir "Centro de salud con menor cantidad de bebes atendidos: ", menora ;
	

FinAlgoritmo
