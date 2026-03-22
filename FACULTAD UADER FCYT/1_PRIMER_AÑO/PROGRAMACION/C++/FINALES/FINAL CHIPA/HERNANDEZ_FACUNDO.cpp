#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int buscador(string codigo, string matrizstring[][3], int contador);
void ordenador (int total[], int n, string matrizstring[][3], int participacion[][4]);
string buscarmaximo(int& maxcantidad, int& maxcaracter, string matrizstring[][3], int participacion[][4], int cursos);

int main(int argc, char *argv[]) {
	int c = 0, x = 0, dni, caract; /// VARIABLEA DE NUMEROS INT
	string codcurso; /// VARIABLES DE STRING
	int matriznum[1000][1] = {0}, participacion[1000][4] = {0}, total[1000] = {0}; /// LINEA PARA MATRIZ DE NUMEROS
	string matrizstring[1000][3]; /// LINEA PARA MATRIZ DE STRINGS
	ifstream archivo;
	archivo.open("cursos.txt");
	if (archivo.fail()){
		cout << "ERROR AL ENCONTRAR EL ARCHIVO" << endl;
		return 1;
	} else{
		while (getline(archivo, matrizstring[c][0])){ /// CODIGO DE CURSO
			getline(archivo, matrizstring[c][1]); /// NOMBRE CURSO
			c++;
		}
	}
	archivo.close();
	ifstream archivo2;
	archivo2.open("asistentes.txt");
	if (archivo2.fail()){
		cout << "ERROR AL ENCONTRAR EL ARCHIVO" << endl;
		return 1;
	} else{
		while (archivo2 >> matriznum[x][0]){ /// DNI
			archivo2.ignore();
			getline(archivo2, matrizstring[x][2]); /// APELLIDO Y NOMBRE
			x++;
		}
	}
	cout << "Ingrese DNI del asistente: " << endl << ">";
	cin >> dni;
	while (dni != 0){
		cout << "Ingrese codigo de curso: " << endl << ">";
		cin >> codcurso;
		int busqueda = buscador(codcurso, matrizstring, c);
		if (busqueda != -1){
			cout << "Ingrese caracter de participacion (1, 2, 3): " << endl << ">";
			cin >> caract;
			participacion[busqueda][caract]++;
			total[busqueda]++;
		}
		cout << "Ingrese DNI del asistente: " << endl << ">";
		cin >> dni;
	}
	ordenador(total, c, matrizstring, participacion);
	/// INFORME 1
	cout << "COD. CURSO" << setw(20) << "NOMBRE CURSO" << setw(20) << "CANT. INVESTIGADORES" << setw(20) << "CANT. PROFESIONALES" << setw(20) << "CANT PRODUCTORES" << setw(20) << "CANT TOTAL" << endl;
	for (int i = 0; i < c; i++){
		cout << matrizstring[i][0] << setw(20) << matrizstring[i][1] << setw(20) << participacion[i][1] << setw(20) << participacion[i][2] << setw(20) << participacion[i][3] << setw(20) << total[i] << endl;
	}
	
	/// INFORME 2
	int maxcantidad;
	int maxcaracter;
	string cursomaximo = buscarmaximo(maxcantidad, maxcaracter, matrizstring, participacion, c);
	cout << "Curso con mayor cantidad de asistentes: " << endl;
	cout << "Nombre del curso: " << cursomaximo << endl;
	cout << "Carácter de participación: " << maxcaracter << endl;
	cout << "Cantidad de asistentes: " << maxcantidad << endl;
	return 0;
}

int buscador(string codigo, string matrizstring[][3], int contador){
	int i = 0;
	while (i < contador){
		if (codigo == matrizstring[i][0]){
			return i;
		}
		i++;
	}
	return -1;
}

void ordenador (int total[], int n, string matrizstring[][3], int participacion[][4]){
	int aux;
	string aux2;
	for (int i = 0; i < n-1; i++){
		for (int j = i+1; j < n; j++){
			if (total[i] > total[j]){
				aux = total[i];
				total[i] = total[j];
				total[j] = aux;
				aux = participacion[i][1];
				participacion[i][1] = participacion[j][1];
				participacion[j][1] = aux;
				aux = participacion[i][2];
				participacion[i][2] = participacion[j][2];
				participacion[j][2] = aux;
				aux = participacion[i][3];
				participacion[i][3] = participacion[j][3];
				participacion[j][3] = aux;
				aux2 = matrizstring[i][0];
				matrizstring[i][0] = matrizstring[j][0];
				matrizstring[j][0] = aux2;
				aux2 = matrizstring[i][1];
				matrizstring[i][1] = matrizstring[j][1];
				matrizstring[j][1] = aux2;
			}
		}
	}
}
	
string buscarmaximo(int& maxcantidad, int& maxcaracter, string matrizstring[][3], int participacion[][4], int cursos) {
	maxcantidad = 0;
	string maxcurso;
	for (int i = 0; i < cursos; i++) {
		for (int j = 1; j <= 3; j++) {  
			if (participacion[i][j] > maxcantidad) {
				maxcantidad = participacion[i][j];
				maxcurso = matrizstring[i][1];  
				maxcaracter = j;  
			}
		}
	}
	return maxcurso; 
}

