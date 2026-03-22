#include <iostream>
using namespace std;

void mostrararreglo(int* array, int tamanio){
	for (int i = 0; i < tamanio; i++){
		cout << array[i] << " ";
	}
	cout << endl;
}
	
void quitarvalor(int*& array, int& tamanio, int valor){
	int posicion = -1;
	for (int i = 0; i < tamanio; i++){
		if (valor == array[i]){
			posicion = i;
		}
	}
	if (posicion == -1) {
		cout << "El valor no se encontró en el arreglo." << endl;
		return;
	}
	int* aux = new int [tamanio - 1];
	//ANTES DE LA POS
	for (int i = 0; i < posicion; i++){
		aux[i] = array[i];
	}
	//DESPUES DE LA POS 
	for (int i = posicion + 1; i < tamanio; i++){
		aux[i - 1] = array[i];
	}
	delete[] array;
	array = aux;
	--tamanio;
}

int main(int argc, char *argv[]) {
	int tamanio = 3, valor;
	int* array = new int[tamanio] {1,2,3};
	cout << "ARRAY CON VALORES ORIGINALES: " << endl;
	mostrararreglo(array, tamanio);
	cout << "Ingrese el valor que coincida: " << endl << ">";
	cin >> valor;
	quitarvalor(array, tamanio, valor);
	cout << "ARRAY SIN EL VALOR QUE COINCIDIO: " << endl;
	mostrararreglo(array, tamanio);
	delete[] array;
	return 0;
}

