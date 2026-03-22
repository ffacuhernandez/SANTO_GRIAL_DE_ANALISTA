#include <iostream>
#include <string>
using namespace std;
/*  Ingrese una cadena de caracteres e informe la segunda palabra de la misma.*/
int main(int argc, char *argv[]) {
	string cadena;
	cout << "Ingrese una cadena de caracteres: " << endl;
	getline (cin,cadena);
	int n = cadena.find(" ");
	string subcadena = cadena.substr(n, 100);
	cout << subcadena;
	
	return 0;
}

