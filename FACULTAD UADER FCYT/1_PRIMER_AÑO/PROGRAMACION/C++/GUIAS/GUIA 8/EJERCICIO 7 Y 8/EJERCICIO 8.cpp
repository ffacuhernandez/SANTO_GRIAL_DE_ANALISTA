#include <iostream>
#include <fstream>
using namespace std;

int main() {
	ifstream archivo("MATRIZ.TXT");
	int N, M, sumatotal = 0;
	
	if (archivo.fail()) {
		cout << "No se pudo abrir el archivo MATRIZ.TXT" << endl;
		return 1;
	} else
	archivo >> N >> M;
	int matriz[100][100];
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			archivo >> matriz[i][j];
		}
	}
	
	// Mostrar la matriz
	cout << "Matriz de " << N << " filas x " << M << " columnas:" << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << matriz[i][j] << " ";
		}
		cout << endl;
	}
	
	// Leer el valor de suma total
	int sumaLeida;
	archivo >> sumaLeida;
	
	// Calcular la suma de los elementos en la matriz
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			sumatotal += matriz[i][j];
		}
	}
	
	// Verificar si la suma coincide con la suma leída
	if (sumatotal == sumaLeida) {
		cout << "La suma de los elementos coincide con el último dato leído: " << sumaLeida << endl;
	} else {
		cout << "La suma de los elementos NO coincide con el último dato leído." << endl;
	}
	
	archivo.close();
	return 0;
}
