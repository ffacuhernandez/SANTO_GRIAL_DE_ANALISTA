#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	const int N = 3;
	int multa, mess, dia, motos[N][5] = {0}, aux, bandera = 0, mes[N][3] = {0};
	string patentex[N], busqueda, aux2;
	for (int i = 0; i < N; i++){
		cout << "Ingrese la patente: " << endl;
		getline(cin,patentex[i]);
		cout << "Ingrese el nro de carnet: " << endl;
		cin >> motos[i][0];
		cout << "Ingrese la cantidad de multas: " << endl;
		cin >> motos[i][1];
		cout << "Ingrese la cantidad de acarreos: " << endl;
		cin >> motos[i][2];
		cin.get();
	}
	cout << "Ingrese la patente de la moto: " << endl;
	getline(cin,busqueda);
	while (busqueda != "x"){
		int i = 0, pos; 
		while (i < N){
			if (busqueda == patentex[i]){
				pos = i;
				bandera = 1;
				i = N;
			}
			i++;
		}
		if (bandera == 0){
			cout << "NO SE ENCONTRO LA PATENTE GOD" << endl;
		} else {
			cout << "Ingrese el tipo de multa: " << endl;
			cin >> multa;
			if (multa > 2){
				motos[pos][2]++;
			}
			cout << "Ingrese dia";
			cin >> dia;
			cout << "Ingrese mes";
			cin >> mess;
			if (mess == 5){
				mes[pos][0] = motos[pos][2];
			}else if (mess == 6){
				mes[pos][1] = motos[pos][2];
			}else if (mess == 7){
				mes[pos][2] = motos[pos][2];
			}else if (mess == 8){
				mes[pos][3] = motos[pos][2];
			}
		}
		cin.get();
		cout << "Ingrese la patente de la moto: " << endl;
		getline(cin,busqueda);
	}
	
	for (int i = 0; i<(N-1); i++){
		for (int j = i+1; j<N; j++){
			if (motos[i][1] > motos[j][1]){
				aux = motos[i][1];
				motos[i][1] = motos[j][1];
				motos[j][1] = aux;
				aux = motos[i][2];
				motos[i][2] = motos[j][2];
				motos[j][2] = aux;
				aux = mes[i][0];
				mes[i][0] = mes[j][0];
				mes[j][0] = aux;
				aux = mes[i][1];
				mes[i][1] = mes[j][1];
				mes[j][1] = aux;
				aux = mes[i][2];
				mes[i][2] = mes[j][2];
				mes[j][2] = aux;
				aux = mes[i][3];
				mes[i][3] = mes[j][3];
				mes[j][3] = aux;
				aux2 = patentex[i];
				patentex[i] = patentex[j];
				patentex[j] = aux2;
			}
		}
	}
	cout << "PATENTE       " <<  "   CANT MULTAS     " << "     CANT ACARREOS" << endl;
	for (int i = N-1; i > -1; i--){
		cout << patentex[i] << "         " << motos[i][1] << "      "   << motos[i][2] << endl;
	}
	cout << "PATENTE      " << "  MAYO    " << "   JUNIO " << "  JULIO   " << "   AGOSTO" << endl;
	for (int i=0; i<N; i++){
		cout << patentex[i] << "            " << mes[i][0] << "         " << mes[i][1] << "            " << mes[i][2] << "           " << mes[i][3] << endl;
	}
	
	return 0;
}

