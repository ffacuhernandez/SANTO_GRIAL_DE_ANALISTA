#include <iostream>
#include <stdlib.h>
using namespace std;

struct nodo{
	int dato;
	nodo *siguiente;
};

void agregarpila(nodo *&pila, int n);
void sacarpila(nodo *&pila, int &n);

int main(int argc, char *argv[]) {
	nodo *pila = NULL;
	int dato;
	cout << "Digite un numero: " << endl << ">";
	cin >> dato;
	agregarpila(pila, dato);
	cout << "Digite otro numero: " << endl << ">";
	cin >> dato;
	agregarpila(pila, dato);
	
	cout << "Sacando elementos de la pila: " << endl;
	while(pila != NULL){ /// MIENTRAS NO SEA EL FINAL DE LA PILA
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
	nodo *nuevo_nodo = new nodo(); /// CREAR EL ESPACIO EN MEMORIA PARA ALMACENAR UN 
	nuevo_nodo -> dato = n; /// CARGAR EL VALOR DENTRO DEL NODO (DATO)
	nuevo_nodo -> siguiente = pila; /// CARGAR EL PUNTERO PILA DENTRO DEL NODO
	pila = nuevo_nodo; /// ASIGNAR EL NUEVO NODO A LA PILA
}
	
void sacarpila(nodo *&pila, int &n){
	nodo *aux = pila;
	n = aux -> dato;
	pila = aux -> siguiente;
	delete aux;
}
