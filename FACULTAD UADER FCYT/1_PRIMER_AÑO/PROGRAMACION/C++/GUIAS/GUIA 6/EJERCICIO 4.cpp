#include <iostream>
using namespace std;
/*4) Rehacer los ejercicios 2 y 3, considerando que los datos se ingresan ordenados, y aplique el método de búsqueda binaria.*/

int main(int argc, char *argv[]) {
	/// PRIMERO HAGO EL EJERCICIO 2 Y DESPUES EL 3 NASSHEEEE
	/// CUANDO SE QUIERA PROBAR UNO DE LOS DOS, COMENTAS EL OTRO.
	
	/// EJERCICIO 2
	float dni[5], nota[5][3], busqueda; 
	float promedio[5] = {0};
	for (int i = 0; i<4; i++){
		cout << "Ingrese el DNI del alumno " << i + 1 << ":" << endl << ">";
		cin >> dni[i];
		for (int j = 0; j<3; j++){
			cout << "Ingrese la nota numero " << j +1 << ":" << endl << ">";
			cin >> nota[i][j];
		}
		promedio[i] = (nota [i][0] + nota[i][1] + nota[i][2]) / 3;
	}
	cout << "Ingrese el dni a buscar: " << endl << ">";
	cin >> busqueda;
	int li = 0, ls = 4, medio = (li+ls) / 2;
	while ((li <= ls) && (busqueda != dni[medio])){
		if (busqueda < dni[medio]){
			ls = medio - 1;
		} else{
			li = medio + 1;
		}
		medio = (li+ls)/2;
	}
	if (li > ls){
		cout << "Elemento no encontrado: ";
	} else{
		cout << "El promedio del alumno es de: " << promedio[medio];
	}
	
	
	
	/// EJERCICIO 3
	int n, cod, clientes [5][3] = {0},busqueda, saldo;
	cout << "Ingrese la cantidad de clientes: " << endl << ">";
	cin >> n;
	for (int i = 0; i < n; i++){
		cout << "Ingrese el codigo del cliente numero " << i + 1 << ":" << endl << ">";
		cin >> cod;
		clientes [i][0] = cod;
		cout << "Ingrese el saldo del cliente: " << endl << ">";
		cin >> saldo;
		clientes [i][1] = saldo;
	}
	cout << "Ingrese el codigo de cliente que desea conocer el saldo: " << endl << ">";
	cin >> busqueda;
	int li = 0, ls=n, medio = (li+ls)/2;
	while ((li<=ls) && (busqueda != clientes[medio][0])){
		if (busqueda < clientes[medio][0]){
			ls = medio - 1;
		}else {
			li = medio + 1;
		}
		medio = (li + ls)/2;
	}
	if (li > ls){
		cout << "CLIENTE INEXISTENTE";
	} else {
		cout << "EL SUELDO DEL CLIENTE ES DE: " << clientes[medio][1];
	}
	
	
	return 0;
}

