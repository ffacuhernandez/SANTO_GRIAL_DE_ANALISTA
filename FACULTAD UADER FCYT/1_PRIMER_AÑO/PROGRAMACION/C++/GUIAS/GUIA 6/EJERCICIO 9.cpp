#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	int n, matriz[100][5] = {0}, busqueda, bandera = 0, pos = 0, desaprobados = 0, aux;
	cout << "Ingrese la cantidad de alumnos: " << endl;
	cin >> n;
	for (int i = 0; i < n; i++){
		cout << "Ingrese el dni: " << endl;
		cin >> matriz[i][0];
		cout << "Ingrese la nota del primer trimestre: ";
		cin >> matriz[i][1];
	}
	cout << "Ingrese el dni a buscar: " << endl;
	cin >> busqueda;
	while(busqueda != 0){
		
		int i=0;
		while (i < n){
			if (matriz[i][0] == busqueda){ 
				bandera =1;
				pos = i;
				i = n;
			}
			i++;
		}
		cout<<"*****************************************"<<endl;
		if (bandera == 0){
			cout<<"El dni no fue hallado";
		}
		else {
			cout << "El dni fue hallado e ingresado en orden: " << pos + 1 << endl;  ///ACÁ ES POS+1 PARA QUE QUEDE LINDO
			cout << "Ingrese la nota del 2do semestre correspondiente: " << endl;
			cin >> matriz[pos][2];
		}
		cout<<"Ingrese otro dni o salga de la busqueda con 0: " << endl;
		cin>>busqueda;
	}
	for (int i = 0; i < n; i++){
		matriz[i][3] = (matriz[i][1] + matriz[i][2]) / 2;
		if (matriz[i][3] < 6){
			desaprobados++;
		}
	}
	cout << "DNI" << "    " << "PROMEDIO" << endl;
	for (int i = 0; i < n; i++){
		cout << "  " << matriz[i][0] << "   " << matriz[i][3] << endl;
	}
	cout << "CANTIDAD DE ALUMNOS QUE NO APROBARON: " << endl;
	cout << desaprobados << endl;
	
	for(int i = 0; i < (n-1); i++){
		for (int j = i+1; j < n; j++){
			if (matriz[i][3] < matriz[i][3]){
				for (int k = 0; k < 4; k++){
					aux = matriz[i][k];
					matriz[i][k] = matriz[j][k];
					matriz[j][k] = aux;
				}
			}
		}
	}
	cout << "SOLO APROBADOS" << endl;
	cout << "DNI" << "    " << "PROMEDIO" << endl;
	for (int i = n-1; i>-1; i--){
		if (matriz[i][3] >= 6){
			cout << matriz[i][0] << "   " << matriz[i][3] << endl;
		}
	}
	return 0;
}

