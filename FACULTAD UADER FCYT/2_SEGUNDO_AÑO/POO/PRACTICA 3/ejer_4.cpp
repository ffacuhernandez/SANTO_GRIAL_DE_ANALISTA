#include <iostream>
#include <stdlib.h>
using namespace std;

void mostrararreglo(int* array, int tamanio){
	for (int i = 0; i < tamanio; i++){
		cout << array[i] << " ";
	}
	cout << endl;
}
	
void quitarposicion(int*& array, int& tamanio, int posicion){
	if (posicion < 0 || posicion >= tamanio){
		cout << "POSICION INVALIDA" << endl;
		return;
	}
	
	int* aux = new int[tamanio - 1];
	
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
	int tamanio = 3, posicion;
	int* array = new int[tamanio]{1,2,3};
	cout << "ARRAY CON VALORES ORIGINALES: " << endl;
	mostrararreglo(array, tamanio);
	cout << "INGRESE POSICION A ELIMINAR DEL ARRAY (0 a " << tamanio - 1 << "):" << endl << ">";
	cin >> posicion;
	quitarposicion(array, tamanio, posicion);
	cout << "ARRAY DESPUES DE SACAR VALOR: " << endl;
	mostrararreglo(array, tamanio);
	return 0;
}

