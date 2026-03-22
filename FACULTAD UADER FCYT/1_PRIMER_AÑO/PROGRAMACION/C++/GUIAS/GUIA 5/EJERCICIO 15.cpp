#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
/*  La Municipalidad de Paraná desea obtener información sobre las multas pagadas durante un mes. Existen 10 tipos de multas, codificadas de 1 a 10, y para cada una se ha fijado su importe en función de litros de nafta súper. 
Para realizar el proceso solicitado se ingresa por cada tipo de multa, la cantidad de litros de nafta a
cobrar (ordenados por tipo de multa). Además se ingresan los datos de las multas pagadas durante el mes: día, número de carnet de conductor, apellido y nombre y tipo de multa (1..10). Estos datos se ingresan, ordenados por día y para un mismo día pueden venir varias multas.  
El fin de datos está dado por día = 99. El precio del litro de nafta súper se ingresa al principio como primer dato. Se desea: a) Obtener el siguiente informe:
DUA        APELLIDO Y NOMBRE        CARNET          TIPO           MONTO
TOTAL DEL DIA 1: $ XXXXX*/
int main(int argc, char *argv[]) {
	int preciomulta[10], ncarnet[31] = {0}, tipomulta[31] = {0};/// LINEA DE ARRAYS
	string ayn [31];
	int dia, c = 0, diainforme = 0, d = 0; /// LINEA DE VARIABLES
	float precionafta, monto[31] = {0}, montotaldia[31] = {0}, tot[31] = {0}, totalmes[1];
	cout << "Ingrese el precio de la que toma mcqueen: " << endl << ">";
	cin >> precionafta;
	for (int i = 0; i < 10; i++){
		cout << "Ingrese la cantidad de litros a cobrar por la multa numero " << i + 1 << endl << ">";
		cin >> preciomulta[i];
	}
	
	cout << "Ingrese el dia del mes a procesar : " << endl << ">";
	cin >> dia;
	while (dia != 99){
		int anterior = dia;
		while (anterior == dia){
		cout << "Ingrese el numero de carnet del conductor: " << endl << ">";
		cin >> ncarnet[c];
		cin.get();
		cout << "Ingrese apellido y nombre: " << endl << ">";
		getline(cin,ayn[c]);
		cout << "Ingrese el tipo de multa (del 1 al 10): " << endl << ">";
		cin >> tipomulta[c];
		monto[c]= (preciomulta[tipomulta[c]-1]);
		tot[c] = monto[c]*precionafta;
		montotaldia[diainforme]+= tot[c];
		totalmes[0]+= montotaldia[diainforme];
		cout << "Ingrese el dia del mes a procesar : " << endl << ">";
		cin >> dia;
		c++;
		}
		diainforme++;
		cout << "DIA" << setw(25) << "APELLIDO Y NOMBRE" << setw(15) << "CARNET" << setw(15) << "TIPO" << setw(15) << "MONTO" << endl;
		for (int i=d; i<c; i++){
			cout << diainforme << setw(15) << ayn[i] << setw(15) << ncarnet[i] << setw(15)<< tipomulta[i] << setw(15) << monto[i] << endl;
		}
		cout << "MONTO TOTAL DEL DIA " << diainforme << ": " << montotaldia;
		d = c;
	}
	cout << "TOTAL DEL MES: " << totalmes;
	

	return 0;
}

