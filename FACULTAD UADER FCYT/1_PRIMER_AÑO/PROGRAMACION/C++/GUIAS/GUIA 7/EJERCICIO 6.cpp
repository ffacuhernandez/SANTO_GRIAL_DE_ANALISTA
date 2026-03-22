#include <iostream>
#include <iomanip>
using namespace std;
int calcdoble(int a){ // FUNCION PARA CALCULAR EL DOBLE DEL DATO.
	int x = a * 2;
	return(x);
}
	
string calparidad(int b){
	string y;
	if (b % 2 == 0) {
		y = " ES PAR";
	} else {
		y = " ES IMPAR";
	}
	return(y);
}

int potenciador(int c){
	int z = c * c * c * c * c;
	return(z);
} 

int main(int argc, char *argv[]) {
	char opcion;
	int dato;
	bool antihack = false;
	cout << "Ingrese un dato numerico (ten cuidado amigo...): " << endl << ">";
	cin >> dato;
	cout << setw(78) <<" -------------------- BIENVENIDO PAPU --------------------" << endl;
	cout << setw(60) << "HAS SIDO SELECCIONADO" << endl;
	cout << setw(64) << "NO HAY TIEMPO PARA PREGUNTAS" << endl;
	cout << setw(58) << "ELIGE UNA OPCION" << endl;
	cout << setw(78) << "---------------------------------------------------------" << endl;
	cout << setw(40) << "CALCULOS: " << endl;
	cout << setw(62) << "A - Calcular el doble del dato." << endl;
	cout << setw(56) << "B - Determinar si es par." << endl;
	cout << setw(65) << "C - Determinar su quinta potencia." << endl;
	cout << setw(41) << "D - Salir." << endl;
	cout << setw(60) << "Elija una opcion (A.D): ";
	cin >> opcion;
	do {
		if (opcion == 'A' or opcion == 'B' or opcion == 'C' or opcion == 'D') {
			antihack = true; 
		} else {
			cout << "CHE CORNETITA, NO TE QUIERAS PASAR DE VIVO Y ELEGI UNA OPCION QUE SEA VALIDA (A, B, C, D): " << endl;
			cin >> opcion;	
		}
	} while (!antihack);
	while (opcion != 'D'){
		switch (opcion){
			case 'A' :{
				int doble = calcdoble(dato);
				cout << "EL DOBLE DEL DATO INGRESADO ES: " << doble;
				break;
			}
			case 'B':{
				string paridad = calparidad(dato);
				cout << "EL NUMERO " << paridad;
				break;
			}
			case 'C' :{
				int potencia = potenciador(dato);
				cout << "LA QUINTA POTENCIA DEL NUMERO ES: " << potencia;
				break;
			}
		}
		cout << setw(78) << "---------------------------------------------------------" << endl;
		cout << setw(40) << "CALCULOS: " << endl;
		cout << setw(62) << "A - Calcular el doble del dato." << endl;
		cout << setw(56) << "B - Determinar si es par." << endl;
		cout << setw(65) << "C - Determinar su quinta potencia." << endl;
		cout << setw(41) << "D - Salir." << endl;
		cout << setw(60) << "Elija una opcion (A.D): ";
		cin >> opcion;
		do {
			antihack = false;
			if (opcion == 'A' or opcion == 'B' or opcion == 'C' or opcion == 'D') {
				antihack = true; 
			} else {
				cout << "CHE CORNETITA, NO TE QUIERAS PASAR DE VIVO Y ELEGI UNA OPCION QUE SEA VALIDA (A, B, C, D): " << endl;
				cin >> opcion;	
			}
		} while (!antihack);
	}
	cout << "GRACIAS PEDAZO DE CORNETA POR USAR EL PROGRAMA, BOLUDITO, SALAME, BOLUDO A PEDAL, GRACIAS PAPULINCE. " << endl;
	return 0;
}

