#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main(int argc, char *argv[]) {
	ifstream archivo;
	int cod, multas, totalmultas = 0;
	int vectcodemultas[24][2] = {0};
	string vectprovincias[24];
	int codigos;
	string provincias;
	archivo.open("PROVINCIA.TXT");
	if (archivo.fail()){
		cout << "ERROR AL ABRIR EL ARCHIVO";
		return 1;
	} else {
		for (int i = 0; i<24; i++){
			archivo >> codigos;
			getline(archivo, provincias);
			vectcodemultas[i][0] = codigos;
			vectprovincias[i] = provincias;
		}
	}
	archivo.close();
	cout << "Ingrese el codigo de provincia (99 para salir)" << endl << ">";
	cin >> cod;
	while (cod != 99){
		int bandera = 0, pos, i = 0;
		while (i<24){
			if (cod == vectcodemultas[i][0]){
				bandera = 1;
				pos = i;
				i = 24;
			}
			i++;
		}
		if (bandera == 0){
			cout << "El codigo de provincia no fue encontrado" << endl;
		} else {
			cout << "Ingrese la cantidad de multas: " << endl << ">";
			cin >> multas;
			totalmultas += multas;
			vectcodemultas[pos][1] += multas;
		}
		cout << "Ingrese el codigo de provincia (99 para salir)" << endl << ">";
		cin >> cod;
	}
	cout << "NOMBRE DE LA PROVINCIA" << setw(35) << "CANTIDAD DE MULTAS" << endl;
	for (int i = 0; i<24; i++){
		cout << vectprovincias[i] << setw(40) << vectcodemultas[i][1] << endl;
	}
	cout << "TOTAL DE MULTAS: " << totalmultas;
	return 0;
}

