#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int buscador(int numtambo, int matriznum[][100]);

int main(int argc, char *argv[]) {
	int c = 0, x = 0, numtambo;
	int matriznum[100][100];
	string matrizstring[100][100];
	ifstream archivo;
	archivo.open("tambos.txt");
	if (archivo.fail()){
		cout << "No se pudo encontrar el archivo";
		return 1;
	} else{
		while (archivo >> matriznum[c][0]){ /// NUMERO TAMBO
			archivo.ignore();
			getline(archivo, matrizstring[c][0]); /// NOMBRE TAMBO
			c++; /// CONTADOR PARA TAMBOS
		}
	}
	archivo.close();
	ifstream archivo2;
	archivo2.open("produccion.txt");
	if (archivo2.fail()){
		cout << "No se pudo encontrar el archivo";
		return 1;
	} else{
		while (archivo2 >> matriznum[x][1]){ /// DIA DEL MES
			archivo2 >> matriznum[x][2]; /// NUMERO DE TAMBO
			archivo2 >> matriznum[x][3]; /// TIPO PASTURA UTILIZADA
			archivo2 >> matriznum[x][4]; /// LECHE 2022
			archivo2 >> matriznum[x][5]; /// LECHE 2023
			x++; /// CONTADOR PARA PRODUCCION
		}
	}
	for (int i = 0; i < 10; i++){
		cout << "Ingrese el numero de tambo: " << endl << ">";
		cin >> numtambo;
		int resultado = buscador(numtambo, matriznum);
		if (resultado != -1){
			cout << "Ingrese la cantidad de vacas en febrero de 2022: " << endl << ">";
			cin >> matriznum[resultado][6];
			cout << "Ingrese la cantidad de vacas en febrero de 2023: " << endl << ">";
			cin >> matriznum[resultado][7];
		}
	}
	
	/// INFORME 1
	cout << "FEBRERO 2022" << endl;
	cout << "NRO TAMBO" << setw(20) << "Cant Vacas" << setw(28) << "Litros leche producidos" << setw(20) << "Productividad" << endl;
	for (int i = 0; i < 10; i++){
		cout << i + 1 << setw(20) << matriznum[i][6] << setw(20) << matriznum[i][4] <<  setw(20) << (matriznum[i][4] / matriznum[i][6]) * 28 << endl;
	}
	cout << "FEBRERO 2023" << endl;
	cout << "NRO TAMBO" << setw(20) << "Cant Vacas" << setw(28) << "Litros leche producidos" << setw(20) << "Productividad" << endl;
	for (int i = 0; i < 10; i++){
		cout << i + 1 << setw(20) << matriznum[i][7] << setw(20) << matriznum[i][5] <<  setw(20) << (matriznum[i][5] / matriznum[i][7]) * 29 << endl;
	}
	
	cout << "---------------------------------------------------" << endl;
	/// INFORME 2
	cout << "Nombre del tambo" << setw(20) << "Dia de mayor produccion de 2022" << setw(20) << "Dia de mayor produccion del 2023";
	for (int i = 0; i < 10; i++){
		
	}
	
	/// INFORME 3
	cout << "Nombre del tambo" << setw(20) << "Tipo de pastura utilizada" << setw(20) << "Productividad" << endl;
	for (int i = 0; i < 10; i++){
		
	}
	return 0;
}
int buscador(int numtambo, int matriznum[][100]){
	int i = 0;
	while (i < 10){
		if (numtambo == matriznum[i][2]){
			return i;
		}
		i++;
	}
	return -1;
}

