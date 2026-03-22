#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
/*Una cooperadora desea obtener la nómina de personas que han adquirido un bono contribución, numerados del 1 al 100. 
Para ello se ingresan los nombres de cada una de las 100 personas que compraron dicho bono, ordenados por número de bono.
Se quiere mostrar al finalizar la carga, un listado con el siguiente formato:
NRO BONO PERSONA QUE ADQUIRIÓ EL BONO 1           XXXXXXXXXXXXXXXXX 2           XXXXXXXXXXXXXXXXX*/

int main(int argc, char *argv[]) {
	string personas[5];
	cout << "Ingrese en orden las personas que han adquirido el bono: " << endl;
	for (int i=0; i < 5; i++){
		getline(cin,personas[i]);
	}
	cout << "Nro Bono" << setw(30) << "Persona que adquirio el bono" << endl;
	for (int i=0; i < 5; i++){
		cout << setw(4) << i+1 << setw(21) << personas[i] << endl;
	}
	return 0;
}

