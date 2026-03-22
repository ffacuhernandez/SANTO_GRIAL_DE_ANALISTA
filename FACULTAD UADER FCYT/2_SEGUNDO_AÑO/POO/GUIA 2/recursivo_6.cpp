#include <iostream>
using namespace std;

/// Realice una función que dado un vector lo transforme de modo tal que el primer elemento sea el
///	último y el ultimo el primero, el segundo el antepenúltimo, etc. Utilice recursividad.

void transforma_vector(int vector[], int primero, int ultimo){
	if (primero >= ultimo){
		return; 
	} else {
		int temporal = vector[primero];
		vector[primero] = vector[ultimo];
		vector[ultimo] = temporal;
		transforma_vector(vector, primero + 1, ultimo - 1);
	}
}

int main(int argc, char *argv[]) {
	int vector[10], tamanio = 10;
	for (int i = 0; i < tamanio; i++){
		cout << "Ingrese el numero de la pos " << i + 1 << endl << ">";
		cin >> vector[i];
	}
	cout << "VECTOR ACTUAL: " << endl;
	for (int i = 0; i < tamanio; i++){
		cout << vector[i] << " ";
	}
	cout << endl;
	transforma_vector(vector, 0, tamanio - 1);
	cout << "DADO VUELTA: " << endl;
	for (int i = 0; i < tamanio; i++){
		cout << vector[i] << " ";
	}
	return 0;
}

