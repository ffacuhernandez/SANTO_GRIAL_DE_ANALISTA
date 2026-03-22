#include <iostream>
using namespace std;

struct nodo{
	int dato;
	nodo *siguiente;
};

void agregarpila(nodo *&pila, int dato);
void sacarpila(nodo *&pila, int &dato);

int main(int argc, char *argv[]) {
	nodo *pila = NULL;
	int dato;
	char decision;
	while(decision != 'N'){
		cout << "Ingrese un numero: " << endl << ">";
		cin >> dato;
		agregarpila(pila, dato);
		cout << "Va a ingresar otro dato a la pila S/N: " << endl << ">";
		cin >> decision;
	}
	
	cout << "Sacando elementos de pila: " << endl << ">";
	while (pila != NULL){
		sacarpila(pila, dato);
		if (pila != NULL){
			cout << dato << " , ";
		} else {
			cout << dato << ".";
		}
	}
	return 0;
}

void agregarpila(nodo *&pila, int n){
	nodo *nuevo_nodo = new nodo();
	nuevo_nodo -> dato = n;
	nuevo_nodo -> siguiente = pila;
	pila = nuevo_nodo;
}

void sacarpila(nodo *&pila, int &n){
	nodo *aux = pila;
	n = aux -> dato;
	pila = aux -> siguiente;
	delete aux;
}
