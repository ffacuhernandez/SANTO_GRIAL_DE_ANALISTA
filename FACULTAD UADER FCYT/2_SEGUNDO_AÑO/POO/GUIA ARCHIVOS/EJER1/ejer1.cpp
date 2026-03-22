#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

void leer_archivo(const string& nombrearchivo, int n){
	ifstream archivo(nombrearchivo);
	if (!archivo){
		cout << "NO SE ENCONTRO EL ARCHIVO" << endl;
		return;
	}
	vector<string> lineas;
	string linea;
	while (getline(archivo, linea)){
		lineas.push_back(linea);
	}
	archivo.close();
	int total_lineas = lineas.size();
	int lineas_por_archivo = (total_lineas + n - 1) / n;
	for (int i = 0; i < n; i++){
		string nombre_salida = "archivo_" + to_string(i + 1) + ".txt";
		ofstream salida(nombre_salida);
		for (int j = i * lineas_por_archivo; j < (i + 1) * lineas_por_archivo && j < total_lineas; j++) {
			salida << lineas[j] << endl;
		}
		salida.close();
		cout << "Se ha creado el archivo: " << nombre_salida << endl;
	}
}

int main(int argc, char *argv[]) {
	string nombrearchivo = "ARCHIEJER_1.txt";
	int n = 2;
	leer_archivo(nombrearchivo,n);
	return 0;
}

