#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

void primeroscuatro (string& aniocortado, int& resultado);
void ordenador(string nombres[], int dnis[], int ingresos[], int anios[], int contador);

int main(int argc, char *argv[]) {
	int jubis = 0, anio = 2023, jubilados[100] = {0}, contador = 0, vectordni[100] = {0}, anios[100] = {0}, ingreso[100];
	string linea, linea2, nombres[100] = {""};
	ifstream datos;
	datos.open("datos_personales.txt");
	if (datos.fail()){
		cout << "ERROR AL ABRIR EL ARCHIVO";
		return 1;
	} else{
		while (!datos.eof()){
			datos >> vectordni[contador];
			datos.ignore();
			getline(datos, nombres[contador]);
			getline(datos, linea);
			primeroscuatro(linea, anios[contador]);
			getline(datos, linea2);
			primeroscuatro(linea2, ingreso[contador]);
			contador++;
		}
	}
	datos.close();
	ordenador(nombres, vectordni, ingreso, anios, contador);
	cout << "DNI" << setw(28) << "APELLIDO Y NOMBRE" << setw(28) << "AÑO DE INGRESO" << endl;
	for (int i = 0; i < contador; i++){
	 	if ((anio - anios[i] >= 52) && (anio - ingreso[i] >= 25)){
			cout << vectordni[i] << setw(23) << nombres[i] << setw(25) << ingreso[i] << endl;
			jubilados[i] = vectordni[i];
			jubis++;
		}
	}
	ifstream catedras;
	catedras.open("docentes_catedras.txt");
	string nombrecatedra[100] = {""}, funcion[100] = {""}, cargo[100] = {""};
	int dnicat[100] = {0}, j = 0;
	if (catedras.fail()){
		cout << "No se encontro el archivo";
		return 1;
	} else{
		while(!catedras.eof()){
			catedras >> dnicat[j];
			catedras.ignore();
			getline(catedras, nombrecatedra[j]);
			getline(catedras, funcion[j]);
			getline(catedras, cargo[j]);
			j++;
		}
	}
	catedras.close();
	ofstream archivo3;
	archivo3.open("catedras_concursos.txt",ios::out);
	if(archivo3.fail()){
		cout<<"Error en abrir el archivo.";
	}else{
		archivo3<<"NOMBRE DE LA CATEDRA"<<setw(20)<<"FUNCION"<<setw(20)<<"CARGO"<<endl;
		for (int i = 0; i < jubis; i++) {
			for (int h = 0; h < j; h++) {
				if (dnicat[h] == jubilados[i]) {
					archivo3 << nombrecatedra[h] << setw(20) << funcion[h] << setw(20) << cargo[h] << endl;
				}
			}
		}
	}
	return 0;
}

void primeroscuatro (string& aniocortado, int& resultado){
	string primeroscuatro = aniocortado.substr(0, 4);
	resultado = stoi(primeroscuatro);
}

	void ordenador(string nombres[], int dnis[], int ingresos[], int anios[], int contador) {
		int aux2;
		string aux;
		for (int i = 0; i < contador - 1; i++) {
			for (int j = i + 1; j < contador; j++) {
				if (nombres[i] > nombres[j]) {
					aux = nombres[i];
					nombres[i] = nombres[j];
					nombres[j] = aux;
					aux2 = dnis[i];
					dnis[i] = dnis[j];
					dnis[j] = aux2;
					aux2 = ingresos[i];
					ingresos[i] = ingresos[j];
					ingresos[j] = aux2;
					aux2 = anios[i];
					anios[i] = anios[j];
					anios[j] = aux2;
				}
			}
		}
	}
