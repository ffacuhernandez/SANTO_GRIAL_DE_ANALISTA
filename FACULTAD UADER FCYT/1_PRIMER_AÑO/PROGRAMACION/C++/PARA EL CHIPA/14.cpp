#include <iostream>
#include <fstream>
using namespace std;

struct alumnos{
	int documento, p1, p2;
	string ayn;
};

void ordenador(alumnos datos[], int contador);

int main(int argc, char *argv[]) {
	int doc, cont_alum = 0;
	alumnos datos[999];
	cout << "Ingrese numero de documento: " << endl << ">";
	cin >> doc;
	while (doc != 0){
		cin.ignore();
		datos[cont_alum].documento = doc;
		cout << "Ingrese apellido y nombre: " << endl << ">";
		getline(cin, datos[cont_alum].ayn);
		cout << "Ingrese nota del primer parcial: " << endl << ">";
		cin >> datos[cont_alum].p1;
		cout << "Ingrese nota del segundo parcial: " << endl << ">";
		cin >> datos[cont_alum].p2;
		cout << "Ingrese numero de documento: " << endl << ">";
		cin >> doc;
		cont_alum++;
	}
	ordenador(datos, cont_alum);
	ofstream archivo;
	archivo.open("FUPRO_2.txt");
	for (int i = 0; i < cont_alum; i++){
		archivo << datos[i].documento << " " << datos[i].ayn << endl;
		archivo << datos[i].p1 << " " << datos[i].p2 << endl;
	}
	archivo.close();
	return 0;
}

void ordenador (alumnos datos[], int contador){
	for (int i = 0; i < contador - 1; i++){
		for (int j = i + 1; j < contador; j++){
			if (datos[i].documento > datos[j].documento){
				alumnos aux = datos[i];
				datos[i] = datos[j];
				datos[j] = aux;
			}
		}
	}
}
