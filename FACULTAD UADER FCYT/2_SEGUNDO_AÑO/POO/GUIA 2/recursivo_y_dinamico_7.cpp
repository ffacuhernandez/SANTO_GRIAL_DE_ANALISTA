#include <iostream>
#include <stdlib.h>
using namespace std;

/// Realice una función que dado un vector de enteros retorne verdadero si este es un palíndromo,
///	por ejemplo: [1,2,3,2,1]. Utilice recursividad.

void acortador_vector(int* &vector, int &contador){
	int* nuevo_vector = new int [contador];
	for (int i = 0; i < contador; i++){
		nuevo_vector[i] = vector[i];
	}
	delete[] vector;
	vector = nuevo_vector;
}

void crear_array(int* &vector, int &contador){
	int dato;
	cout << "INGRESE UN NUMERO (777 PARA TERMINAR)" << endl << ">";
	cin >> dato;
	while (dato != 777){
		vector[contador] = dato;
		contador++;
		cout << "INGRESE UN NUMERO (777 PARA TERMINAR)" << endl << ">";
		cin >> dato;
	}
	acortador_vector(vector, contador);
}

bool es_palindromo(int vector[], int inicio, int fin){
	if (inicio >= fin){
		return true;
	} else {
		if (vector[inicio] == vector[fin]){
			return es_palindromo(vector, inicio + 1, fin - 1);
		} else {
			return false;
		}
	}
}

int main(int argc, char *argv[]) {
	int tamanio_guaso = 999;
	int contador = 0;
	int* vector = new int [tamanio_guaso];
	crear_array(vector, contador);
	bool verificacion = es_palindromo(vector, 0, contador - 1);
	if (verificacion){
		cout << "EL VECTOR ES UN PALINDROMO" << endl;
	} else {
		cout << "EL VECTOR NO ES UN PALINDROMO" << endl;
	}
	delete[] vector;
	return 0;
}

