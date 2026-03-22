#include <iostream>
#include <stdlib.h>
using namespace std;

void mostrararreglo(int* array, int tamanio){
	for (int i = 0; i < tamanio; i++){
		cout << array[i] << " ";
	}
	cout << endl;
}
	
void duplicararray(int*& array,int& tamanio){
	int nuevotamanio = tamanio * 2;
	int* aux = new int[nuevotamanio];
	//HASTA LA PRIMER MITAD
	for (int i = 0; i < tamanio; i++){
		aux[i] = array[i];
	}
	//SEGUNDA MITAD
	/* i = 5, array[5 - 5] = array[0] => aux[5] = 1
	i = 6, array[6 - 5] = array[1] => aux[6] = 2
	i = 7, array[7 - 5] = array[2] => aux[7] = 3
	i = 8, array[8 - 5] = array[3] => aux[8] = 4
	i = 9, array[9 - 5] = array[4] => aux[9] = 5*/
	for (int i = tamanio; i < nuevotamanio; i++){
		aux[i] = array[i - tamanio];
	}
	delete[] array;
	array = aux;
	tamanio = nuevotamanio;
}

int main(int argc, char *argv[]) {
	int tamanio = 5;
	int* array = new int[tamanio] {1,2,3,4,5};
	cout << "ARRAY CON VALORES ORIGINALES: " << endl;
	mostrararreglo(array, tamanio);
	duplicararray(array,tamanio);
	cout << "ARRAY DUPLICADO :" << endl;
	mostrararreglo(array, tamanio);
	delete[] array;
	return 0;
}

