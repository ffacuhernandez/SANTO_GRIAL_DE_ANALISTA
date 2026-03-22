#include <iostream>
#include <iomanip>
using namespace std;
/*Generar una matriz de 10x10 elementos con números al azar. 
La matriz se debe llenar se acuerdo al  gráfico. Muestre la matriz generada.*/
int main(int argc, char *argv[]) {
	int matriz [10][10] = {0};
	
	for (int i = 0; i < 10; i++){
		int aleatorio = rand() % 100;
		matriz[i][0] = aleatorio;
	}
	cout << "PRIMERA COLUMNA: " << endl;
	for (int i = 0; i < 10; i++){
		for (int j = 0; j < 10; j++){
			cout << setw(7) <<matriz[i][j] << setw(7);
		}
		cout << endl;
	}
	for (int i = 1; i < 10; i++){
		int aleatorio = rand()% 100;
		matriz [9][i] = aleatorio;
	}
	cout << "TODA LA ULTIMA FILA: " << endl;
	for (int i = 0; i < 10; i++){
		for (int j = 0; j < 10; j++){
			cout << setw(7)<< matriz[i][j] << setw(7);
		}
		cout << endl;
	}
	for (int i = 8; i >= 0; i--){
		int aleatorio = rand() % 100;
		matriz [i][9] = aleatorio;
	}
	cout << "TODA LA ULTIMA COLUMNA: " << endl;
	for (int i = 0; i < 10; i++){
		for (int j = 0; j < 10; j++){
			cout << setw(7)<< matriz[i][j] << setw(7);
		}
		cout << endl;
	}
	for (int i = 8; i > 0; i--){
		int aleatorio = rand() % 100;
		matriz[0][i] = aleatorio;
	}
	cout << "PARA PRIMERA FILA: " << endl;
	for (int i = 0; i < 10; i++){
		for (int j = 0; j < 10; j++){
			cout << setw(7)<< matriz[i][j] << setw(7);
		}
		cout << endl;
	}
	for (int i = 1; i < 9; i++){
		int aleatorio = rand() % 100;
		matriz [i][1] = aleatorio;
	}
	cout << "PARA SEGUNDA COLUMNA: " << endl;
	for (int i = 0; i < 10; i++){
		for (int j = 0; j < 10; j++){
			cout << setw(7)<< matriz[i][j] << setw(7);
		}
		cout << endl;
	}
	return 0;
}
