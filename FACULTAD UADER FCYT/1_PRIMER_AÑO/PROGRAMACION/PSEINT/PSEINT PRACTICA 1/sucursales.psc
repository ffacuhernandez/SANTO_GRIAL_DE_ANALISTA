Algoritmo empresa_con_sucursales
	//2 sucursales. se conocen los montos de ventas cada 6 meses DE CADA UNO.
	Definir cal1, cal2, cal3, cal4, sucursal1, sucursal2, tventas, empleados Como entero;
	Definir div1, div2 Como Real;
	Escribir "dime el total de venta del primer semestre en la primera sucursal";
	Leer cal1;
	Escribir "ahora dime el total de venta del segundo semestre";
	leer cal2;
	sucursal1=cal1+cal2;
	Escribir "dime el total de venta del primer semestre en la segunda sucursal";
	leer cal3;
	Escribir "ahora dime el total de venta del segundo semestre";
	Leer cal4;
	sucursal2=cal3+cal4;
	tventas=sucursal1+sucursal2;
	Escribir "dime la cantidad de empleados que tenian las sucursales";
	Leer empleados;
	div1= tventas/0.2;
	div2= div1/empleados;
	Escribir "el total de ventas en las dos sucursales es de ", tventas, " y el total a cada empleado es ", div2;
	
	
	
FinAlgoritmo
