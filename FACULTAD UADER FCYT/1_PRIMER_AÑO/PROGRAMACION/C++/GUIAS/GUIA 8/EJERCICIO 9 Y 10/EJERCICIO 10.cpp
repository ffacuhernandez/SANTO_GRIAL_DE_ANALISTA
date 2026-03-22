#include <iostream>
#include <fstream>
using namespace std;

void ordenador(int codigos[], int sueldos[]){
	int aux;
	for (int i = 0; i < 10; i++){
		for (int j = i+1; j<10; j++){
			if (sueldos[i] < sueldos[j]){
				aux = sueldos[i];
				sueldos[i] = sueldos[j];
				sueldos[j] = aux;
				aux = codigos[i];
				codigos[i] = codigos[j];
				codigos[j] = aux;
			}
		}
	}
}

int main(int argc, char *argv[]) {
	int codigo, sueldo;
	int codigos[10], sueldos[10];
	ifstream archivo;
	archivo.open("SUELDOS.TXT");
	if (archivo.fail()){
		cout << "No se encontro el archivo";
		return 1;
	} else {
		int i = 0;
		while (archivo >> codigo >> sueldo){
			codigos[i] = codigo;
			sueldos[i] = sueldo;
			i++;
		}
	}
	archivo.close();
	ordenador(codigos, sueldos);
	cout << "ORDENADOS DE MAYOR A MENOR POR SUELDO" << endl;
	for (int i = 0; i < 10; i++) {
		cout << "CODIGO: " << codigos[i] << "     SUELDO: " << sueldos[i] << endl;
	}
	return 0;
}

