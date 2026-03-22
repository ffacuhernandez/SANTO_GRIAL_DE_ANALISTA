#include <iostream>
using namespace std;

///Realice un método que retorne el mayor elemento de un vector de 10 enteros. Utilice recursividad.

int mayor_vector(int vector[], int n) {
	if (n == 1) {
		return vector[0]; // Caso base: si solo hay un elemento, es el mayor
	}
	
	int mayorsete = mayor_vector(vector, n - 1); // Llamada recursiva
	
	if (vector[n - 1] > mayorsete) {
		return vector[n - 1]; // Si el elemento actual es mayor, lo retornamos
	} else {
		return mayor_parcial; // Si no, retornamos el mayor parcial
	}
}

int main(int argc, char *argv[]) {
	int vector[10], tamanio = 10;
	for (int i = 0; i < tamanio; i++){
		cout << "Ingrese el numero de la pos " << i + 1 << endl << ">";
		cin >> vector[i];
	}
	int resul = mayor_vector(vector, tamanio);
	cout << "EL MAYOR ES: " << resul << endl;
	return 0;
}

