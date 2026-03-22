#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

int main() {
	int N; // Tamaño de la matriz
	cout << "Ingrese el tamaño de la matriz cuadrada: ";
	cin >> N;
	
	// Declarar matrices
	vector<vector<int>> matriz(N, vector<int>(N, 0)); // Matriz principal
	vector<vector<int>> contador(N, vector<int>(N, 0)); // Matriz de contador
	srand(time(0)); // Inicializar la semilla para números aleatorios
	
	int elementosGenerados = 0;
	while (elementosGenerados < N * N) {
		int fila = rand() % N;
		int columna = rand() % N;
		
		// Verifica si la celda ya ha sido asignada
		if (matriz[fila][columna] == 0) {
			int valor = rand() % 100; // Genera un número aleatorio entre 0 y 99
			matriz[fila][columna] = valor;
			contador[fila][columna]++;
			elementosGenerados++;
		}
	}
	// Mostrar la matriz principal
	cout << "Matriz Principal:" << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << matriz[i][j] << "\t";
		}
		cout << endl;
	}
	// Mostrar la matriz de contador
	cout << "Matriz de Contador:" << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << contador[i][j] << "\t";
		}
		cout << endl;
	}
	
	return 0;
}
