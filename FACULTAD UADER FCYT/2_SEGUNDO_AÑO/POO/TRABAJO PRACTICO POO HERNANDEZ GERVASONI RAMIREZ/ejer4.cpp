#include <iostream>
#include <fstream>
using namespace std;

// RAMIREZ - HERNANDEZ - GERVASONI
/* ACTIVAD 4:  Escriba un programa que reemplace un carácter ingresado por el usuario por otro carácter
también ingresado por el usuario en un archivo de texto, indique en cuantas líneas lo
reemplazó.*/

void reemplazar(string &cadena, char caracter1, char caracter2, int &contador) {
	int pos = cadena.find(caracter1, 0);
	if (pos != -1){
		contador++;
	}
	while (pos != -1){
		cadena[pos] = caracter2;
		pos = cadena.find(caracter1, pos + 1);
	}
}

int main() {
	char caracter1, caracter2;
	cout << "Ingrese caracter a reemplazar del archivo: " << endl << ">";
	cin >> caracter1;
	cout << "Ahora, ingrese el caracter que desea reemplazar por " << caracter1 << ":" << endl << ">";
	cin >> caracter2;
	
	ifstream archivo("archivo_ejer4.txt"); 
	ofstream archivo_borrador("archivo_ejer4_borrador.txt"); 
	
	if (archivo.fail() || archivo_borrador.fail()) {
		cout << "ERROR AL ENCONTRAR/ABRIR EL ARCHIVO" << endl;
		return -1;
	} else {
		string linea;
		int cont_lineas = 0;
		while (getline(archivo, linea)) {
			reemplazar(linea, caracter1, caracter2, cont_lineas);
			archivo_borrador << linea << endl; 
		}
		archivo.close();
		archivo_borrador.close();
		
		remove("archivo_ejer4.txt"); 
		rename("archivo_ejer4_borrador.txt", "archivo_ejer4.txt"); 
		cout << "Se reemplazó el caracter en " << cont_lineas << " líneas." << endl;
	}
	return 0;
}
