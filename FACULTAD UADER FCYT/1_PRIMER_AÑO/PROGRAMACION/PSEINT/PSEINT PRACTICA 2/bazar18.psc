Algoritmo EJERCICIO18
	Definir NyA,DNI,FP,TT,B Como Caracter;
	// NyA= Nombre y Apellido; FP=Forma de Pago
	// TT= Tipo de Tarjeta; B= Banco
	Definir Cant,PrecioU,ST,RTC,DTC,R,D,TP Como Real;
	// Cant= Cantidad comprada; PrecioU= Precio Unitario; ST=Subtotal
	// RTC= Recargo Tarjeta Crédito; DTC= Descuento Tarjeta Crédito
	// R= Recargo; D= Descuento; TP= Total a Pagar
	Definir CC, Rubro Como Entero;
	// CC = Cantidad de Cuotas
	Escribir 'Ingrese Nombre y Apellido del cliente';
	Leer NyA;
	Escribir 'Ingrese el DNI';
	Leer DNI;
	Escribir 'Seleccione rubro de producto: ';
	Escribir '1. Calefactores';
	Escribir '2. Radiadores';
	Escribir '3. Caloventores';
	Escribir '4. Otro producto';
	Leer Rubro;
	Escribir 'Ingrese cantidad comprada';
	Leer Cant;
	Escribir 'Ingrese precio unitario';
	Leer PrecioU;
	Escribir 'Ingrese forma de pago (C: Contado| D: Débito | T: Tarjeta de Crédito)';
	Leer FP;
	// Calculo de datos:
	RTC <- 0;
	DTC <- 0;
	R <- 0;
	D <- 0;
	ST <- Cant*PrecioU;
	TP <- ST;
	Si FP='C' Entonces
		Segun Rubro  Hacer
			1,2,3:
				D <- (15*ST)/100; //cantidad del descuento
				TP= ST-D; //aca el precio final con descuento ya hecho
		FinSegun
	SiNo
		Si FP='T' Entonces
			Escribir 'Ingrese tipo de tarjeta: [Visa | Mastercard | Naranja]';
			Leer TT;
			Escribir 'Ingrese Banco: [BERSA | FRANCES | GALICIA | OTROS]';
			Leer B;
			Escribir 'Ingrese Cantidad de Cuotas [ 1 | 3 | 6 | 12 | 18 ]';
			Leer CC;
			RTC <- (20*ST)/100;
			TP= ST + RTC;
			Si TT='Visa' Y B='BERSA' Entonces
				DTC <- (15*TP)/100;
				TP= TP-DTC;
			FinSi
		SiNo
			// En D no se hace nada, por lo tanto si lo ingresado es distinto de D, la forma de pago ingresada será erronea.
			Si FP<>'D' Entonces
				Escribir 'La forma de pago ingresada no es la indicada';
			FinSi
		FinSi
	FinSi
	Escribir "---------------[DATOS]-------------------";
	Escribir 'DNI: ',DNI,'            CLIENTE: ',NyA;
	Escribir 'RUBRO DEL PRODUCTO: ',Rubro,'      CANTIDAD: ',Cant;
	Escribir 'PRECIO UNITARIO: $',PrecioU,'      FORMA DE PAGO: ',FP;
	Escribir "SUBTOTAL: $",ST ;
	Escribir "DESCUENTOS: $",D;
	Escribir "RECARGOS: $", R;
	Escribir "DESCUENTO TARJETA CRÉDITO: $", DTC;
	Escribir "RECARGO TARJETA CRÉDITO: $", RTC;
	Escribir "TOTAL A PAGAR: $", TP;
FinAlgoritmo
