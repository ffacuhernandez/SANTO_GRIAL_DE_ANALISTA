#include <iostream>
using namespace std;

///Realice un método que retorne el promedio de un vector de 10 enteros 

float promedio_vector(int vector[], int n){
	if (n == 0){
		return 0;
	} else {
		return vector[n - 1] + promedio_vector(vector, n - 1);
	}
}

int main(int argc, char *argv[]) {
	int vector[10], tamanio = 10;
	for (int i = 0; i < tamanio; i++){
		cout << "Ingrese el numero de la pos " << i + 1 << endl << ">";
		cin >> vector[i];
	}
	float prom = promedio_vector(vector, tamanio) / tamanio;
	cout << "EL PROMEDIO DEL VECTOR ES: " << prom << endl;
	return 0;
}

