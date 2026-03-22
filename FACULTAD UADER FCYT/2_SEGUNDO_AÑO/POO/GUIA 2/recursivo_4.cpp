#include <iostream>
using namespace std;

///Realice un método que retorne el menor elemento de un vector de 10 enteros. Utilice recursividad.

int menor_vector(int vector[], int n){
	if (n == 1){
		return vector[n - 1];
	} else {
		int menorsete = menor_vector(vector, n - 1);
		if (menorsete < vector[n - 1]){
			return menorsete;
		} else {
			return vector[n - 1];
		}
	}
}

int main(int argc, char *argv[]) {
	int vector[10], tamanio = 10;
	for (int i = 0; i < tamanio; i++){
		cout << "Ingrese el numero de la pos " << i + 1 << endl << ">";
		cin >> vector[i];
	}
	int resul = menor_vector(vector, tamanio);
	cout << "EL MENOR ES: " << resul << endl;
	return 0;
}

