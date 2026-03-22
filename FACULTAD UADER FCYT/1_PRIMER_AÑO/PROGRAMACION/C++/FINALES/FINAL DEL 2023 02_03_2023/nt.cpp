#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

struct tambos{
	int numtambo, diames, pastura, litros2022, litros2023;
	string nombretambo;
};

int main(int argc, char *argv[]) {
	int cont = 0, dia, num, pastura, leche2022, leche2023, totaleche2022[10] = {0}, totaleche2023[10] = {0}, tambonum, vacas2022[10], vacas2023[10];
	tambos datos[999];
	int produccion[10][31][1];
	ifstream archivo;
	archivo.open("tambos.txt");
	if (archivo.fail()){
		return 1;
	} else {
		while (archivo >> datos[cont].numtambo){
			archivo.ignore();
			getline(archivo, datos[cont].nombretambo);
			cont++;
		}
	}
	cont = 0;
	archivo.close();
	ifstream archivo2;
	archivo2.open("produccion.txt");
	if (archivo2.fail()){
		return 1;
	} else {
		while (archivo2 >> dia){
			archivo2 >> num;
			archivo2 >> pastura;
			archivo2 >> leche2022;
			totaleche2022[num] += leche2022;
			archivo2 >> leche2023;
			totaleche2023[num] += leche2023;
			produccion[num][dia][0] += leche2022;
			produccion[num][dia][1] += leche2023;
		}
	}
	archivo2.close();
	for (int i = 0; i < 10; i++){
		cout << "Ingrese el numero de tambo: " << endl << ">";
		cin >> tambonum;
		cout << "Ingrese las vacas en el 2022: " << endl << ">";
		cin >> vacas2022[tambonum];
		cout << "Ingrese las vacas en el 2023: " << endl << ">";
		cin >> vacas2023[tambonum];
	}
	/// INFORME 1
	cout << "FEBRERO 2022" << endl;
	cout << "NRO TAMBO" << setw(20) << "CANT. VACAS" << setw(20) << "LITROS LECHE PRODUCIDOS" << setw(20) << "PRODUCTIVIDAD" << endl;
	for (int i = 0; i < 10; i++){
		cout << i+1 << setw(20) << vacas2022[i] << setw(20) << totaleche2022[i] << setw(20) << (totaleche2022[i] / vacas2022[i]) * 28 << endl;
	}
	
	return 0;
}

