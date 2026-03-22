#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	const int N = 2500;
	string ayn, codigos[N][20] = {0}, cod, cod2, busqueda, aux, total;
	int matriz[11][5], importe, bandera, cod3, aux2, vcuota, val;
	for (int i = 0; i<N; i++){
		cout << "Ingrese codigo del asociado" << endl << ">";
		getline(cin,cod);
		codigos[i][0] = cod;
		cout << "Ingrese apellido y nombre" << endl << ">";
		getline(cin,ayn); 
		codigos[i][1] = ayn;
		cout << "Ingrese codigo de plan (PS200:Plan superior o PJ500: Plan joven) " << endl << ">";
		getline(cin,cod2);
		codigos[i][2] = cod2;
	}
	cout << "Ingrese importe de la cuota societaria: " << endl << ">";
	cin >> importe;
	for (int i = 0; i<N; i++){
		if (codigos[i][2] == "PJ500"){
			vcuota = importe / 0.75;
			codigos[i][13] = vcuota;
		}
	}
	
	for (int i = 0; i<11; i++){
		cout << "Ingrese costo del servicio numero " << i + 1 << endl << ">";
		cin >> matriz[i][0];
	}
	cin.get();
	cout << "Ingrese codigo de asociado a cargar datos: " << endl;
	getline(cin,busqueda);
	while (busqueda != "ZZZ"){
		int i = 0, pos;
		while(i<N){
			if (busqueda == codigos[i][0]){
				pos = i;
				bandera = 1;
				i = N;
			}
			i++;
		}
		if (bandera == 0){
			cout << "Codigo no existente" << endl;
		}else {
			cout << "Ingrese el codigo de servicio utilizado: " << endl;
			cin >> cod3;
			if (cod3 == 1){
				codigos[pos][3] += 1;
				val = matriz[cod3][0];
				codigos[pos][14] = val; 
			}
			if (cod3 == 2){
				codigos[pos][3] += 1;
				val = matriz[cod3][0];
				codigos[pos][14] = val; 
			}
			if (cod3 == 3){
				codigos[pos][3] += 1;
				val = matriz[cod3][0];
				codigos[pos][14] = val; 
			}
			if (cod3 == 4){
				codigos[pos][3] += 1;
				val = matriz[cod3][0];
				codigos[pos][14] = val; 
			}
			if (cod3 == 5){
				codigos[pos][3] += 1;
				val = matriz[cod3][0];
				codigos[pos][14] = val; 
			}
			if (cod3 == 6){
				codigos[pos][3] += 1;
				val = matriz[cod3][0];
				codigos[pos][14] = val; 
			}
			if (cod3 == 7){
				codigos[pos][3] += 1;
				val = matriz[cod3][0];
				codigos[pos][14] = val; 
			}
			if (cod3 == 8){
				codigos[pos][3] += 1;
				val = matriz[cod3][0];
				codigos[pos][14] = val; 
			}
			if (cod3 == 9){
				codigos[pos][3] += 1;
				val = matriz[cod3][0];
				codigos[pos][14] = val; 
			}
			if (cod3 == 10){
				codigos[pos][3] += 1;
				val = matriz[cod3][0];
				codigos[pos][14] = val; 
			}
		}
		cout << "Ingrese codigo de asociado: " << endl;
		cin >> busqueda;
	}
	for (int i = 0; i<N-1; i++){
		for (int j = i+1; j<N; j++){
			if (codigos[i][1] > codigos[j][1]){
				aux = codigos[i][1];
				codigos[i][1] = codigos[j][1];
				codigos[j][1] = aux;
				aux = codigos[i][0];
				codigos[i][0] = codigos[j][0];
				codigos[j][0] = aux;
				aux = codigos[i][2];
				codigos[i][2] = codigos[j][2];
				codigos[j][2] = aux;
				aux = codigos[i][3];
				codigos[i][3] = codigos[j][3];
				codigos[j][3] = aux;
				aux = codigos[i][4];
				codigos[i][4] = codigos[j][4];
				codigos[j][4] = aux;
				aux = codigos[i][5];
				codigos[i][5] = codigos[j][5];
				codigos[j][5] = aux;
				aux = codigos[i][6];
				codigos[i][6] = codigos[j][6];
				codigos[j][6] = aux;
				aux = codigos[i][7];
				codigos[i][7] = codigos[j][7];
				codigos[j][7] = aux;
				aux = codigos[i][8];
				codigos[i][8] = codigos[j][8];
				codigos[j][8] = aux;
				aux = codigos[i][9];
				codigos[i][9] = codigos[j][9];
				codigos[j][9] = aux;
				aux = codigos[i][10];
				codigos[i][10] = codigos[j][10];
				codigos[j][10] = aux;
				aux = codigos[i][11];
				codigos[i][11] = codigos[j][11];
				codigos[j][11] = aux;
				aux = codigos[i][12];
				codigos[i][12] = codigos[j][12];
				codigos[j][12] = aux;
				aux = codigos[i][13];
				codigos[i][13] = codigos[j][13];
				codigos[j][13] = aux;
				aux2 = matriz[i][0];
				aux = codigos[i][14];
				codigos[i][14] = codigos[j][14];
				codigos[j][14] = aux;
				matriz[i][0] = matriz[j][0];
				matriz[j][0] = aux2;
			}
		}
	}
	cout << "COD ASOC.     " << "      APELLIDO Y NOMBRE     " << "   PLAN     " << "  S1   " << "  S2   " << "  S3   " << "  S4   " << "  S5   " << "  S6   " << "  S7   " << "  S8   " << "  S9   " << "  S10   " << endl;
	for (int i = 0; i<N; i++){
		cout << codigos[i][0] << "   " << codigos[i][1] << "       " <<  codigos[i][2] << "      " << codigos[i][3] << "      " << codigos[i][4] << "      " << codigos[i][5] << "      " << codigos[i][6] << "      " << codigos[i][7] << "      " << codigos[i][8] << "      " << codigos[i][9] << "      " << codigos[i][10] << "      " << codigos[i][11] << "      " << codigos[i][12];
	}
	for (int i = 0; i<N; i++){
		cout << codigos[i][0] << "    " << codigos[i][13] << "     " << codigos[i][14];
	}
	return 0;
}

