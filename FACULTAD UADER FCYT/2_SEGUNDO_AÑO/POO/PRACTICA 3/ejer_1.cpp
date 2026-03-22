#include <iostream>

using namespace std;

// Función para imprimir un arreglo dinámico
void imprimirArreglo(int* arr, int tamaño) {
	for (int i = 0; i < tamaño; ++i) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

// Función para agregar un nuevo valor en la última posición
void agregarAlFinal(int*& arr, int& tamaño, int valor) {
	// Crear un nuevo arreglo con un tamaño mayor
	int* nuevoArr = new int[tamaño + 1];
	
	// Copiar los elementos del arreglo original al nuevo arreglo
	for (int i = 0; i < tamaño; ++i) {
		nuevoArr[i] = arr[i];
	}
	
	// Agregar el nuevo valor al final
	nuevoArr[tamaño] = valor;
	
	// Liberar la memoria del arreglo original
	delete[] arr;
	
	// Asignar el puntero al nuevo arreglo
	arr = nuevoArr;
	
	// Incrementar el tamaño del arreglo
	++tamaño;
}

int main() {
	int tamaño = 3;
	int* arr = new int[tamaño]{1, 2, 3};
	
	cout << "Arreglo original: ";
	imprimirArreglo(arr, tamaño);
	
	agregarAlFinal(arr, tamaño, 4);
	
	cout << "Arreglo después de agregar 4: ";
	imprimirArreglo(arr, tamaño);
	
	// Liberar la memoria al final
	delete[] arr;
	
	return 0;
}
