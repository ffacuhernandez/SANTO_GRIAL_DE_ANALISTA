#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

void ordenador(int primero[], string segundo[], int tercero[], int contador);
int mide_antiguedad(int dato);

int main(int argc, char *argv[]) {
	int matriznum[100][100], permitidos[100] = {0}, permitidos3[100] = {0};
	string matrizstring[100][100], permitidos2[100] = {0};
	int c = 0, x = 0, z = 0, cate1 = 0, cate2 = 0, cate3 = 0, cate4 = 0, cate5 = 0;
	ifstream archivo;
	archivo.open("ALUMNOS.TXT");
	if (archivo.fail()){
		return 1;
	} else{
		while (archivo >> matriznum[c][0]){ /// DNI
			archivo.ignore();
			getline(archivo,matrizstring[c][0]); /// A Y N
			getline(archivo, matrizstring[c][1]); /// FECHA INCIO
			archivo >> matriznum[c][1]; /// TIPO ENTRENAMIENTO
			c++;
		}
	}
	archivo.close();
	ifstream archivo2;
	archivo2.open("ACTUALIZACION.TXT");
	if (archivo2.fail()){
		return 1;
	} else{
		while (archivo2 >> matriznum[x][2]){ /// DNI
			archivo2.ignore();
			getline(archivo2, matrizstring[x][2]); /// NOMBRE Y APELLIDO
 			archivo2 >> matriznum[x][3]; /// TIPO ENTRENAMIENTO
			archivo2.ignore();
			getline(archivo2,matrizstring[x][3]); /// FECHA
			archivo2.ignore();
			getline(archivo2, matrizstring[x][4]); /// SITUACION
			x++;
		}
	}
	archivo2.close();
	for (int i = 0; i < x; i++){
		string calculo = matrizstring[i][1].substr(3,3);
		int mes = stoi(calculo);
		int antiguedad = 11 - mes;
		if ((antiguedad > 60 ) && (matrizstring[i][2] == "Alta")){
			permitidos[i] = matriznum[i][2];
			permitidos2[i] = matrizstring[i][2];
			permitidos3[i] = antiguedad;
			int cat = mide_antiguedad(antiguedad);
			if (cat == 1){
				cate1++;
			} else if (cat == 2){
				cate2++;
			} else if (cat == 3){
				cate3++;
			} else if (cat == 4){
				cate4++;
			} else{
				cate5++;
			}
			z++;
		}
	}
	ordenador(permitidos, permitidos2, permitidos3, z);
	/// INFORME 1
	cout << "DNI" << setw(20) << "NOMBRE Y APELLIDO" << setw(20) << "ANTIGUEDAD" << endl;
	for (int i = 0; i < z; i++){
		cout << permitidos[i] << setw(20) << permitidos2[i] << setw(20) << permitidos3[i] << endl;
	}
	/// INFORME 2
	cout << setw(50) << "6 A 12" << setw(10) << "13 A 18" << setw(10) << "19 A 24" << setw(10) << "25 A 30" << setw(10) << "31 A 36" << endl;
	cout << "SEMIPERSONALIZADO" << setw(10) << cate1 << setw(10)<< cate2  << setw(10)<< cate3 << setw(10)<< cate4  << setw(10) << cate5 <<endl;
	cout << "PERSONALIZADO" << setw(10) << cate1 << setw(10)<< cate2  << setw(10)<< cate3 << setw(10)<< cate4  << setw(10) << cate5 <<endl;
	cout << "FUNCIONAL" << setw(10) << cate1 << setw(10)<< cate2  << setw(10)<< cate3 << setw(10)<< cate4  << setw(10) << cate5 <<endl;
	cout << "CROSSFIT" << setw(10) << cate1 << setw(10)<< cate2  << setw(10)<< cate3 << setw(10)<< cate4  << setw(10) << cate5 <<endl;
	cout << "CALISTENIA" << setw(10) << cate1 << setw(10)<< cate2  << setw(10)<< cate3 << setw(10)<< cate4  << setw(10) << cate5 <<endl;
	return 0;
}

void ordenador(int primero[], string segundo[], int tercero[], int contador){
	int aux;
	string aux2;
	for (int i = 0; i < contador-1; i++){
		for (int j = i+1; j < contador; j++){
			if (tercero[i] > tercero[j]){
				aux = tercero[i];
				tercero[i] = tercero[j];
				tercero[j] = aux;
				aux = primero[i];
				primero[i] = primero[j];
				primero[j] = aux;
				aux2 = segundo[i];
				segundo[i] = segundo[j];
				segundo[j] = aux2;
			}
		}
	}
}

int mide_antiguedad(int dato){
	if ((dato >= 6) && (dato <= 12)){
		return 1;
	} else if ((dato >= 13) && (dato <= 18)){
		return 2;
	} else if ((dato >= 19) && (dato <= 24)){
		return 3;
	} else if ((dato >= 25)&&(dato <= 30)){
		return 4;
	} else {
		return 5;
	}
}
