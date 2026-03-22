#include <iostream>
using namespace std;
/* a) Declarar un vector llamado números con la capacidad suficiente para almacenar 
las edades de todos los alumnos de la comisión. b) Ingresar la cantidad de alumnos que posee 
la comisión y luego almacenar en el vector las edades de todos los alumnos. c) Ingresar una posición y 
informar la edad almacenada en ella. Repetir c) hasta que se ingrese una posición no válida.*/
int main(int argc, char *argv[]) {
	int numeros [100];
	int alumnos;
	int pos;
	cout << "Ingrese la cantidad de alumnos que posee la comision: ";
	cin >> alumnos;
	for (int i=0; i<alumnos; i++){
		cout << "Ingrese la edad del alumno: ";
		cin >> numeros[i+1];
	}
	cout << "Ingrese la posicion del alumno que desea conocer la edad: ";
	cin >> pos;
	while (pos <= alumnos){
		cout << "La edad del alumno posicion es: " << numeros[pos] << endl;
		cout << "Ingrese la posicion del alumno que desea conocer la edad: ";
		cin >> pos;
	} 
	return 0;
}

