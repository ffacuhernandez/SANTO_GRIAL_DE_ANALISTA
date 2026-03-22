#include <iostream>
#include <string>
using namespace std;
/*  Se desea generar una dirección de correo en base a la información ingresada por un estudiante. 
Se ingresa: nombre, apellido, fecha de nacimiento (DD/MM/AAAA) y facultad. La dirección de correo se forma de la 
siguiente manera: Primer letra del nombre + Apellido + DDMM + “@” + facultad + “.edu.ar” */
int main(int argc, char *argv[]) {
	string nombre, apellido, fecha, facultad;
	cout << "Ingrese nombre, apellido, fecha de nacimiento y facultad: " << endl;
	getline(cin, nombre);
	getline(cin, apellido);
	getline(cin, fecha); 
	getline(cin, facultad);
	char primerletra = nombre[0];
	string dia = fecha.substr(0,2);
	string mes = fecha.substr(2,2);
	string mail = primerletra + apellido + dia + mes + "@" + facultad + ".edu.ar";
	cout << "La direccion de correo sera: " << mail;
	return 0;
}

