#include <iostream>
#include <iomanip>
using namespace std;


/// ESTRUCTURA DE DATOS
struct Indices{
	int clave;
	int direccion;
};

struct Datos{
	int clave;
	string dato;
	int direccion;
};

/// ALGORITMO PARA LA INSERCION
void insercion(int c, string d, Indices* indices, Datos* datos){ 
	
}


/// ALGORITMO PARA LA CONSULTA
void consulta(int c, Indices* indices, Datos* datos){
	bool encontrado = false;
	for (int i = 0; i < 3; i++){
		if (c >= indices[i].clave &&( i == 2 || c < indices[i + 1].clave)){
			int direccion = indices[i].direccion;
			for (int j = direccion; j < direccion + 4; j++){
				if (datos[j].clave == c) {
					cout << "CLAVE ENCONTRADA: " << datos[j].clave << "\n";
					cout << "DATOS DEL REGISTRO: " << datos[j].dato << "\n";
					encontrado = true;
					return;
				}
			}
		}
	}
	if (!encontrado) {
		cout << "CLAVE NO ENCONTRADA\n";
	}
}
	
/// MENU PARA ELEGIR EL ALGORITMO
void menu(Indices* indices, Datos* datos){
	int opcion, clave;
	string dato;
	cout << " --> MENU <--\n";
	cout << "1 - REALIZAR UNA CONSULTA\n";
	cout << "2 - REALIZAR UNA INSERCION\n";
	cout << "3 - SALIR\n";
	cout << "ELIGA UNA OPCION:\n" << ">";
	cin >> opcion;
	while (opcion != 3){
		switch(opcion){
		case 1:
			cout << "INGRESE LA CLAVE A BUSCAR:\n";
			cin >> clave;
			consulta(clave, indices, datos);
			break;
		case 2:
			cout << "INGRESE LA CLAVE DEL REGISTRO:\n";
			cin >> clave;
			cin.ignore();
			cout << "INGRESE EL DATO DEL REGISTRO\n";
			getline(cin,dato);
			insercion(clave, dato, indices, datos);
			break;
		}
		cout << "1 - REALIZAR UNA CONSULTA\n";
		cout << "2 - REALIZAR UNA INSERCION\n";
		cout << "3 - SALIR\n";
		cout << "ELIGA UNA OPCION:\n";
		cin >> opcion;
	}
}		
	
int main(int argc, char *argv[]) {
	
	/// PARAMETROS QUE SON DADOS
	const int n = 4;
	const int OVER = 12;
	const int OMAX = 19;
	
	/// CALCULOS
	int bloques = OVER / n; // Van a ser 3 bloques de 4 elementos cada uno
	const int PMAX = OVER - 1; // Nos rompimos la cabeza pensando esto
	
	/// DEFINIMOS LOS ARREGLOS
	Indices* indices = new Indices[bloques];
	Datos* datos = new Datos[OMAX];
	
	/// EMPEZAMOS TODAS LAS CLAVES EN 0, VACIAS
	for (int i = 0; i < OMAX; i++){
		datos[i].clave = 0;
	}
	
	cout << setw(90) <<  " <---- SE CREARON LOS ARREGLOS CON LOS SIGUIENTES DATOS ---->\n";
	cout << setw(67) << " <---- DATOS POR BLOQUE: " << n << " ---->\n";
	cout << setw(69) << " <---- COMIENZO DEL OVERFLOW: " << OVER << " ---->\n";
	cout << setw(76) << " <---- TAMANIO MAXIMO DEL ARREGLO DE DATOS: " << OMAX << " ---->\n";
	
	///MENU PARA COMENZAR CON LOS ALGORITMOS
	menu(indices, datos);
	
	/// LIBERAR LA MEMORIA AL PINGO
	delete[] indices;
	delete[] datos;
	
	return 0;
}
