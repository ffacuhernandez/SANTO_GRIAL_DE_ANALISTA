#include <iostream>
#include <stdlib.h>
using namespace std;

struct nodo{
	int dato;
	nodo *siguiente;
};

void agregar_pila(nodo *&pila, int n);
void sacar_pila(nodo *&pila, int &n);

int main(int argc, char *argv[]) {
	nodo *pila = NULL;
	int dato;
	cout << "Ingrese un dato: " << endl << ">";
	cin >> dato;
	agregar_pila(pila, dato);
	
	cout << "Ingrese otro dato: " << endl << ">";
	cin >> dato;
	agregar_pila(pila, dato);
	
	cout << "Sacando elementos de la pila: " << endl;
	while (pila != NULL){
		sacar_pila(pila, dato);
		if (pila != NULL){
			cout << dato << " , ";
		} else{
			cout << dato << ".";
		}
	}
	return 0;
}

void agregar_pila(nodo *&pila, int n){
	nodo *nuevo_nodo = new nodo();
	nuevo_nodo->dato = n;
	nuevo_nodo->siguiente = pila;
	pila = nuevo_nodo;
	
	cout << "Elemento " << n << " agregado a la pila" << endl;
}

void sacar_pila(nodo *&pila, int &n){
	nodo *aux = pila;
	n = aux->dato;
	pila = aux->siguiente;
	delete aux;
}
	
