#include <iostream>
using namespace std;
/*Una empresa posee N empleados y de cada uno de ellos los siguientes datos: Código de empleado (numérico), cantidad de horas normales trabajadas, 
cantidad de horas extras trabajadas. La cantidad de empleados y el valor de la hora normal de trabajo se leen como primeros datos Se pide: 
a) Informar el sueldo a percibir por cada empleado, teniendo en cuenta que las horas extras se pagan el doble que las horas normales de trabajo.
b) Realizar un informe ordenado por el sueldo a percibir por cada empleado de mayor a menor.*/
int main(int argc, char *argv[]) {
	int n, vhora, matriz[100][4], aux = 0;
	cout << "Ingrese la cantidad de empleados: " << endl;
	cin >> n;
	cout << "Ingrese el valor de la hora normal trabajada: " << endl;
	cin >> vhora;
	for (int i = 0; i < n; i++){
		cout << "Ingrese codigo de empleado: " << endl;
		cin >> matriz[i][0];
		cout << "Ingrese la cantidad de horas normales trabajadas" << endl;
		cin >> matriz[i][1];
		cout << "Ingrese la cantidad de horas extras trabajadas: " << endl;
		cin >> matriz[i][2];
		matriz[i][3] = (matriz[i][1] * vhora) + ((matriz[i][2] * vhora)*2);
	}
	cout << "SUELDO POR CADA EMPLEADO: " << endl;
	for (int i = 0; i < n; i++){
		cout << "EMPLEADO CODIGO " << matriz[i][0]  << " CON UN SUELDO DE: " << matriz[i][3] << endl; 
	}
	for (int i = 0; i<(n-1); i++){
		for(int j = i+1; j<n; j++){
			if (matriz[i][3] > matriz[j][3]){
				for (int k = 0; k<4; k++){
					aux = matriz[i][k];
					matriz[i][k] = matriz[j][k];
					matriz[j][k] = aux;
				}
			}
		}
	}
	for (int i = n-1; i > -1; i--){
		cout << matriz[i][0] << "   " << matriz[i][1] << "   " << matriz[i][2] << "   " <<matriz[i][3] << endl;
	}
	return 0;
}

