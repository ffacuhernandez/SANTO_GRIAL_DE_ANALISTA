#include <iostream>
#include <stdlib.h>
using namespace std;

struct nodo{
	int dato;
	nodo *siguiente;
};

void insertar_cola(nodo *&frente, nodo*&fin, int);
bool cola_vacia (nodo *frente);
void sacar_cola(nodo *&frente, nodo *&fin, int &n);

int main(int argc, char *argv[]) {
	nodo *frente = NULL;
	nodo *fin = NULL;
	int num, dato;
	do {
		cout << "MENU DE OPCIONES" << endl;
		cout << "1: INSERTAR UN NUMERO A LA COLA" << endl;
		cout << "2: MOSTRAR TODOS LOS ELEMENTOS DE LA COLA" << endl;
		cout << "3: SALIR" << endl;
		cout << "--------------" << endl;
		cout << "ELIGE UNA OPCION: " << endl << ">";
		cin >> num;
		
		switch (num){
		case 1:
			cout << "Ingrese el caracter para agregar: " << endl << ">";
			cin >> dato;
			insertar_cola(frente, fin, dato);
			break;
		case 2: 
			cout << "SACANDO ELEMENTOS DE LA COLA: " << endl;
			while (frente != NULL){
				sacar_cola(frente, fin, dato);
				if (frente != NULL){
					cout << dato << ",";
				} else{
					cout << dato << ".";
				}
				cout << "Dato: " << dato << ", Frente: " << frente << ", Fin: " << fin << endl;
				
			}
			break;
		case 3: break;
		}
		cout << endl;
	} while (num != 3);
	return 0;
}

void insertar_cola(nodo *&frente, nodo*&fin, int n){
	nodo *nuevo_nodo = new nodo();
	nuevo_nodo->dato = n;
	nuevo_nodo->siguiente = NULL;
	if (cola_vacia(frente)){
		frente = nuevo_nodo;
		fin = nuevo_nodo;
	} else {
		fin -> siguiente = nuevo_nodo;
	}
}

bool cola_vacia (nodo *frente){
	return (frente == NULL)? true: false;
}
	
void sacar_cola(nodo *&frente, nodo *&fin, int &n){
	n = frente -> dato;
	nodo *aux = frente;
	if (frente == fin){
		frente = NULL;
		fin = NULL;
	} else{
		frente = frente -> siguiente;
	}
	delete aux;
}
	
