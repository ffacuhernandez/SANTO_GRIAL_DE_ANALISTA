#include <iostream>
using namespace std;

/// Realice una función que, dado 2 vectores de enteros, los concatene. Utilice recursividad.

void concatenador(int* vector1, int n1, int* vector2, int n2, int* vector_final, int &indice) {
	if (n1 == 0) {
		if (n2 == 0){
			return;
		}  
		vector_final[indice] = *vector2;  
		indice++;  
		concatenador(vector1, n1, vector2 + 1, n2 - 1, vector_final, indice);  
	} else {
		vector_final[indice] = *vector1;  
		indice++;  
		concatenador(vector1 + 1, n1 - 1, vector2, n2, vector_final, indice); 
	}
}

int main(int argc, char *argv[]) {
	int tamanio1 = 5, tamanio2 = 10, total = tamanio1 + tamanio2;
	int vector1[5], vector2[10], vector_final[15];
	int indice = 0;
	

	for (int i = 0; i < tamanio1; i++) {
		cout << "Ingrese el valor numero " << i + 1 << " para el primer array: " << endl << ">";
		cin >> vector1[i];
	}
	

	for (int i = 0; i < tamanio2; i++) {
		cout << "Ingrese el valor numero " << i + 1 << " para el segundo array: " << endl << ">";
		cin >> vector2[i];
	}
	

	concatenador(vector1, tamanio1, vector2, tamanio2, vector_final, indice);
	

	cout << "ARRAY CONCATENADO: " << endl;
	for (int i = 0; i < total; i++) {
		cout << vector_final[i] << " ";
	}
	
	return 0;
}
