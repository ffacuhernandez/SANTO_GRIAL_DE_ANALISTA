#include <iostream>
using namespace std;
/*Cargar un vector con N palabras. Luego intercambiar los valores del vector: el 1ero con el enésimo,
el 2do con el enésimo -1, y así sucesivamente. Informar en 2 strings el vector original y el intercambiado.*/
int main(int argc, char *argv[]) {
	string palabras[999];
	int cantpalabras;
	cout << "Ingrese cantidad de palabras: " << endl;
	cin >> cantpalabras;
	for (int i = 0; i < cantpalabras; i++){
		cout<<"Ingrese la palabra"<<endl;
		cin >> palabras[i];
	}
	cout << "Palabras en orden original: "<< endl;
	for (int i = 0; i < cantpalabras; i++){
		cout << palabras[i] << " - ";
	}
	cout << endl;
	cout << "Palabras intercambiadas por su enesima posicion" << endl;
	for (int i = cantpalabras-1; i > -1; i--)
	{
		cout << palabras[i] << " - ";
	}
	
	
	return 0;
}

