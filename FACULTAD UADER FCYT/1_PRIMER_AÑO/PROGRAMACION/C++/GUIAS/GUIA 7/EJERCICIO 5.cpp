#include <iostream>
using namespace std;

bool EVALUA (int N1, int N2, int N3){ // FUNCION PARA EVALUAR LA PROMOCION
	int suma = N1 + N2 + N3;
	if (N3 >= 25 && suma >= 75){
		return true;
	} else {
		return false;
	}
}

int main(int argc, char *argv[]) {
	int N1, N2, N3;
	cout << "Ingrese los creditos obtenidos del primer parcial: " << endl << ">";
	cin >> N1;
	cout << "Ingrese los creditos obtenidos del segundo parcial: " << endl << ">";
	cin >> N2;
	cout << "Ingrese los creditos obtenidos del tercer parcial: " << endl << ">";
	cin >> N3;
	bool BAND = EVALUA (N1, N2, N3); // LLAMO A LA FUNCION
	if (BAND){
		cout << "BIEN AHI FIERA KRAKEN TORO. MATERIA PROMOCIONADA.";
	} else {
		cout << "MAL AHI PERRO. A ESTUDIAR AMIGO ASI RENDIS EL RECUPERATORIO Y PROMOCIONAS DE RUCULA GONZALES.";
	}
	return 0;
}

