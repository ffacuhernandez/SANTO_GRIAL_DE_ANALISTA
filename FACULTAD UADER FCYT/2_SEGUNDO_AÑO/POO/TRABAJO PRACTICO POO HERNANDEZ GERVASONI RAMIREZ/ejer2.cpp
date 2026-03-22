#include <iostream>
#include <fstream>
using namespace std;

// RAMIREZ - HERNANDEZ - GERVASONI
/* ACTIVIDAD 2: Escriba un programa que cuente cuántas veces está un carácter ingresado por el usuario
	en cada línea de un archivo de texto. */

int main(int argc, char *argv[]) {
	
	/// USUARIO INGRESA CARACTER A BUSCAR
	string linea;
	char caracter;
	cout << "Ingrese el caracter a buscar: " << endl << ">";
	cin >> caracter;
	
	/// BUSQUEDA DEL CARACTER EN CADA LINEA DEL ARCHIVO
	ifstream archivo;
	archivo.open("archivo_ejer2.txt");
	if (archivo.fail()){
		cout << "ERROR AL ENCONTRAR/ABRIR EL ARCHIVO" << endl;
		return -1;
	} else {
		int cont_lineas = 0;
		while (getline(archivo, linea)){
			int cont_caracter = 0;
			int pos = linea.find(caracter, 0);
			while (pos != -1){
				cont_caracter++;
				pos = linea.find(caracter, pos + 1);
			}
			cout << "En la linea " << ++cont_lineas << " aparece " << cont_caracter << " veces el caracter --> " << caracter << " <--" << endl;
		}
	}
	archivo.close();
	return 0;
}

