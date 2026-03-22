#include <iostream>
#include <fstream>
using namespace std;

// RAMIREZ - HERNANDEZ - GERVASONI
// ACTIVIDAD 1: Escriba un programa que indique cuántas líneas tiene un archivo de texto.

int main(int argc, char *argv[]) {
	int cont_lineas = 0;
	string num;
	ifstream archivo;
	archivo.open("archivo_ejer1.txt");
	if (archivo.fail()){
		cout << "ERROR AL ENCONTRAR/ABRIR EL ARCHIVO" << endl;
		return -1;
	} else {
		while (getline(archivo,num)){
			cont_lineas++;
		}
	}
	archivo.close();
	cout << "La cantidad de lineas son: " << cont_lineas;
	return 0;
}

