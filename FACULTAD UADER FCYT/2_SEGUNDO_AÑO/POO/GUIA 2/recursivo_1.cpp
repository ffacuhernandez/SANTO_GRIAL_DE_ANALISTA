#include <iostream>
using namespace std;

/// Realice un método que retorne el acumulado de un vector de 10 enteros. Utilice recursividad.

int acumulador_vector(int vector[], int n){
	if (n == 0){
		return 0;
	} else {
		return vector[n - 1] + acumulador_vector(vector, n - 1);
	}
}

int main(int argc, char *argv[]) {
	int tamanio = 10, vector[10];
	for (int i = 0; i < tamanio; i++){
		cout << "INGRESE EL ELEMENTO NUMERO " << i + 1 << endl << ">";
		cin >> vector[i];
	}
	int resultado = acumulador_vector(vector, tamanio);
	cout << "EL ACUMULADO DEL VECTOR ES " << resultado << endl;
	return 0;
}

