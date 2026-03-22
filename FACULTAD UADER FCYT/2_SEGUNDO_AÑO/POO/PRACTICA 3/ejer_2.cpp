#include <iostream>
#include <stdlib.h>
using namespace std;

void mostrararreglo(int* array, int tamanio){
	for (int i = 0; i < tamanio; i++){
		cout << array[i] << " ";
	}
}

void agregaralinicio(int*& array, int &tamanio, int valor){
	int* aux = new int[tamanio + 1];
	aux[0] = valor;
	for (int i = 0; i < tamanio; i++){
		aux[i + 1] = array[i];
	}
	delete[] array;
	array = aux;
	++tamanio;
}

int main(int argc, char *argv[]) {
	int tamanio = 3, valor;
	int* array = new int[tamanio]{1,2,3};
	cout << "Arreglo original: " << endl;
	mostrararreglo(array, tamanio);
	cout << "Ingrese un numero para agregar al principio: " << endl << ">";
	cin >> valor;
	agregaralinicio(array, tamanio, valor);
	cout << "Con valor agregado: " << endl;
	mostrararreglo(array, tamanio);
	
	return 0;
}

