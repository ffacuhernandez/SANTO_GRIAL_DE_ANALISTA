Algoritmo alamccceeen
	// Un almacén de barrio necesita un programa para calcular el total a cobrar a un cliente por una compra. Se ingresan los datos de la venta: Nombre y Apellido del cliente, cantidad comprada del artículo y precio unitario del mismo. Al monto total de la venta, se le efectúa un descuento del 5%. Luego de realizado el descuento se 	calcula el IVA del 21% para obtener el total a pagar.
	Definir nombreyapellido Como Caracter;
	Definir cantidadarticulo, precioarticulo, calculo1 Como real;
	Escribir "decime tu nombreyapellido";
	Leer nombreyapellido;
	Escribir "ingresar la cantidad producto";
	Leer cantidadarticulo;
	Escribir "dime el precio del articulo";
	Leer precioarticulo;
	calculo1= (cantidadarticulo*precioarticulo)*1.16;
	Escribir "el cliente", nombreyapellido, "gasto un total de ", calculo1;
	
	
FinAlgoritmo
