#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

void guardarenarchivo(ofstream &archivo, const char* cadena){
	int longitud = strlen(cadena) + 1; // Incluye el ultimo 0
	archivo.write(reinterpret_cast<const char*>(&longitud), sizeof(int));
	archivo.write(cadena, longitud);
}
	

void escribir(){
	ofstream archivo ("example.txt", ios :: binary | ios :: app);
	if (!archivo){
		cout << "ERROR AL ABRIR EL ARCHIVO" << endl;
		return;
	}
	char texto[30];
	cout << "Ingrese la cadena que desea escribir (letra secreta para finalizar)" << endl << ">";
	cin.getline(texto,30);
	while(strcmp(texto, ":q") != 0){
		guardarenarchivo(archivo, texto);
		cout << "Ingrese la cadena que desea escribir (letra secreta para finalizar)" << endl << ">";
		cin.getline(texto,30);
	}
	archivo.close();
}

int main(int argc, char *argv[]) {
	escribir();
	return 0;
}

