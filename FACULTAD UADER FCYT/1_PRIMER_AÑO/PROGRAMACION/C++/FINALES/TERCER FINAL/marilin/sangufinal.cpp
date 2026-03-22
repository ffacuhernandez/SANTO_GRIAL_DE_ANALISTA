#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

/// STRUCT
struct gimnasio{
	int dni;
	string nya;
	string fecha;
	int entrenamiento;
	string situacion = "Alta";
	int antiguedad;
	bool no_participa = false;
};

/// FUNCIONES
int calcula_antiguedad(string fecha);
int buscador(int dni, gimnasio nuevos[], int contador);
void ordenador(gimnasio viejos[], int contador);
void ordenagod(gimnasio nuevos[], int contador);
int mewing(int dni, gimnasio viejos[],int contador);

/// MAIN
int main(int argc, char *argv[]) {
	
	/// VARIABLES
	gimnasio viejos[500];
	gimnasio nuevos[500];
	int cont_viejos = 0;
	int cont_nuevos = 0;
	
	/// LECTURA DE ARCHIVOS
	ifstream archivo;
	archivo.open("./ALUMNOS.txt");
	if (archivo.fail()){
		return -1;
	} else {
		while (archivo >> viejos[cont_viejos].dni){
			archivo.ignore();
			getline(archivo, viejos[cont_viejos].nya);
			getline(archivo, viejos[cont_viejos].fecha);
			archivo >> viejos[cont_viejos].entrenamiento;
			cont_viejos++;
		}
	}
	archivo.close();
	archivo.open("./ACTUALIZACION.txt");
	if (archivo.fail()){
		return -1;
	} else {
		while (archivo >> nuevos[cont_nuevos].dni){
			archivo.ignore();
			getline(archivo, nuevos[cont_nuevos].nya);
			archivo >> nuevos[cont_nuevos].entrenamiento;
			archivo.ignore();
			getline(archivo,nuevos[cont_nuevos].fecha);
			getline(archivo,nuevos[cont_nuevos].situacion);
			cont_nuevos++;
		}
	}
	archivo.close();
	
	/// BUSCAR LOS DNI`S DEL PRIMER ARCHIVO EN EL SEGUNDO, ASI ACTUALIZAMOS SU INFO
	for (int i = 0; i < cont_viejos; i++){
		int pos = buscador(viejos[i].dni, nuevos, cont_nuevos);
		if (pos != -1){
			viejos[i].situacion = nuevos[pos].situacion;
		}
	}
	
	/// CALCULAMOS LA ANTIGUEDAD
	for (int i = 0; i < cont_viejos; i++){
		viejos[i].antiguedad = calcula_antiguedad(viejos[i].fecha);
	}
	for (int i = 0; i < cont_nuevos; i++){
		nuevos[i].antiguedad = calcula_antiguedad(nuevos[i].fecha);
	}
	
	/// ORDENAMOS
	ordenador(viejos, cont_viejos);
	ordenagod(nuevos, cont_nuevos);
	
	/// INFORME 1 
	cout << setw(5) << "DNI" << setw(34) << "NOMBRE Y APELLIDO" << setw(28) << "ANTIGUEDAD (en meses)" << endl;
	for (int i = 0; i < cont_viejos; i++){
		if ((viejos[i].antiguedad >= 6) && (viejos[i].situacion == "Alta")){
			cout << viejos[i].dni << setw(28) << viejos[i].nya << setw(20) << viejos[i].antiguedad << endl;
		} else{
		viejos[i].no_participa = true;
		}
	}
	for (int i = 0; i < cont_nuevos; i++){
		if ((nuevos[i].antiguedad >= 6) && (nuevos[i].situacion == "Alta")){
			cout << nuevos[i].dni << setw(28) << nuevos[i].nya << setw(20) << nuevos[i].antiguedad << endl;
		}else{
			nuevos[i].no_participa = true;
		}
	}
	
	cout << "--------------------------------------------------------" << endl;
	
	///INFORME 2
	int matriz[5][5] = {0};
	for (int i = 0; i < cont_viejos; i++){
		if (viejos[i].situacion == "Alta"){
			int indice = viejos[i].entrenamiento - 1;
			if (viejos[i].antiguedad >= 31)
				matriz[indice][4]++;
			else if (viejos[i].antiguedad >= 25)
				matriz[indice][3]++;
			else if (viejos[i].antiguedad >= 19)
				matriz[indice][2]++;
			else if (viejos[i].antiguedad >= 13)
				matriz[indice][1]++;
			else if (viejos[i].antiguedad >= 6)
				matriz[indice][0]++;
		}
	}
	
	for (int i = 0; i < cont_nuevos; i++){
		if (nuevos[i].situacion == "Alta"){
			int indice = nuevos[i].entrenamiento - 1;
			if (nuevos[i].antiguedad >= 31)
				matriz[indice][4]++;
			else if (nuevos[i].antiguedad >= 25)
				matriz[indice][3]++;
			else if (nuevos[i].antiguedad >= 19)
				matriz[indice][2]++;
			else if (nuevos[i].antiguedad >= 13)
				matriz[indice][1]++;
			else if (nuevos[i].antiguedad >= 6)
				matriz[indice][0]++;
		}
	}
	
	cout << setw(80) << "6 a 12     13 a 18     19 a 24     25 a 30     31 a 36" << endl; 
	string entrenamiento[] = {"Semipersonalizado","Personalizado","Funcional","Crossfit","Calistenia"};
	for (int i = 0; i < 5; i++){
		cout << setw(20) << entrenamiento[i] << setw(9);
		for (int j = 0; j < 5; j++){
			cout << matriz[i][j] << setw(12);
		}
		cout << endl;
	}	
	
	/// CREACION DEL TXT, SOLO LIBRES
	ofstream archivo2;
	archivo2.open("alumnos_que_no_participan");
	for (int i = 0; i < cont_viejos; i++){
		if (viejos[i].no_participa == true){
			if (viejos[i].antiguedad < 6){
				archivo2 << viejos[i].dni << " " << viejos[i].nya << " " << "ANTIGUEDAD INSUFICIENTE" << endl;
			} else {
				archivo2 << viejos[i].dni << " " << viejos[i].nya << " " << "BAJA" << endl;
			}
		}
	}
	for (int i = 0; i < cont_nuevos; i++){
		if (nuevos[i].no_participa == true){
			int pos2 = mewing(nuevos[i].dni, viejos, cont_viejos);
			if (pos2 == -1){
				if (nuevos[i].antiguedad < 6){
					archivo2 << nuevos[i].dni << " " << nuevos[i].nya << " " << "ANTIGUEDAD INSUFICIENTE" << endl;
				} else {
					archivo2 << nuevos[i].dni << " " << nuevos[i].nya << " " << "BAJA" << endl;
				}
			}
		}
	}
	archivo.close();
	return 0;
}


