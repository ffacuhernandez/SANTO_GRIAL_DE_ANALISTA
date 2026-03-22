#include <iostream>
#include <fstream>
using namespace std;

/// STRUCT 
struct pacientes{
	int dni;
	string apellido;
	string nombre;
	string fechanac;
	string obrasocial;
	string descriobra;
	string codigopat;
	string descripat;
};

///FUNCIONES
int buscapaciente(int dni, pacientes datos[], int contador);
string cortadora(string codigo);

int main(int argc, char *argv[]) {
	pacientes datos[500];
	pacientes patologias[24];
	pacientes nuevos[500];
	
	/// VARIABLES
	int cont_pacientes = 0;
	int cont_patologias = 0;
	int cont_nuevos = 0;
	int dia;
	int dni;
	string codigo;
	
	/// LECTURA TXT
	ifstream archivo;
	archivo.open("pacientes.txt");
	if (archivo.fail()){
		cout << "No se encontro el archivo";
		return 1;
	} else {
		while (archivo >> datos[cont_pacientes].dni){
			archivo.ignore();
			getline(archivo,datos[cont_pacientes].apellido);
			getline(archivo,datos[cont_pacientes].nombre);
			getline(archivo,datos[cont_pacientes].fechanac);
			getline(archivo,datos[cont_pacientes].obrasocial);
			getline(archivo,datos[cont_pacientes].codigopat);
			cont_pacientes++;
		}
	}
	archivo.close();
	archivo.open("pat_respi.txt");
	if (archivo.fail()){
		cout << "No se encontro el archivo";
		return 1;
	} else {
		while (getline(archivo,patologias[cont_patologias].codigopat)){
			getline(archivo,patologias[cont_patologias].descripat);
			cont_patologias++;
		}
	}
	
	/// CARGA DE DATOS
	cout << "Ingrese el dia: " << endl << ">";
	cin >> dia;
	while (dia != 99){
		cout << "Ingrese el dni del paciente: " << endl << ">";
		cin >> dni;
		int pos = buscapaciente(dni, datos, cont_pacientes);
		if (pos != -1){
			cout << "PACIENTE ENCONTRADO, ANASHEI!!!" << endl;
			cout << "Ingrese el codigo de patologia: " << endl << ">";
			cin >> codigo;
			string dosprimeras = cortadora(datos[pos].codigopat);
			if (dosprimeras == "VR"){
				cout << "CODIGO ANTERIOR QUE ARRANCA CON VR, SE CAMBIA POR EL NUEVO: " << codigo << endl;
				datos[pos].codigopat = codigo;
			} else {
				cout << "NO SE CAMBIA NADA MAN" << endl;
			}
		} else {
			cout << "Ingrese dni del paciente: " << ">" << endl;
			cin >> nuevos[cont_nuevos].dni;
			cin.ignore();
			cout << "Ingrese apellido: " << endl <<">";
			getline(cin,nuevos[cont_nuevos].apellido);
			cout << "Ingrese nombre/s: " << endl << ">";
			getline(cin,nuevos[cont_nuevos].nombre);
			cout << "Ingrese fecha de nacimiento (AAAAMMDD): " << ">";
			getline(cin,nuevos[cont_nuevos].fechanac);
			cout << "Ingrese obra social (S o N): " << endl << ">";
			getline(cin,nuevos[cont_nuevos].obrasocial);
			cout << "Ingrese descripcion de obra social: " << endl << ">";
			getline(cin,nuevos[cont_nuevos].descriobra);
			cout << "Ingrese codigo de patologia: " << endl << ">";
			getline(cin,nuevos[cont_nuevos].codigopat);
			cont_nuevos++;
		}
	}
	
	int total_gagas = 0; 
	for(int  i = 0; i < cont_pacientes; i++){
		string anios = datos[i].fechanac.substr(0, 4);
		int edad = stoi(anios);
		if ((edad > 60) && (datos[i].codigopat != "VR")){
			total_gagas++;
		}
	}
	
	for (int i = 0; i < cont_nuevos; i++){
		
	}
	return 0;
}

int buscapaciente(int dni, pacientes datos[], int contador){
	for (int i = 0; i < contador; i++){
		if (dni == datos[i].dni){
			return i;
		}
	}
	return -1;
}
	
string cortadora(string codigo){
	string cortado = codigo.substr(0, 2);
	return cortado;
}
