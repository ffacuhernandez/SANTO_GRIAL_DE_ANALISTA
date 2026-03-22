#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc, char *argv[]) {
	const int  N = 7;
	int precio[N][5] = {0}, tipo, cab, cabina[100][5] = {0}, dia, total1, totalvehiculos = 0, total7 = 0, maspete, min = 9999;
	for (int i = 0; i<N; i++){
		cout << "Ingrese precio del vehiculo numero " << i + 1 << ":" << endl;
		cin >> precio[i][0];
	}
	
	cout << "Ingrese tipo de vehiculo que pasó (1 al 7) " << endl;
	cin >> tipo;
	while ((tipo < 0) or (tipo > 7)){
		cout << "*ERROR* INGRESE TIPO DE VEHICULO VALIDO: " << endl << ">";
		cin >> tipo;
	}
	while (tipo != 0){
		if (tipo == 1){
			total1 += precio[tipo][0];
		}
		//if (tipo == 2){
		//	precio[tipo][2] += precio[tipo][0];
		//}
		//if (tipo == 3){
		//	precio[tipo][3] += precio[tipo][0];
		//}
		//if (tipo == 4){
		//	precio[tipo][4] += precio[tipo][0];
		//}
		//if (tipo == 5){
		//}
		//if (tipo == 6){
		//	precio[tipo][6] += precio[tipo][0];
		//}
		if (tipo == 7){
		total7++;
		}
		cout << "Ingrese dia: " << endl;
		cin >> dia;
		cout << "Ingrese cabina (1 a 3)" << endl;
		cin >> cab;
		while ((cab < 1) or (cab > 3)){
			cout << "Ingrese una cabina valida (1 al 3)" << endl;
			cin >> cab;
		}
		if (cab == 1){
		cabina[dia][0]++;
		if (cabina[dia][0] < min){
			min = cabina[dia][0];
			maspete = dia;
		}
		
		}
		if (cab == 2){
		cabina[dia][1]++;
		}
		if (cab == 3){
		cabina[dia][2]++;
		}
		totalvehiculos++;
		cout << "Ingrese tipo de vehiculo que pasó: " << endl;
		cin >> tipo;
		while ((tipo < 0) or (tipo > 7)){
			cout << "*ERROR* INGRESE TIPO DE VEHICULO VALIDO: " << endl << ">";
			cin >> tipo;
		}
	}
	cout << endl;
	cout << "TOTAL DE VEHICULOS" << endl;
	cout << "DIA" << setw(15) << "CABINA 1" << setw(15) << "CABINA 2" << setw(15) << "CABINA 3" << endl;
	for (int i = 1; i<32; i++){
		cout << i << setw(13) << cabina[i][0] << setw(13) << cabina[i][1] << setw(13) << cabina[i][2] << endl;
	}
	cout << endl;
	cout << "TOTAL RECAUDADO EN EL MES DE VEHICULOS TIPO 1: " << total1 << endl;
	cout << endl;
	int porcentaje = (total7/totalvehiculos) * 100;
	cout << "PORCENTAJE DE VEHICULOS TIPO VII SOBRE EL TOTAL DE VEHICULOS: " << porcentaje << endl;
	cout << endl;
	cout << "DIA EN EL QUE LA CABINA 1 REGISTRO MENOS CANTIDAD DE VEHICULOS: " << maspete;
	
	return 0;
}

