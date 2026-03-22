#include <iostream>

using namespace std;

int main() {
	int matriz[3][3];
	
	// Leer la matriz de 3x3
	cout << "Ingrese los valores de la matriz de 3x3:" << endl;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << "Ingrese el valor para la fila " << i + 1 << " y columna " << j + 1 << ": ";
			cin >> matriz[i][j];
		}
	}
	
	// Pedir al usuario el número de la fila a mostrar
	int fila;
	cout << "Ingrese el número de la fila que desea mostrar (1, 2 o 3): ";
	cin >> fila;
	
	// Verificar que el número de fila sea válido
	if (fila >= 1 && fila <= 3) {
		cout << "Valores de la fila " << fila << ":" << endl;
		for (int j = 0; j < 3; j++) {
			cout << matriz[fila - 1][j] << " ";
		}
		cout << endl;
	} else {
		cout << "Número de fila no válido. Debe ser 1, 2 o 3." << endl;
	}
	
	return 0;
}

