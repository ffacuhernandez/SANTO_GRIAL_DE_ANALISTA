#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char *argv[]) {
	ofstream archivo;
	int codigo[24];
	string provincia[24];
	archivo.open("PROVINCIA.TXT");
	for (int i = 0; i<24; i++){
		cout << "Ingrese el nombre de la provincia: " << endl << ">";
		getline(cin, provincia[i]);
		codigo[i] = i;
	}
	for (int i = 0; i<24; i++){
		archivo << codigo[i] << " " << provincia[i] << endl;
	}
	return 0;
}

