#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc, char *argv[]) {
	const int N = 3;
	int matriz[N][6] = {0}, busqueda, bandera, aux, promtotal, min = 9999, max = 0;
	string ayn[N], aux2;
	for (int i = 0; i < N; i++){
		cout << "Ingrese el DNI: " << endl;
		cin >> matriz[i][0];
		cin.get();
		cout << "Ingrese apellido y nombre: " << endl;
		getline(cin,ayn[i]);
		cout << "Ingrese telefono: " << endl;
		cin >> matriz[i][1];
	}
	cout << "Ingrese DNI del postulante que desea cargarle datos: " << endl;
	cin >> busqueda;
	while (busqueda != 0){
		int i = 0, pos;
		while(i<N){
			if(busqueda == matriz[i][0]){
				pos = i;
				bandera = 1;
				i = N;
			}
			i++;
		}
		if (bandera == 0){
			cout << "DNI NO ENCONTRADO" << endl;
		}else {
				cout << "Ingrese puntaje de la prueba 1: " << endl;
				cin >> matriz[pos][2];
				cout << "Ingrese puntaje de la prueba 2: " << endl;
				cin >> matriz[pos][3];
				cout << "Ingrese puntaje de la prueba 3: " << endl;
				cin >> matriz[pos][4];
				cout << "Ingrese puntaje de la prueba 4: " << endl;
				cin >> matriz[pos][5];
				matriz[pos][6] = ((matriz[pos][2] * 2) + (matriz[pos][2] * 3) + (matriz[pos][4] * 4) + (matriz[pos][5] * 5));
				if (matriz[pos][6] < min){
					min = matriz[pos][6];
				}
				if (matriz[pos][6] > max){
					max = matriz[pos][6];
				}
				
				promtotal += matriz[pos][6];
			}
		cout << "Ingrese DNI del postulante que desea cargarle datos: " << endl;
		cin >> busqueda;
	}
	for (int i = 0; i<N-1; i++){
		for(int j = i+1; j<N; j++){
			if (matriz[i][6] > matriz[j][6]){
				aux = matriz[i][6];
				matriz[i][6] = matriz[j][6];
				matriz[j][6] = aux;
				aux = matriz[i][2];
				matriz[i][2] = matriz[j][2];
				matriz[j][2] = aux;
				aux = matriz[i][3];
				matriz[i][3] = matriz[j][3];
				matriz[j][3] = aux;
				aux = matriz[i][4];
				matriz[i][4] = matriz[j][4];
				matriz[j][4] = aux;
				aux = matriz[i][5];
				matriz[i][5] = matriz[j][5];
				matriz[j][5] = aux;
				aux = matriz[i][0];
				matriz[i][0] = matriz[j][0];
				matriz[j][0] = aux;
				aux2 = ayn[i];
				ayn[i] = ayn[j];
				ayn[j] = aux2;
				aux = matriz[i][1];
				matriz[i][1] = matriz[j][1];
				matriz[j][1] = aux;
			}
		}
	}
	cout << "DNI" << setw(15) <<  "AF" << setw(15) << "CA" << setw(15) << "CO" << setw(15) << "CI" << setw(18) << "PUNTAJE FINAL" << endl;
	for (int i = 0; i<N; i++){
		cout << matriz[i][0] << setw(15) << matriz[i][2] << setw(15) << matriz[i][3] << setw(15) << matriz[i][4] << setw(15) << matriz[i][5] << setw(15)<< matriz[i][6] << endl;
	}
	promtotal = promtotal/N;
	cout << endl;
	cout << "EL PROMEDIO DE TODO EL GRUPO ES: " << promtotal << " Y EL VALOR MINIMO FUE " << min << " Y EL VALOR MAXIMOS FUE " << max << endl;
	cout << endl;
	cout << endl;
	cout << "CORNETITAS QUE SUPERARON EL PROMEDIO TOTAL DE TODOS LOS PARTICIPANTES: " << endl;
	cout << "DNI" << setw(25) <<  "APELLIDO Y NOMBRE" << setw(15) << "TELEFONO" << setw(18) << "PUNTAJE FINAL" << endl;
	for (int i = 0; i<N; i++){
		if (matriz[i][6] > promtotal){
			cout << matriz[i][0] << setw(17) << ayn[i] << setw(22) << matriz[i][1] << setw(15) << matriz[i][6] << endl;
		}
	}
	return 0;
}

