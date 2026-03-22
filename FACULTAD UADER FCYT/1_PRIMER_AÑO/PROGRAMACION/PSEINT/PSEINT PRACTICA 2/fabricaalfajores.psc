Algoritmo fabricaalfajores
	Definir cliente, gusto, regalo Como Caracter;
	Definir tipocaja, gustiano, total, regalox, ibai Como Real;
	Escribir "Dime tu nombre";
	leer cliente;
	Escribir "dime el gusto (dulce de leche, frutales o mouse)";
	Leer gusto;
	Escribir "dime el tipo de caja (6,12 o 24)";
	leer tipocaja;
	Escribir "es para regalo? V/F";
	leer regalo;
	si gusto="dulce de leche" Entonces
		gustiano=50;
	sino
		si gusto="frutales" Entonces
			gustiano=20;
		SiNo
			si gusto="mouse" Entonces
				gustiano=40;
			FinSi
		FinSi
	FinSi
	segun tipocaja hacer
		6: total=(6*gustiano);
		12: total=(0.9*gustiano)*12;
		24: total=(24*gustiano)*0.8;
		De Otro Modo:
			Escribir "no corresponde a ninguna de nuestras cajas, debe ser de 6, 12 o 24";
	FinSegun
	
	si regalo="V" Entonces
		regalox=(total+250);
	sino
		si regalo="F" Entonces
			regalox=0;
		FinSi
	FinSi
	si regalo="V" Entonces
		ibai=regalox*1.21;
	SiNo
		si regalo="F" Entonces
			ibai=total*1.21;
		FinSi
	FinSi
	Escribir "Cliente: ", cliente,"          ", "Tipo de caja: ", tipocaja, "       ", "Gusto: ", regalox;
	escribir "Subtotal ", total, "           Recargo Regalo:", regalox;
	Escribir "IVA 21%: ", ibai ;
	Escribir "Total: ", ibai;
	
FinAlgoritmo
