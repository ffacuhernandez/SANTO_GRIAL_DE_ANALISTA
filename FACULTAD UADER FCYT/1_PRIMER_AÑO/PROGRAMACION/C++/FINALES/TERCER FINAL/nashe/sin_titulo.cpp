#include <iostream>
#include <fstream>
using namespace std;

///STRUCT 
struct info_gym{
	int dni;
	string nya;
	string fecha;
	int entrenamiento;
	string situacion;
	int antiguedad;
};

///FUNCIONES
int calcula_antiguedad(string fecha);

///MAIN
int main(int argc, char *argv[]) {
	
	info_gym alumnos[500];
	info_gym actualizacion[500];
	
	///VARIABLES
	int cont_alumnos = 0;
	int cont_actualizados = 0;
	
	/// LECTURA ARCHIVOS
	/// TXT ALUMNOS
	ifstream archivo;
	archivo.open("alumnos.txt");
	if (archivo.fail()){
		cout << "No se pudo encontrar el archivo";
		return 1;
	} else {
		while(archivo >> alumnos[cont_alumnos].dni){
			archivo.ignore();
			getline(archivo,alumnos[cont_alumnos].nya);
			getline(archivo,alumnos[cont_alumnos].fecha);
			archivo >> alumnos[cont_alumnos].entrenamiento;
			cont_alumnos++;
		}
	}
	archivo.close();
	
	/// TXT ACTUALIZACION
	archivo.open("actualizacion.txt");
	if (archivo.fail()){
		cout << "No se pudo abrir el txt";
		return 1;
	} else {
		while (archivo >> actualizacion[cont_actualizados].dni){
			archivo.ignore();
			getline(archivo,actualizacion[cont_actualizados].nya);
			archivo >> actualizacion[cont_actualizados].entrenamiento;
			archivo.ignore();
			getline(archivo,actualizacion[cont_actualizados].fecha);
			getline(archivo,actualizacion[cont_actualizados].situacion);
			cont_actualizados++;
		}
	}
	
	/// CALCULAR ANTIGUEDAD
	for (int i = 0; i < cont_actualizados; i++){
		actualizacion[i].antiguedad = calcula_antiguedad(actualizacion[i].fecha);
	}
	
	return 0;
}


int calcula_antiguedad(string fecha){
	int antiguedad = 0;
	int anio_actual = 2023;
	int mes_octubre = 10;
	int anio = stoi(fecha.substr(0, 4));
	int mes = stoi(fecha.substr(4, 2));
	if (anio < 2023){
		antiguedad = (anio_actual - anio) * 12;
		antiguedad += mes_octubre - mes;
	} else {
		antiguedad = mes_octubre - mes;
	}
	return antiguedad;
}
