#include <iostream>
#include <stdlib.h>
#include <fstream>
using namespace std;

// RAMIREZ - HERNANDEZ - GERVASONI
/* ACTIVAD 7:  Se requiere desarrollar un programa en C++ que gestione registros de personas
almacenados en un archivo de texto llamado datos.txt. El programa debe realizar las siguientes operaciones:
1- Leer los datos del archivo datos.txt y almacenarlos en un array dinámico de
registros de personas.
2 - Determinar y mostrar por pantalla el año de nacimiento mínimo, el año de
nacimiento máximo y el total de registros leídos.*/

struct persona{
	int id;
	int anio;
	string nombre;
};

void acortarVector(persona* &p, int cant);
int leerAlmacenar(persona* &p, int cant);
void mostrarDatos(persona *p, int cant);

int main(int argc, char *argv[]) {
	int cantPersonas = 0;
	persona* p;
	
	cantPersonas = leerAlmacenar(p,cantPersonas);
	mostrarDatos(p,cantPersonas);
	
	delete[] p;
	
	return 0;
}

void acortarVector(persona* &p, int cant){
	persona *aux = new persona[cant];
	for (int i = 0; i < cant; i++){
		aux[i] = p[i];
	}
	delete[] p;
	p = aux;
}

int leerAlmacenar(persona* &p, int cant){
	int i = 0;
	int max = 999;
	string texto;
	//Creacion del arreglos dinamico.
	p = new persona[max];

	//Lectura del archivo
	ifstream archivo;
	archivo.open("datos2.txt");
	
	if(archivo.fail()){
		cout<<"El archivo fallo";
		exit(1);
	}
	
	while(archivo >> p[i].id >> p[i].anio){
		archivo.ignore();
		getline(archivo,p[i].nombre);
		cout<<p[i].id <<" "<< p[i].anio << " " << p[i].nombre <<endl;
		i++;
	}
	
	if (i < max)
		acortarVector(p, i);
	
	archivo.close();
	return i;
}
	
void mostrarDatos(persona *p, int cant){
	int min = p[0].anio;
	int max = p[0].anio;
	
	for(int i = 1; i < cant; i++){
		if(min > p[i].anio){
			min = p[i].anio;
		}
		
		if(max < p[i].anio){
			max = p[i].anio;
		}
	}
	
	cout<<endl<<"Año de nacimieno minimo: "<<min<<endl;
	cout<<"Año de nacimieno maximo: "<<max<<endl;
	cout<<"Cantidad de personas registradas: "<<cant<<endl;
	
}
