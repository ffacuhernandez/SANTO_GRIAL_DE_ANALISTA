#include <iostream>
#include <string>
using namespace std;

int main(int argc, char *argv[]) {
	string cad, valori, valorf;
	cout << "Ingrese la cadena de caracteres: ";
	getline (cin,cad);
	char primerletra = cad [0];
	char ultimaletra = cad [cad.size()-1];
	string subcadena = cad.substr(1,cad.size()-2);
	cout << "CADENA ORIGINAL: " << cad << endl << "Primera letra: " << primerletra << endl << "Ultima letra: " << ultimaletra << endl << "Subcadena que queda: " << subcadena; 
	
	
	return 0;
}

