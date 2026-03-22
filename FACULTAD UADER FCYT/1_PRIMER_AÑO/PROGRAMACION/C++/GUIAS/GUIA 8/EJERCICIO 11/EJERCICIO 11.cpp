#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char *argv[]) {
	ifstream archivo;
	archivo.open("PRODUCTOS_EN_DOLARES.TXT");
	if (archivo.fail()){
		cout << "No se encontro el archivo";
		return 1;
	}
	string vecdescripciones[10];
	int contador = 0;
	float vecdolares[10] = {0}, precioenpesos[10] = {0};
	int veccodigos[10] = {0};
	while (!archivo.eof()) {
		archivo >> veccodigos[contador];
		archivo.ignore();
		getline(archivo, vecdescripciones[contador]);
		archivo >> vecdolares[contador];
		precioenpesos[contador] = vecdolares[contador] * 1000;
		contador++;
	}
	archivo.close();
	ofstream archipesos;
	archipesos.open("PRODUCTOS_EN_PESOS.TXT");
	for (int i = 0; i < contador; i++) {
		archipesos << veccodigos[i] << endl << vecdescripciones[i] << endl << precioenpesos[i] << endl;
	}
	
	archipesos.close();
	return 0;
}
