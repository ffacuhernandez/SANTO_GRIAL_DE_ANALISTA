#include <iostream>
#include <fstream>
using namespace std;

struct barras{
	string apodo;
	int detenciones;
};

void ordenador(barras datos[], int tamanio);
void funciontroll(barras datos[], int tamanio);

int main(int argc, char *argv[]) {
	int cb = 0; // CANTIDAD BARRAS
	barras datos[999];
	ifstream archivo;
	archivo.open("BARRAS.txt");
	if (archivo.fail()){
		return 1;
	} else {
		while (getline(archivo, datos[cb].apodo, '|' )){
			archivo >> datos[cb].detenciones;
			archivo.ignore();
			cb++;
		}
	}
	ordenador(datos, cb); /// FUNCION PARA ORDENAR PORQUE SI
	cout << "ORDENADO POR DETENCIONES PORQUE ME PINTO PARA PROBAR FUNCIONES CON STRUCTS: " << endl;
	for (int i = 0; i < cb; i++){
		cout << datos[i].apodo << " " << datos[i].detenciones << endl;
	}
	funciontroll(datos, cb); /// PARA TIRAR EL INFORME Y PROBAR QUE ONDA CON FUNCIONES
	
	return 0;
}

void ordenador(barras datos[], int tamanio){
	for (int i = 0; i < tamanio - 1; i++){
		for (int j = i+1; j < tamanio; j++){
			if (datos[i].detenciones < datos[j].detenciones){
				barras aux = datos[i];
				datos[i] = datos[j];
				datos[j] = aux;
			}
		}
	}
}
	
void funciontroll(barras datos[], int tamanio){
	/// ACA VA TODA LA MUGRE
	}
