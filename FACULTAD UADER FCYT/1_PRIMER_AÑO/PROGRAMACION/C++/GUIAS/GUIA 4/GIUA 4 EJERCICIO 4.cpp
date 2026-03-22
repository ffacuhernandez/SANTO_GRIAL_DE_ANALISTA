#include <iostream>
#include <string>
using namespace std;

/*Ingrese 2 cadenas de caracteres y un valor entero X. 
Inserte la segunda cadena dentro de la primera a partir de la posición X, salvo que dicha posición sea inválida. */

int main(int argc, char *argv[]) {
	string cadena1, cadena2;
	int valentero;
	cout << "Ingrese las dos cadenas de caracteres: " << endl;
	getline(cin,cadena1);
	getline(cin,cadena2);
	cout << "Ingrese un valor entero: " << endl;
	cin >> valentero;
	int n = cadena1.size();
	if (n > valentero) {
		n = valentero;
		cadena1.insert(n, cadena2);
		cout << cadena1;
	} else {
		cout << "El valor entero es invalido";
	}
	

	
	
	
	
	
	
	
	
	return 0;
}

