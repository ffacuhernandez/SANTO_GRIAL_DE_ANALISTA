#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char *argv[]) {
	int matriz[100][5], cod, N;
	cout << "Ingrese la cantidad de competidores: " << endl << ">";
	cin >> N;
	for (int i = 0; i < N; i++){
		cout << "Ingrese el numero de competidor: " << endl << ">";
		cin >> matriz[i][0];
		cout << "Ingrese el codigo de deporte (1= natación, 2=carrera, 3=bicicleta): " << endl << ">";
		cin >> cod;
		if (cod == 1){
			cout << "Ingrese el tiempo en natacion(en minutos): " << endl << ">";
			cin >> matriz[i][1];
			cout << "Ingrese el codigo de deporte 2 o 3: " << endl << ">";
			cin >> cod;
			if (cod == 2){
				cout << "Ingrese tiempo en carrera: " << endl << ">";
				cin >> matriz[i][2];
				cout << "Ingrese el tiempo en bicicleta: " << endl << ">";
				cin >> matriz[i][3];
				cod = 0;
			} else if (cod == 3){
				cout << "Ingrese el tiempo en bicicleta: " << endl << ">";
				cin >> matriz[i][3];
				cout << "Ingrese tiempo en carrera: " << endl << ">";
				cin >> matriz[i][2];
				cod = 0;
			}
		}
		if (cod == 2){
			cout << "Ingrese tiempo en carrera: " << endl << ">";
			cin >> matriz[i][2];
			cout << "Ingrese el codigo de deporte 1 o 3: " << endl << ">";
			cin >> cod;
			if (cod == 1){
				cout << "Ingrese el tiempo en natacion(en minutos): " << endl << ">";
				cin >> matriz[i][1];
				cout << "Ingrese el tiempo en bicicleta: " << endl << ">";
				cin >> matriz[i][3];
				cod = 0;
			} else if (cod == 3){
				cout << "Ingrese el tiempo en bicicleta: " << endl << ">";
				cin >> matriz[i][3];
				cout << "Ingrese el tiempo en natacion(en minutos): " << endl << ">";
				cin >> matriz[i][1];
				cod = 0;
			}
		}
		if (cod == 3){
			cout << "Ingrese el tiempo en bicicleta: " << endl << ">";
			cin >> matriz[i][3];
			cout << "Ingrese el codigo de deporte 1 o 2: " << endl << ">";
			cin >> cod;
			if (cod == 2){
				cout << "Ingrese tiempo en carrera: " << endl << ">";
				cin >> matriz[i][2];
				cout << "Ingrese el tiempo en natacion(en minutos): " << endl << ">";
				cin >> matriz[i][1];
				cod = 0;
			} else if (cod == 1){
				cout << "Ingrese el tiempo en natacion(en minutos): " << endl << ">";
				cin >> matriz[i][1];
				cout << "Ingrese tiempo en carrera: " << endl << ">";
				cin >> matriz[i][2];
				cod = 0;
			}
		} 
	}
	ofstream natacion;
	ofstream carrera;
	ofstream bicicleta;
	natacion.open("NATACION.TXT");
	for (int i = 0; i < N; i++){
		natacion << matriz[i][0] << " " << matriz[i][1] << endl;
	}
	natacion.close();
	carrera.open("CARRERA.TXT");
	for (int i = 0; i < N; i++){
		carrera<< matriz[i][0] << " " << matriz[i][2] << endl;
	}
	carrera.close();
	bicicleta.open("BICICLETA.TXT");
	for (int i = 0; i < N; i++){
		bicicleta << matriz[i][0] << " " << matriz[i][3] << endl;
	}
	bicicleta.close();
	return 0;
}

