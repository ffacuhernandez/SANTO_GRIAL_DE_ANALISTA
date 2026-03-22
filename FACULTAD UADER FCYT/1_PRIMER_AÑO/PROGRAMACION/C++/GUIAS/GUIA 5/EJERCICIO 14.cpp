#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
/*Se ha solicitado ingresar los siguientes datos correspondientes a 500 personas inscriptas en un curso de gimnasia: Apellido y nombre, Domicilio, Edad, Documento, Sexo y Altura. Estos datos se ingresan sin ningún orden 
y se solicita que dicha información sea guardada en matrices. Informar un listado con los siguientes datos: Apellido y nombre – Documento Sexo, de las personas cuya altura supera el promedio general de las mismas.*/
///EL EJERCICIO ESTA HECHO PARA 500 (NASHE), PERO PARA PROBAR USAR NUMERO BAJITO.
int main(int argc, char *argv[]) {
	string parastrings[500][3];
	int paranumeros [500][3] = {0};
	float alturas;
	for (int i = 0; i<500; i++){
		cout << "Ingrese apellido y nombre de la persona " << i+1 << ":" << endl << ">";
		getline(cin,parastrings[i][0]);
		cout << "Ingrese domicilio: " << endl << ">";
		getline(cin,parastrings[i][1]);
		cout << "Ingrese la edad: " << endl << ">";
		cin >> paranumeros[i][0];
		cout << "Ingrese documento: " << endl << ">";
		cin >> paranumeros[i][1];
		cin.ignore();
		cout << "Ingrese sexo: " << endl << ">";
		getline(cin,parastrings[i][2]);
		cout << "Ingrese altura: " << endl << ">";
		cin >> paranumeros[i][2];
		alturas+=paranumeros[i][2];
		cin.ignore();
	}
	alturas=alturas/500;
	cout << "LISTADO DE PERSONAS QUE SUPERAN LA MEDIA: " << endl;
	cout << "APELLIDO Y NOMBRE" << setw(15) << "DOCUMENTO" << setw(15) << "SEXO" << endl;
	for (int i = 0; i<500; i++){
		if (paranumeros[i][2] > alturas){
			cout << parastrings[i][0] << setw(20) << paranumeros[i][1] << setw(20) << parastrings[i][2] << endl;
		}
	}
	
	return 0;
}

