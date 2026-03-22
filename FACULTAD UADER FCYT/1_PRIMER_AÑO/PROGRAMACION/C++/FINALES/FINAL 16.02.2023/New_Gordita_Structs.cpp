#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

/// STRUCTS
struct pacientes{
	int dni;
	string fecha, ayn, obra_social, descrip_obra, codigo; 
};

struct patologias{
	string codigo_pat, descrip;
};


///FUNCIONES
int busqueda(int documento, int cont_pacientes, pacientes datos[]);
string extractor(pacientes datos[], int dato);


int main(int argc, char *argv[]) {
	
	pacientes datos[500];
	pacientes nuevos[500];
	patologias informacion[500];
	
	int cont_pacientes = 0, cont_patologias = 0, cont_nuevos = 0;
	float cont_cronicos = 0;
	
	int dia, dni, code;
	
	ifstream archivo;
	archivo.open("PACIENTES.txt");
	if (archivo.fail()){
		return 1;
	} else {
		while (archivo >> datos[cont_pacientes].dni){
			archivo.ignore();
			getline(archivo, datos[cont_pacientes].ayn);
			getline(archivo, datos[cont_pacientes].fecha);
			getline(archivo, datos[cont_pacientes].obra_social);
			getline(archivo, datos[cont_pacientes].descrip_obra);
			getline(archivo, datos[cont_pacientes].codigo);
			cont_pacientes++;
		}
	}
	archivo.close();
	archivo.open("PAT_RESPI.TXT");
	if (archivo.fail()){
		return 1;
	} else {
		while (getline(archivo, informacion[cont_patologias].codigo_pat)){
			getline(archivo, informacion[cont_patologias].descrip);
			cont_patologias++;
		}
	}
	
	/// CARGA DE DATOS
	cout << "Ingrese dia: " << endl << ">";
	cin >> dia;
	while (dia != 99){
		cout << "Ingrese DNI: " << endl << ">";
		cin >> dni;
		int dato = busqueda(dni, cont_pacientes, datos); /// BUSQUEDA PARA SABER SI EXISTE EL USUARIO
		if (dato != -1){
			cout << "PACIENTE ENCONTRADO" << endl;
			cout << "Ingrese codigo de patologia: " << endl << ">";
			cin >> code;
			string dosprimeras = extractor(datos, dato);  /// FUNCION EXTRACCION DE DATOS
			if (dosprimeras == "VR"){
				cout << "CODIGO DE PATOLOGIA VR, ENTONCES SE CAMBIA POR EL NUEVO CODIGO: " << code;
				datos[dato].codigo = code;
			} else {
				cout << "NO SE CAMBIA EL CODIGO" << endl;
			}
		} else {
			nuevos[cont_nuevos].dni = dni;
			cin.ignore();
			cout << "Ingrese apellido y nombre: " << endl << ">";
			getline(cin,nuevos[cont_nuevos].ayn);
			cout << "Ingrese fecha de nacimiento: " << endl << ">";
			getline(cin,nuevos[cont_nuevos].fecha);
			cout << "Ingrese obra social (S o N)" << endl << ">";
			getline(cin,nuevos[cont_nuevos].obra_social);
			cout << "Ingrese descripcion obra social: " << endl << ">";
			getline(cin, nuevos[cont_nuevos].descrip_obra);
			cout << "Ingrese codigo de patologia: " << endl << ">";
			getline(cin,nuevos[cont_nuevos].codigo);
			cont_nuevos++;
		}
		cout << "Ingrese dia: " << endl << ">";
		cin >> dia;
	}
	
	/// INFORME 1
	for (int i = 0; i < cont_pacientes; i++){
		int cortado = 2023 - stoi(datos[i].fecha.substr(0,4));
		string letras = datos[i].codigo.substr(0,2);
		if ((cortado > 60) && (letras != "VR")){
			cont_cronicos++;
		}
	}
	for (int i = 0; i < cont_nuevos; i++){
		int cortado = 2023 - stoi(nuevos[i].fecha.substr(0,4));
		string letras = nuevos[i].codigo.substr(0,2);
		if ((cortado > 60) && (letras != "VR")){
			cont_cronicos++;
		}
	}
	float total = (cont_cronicos / (cont_pacientes + cont_nuevos)) * 100;
	cout << "El total de pacientes con enfermades cronicas y mayores de 60 anios es: " << total << "%" << endl;
	
	/// INFORME 2
	cout << "CODIGO" << setw(20) << "DESCRIPCION" << setw(20) << "1 QUINCENA" << setw(20) << "2 QUINCENA" << endl;
	
	
	/// INFORME 3
	ofstream archivo2;
	archivo2.open("PACIENTES_NEW.txt");
	for (int i = 0; i < cont_pacientes; i++){
		archivo2 << datos[i].dni << endl;
		archivo2 << datos[i].ayn << endl;
		archivo2 << datos[i].fecha << endl;
		archivo2 << datos[i].obra_social << endl;
		archivo2 << datos[i].descrip_obra << endl;
		archivo2 << datos[i].codigo << endl;
	}
	
	for (int i = 0; i < cont_nuevos; i++){
		archivo2 << nuevos[i].dni << endl;
		archivo2 << nuevos[i].ayn << endl;
		archivo2 << nuevos[i].fecha << endl;
		archivo2 << nuevos[i].obra_social << endl;
		archivo2 << nuevos[i].descrip_obra << endl;
		archivo2 << nuevos[i].codigo << endl;
	}
	
	return 0;
}

int busqueda(int documento, int cont_pacientes, pacientes datos[]){
	for (int i = 0; i < cont_pacientes; i++){
		if (documento == datos[i].dni){
			return i;
		}
	}
	return -1;
}
	
string extractor(pacientes datos[], int dato){
	string recortadito = datos[dato].codigo.substr(0,2);
	return recortadito;
}
