#include <iostream>
#include <string>
using namespace std;

int main(int argc, char *argv[]) {
	const int N = 5;
	string codigoasociado[N][4];
	int cuota, costoservicio[11], busqueda;
	for (int i = 0; i<N; i++){
		cout << "Ingrese codigo de asociado: " << endl << ">";
		getline(cin,codigoasociado[i][0]);
		cout << "Ingrese apellido y nombre: " << endl << ">";
		getline(cin,codigoasociado[i][1]);
		cout << "Ingree codigo de plan (PS200: Plan Senior o PJ500: Plan Juvenil):" << endl << ">";
		getline(cin,codigoasociado[i][2]);
	}
	cout << "Ingrese importe de la cuota societaria" << endl << ">";
	cin >> cuota;
	for (int i = 0; i<N; i++){
		if (codigoasociado[i][2] == "PJ500"){
			codigoasociado[i][2] = codigoasociado[i][2] * 0.75;
		}
	}
	for (int i = 0; i<11; i++){
		cout << "Ingrese costo del servicio numero " << i+1 << ":" << endl << ">";
		cin >> costoservicio[i];
	}
	cout << "Ingrese codigo de asociado" << endl << ">";
	cin >> busqueda;
	return 0;
}

