#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

/// STRUCTS 
struct cursos{
	string codigo;
	string nombre;
	int investigadores = 0;
	int profesionales = 0;
	int productores = 0;
	int total_curso = 0;
};

struct asistentes{
	int dni;
	string nya;
	int asistencia = 0;
};

/// FUNCIONES
int buscador(string codigo, cursos datos[], int contador);
int funcionfinal(cursos datos[], int contador, int &caracter_participacion, string &codigo);
int asistencia(int dni, asistentes info[], int contador);
	
int main(int argc, char *argv[]) {
	
	/// VARIABLES
	cursos datos[100];
	asistentes info[100];
	int cont_cursos = 0;
	int cont_asistentes = 0;
	int dni;
	string cod;
	int codigoparticipacion;
	
	/// LECTURA ARCHIVOS
	ifstream archivo;
	archivo.open("./cursos.txt");
	if (archivo.fail()){
		return 1;
	} else {
		while (getline(archivo, datos[cont_cursos].codigo)){
			getline(archivo, datos[cont_cursos].nombre);
			cont_cursos++;
		}
	}
	archivo.close();
	archivo.open("./asistentes.txt");
	if (archivo.fail()){
		return 1;
	} else {
		while(archivo >> info[cont_asistentes].dni){
			archivo.ignore();
			getline(archivo, info[cont_asistentes].nya);
			cont_asistentes++;
		}
	}
	
	/// CARGA DE DATOS 
	cout << "Ingrese DNI: " << endl << ">";
	cin >> dni;
	int total = asistencia(dni, info, cont_asistentes);
	if (total != -1){
		info[total].asistencia++;
	}
	while (dni != 0){
		cin.ignore();
		cout << "Ingrese codigo de curso: " << endl << ">";
		getline(cin, cod);
		int pos = buscador(cod, datos, cont_cursos);
		if (pos != -1){
			cout << "Ingrese codigo de participacion: " << endl << ">";
			cin >> codigoparticipacion;
			if (codigoparticipacion == 1){
				datos[pos].investigadores++;
			} else if (codigoparticipacion == 2){
				datos[pos].profesionales++;
			} else if (codigoparticipacion == 3){
				datos[pos].productores++;
			}
			datos[pos].total_curso++;
		} else {
			cout << "NO ME VAS A CAGAR MOGUL, NO SEAS CORNETA, INGRESA UN CODIGO QUE EXISTA" << endl;
		}
		cout << "Ingrese DNI: " << endl << ">";
		cin >> dni;
	}
	
	/// INFORME 1
	cout << "CODIGO DE CURSO" << setw(24) << "Nombre Curso" << setw(24) << "Cant. Investigadores" << setw(24) <<"Cant. Profesionales" << setw(24) << "Cant. Productores" << setw(24) << "Cant. Total" << endl;
	for (int i = 0; i < cont_cursos; i++){
		cout << datos[i].codigo << setw(24) << datos[i].nombre << setw(24) << datos[i].investigadores << setw(24) << datos[i].profesionales << setw(24) << datos[i].productores << setw(24) << datos[i].total_curso << endl;
	}
	
	/// INFORME 2
	int caracter_participacion;
	string codigo = "";
	int mas_asistentes = funcionfinal(datos, cont_cursos, caracter_participacion, codigo);
	cout << "EL NUMERO ES DE: " << mas_asistentes << " CON EL CODIGO " << codigo << " Y EN EL CARACTER DE PARTICIPACION " << caracter_participacion << endl;
	
	ofstream archivo2;
	archivo2.open("./no_asistentes.txt");
	for (int i = 0; i < cont_asistentes; i++){
		if (info[i].asistencia == 0){
			archivo2 << info[i].dni << " " << info[i].nya << endl;
		}
	}
	return 0;
}

int buscador(string codigo, cursos datos[], int contador){
	for (int i = 0; i < contador; i++){
		if (codigo == datos[i].codigo){
			return i;
		}
	}
	return -1;
}
	
int funcionfinal(cursos datos[], int contador, int &caracter_participacion, string &codigo){
	int mayor = 0;
	for (int  i = 0; i < contador; i++){
		if (datos[i].investigadores > mayor){
			mayor = datos[i].investigadores;
			caracter_participacion = 1;
			codigo = datos[i].codigo;
		}
		if (datos[i].profesionales > mayor){
			mayor = datos[i].profesionales;
			caracter_participacion = 2;
			codigo = datos[i].codigo;
		}
		if (datos[i].profesionales > mayor){
			mayor = datos[i].profesionales;
			caracter_participacion = 3;
			codigo = datos[i].codigo;
		}
	}
	return mayor;
}

int asistencia(int dni, asistentes info[], int contador){
	for (int i = 0; i < contador; i++){
		if (dni == info[i].dni){
			return i;
		}
	}
	return -1;
}
