#include <iostream>
#include <string>
using namespace std;
/*  Ingrese una cadena de caracteres e informe si la misma tiene más de una palabra, 
la letra con la que empieza y la letra con la que termina.*/
int main(int argc, char *argv[]) {
	string cadena;
	cout << "Ingrese la cadena de caracteres: " << endl;
	getline (cin,cadena);
	int n = cadena.find(" ");
	if (n != -1){
		char primeraletra = cadena[0];
		char ultimaletra = cadena [cadena.size()-1];
		cout << "La cadena tiene mas de una palabra y la primer letra es " << primeraletra << " y la ultima letra es " << ultimaletra;
	} else  {
		char primeraletra = cadena[0];
		char ultimaletra = cadena [cadena.size()-1];
		cout << "La cadena tiene una sola palabra y la primer letra es " << primeraletra << " y la ultima letra es " << ultimaletra;
	}
	
	return 0;
}

