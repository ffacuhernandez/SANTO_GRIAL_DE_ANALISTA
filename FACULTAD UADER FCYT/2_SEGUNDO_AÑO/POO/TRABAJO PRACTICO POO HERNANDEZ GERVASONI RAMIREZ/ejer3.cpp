#include <iostream>
#include <fstream>
using namespace std;

// RAMIREZ - HERNANDEZ - GERVASONI
/* ACTIVAD 3:  Escriba un programa que modifique un archivo de texto de forma que cada oración
comience en una nueva línea*/

int main(int argc, char *argv[]) {
	
	string auxiliar = "";
	string linea;
	
	ifstream archivo;
	archivo.open("archivo_ejer3.txt");
	if (archivo.fail()){
		cout << "ERROR AL ENCONTRAR/ABRIR EL ARCHIVO" << endl;
		return -1;
	} else {
		int inicio = 0;
		while (getline(archivo, linea)){
			int busqueda = linea.find_first_of("?!.");
			while (busqueda != -1){
				if (linea[inicio] == ' '){
					inicio++;
				}
				auxiliar += linea.substr(inicio, ((busqueda + 1) - inicio)) + "\n";
				inicio = busqueda + 1;
				busqueda = linea.find_first_of("?!.", inicio);
			}
		}
	}
	archivo.close();
	
	ofstream archivo2;
	archivo2.open("archivo_ejer3.txt");
	archivo2 << auxiliar;
	archivo2.close();
	return 0;
}

