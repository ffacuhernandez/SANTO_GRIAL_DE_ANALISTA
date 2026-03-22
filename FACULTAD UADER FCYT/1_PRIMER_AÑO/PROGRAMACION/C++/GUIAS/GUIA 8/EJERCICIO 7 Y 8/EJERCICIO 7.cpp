#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char *argv[]) {
	int N, M, sumatotal = 0;
	cout << "Ingrese el numero de filas que va a tener la matriz: " << endl << ">";
	cin >> N;
	cout << "Ingrese el numero de columnas que va a tener la matriz: " << endl << ">";
	cin >> M;
	int matriz[100][100] = {0};
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			matriz[i][j] = rand() % 1000;
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			sumatotal += matriz[i][j];
		}
	}
	ofstream archivo;
	archivo.open("MATRIZ.TXT");
	archivo << N << " " << M << endl;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			archivo << matriz[i][j] << " ";
		}
		archivo << endl;
	}
	archivo << sumatotal << endl;
	archivo.close();
	return 0;
}

