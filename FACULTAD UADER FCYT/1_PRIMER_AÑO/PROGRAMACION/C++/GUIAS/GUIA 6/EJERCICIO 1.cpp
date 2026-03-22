#include <iostream>
using namespace std;
/*Escriba un algoritmo que lea una lista de N datos numéricos (sin ordenar) y determine la posición de un número que se lee como dato. 
Si el dato buscado no se encuentra mostrar un mensaje que indique que el mismo no fue hallado.*/
int main(int argc, char *argv[]) {
	int n, pos, vector[10], dato;
	cout << "Ingrese el largo de la lista de numeros: " << endl << ">";
	cin >> n;
	for (int i = 0; i < n; i++){
		cout << "Ingrese el numero " << i + 1<< endl << ">";
		cin >> vector[i];
	}
	
	cout << "Ingrese un dato para buscar en la lista: "  << endl << ">";
	cin >> dato;
	int i = 0;
	int bandera = 0;
	while (i<n){
		if (vector[i] == dato){
			bandera = 1;
			pos = i + 1;
			i = n;
		}
		i++;
	}
	if (bandera == 0 ){
		cout << "No se encontro el dato en el vector";
	} else {
		cout << "Se encontro el dato en el vector en la posicion " << pos; 
	}
	return 0;
}

