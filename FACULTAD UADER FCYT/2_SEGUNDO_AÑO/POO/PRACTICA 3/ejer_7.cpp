#include <iostream>
#include <stdlib.h>
using namespace std;

void mostrararreglo(int* array, int tamanio){
	for (int i = 0; i < tamanio; i++){
		cout << array[i] << " ";
	}
	cout << endl;
}

void quitarelementos(int*& array, int& tamanio, int cantidad){
	if (cantidad <= 0 || cantidad > tamanio) {
		cout << "Cantidad inválida o mayor que el tamaño del arreglo." << endl;
		return;
	}
	int nuevotamanio = tamanio - cantidad;
	int* aux = new int[nuevotamanio];
	for (int i = 0; i < nuevotamanio; i++){
		aux[i] = array[i];
	}
	delete[] array;
	array = aux;
	tamanio = nuevotamanio;
}

int main(int argc, char *argv[]) {
	int tamanio = 5, cantidad;
	int* array = new int[tamanio] {1,2,3,4,5};
	cout << "ARRAY CON VALORES ORIGINALES: " << endl;
	mostrararreglo(array, tamanio);
	cout << "Ingrese la cantidad a eliminar: " << endl << ">";
	cin >> cantidad;
	quitarelementos(array, tamanio, cantidad);
	cout << "Nuevo array: " << endl;
	mostrararreglo(array, tamanio);
	return 0;
}

