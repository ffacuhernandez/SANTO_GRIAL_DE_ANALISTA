#include <iostream>
using namespace std;
/* Se dispone de una lista con los 25 números de documentos de un grupo de alumnos, guardados en un vector DNI. Además, por cada alumno se tiene las 3 calificaciones obtenidas 
en los exámenes parciales de una materia, las cuales se almacenan en una matriz llamada NOTA. Se desea conocer el promedio de un alumno del que se lee su número de documento como dato. 
Si el número de documento buscado no se encuentra mostrar un mensaje que indique que el mismo no fue hallado.*/
int main(int argc, char *argv[]) {
	int dni[5], nota[5][3], busqueda, promedio[5];

	for (int i = 0; i<3; i++){
		cout << "Ingrese el DNI del alumno " << i + 1 << ":" << endl << ">";
		cin >> dni[i];
		for (int j = 0; j<3; j++){
		cout << "Ingrese la nota numero " << j +1 << ":" << endl << ">";
		cin >> nota[i][j];
		}
		promedio[i] = (nota [i][0] + nota[i][1] + nota[i][2]) / 3;
	}

	cout << "Ingrese el numero de documento del alumno que desea conocer la nota: " << endl << ">";
	cin >> busqueda;
	int i = 0;
	int bandera = 0;
	int pos = 0;
	while (i < 3) {
		if ( busqueda == dni[i]){
			bandera = 1;
			pos = i;
			i = 3;
		}
		i++;
	}
	
	if (bandera == 0){
		cout << "No se encontro el documento buscado CORNETITA BURROOO";
	} else{
		cout << "El promedio es de : " << promedio[pos];
	}
	return 0;
}

