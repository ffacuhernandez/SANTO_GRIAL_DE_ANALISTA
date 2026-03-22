#include <iostream>
#include <iomanip>
#include <stdlib.h>
using namespace std;

struct nodo{
	char dato;
	nodo *siguiente;
};

void insertarcola(nodo *&frente, nodo *&fin, char n);
bool colavacia(nodo *frente);
void suprimircola(nodo *&frente, nodo *&fin, char &n);

int main(int argc, char *argv[]) {
	
	nodo *frente = NULL;
	nodo *fin = NULL;
	
	int opcion;
	char dato;
	
	while (opcion != 3){
		cout << "------------------ MENU ------------------" << endl;
		cout << "1)Insertar caracter a la cola: " << endl;
		cout << "2)Mostrar todos los elementos de la cola" << endl;
		cout << "3)SALIR" << endl << ">";
		cin >> opcion;
		
		switch (opcion){
		case 1: cout << "Ingrese el caracter para agregar a la cola: " << endl << ">";
			cin >> dato;
			insertarcola(frente, fin, dato);
			break;
		case 2: cout << "Sacando los elementos de la cola: " << endl;
			while(frente != NULL){
				suprimircola(frente, fin, dato);
				if (frente != NULL){
					cout << dato << ",";
				} else {
					cout << dato << "." << endl;
				}
			}
			break;
		case 3: break;
		}
	}
	return 0;
}

/// FUNCION INSERTAR ELEMENTOS
void insertarcola(nodo *&frente, nodo *&fin, char n){
	nodo *nuevo_nodo = new nodo();
	nuevo_nodo -> dato = n;
	nuevo_nodo -> siguiente = NULL;
	
	if (colavacia(frente)){
		frente = nuevo_nodo;
	} else {
		fin -> siguiente = nuevo_nodo;
	}
	fin = nuevo_nodo;
}
	
/// DETERMINAR SI COLA ESTA VACIA
bool colavacia(nodo *frente){
	return (frente == NULL)? true : false;
}
	
/// SACAR ELEMENTOS DE LA COLA
void suprimircola(nodo *&frente, nodo *&fin, char &n){
	n = frente -> dato;
	nodo *aux = frente;
	
	if(frente == fin){
		frente = NULL;
		fin = NULL;
	} else{
		frente = frente -> siguiente;
	}
	delete aux;
}
