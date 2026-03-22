#include <iostream>
#include <stdlib.h>
using namespace std;

void agregar_elemento(int* &vector, int &tamanio, int n){
	int *aux = new int [tamanio + 1];
	for (int i = 0; i < tamanio; i++){
		aux[i] = vector[i];
	}
	aux[tamanio] = n;
	delete[] vector;
	vector = aux;
	tamanio++;
}

int main(int argc, char *argv[]) {
	int tamanio = 3, new_elemento = 0;
	int *vector = new int[tamanio]{1, 2, 3};
	cout << "VECTOR INICIAL: " << endl;
	for (int i = 0; i < tamanio; i++){
		cout << vector[i] << " ";
	}
	cout << "Ingrese el elemento a agregar: " << endl << ">";
	cin >> new_elemento;
	agregar_elemento(vector, tamanio, new_elemento);
	cout << "VECTOR FINAL: " << endl;
	for (int i = 0; i < tamanio; i++){
		cout << vector[i] << " ";
	}
	return 0;
}

