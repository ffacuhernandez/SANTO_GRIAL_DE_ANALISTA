#include <iostream>
#include <fstream>
using namespace std;

// RAMIREZ - HERNANDEZ - GERVASONI
/* ACTIVAD 6: Dado un archivo de texto, con el formato:
palabra: definición
Realice una función que dada una palabra retorne la definición.*/

struct diccionario{
	string palabra;
	string definicion;
};

string buscador(string palabra, diccionario datos[], int contador){
	for (int i = 0; i < contador; i++){
		if (palabra == datos[i].palabra){
			return datos[i].definicion;
		}
	}
	return "LA PALABRA INGRESADA NO SE ENCUENTRA EN EL DICCIONARIO";
}

int main(int argc, char *argv[]) {
	
	diccionario datos[500];
	string palabra, definicion, busqueda;
	int contador = 0;
	
	ifstream archivo;
	archivo.open("archivo_ejer6.txt");
	if (archivo.fail()) {
		cout << "ERROR AL ENCONTRAR/ABRIR EL ARCHIVO" << endl;
		return -1;
	} else {
		while (getline(archivo, datos[contador].palabra, ':')){
			archivo.ignore();
			getline(archivo, datos[contador].definicion);
			contador++;
		}
	}
	cout << "---------------- DICCIONARIO DE POCAS PALABRAS ----------------" << endl;
	cout << "Ingrese la palabra la cual quiera saber su definicion (para salir escribir EXIT) " << endl << ">";
	getline(cin,busqueda);
	while (busqueda != "EXIT"){
		string resultado = buscador(busqueda, datos, contador);
		cout << resultado << endl;
		cout << "***********************************" << endl;
		cout << "Ingrese la palabra la cual quiera saber su definicion (para salir escribir EXIT) " << endl << ">";
		getline(cin,busqueda);
	}
	
	return 0;
}

