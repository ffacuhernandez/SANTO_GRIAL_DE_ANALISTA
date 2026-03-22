#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main(int argc, char *argv[]) {
	int n, p7, cod, i7, i5, i3, max = 9999, pentium, procesadores[100][100] = {0};
	float god [100][2];
	string nombres[100][100], nreparticion, nresponsable, narea, tacanio;
	cout << "Ingrese la cantidad de reparticiones: " << endl << ">";
	cin >> n;
	cout << "Ingrese el precio de un equipo i7: " << endl << ">";
	cin >> p7;
	cin.ignore();
	for (int i = 0; i<n; i++){
		
		cout << "Ingrese nombre de la reparticion: " << endl << ">";
		getline(cin,nreparticion);
		nombres[i][0] = nreparticion;
		cout << "Ingrese nombre del responsable: " << endl << ">";
		getline(cin,nresponsable);
		nombres[i][1] = nresponsable;
	}
	
	cout << "Ingrese codigo de reparticion de 1 a " << n << ":" << endl << ">";
	cin >> cod;
	while (cod != 9999){
		cin.ignore();
		int c = 0;
		cout << "Ingrese nombre del area: " << endl << ">";
		getline(cin,narea);
		nombres[cod-1][2] = narea;
		cout << "Ingrese cantidad de equipos i7: " << endl << ">";
		cin >> i7;
		procesadores[cod-1][0]+= i7; /// PROCESADORES i7
		cout << "Ingrese cantidad de equipos i5: " << endl << ">";
		cin >> i5;
		procesadores[cod-1][1]+= i5; ///PROCESADORES I5
		cout << "Ingrese cantidad de equipos i3: " << endl << ">";
		cin >> i3;
		procesadores[cod-1][2]+= i3; /// PROCESADORES I3
		cout << "Ingrese cantidad de equipos pentium: " << endl << ">";
		cin >> pentium;
		procesadores[cod-1][3]+= pentium; /// PROCESADORES PENTIUM
		procesadores[cod-1][5]+= procesadores[cod-1][0] + procesadores [cod-1][1] + procesadores [cod-1][2] + procesadores[cod-1][3]; /// ACUMULADOR DE TODOS LOS PROCESADORES
		procesadores[cod-1][6]+= procesadores[cod-1][2] + procesadores[cod-1][3]; /// SUMA DE PORONGAS
		god[cod-1][2]+= procesadores[cod-1][6]*p7; /// TOTAL QUE GASTAS EN CAMBIAR LAS PORONGAS.
		if (god[cod-1][2] < max){ /// CONDICIONAL PARA SABER CUAL ES LA REPARTICION QUE MENOS TIENE QUE GASTAR
			max = god[cod-1][2];
			tacanio = nombres[cod-1][1];
		}
		god[cod-1][1]+=(procesadores[cod-1][5] / procesadores[cod-1][6]); /// DIVISION PARA SACAR EL TOTAL EN PORCIENTO
		c++;
		procesadores[cod-1][4]+=c; /// ACUMULADOR DE AREAS
		cout << "Ingrese codigo de reparticion de 1 a " << n << ":" << endl << ">";
		cin >> cod;
	}
	
	cout << "Reparticion" << setw(10) <<"Cant.áreas" << setw(10) << "i7" << setw(10) << "i5" << setw(10) << "i3" << setw(10) <<"Pentium o inferiores" << setw(10) << "Total a cambiar" << setw(10) <<"Porcentaje" << endl;
	for (int i = 0; i<n; i++){
		cout << nombres [i][0] << setw(10) << procesadores[i][4] << setw(10) << procesadores[i][0] << setw(10) << procesadores[i][1] << setw(10)<< procesadores[i][2] << setw(10) << procesadores[i][3] <<setw(10) << procesadores[i][6] << setw(10)<< god[i][1] << "%" << endl;
		cout << "TOTAL A GASTAR DE LA PARTICION " << i+1 << god[i][2] << "$" << endl;
	}
	cout << "RESPONSABLE DE LA PARTICION QUE MENOS DEBE GASTAR: " << tacanio;
	
	return 0;
}

