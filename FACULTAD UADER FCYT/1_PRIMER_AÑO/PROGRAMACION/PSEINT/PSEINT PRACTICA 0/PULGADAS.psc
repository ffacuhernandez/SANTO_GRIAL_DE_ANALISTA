Algoritmo dmasdmasd
	//Se desea contar con un algoritmo que, ingresado el sueldo neto de una persona,calcule su aporte jubilatorio (16% del sueldo neto) y el sueldo líquido (sueldo neto - aporte jubilatorio).
	//datos: sueldo neto, aporte jubilatorio del 16%, sueldo luquido (sueldo neto - aporte jubialtorio)
	Definir sueldoneto Como entero;
	Definir aportejubilatorio, sueldoliquidox Como Real;
	Escribir "dime tu sueldo neto";
	Leer sueldoneto;
	aportejubilatorio = sueldoneto*0.16;
	sueldoliquidox = sueldoneto - aportejubilatorio;
	Escribir "su aporte jubilatorio es de ", aportejubilatorio, " y su sueldo liquido es de ", sueldoliquidox;
	
	
	
FinAlgoritmo
