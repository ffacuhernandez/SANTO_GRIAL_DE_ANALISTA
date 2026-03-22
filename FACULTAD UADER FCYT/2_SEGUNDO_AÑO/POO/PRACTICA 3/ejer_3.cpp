#include <iostream>
using namespace std;

// Función para mostrar un arreglo dinámico
void mostrararreglo(int* array, int tamanio){
	for (int i = 0; i < tamanio; i++){
		cout << array[i] << " ";
	}
	cout << endl;
}
	
	// Función para agregar un nuevo valor en una posición específica
	void agregarEnPosicion(int*& array, int& tamanio, int valor, int posicion){
		// Verificar si la posición es válida
		if (posicion < 0 || posicion > tamanio) {
			cout << "Posición inválida" << endl;
			return;
		}
		
		// Crear un nuevo arreglo con un tamaño mayor
		int* aux = new int[tamanio + 1];
		
		// Copiar los elementos del arreglo original antes de la posición
		for (int i = 0; i < posicion; i++) {
			aux[i] = array[i];
		}
		
		// Insertar el nuevo valor en la posición especificada
		aux[posicion] = valor;
		
		// Copiar los elementos del arreglo original después de la posición
		for (int i = posicion; i < tamanio; i++) {
			aux[i + 1] = array[i];
		}
		
		// Liberar la memoria del arreglo original
		delete[] array;
		
		// Actualizar el puntero del arreglo
		array = aux;
		
		// Incrementar el tamaño del arreglo
		++tamanio;
	}
		
		int main() {
			int tamanio = 3, valor, posicion;
			
			// Crear el arreglo dinámico
			int* array = new int[tamanio]{1, 2, 3};
			
			// Mostrar el arreglo original
			cout << "Arreglo original: " << endl;
			mostrararreglo(array, tamanio);
			
			// Solicitar al usuario el valor y la posición para agregar
			cout << "Ingrese un numero para agregar: " << endl << ">";
			cin >> valor;
			cout << "Ingrese la posición para agregar el número (0 a " << tamanio << "): " << endl << ">";
			cin >> posicion;
			
			// Agregar el valor en la posición especificada
			agregarEnPosicion(array, tamanio, valor, posicion);
			
			// Mostrar el arreglo con el nuevo valor agregado
			cout << "Con valor agregado: " << endl;
			mostrararreglo(array, tamanio);
			
			// Liberar la memoria al final
			delete[] array;
			
			return 0;
		}
		
