#include <iostream>
#include <stdlib.h>
using namespace std;

/// Realice una función que dado un vector dinámico de enteros, agregue un nuevo valor pasado
///	por parámetro en una posición pasada por parámetros.

void valor_en_pos(int *&vector, int &tamanio){
	int posicion, valor;
	cout << "Ingrese la pos para agregar elemento: " << endl << ">";
	cin >> posicion;
	while (posicion < 1 || posicion > tamanio){
		cout << "POSICION INVALIDA INGRESA UNA VALIDA CORNETA: " << endl << ">";
		cin >> posicion;
	}
	posicion = posicion - 1;
	cout << "Ingrese el valor para agregar en la pos " << posicion + 1 << ": " << endl << ">";
	cin >> valor;
	
	int *aux= new int[tamanio + 1];
	for (int i = 0; i < posicion; i++){
		aux[i] = vector[i];
	}
	
	aux[posicion] = valor;
	
	for (int i = posicion; i < tamanio; i++){
		aux[i + 1] = vector[i];
	}
	
	delete[] vector;
	vector = aux;
	tamanio++;
}
int main(int argc, char *argv[]) {
	int tamanio = 3;
	int *vector = new int[tamanio]{1, 2, 3};
	cout << "VECTOR INICIAL: " << endl;
	for (int i = 0; i < tamanio; i++){
		cout << vector[i] << " ";
	}
	cout << endl;
	valor_en_pos(vector, tamanio);
	
	cout << "VECTOR FINAL: " << endl;
	for (int i = 0; i < tamanio; i++){
		cout << vector[i] << " ";
	}
	delete[] vector;
	return 0;
}

