#include <iostream>
#include <fstream>
using namespace std;

void ordenador3000(int matriz[][2]){;
	int aux;
	for(int i = 0; i < (10-1); i++){ 
		for (int j = i+1; j < 10; j++){ 	
			if (matriz[i][1] > matriz[j][1]) { 
				aux= matriz[i][1];
				matriz[i][1]= matriz[j][1]; 
				matriz[j][1]= aux; 
				aux= matriz[i][0];
				matriz[i][0]= matriz[j][0]; 
				matriz[j][0]= aux;
			} 
		}
	}
}
int main(int argc, char *argv[]) {
	ifstream archivo;
	int matriz[10][2];
	archivo.open("./LOTE_EJERCICIO1.txt");
	if (archivo.fail()){
		cout << "Archivo no encontrado";
		return 1;
	} else{
		for (int i = 0; i < 10; i++) {
			archivo >> matriz[i][0] >> matriz[i][1];
		}
	}
	ordenador3000(matriz);
	cout << "MATRIZ ORDENADA POR LOS VALORES DE Y" << endl;
	for (int i = 0; i < 10; i++){
		cout << matriz[i][0] << "     " << matriz[i][1] << endl;
	}
	return 0;
}

