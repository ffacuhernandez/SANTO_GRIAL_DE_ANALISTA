#include <iostream>
using namespace std;
int validar_edad(int n);

int main(int argc, char *argv[]) {
	int edad, dni, maxedad = 0, mayordetodos;
	cout << "Ingrese la edad del miembro: " << endl << ">";
	cin >> edad;
	while (edad != 200){
		int chequeo = validar_edad(edad);
		cout << "Ingrese el DNI del alumno: " << endl << ">";
		cin >> dni;
		if (chequeo > maxedad){
			maxedad = chequeo;
			mayordetodos = dni;
		}
		cout << "Ingrese la edad del miembro: " << endl << ">";
		cin >> edad;
	}
	cout << "EL DNI DEL MIEMBRO MAS VIEJO CHOTO ES: " << mayordetodos << endl;
	return 0;
}

int validar_edad(int n){
	if ((n < 12) or (n > 90)){
		while ((n < 12) or (n > 90)){
			cout << "*ERROR* INGRESE UNA EDAD VALIDA (MAYOR A 12 Y MENOR A 90)" << endl;
			cout << "Ingrese la edad del miembro: " << endl;
			cin >> n;
		}
	}
	return (n);
}
