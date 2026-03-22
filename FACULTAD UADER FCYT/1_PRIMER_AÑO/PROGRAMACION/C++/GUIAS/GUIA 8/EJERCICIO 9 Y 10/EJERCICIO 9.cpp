#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char *argv[]) {
	int empleados;
	float valorhora, codigos[10][4] = {0}, calnormal, caldoble;
	cout << "Ingrese la cantidad de empleados: " << endl << ">";
	cin >> empleados;
	cout << "Ingrese el valor de la hora normal de trabajo: " << endl << ">";
	cin >> valorhora;
	for (int i = 0; i < empleados; i++){
		cout << "Ingrese codigo de empleado: " << endl << ">";
		cin >> codigos[i][0];
		cout << "Ingrese la cantidad de horas normales trabajadas: " << endl << ">";
		cin >> codigos[i][1];
		cout << "Ingrese la cantidad de horas extras trabajadas: " << endl << ">";
		cin >> codigos[i][2];
		calnormal = codigos[i][1] * valorhora;
		caldoble = codigos[i][2] * (valorhora * 2);
		codigos[i][3] = calnormal + caldoble;
	}
	ofstream archivo;
	archivo.open("SUELDOS.TXT");
	for (int i = 0; i < empleados; i++){
		archivo << codigos[i][0] << " " << codigos[i][3] << endl;
	}
	archivo.close();
	return 0;
}

