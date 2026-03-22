#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

/// STRUCTS
struct empleados{
	string id;
	string apellido;
	string nombre;
	string fecha;
	int experiencia;
	string codeproyecto;
};

struct proyecto{
	string codigo;
	string nombreproyecto;
	string area;
	int contador1 = 0;
	int contador2 = 0;
};

///FUNCIONES
int buscador(string codigo, empleados datos[], int contador);
string busca_area(string codigo, proyecto info[], int contador);
int busca_proyecto(string codigo, proyecto info[], int contador);

int main(int argc, char *argv[]) {
	
	/// VARIABLES
	empleados datos[500];
	proyecto info[500];
	empleados nuevos[500];	//OBS ????
	
	int cont_empleados = 0;
	int cont_proyectos = 0;
	int cont_nuevos = 0;
	int cont_calculo = 0;
	string code;
	string dia;
	string cod_proyecto;
	
	ifstream archivo;
	archivo.open("empleados.txt");
	if (archivo.fail()){
		return 1;
	} else {
		while (getline(archivo, datos[cont_empleados].id)){
			getline(archivo, datos[cont_empleados].apellido);
			getline(archivo, datos[cont_empleados].nombre);
			getline(archivo, datos[cont_empleados].fecha);
			archivo >> datos[cont_empleados].experiencia;
			archivo.ignore();
			getline(archivo, datos[cont_empleados].codeproyecto);
			cont_empleados++;
		}
	}
	archivo.close();
	archivo.open("proyectos.txt");
	if (archivo.fail()){
		return 1;
	} else {
		while (getline(archivo, info[cont_proyectos].codigo)){
			getline(archivo, info[cont_proyectos].nombreproyecto);
			getline(archivo, info[cont_proyectos].area);
			cont_proyectos++;
		}
	}
	archivo.close();
	
	/// PUNTO A
	cout << "Ingrese dia: " << endl << ">";
	getline(cin, dia);
	cout << "Ingrese ID de empleado: " << endl << "<";
	getline(cin, code);
	while (code != "0"){
		int pos  = buscador(code, datos, cont_empleados);
		if (pos != -1){ // LO ENCONTRO
			//OBS... TODO ESTO ESTA EN EL "THEN" Y EN EL "ELSE" O SEA, DEBERIA ESTAR AFUERA DEL IF DIRECTAMENTE
			cout << "Ingrese codigo de proyecto: " << endl << ">";
			getline(cin, cod_proyecto);
			int posicion = busca_proyecto(cod_proyecto, info, cont_proyectos);
			if (dia < "15"){
				info[posicion].contador1++;
			} else{
				info[posicion].contador2++;
			}
			//FIN OBS...
			datos[pos].codeproyecto = cod_proyecto;
			string nuevafecha = "202401" + dia;
			datos[pos].fecha = nuevafecha;
		} else {
			nuevos[cont_nuevos].id = code;
			cout << "Ingrese el apellido: " << endl << ">";
			getline(cin, nuevos[cont_nuevos].nombre);
			cout << "Ingrese el nombre: " << endl << ">";
			getline(cin, nuevos[cont_nuevos].apellido);
			cout << "Ingrese la fecha asignacion al proyecto: " << endl << ">";
			getline(cin, nuevos[cont_nuevos].fecha);
			cout << "Ingrese los a�os de experiencia: " << endl << ">";
			cin >> nuevos[cont_nuevos].experiencia;
			cin.ignore();
			//OBS... TODO ESTO ESTA EN EL "THEN" Y EN EL "ELSE" O SEA, DEBERIA ESTAR AFUERA DEL IF DIRECTAMENTE
			cout << "Ingrese el codigo proyecto al cual fue asignado: " << endl << ">";
			getline(cin, nuevos[cont_nuevos].codeproyecto);
			int posicion2 = busca_proyecto(nuevos[cont_nuevos].codeproyecto, info, cont_proyectos);
			if (dia < "15"){
				info[posicion2].contador1++;
			} else{
				info[posicion2].contador2++;
			}
			//FIN OBS...
			cont_nuevos++;
		}
		cout << "Ingrese dia: " << endl << ">";
		cin >> dia;
		cin.ignore();
		cout << "Ingrese ID del empleado: " << endl << ">";
		getline(cin, code);
	}
	
	/// PUNTO B
	int total_empleados = cont_empleados + cont_nuevos;
	for (int i = 0; i < cont_empleados; i++){
		string indice = busca_area(datos[i].codeproyecto, info, cont_proyectos); //ERR aca es donde se te complico usar 2 arreglos separados.. solamente estas contando los del archivo
		if (indice != "no existente"){
			if ((datos[i].experiencia > 3) && (indice == "Disenio Interfaz de Usuario")){
				cont_calculo++;
			}
		}
	}
	float porcentaje = (cont_calculo * 100) / total_empleados;	//ERR aca se te acarrea el mismo error
	cout << "EL PORCENTAJE DE EMPLEADOS CON MAS DE 3 ANIOS Y LA AREA DE DISENIO DE INTERFAZ DE USUARIO ES :  " << porcentaje << "%" <<  endl;
	
	/// PUNTO C
	cout << "Cod. Proyecto" << setw(39) << "Area de especializacion" << setw(29) << "Quincena 1" << setw(22) << "Quincena 2" << endl;
	for (int i = 0; i < cont_proyectos; i++){
		cout << info[i].codigo << setw(50) << info[i].area << setw(20) << info[i].contador1 << setw(20) << info[i].contador2 << endl;
	}
	
	return 0;
}

int buscador(string codigo, empleados datos[], int contador){
	for (int i = 0; i < contador; i++){
		if (codigo == datos[i].id){
			return i;
		}
	}
	return -1;
}
	
string busca_area(string codigo, proyecto info[], int contador){
	for (int i = 0; i < contador; i++){
		if (codigo == info[i].codigo){
			string area = info[i].area;
			return area;
		}
	}
	return "no existente";
}
	
int busca_proyecto(string codigo, proyecto info[], int contador){
	for (int i = 0; i < contador; i++){
		if (codigo == info[i].codigo){
			return i;
		}
	}
	return -1;
}