/// FUNCIONES
int buscador(int dni, gimnasio nuevos[], int contador){
	for (int i = 0; i < contador; i++){
		if (dni == nuevos[i].dni){
			return i;
		}
	}
	return -1;
}
	
int calcula_antiguedad(string fecha){
	int antiguedad = 0;
	int anio_actual = 2023;
	int mes_actual = 10;
	int anio = stoi(fecha.substr(0, 4));
	int mes = stoi(fecha.substr(4, 2));
	if (anio < 2023){
		antiguedad = (anio_actual - anio) * 12;
		antiguedad += (mes_actual - mes);
	} else {
		antiguedad = mes_actual - mes;
	}
	return antiguedad;
}

void ordenador(gimnasio viejos[], int contador){
	for (int i = 0; i < contador - 1; i++){
		for (int j = i + 1; j < contador; j++){
			if (viejos[i].antiguedad < viejos[j].antiguedad){
				gimnasio aux = viejos[i];
				viejos[i] = viejos[j];
				viejos[j] = aux;
			}
		}
	}
}
void ordenagod(gimnasio nuevos[], int contador){
	for (int i = 0; i < contador - 1; i++){
		for (int j = i + 1; j < contador; j++){
			if (nuevos[i].antiguedad < nuevos[j].antiguedad){
				gimnasio aux = nuevos[i];
				nuevos[i] = nuevos[j];
				nuevos[j] = aux;
			}
		}
	}
}

int mewing(int dni, gimnasio viejos[],int contador){
	for (int i = 0; i < contador; i++){
		if (dni == viejos[i].dni){
			return i;
		}
	}
	return -1;
}
