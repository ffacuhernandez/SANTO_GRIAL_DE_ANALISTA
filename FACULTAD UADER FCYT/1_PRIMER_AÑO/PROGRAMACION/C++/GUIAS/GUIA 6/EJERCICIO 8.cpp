#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	int n, matriz [100][5] = {0}, aux = 0, max = 99999, masrendimiento;
	cout << "Ingrese la cantidad de productores: " << endl << ">";
	cin >> n;
	for (int i = 0; i < n; i++){
		cout << "Ingrese codigo de productor: " << endl << ">";
		cin >> matriz[i][0];
		cout << "Ingrese la cantidad de hectareas sembradas en un año: " << endl << ">";
		cin >> matriz[i][1];
		cout << "Ingrese la cantidad de toneladas cosechadas en un año: " << endl << ">";
		cin >> matriz[i][2];
		matriz[i][3] = (matriz[i][2] / matriz[i][1]);
		if (matriz[i][3] > max){
			max = matriz[i][3];
			masrendimiento = matriz[i][0];
		}
	}
	
	for (int i = 0; i<(n-1); i++){
		for (int j = i+1; j < n; j++){
			if (matriz[i][1] > matriz[j][1]){
				for (int k = 0; k<4; k++){
					aux = matriz[i][k];
					matriz[i][k] = matriz[j][k];
					matriz[j][k] = aux;
				}
			}
		}
	}
	cout << " ORDENADOS POR CANTIDAD DE HECTAREAS DE MAYOR A MENOR: " << endl;
	cout << " CODIGO: " << "     " << "HECTAREAS: " << endl;
	for (int i = n-1; i > -1 ;i--){
		cout <<"     " << matriz[i][0] <<"            "<< matriz[i][1] << endl;
	}
	cout << endl;
	cout << "RENDIMIENTO PROMEDIO DE CADA PRODUCTOR: " << endl;
	cout << " CODIGO: " << "     " << "PROMEDIO " << endl;
	for (int i = 0; i < n; i++){
		cout << "   " << matriz[i][0] << "              " << matriz[i][3] << endl;
	}
	cout << "EL PRODUCTOR CON CODIGO " << masrendimiento << " ES EL QUE OBTUVO MAYOR RENDIMIENTO POR HECTAREA";
	return 0;
}

