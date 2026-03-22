#include <iostream>
#include <fstream>
using namespace std;

void leer(){
	ifstream archivo("example.txt", ios :: binary);
	if (!archivo){
		cout << "ERROR AL ABRIR EL ARCHIVO" << endl;
		return;
	}
	while (archivo.peek() != EOF){
		int longitud;
		archivo.read(reinterpret_cast<char*>(&longitud), sizeof(int));
		if (archivo.eof()) break; /// EVITA LEER BULLSHIT
		char *cadena = new char [longitud];
		archivo.read(cadena, longitud);
		cout << cadena << endl;
		delete[] cadena;
	}
	archivo.close();
}

int main(int argc, char *argv[]) {
	leer();
	return 0;
}

