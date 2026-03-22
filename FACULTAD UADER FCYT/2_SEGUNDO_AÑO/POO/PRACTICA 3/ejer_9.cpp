#include <iostream>
using namespace std;

// Función para mostrar una matriz
void mostrarMatriz(int** matriz, int filas, int columnas) {
	for (int i = 0; i < filas; i++) {
		for (int j = 0; j < columnas; j++) {
			cout << matriz[i][j] << " ";
		}
		cout << endl;
	}
}

// Función para contar las repeticiones y crear la matriz
int** generarMatriz(int* array, int tamanio, int& filas) {
	// Encontrar el número de elementos únicos
	int* unico = new int[tamanio];
	int* conteo = new int[tamanio];
	int numUnicos = 0;
	
	// Inicializar conteos
	for (int i = 0; i < tamanio; i++) {
		conteo[i] = 0;
	}
	
	// Contar las repeticiones
	for (int i = 0; i < tamanio; i++) {
		bool encontrado = false;
		for (int j = 0; j < numUnicos; j++) {
			if (unico[j] == array[i]) {
				conteo[j]++;
				encontrado = true;
				break;
			}
		}
		if (!encontrado) {
			unico[numUnicos] = array[i];
			conteo[numUnicos] = 1;
			numUnicos++;
		}
	}
	
	// Crear la matriz con 2 columnas
	int** matriz = new int*[numUnicos];
	for (int i = 0; i < numUnicos; i++) {
		matriz[i] = new int[2];
	}
	
	// Llenar la matriz con los datos
	for (int i = 0; i < numUnicos; i++) {
		matriz[i][0] = unico[i];
		matriz[i][1] = conteo[i];
	}
	
	// Actualizar el número de filas
	filas = numUnicos;
	
	// Liberar memoria auxiliar
	delete[] unico;
	delete[] conteo;
	
	return matriz;
}

int main() {
	int tamanio = 10;
	int array[] = {1, 2, 2, 3, 3, 3, 4, 4, 4, 4};
	
	// Mostrar el vector original
	cout << "VECTOR CON VALORES: " << endl;
	for (int i = 0; i < tamanio; i++) {
		cout << array[i] << " ";
	}
	cout << endl;
	
	// Generar la matriz y obtener el número de filas
	int filas;
	int** matriz = generarMatriz(array, tamanio, filas);
	
	// Mostrar la matriz
	cout << "MATRIZ CON NuMERO Y REPETICIONES: " << endl;
	mostrarMatriz(matriz, filas, 2);
	
	// Liberar la memoria de la matriz
	for (int i = 0; i < filas; i++) {
		delete[] matriz[i];
	}
	delete[] matriz;
	
	return 0;
}
