#include <iostream>
using namespace std;
/*Ingresar 5 números enteros por teclado. Luego, generar un nuevo arreglo, donde sus elementos 
sean los del arreglo anterior, pero multiplicados por 3. Mostrar por pantalla el segundo arreglo. */
int main(int argc, char *argv[]) {
	int arreglo1[5];
	int arreglo2[5];
	cout << "Ingrese 5 numeros enteros: " << endl;
	for (int i = 0;i < 5; i++){
		cin >> arreglo1[i];
	}
	cout << "Primer arreglo con sus valores multiplicado por 3: " << endl;
	for (int i = 0; i < 5; i++){
		arreglo2[i] = arreglo1[i] * 3;
		  cout << arreglo2[i] << endl;
	}
	return 0;
}

