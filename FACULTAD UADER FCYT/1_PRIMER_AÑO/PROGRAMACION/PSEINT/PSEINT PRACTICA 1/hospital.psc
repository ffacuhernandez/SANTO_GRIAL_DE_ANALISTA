Algoritmo hospital
	//tres areas: ginecologia, pediatria, traumatologìa. el presupuesto anual se reparte asi:
	// GINECOLOGIA: 40% presupuesto.
	// TRAUMATOLOGIA: 30% presupuesto.
	// PEDIATRIA: 30% presupuesto.
	Definir total, gineco, trauma, pedi Como real;
	Escribir "dime el monto total del presupuesto: ";
	leer total;
	gineco=total*0.4;
	trauma=total*0.3;
	pedi=total*0.3;
	Escribir "el total para ginecologia es: ", gineco, ". El total para traumatologia es: ", trauma, ". Y el total para pediatria es: ", pedi;
	
FinAlgoritmo
