#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

/// STRUCTS
struct productos{
	string codigo, fecha, hora;
	int meses;
};

/// FUNCIONES
void sabercodigo (productos datos[], int &codigopais, int contador);
int separador (string fecha, int &dia, int &mes);
string generar_cod(string codigo);
void ordenador(productos datos[], int contador);

int main(int argc, char *argv[]) {
	
	productos datos[500];
	int productos_vencidos[31][12] = {0};
	int cont_productos = 0, nacionales = 0, importados = 0;
	
	ifstream archivo;
	archivo.open("produc.txt");
	if (archivo.fail()){
		return 1;
	} else {
		while (getline(archivo,datos[cont_productos].codigo, ' ')){
			getline(archivo,datos[cont_productos].fecha, '-');
			getline(archivo,datos[cont_productos].hora, ' ');
			archivo >> datos[cont_productos].meses;
			archivo.ignore();
			cont_productos++;
		}
	}
	
	/// INFORME A
	for (int i = 0; i < cont_productos; i++){
		int code_parametro = 0;
		sabercodigo(datos, code_parametro, i);
		if (code_parametro == 779){
			nacionales++;
		} else{
			importados++;
		}
	}
	
	cout << "La cantidad de productos nacionales son " << nacionales << " y la cantidad de importados " << importados << endl;
	
	/// INFORME B
	for (int i = 0; i < cont_productos; i++){
		int dia = 0, mes = 0;
		int anio = separador(datos[i].fecha, dia, mes);
		int tiempo = datos[i].meses / 12;
		if ((anio + tiempo) == 2024){
			productos_vencidos[dia - 1][mes - 1]++;
		}
	}
	
	cout << setw(6) << " ";
	for (int i = 0; i < 12; i++){
		cout << setw(6) << i + 1;
	}
	cout << endl;
	for (int i = 0; i < 31; i++){
		cout << setw(6) << i + 1;
		for (int j = 0; j < 12; j++){
			cout << setw(6) << productos_vencidos[i][j];
		}
		cout << endl;
	}
	
	cout << "------------------------------------------------------------------" << endl;
	
	/// INFORME C EL NASHE
	for (int i = 0; i < cont_productos; i++){
		string digito = generar_cod(datos[i].codigo);
		datos[i].codigo += digito;
	}
	
	ordenador(datos, cont_productos); /// ORDENAMIENTO
	
	cout << "CODIGO DE BARRAS" << setw(21) << "FECHA Y HORA" << setw(35) << "TIEMPO VALIDEZ EN MESES" << endl;
	for (int i = 0; i < cont_productos; i++){
		cout << datos[i].codigo << setw(18) << datos[i].fecha << "-" << datos[i].hora << setw(23) << datos[i].meses << endl;
	}
	
	return 0;
}

void sabercodigo (productos datos[], int &codigopais, int contador){
	codigopais = stoi(datos[contador].codigo.substr(0,3)); 
}
	
int separador (string fecha, int &dia, int &mes){
	dia = stoi(fecha.substr(0,2));
	mes = stoi(fecha.substr(3,2));
	int anio = stoi(fecha.substr(6,4));
	return anio;
}

string generar_cod(string codigo){
	int suma = 0;
	int largo = codigo.size();
	for (int i = largo - 1; i >= 0; i--) {
		int digito = codigo[i] - '0'; // ESTO SIRVE PARA CONVERTIR EL CARACTER A NUMERO
		if ((largo - i) % 2 == 0) {
			suma += digito * 1;
		} else {
			suma += digito * 3;
		}
	}
	int docena = ((suma + 9) / 10) * 10;
	int digito_control = docena - suma;
	string resultado = to_string(digito_control); // PARA PASARLO A STRING DEVUELTA
	return resultado;
}

void ordenador(productos datos[], int contador){
	for (int i = 0; i < contador - 1; i++){
		for (int j = i + 1; j < contador; j++){
			if (datos[i].codigo < datos[j].codigo){
				productos aux = datos[i];
				datos[i] = datos[j];
				datos[j] = aux;
			}
		}
	}
}
