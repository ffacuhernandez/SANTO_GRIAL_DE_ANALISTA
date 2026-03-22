#include <iostream>
#include <fstream>
#include <string>
/*
	Resolucion by Chotawer
	Final 
*/

using namespace std;

/// struct
struct tambo{
	string nombre, pastura_utilizada;
	int vacas_2022, vacas_2023;
	float litros_2022 = 0, litros_2023 = 0;
	float produccion_2022, produccion_2023;
	int dia_mayor_prod_2022, dia_mayor_prod_2023;
};

struct produccion{
	int numero_tambo;
	int tipo_pastura; // Entendemos según el enunciado que nos pondrá el número
	float litros_2022 = 0;
	float litros_2023 = 0;
};

/// Funciones
void obtenerDiaMayor(produccion prod[],tambo tambos[]);
void ordenar(tambo tambos[]);

int main(int argc, char *argv[]) {
	produccion prod[30];
	tambo tambos[12];
	int indice;
	/// Lectura de datos
	ifstream archivo; archivo.open("./tambos.txt");
	if (archivo.fail())
		return 1;
	else
		while (archivo >> indice){
			archivo.ignore();  // No tenemos el archivo original, pero suponemos que esta uno debajo del otro.
			getline(archivo,tambos[indice-1].nombre);
		}
	archivo.close();
	
	archivo.open("./produccion.txt");
	if (archivo.fail())
		return 1;
	else
		while (archivo >> indice)
			archivo >> prod[indice-1].numero_tambo
				>> prod[indice-1].tipo_pastura
				>> prod[indice-1].litros_2022
				>> prod[indice-1].litros_2023;
	archivo.close();
	
	/// Carga de datos
	for (int i = 0; i < 10; i++){
		cout << "Ingrese número de tambo";
		cin >> indice; 	
		cout << "Cantidad de vacas 2022:";
		cin >> tambos[indice].vacas_2022;
		cout << "Cantidad de vacas 2023:";
		cin >> tambos[indice].vacas_2023;
	}
	
	/// Informe 1
	for (int i = 0; i < 28; i++){
		indice = prod[i].numero_tambo - 1;
		tambos[indice].litros_2022 += prod[i].litros_2022;
		tambos[indice].litros_2023 += prod[i].litros_2023;
	}
	// El enunciado no es claro, pero inferimos que se calcula así.
	for (int i = 0; i < 10; i++){
		tambos[i].produccion_2022 = (tambos[i].litros_2022 / tambos[i].vacas_2022) * 28;
		tambos[i].produccion_2023 = (tambos[i].litros_2023 / tambos[i].vacas_2023) * 28;
	}
	
	cout << "Febrero 2022\n";
	for (int i = 0; i < 10; i++) {
		
	}
	
	cout << "Febrero 2023\n";
	for (int i = 0; i < 10; i++) {
		
	}
	
	/// Informe 2
	obtenerDiaMayor(prod,tambos);
	
	cout << "Nombre del Tambo     Día Mayor Produccion del 2022    Día Mayor Produccion del 2023\n" ;
	for (int i = 0; i < 10; i++)
		cout << tambos[i].nombre << " " << tambos[i].produccion_2022 << " " << tambos[i].produccion_2023 << "\n";
	
	/// Informe 3
	
	/// Saber pastura
	for (int i = 0; i < 10; i++){
		if (prod[i].tipo_pastura == 1){
			tambos[i].pastura_utilizada = "PASTO OVILLO";
		} else {
			tambos[i].pastura_utilizada = "ALFALFA";
		}
	}
	ordenar(tambos);
	cout << "Nombre del tambo" << " " << "Tipo de pastura utilizada" << " " << "Productividad" << "\n";
	for (int i = 0; i < 10; i++)
		cout << tambos[i].nombre << " " << tambos[i].pastura_utilizada << " " << tambos[i].produccion_2023 << "\n";
	return 0;
}

void obtenerDiaMayor(produccion prod[], tambo tambos[]){
	for (int dia = 0; dia < 28; dia++){
		int max_2022 = 0, max_2023 = 0;
		if (prod[dia].litros_2022 > max_2022){
			max_2022 = prod[dia].litros_2022;
			int indice = prod[dia].numero_tambo - 1;
			tambos[indice].produccion_2022 = dia+1;	// Dia del mes
		}
		if (prod[dia].litros_2023 > max_2023){
			max_2023 = prod[dia].litros_2023;
			int indice = prod[dia].numero_tambo - 1;
			tambos[indice].produccion_2023 = dia+1;	// Dia del mes
		}
	}
}
	
void ordenar(tambo tambos[]){
	for (int i = 0; i < 10-1; i++){
		for (int j = i+1; j < 10; j++){
			if (tambos[i].produccion_2023 < tambos[j].produccion_2023){
				tambo aux = tambos[i];
				tambos[i] = tambos[j];
				tambos[j] = aux;
			}
		}
	}
	
}
