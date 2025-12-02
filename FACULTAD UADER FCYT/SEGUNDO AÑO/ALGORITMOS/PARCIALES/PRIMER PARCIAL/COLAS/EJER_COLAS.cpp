#include <iostream>
#include <stdlib.h>
using namespace std;

struct nodo{
	int dato;
	nodo *siguiente;
};

void insertarlista(nodo *&lista, int n);
void mostrarlista(nodo *lista);
int calcularmayormenor(nodo *lista, int &menor);

int main(int argc, char *argv[]) {
	nodo *lista = NULL;
	int menor = 99999;
	int dato;
	char decision;
	do {
		cout << "Digite un numero: " << endl << ">";
		cin >> dato;
		insertarlista(lista, dato);
		cout << "Agregar otro nodo? (S/N)" << endl << ">";
		cin >> decision;
	} while (decision == 's');
	
	cout << "Elementos de la lista: " << endl;
	mostrarlista(lista);
	cout << endl;
	int masgrande = calcularmayormenor(lista,menor);
	cout << "El elemento mas grande es " << masgrande << " y el menor es " << menor << endl;
	return 0;
}

/// INSERTANDO NODOS DE FORMA QUE EL USUARIO QUIERA, NO EN ORDEN
void insertarlista(nodo *&lista, int n){
	nodo *nuevo_nodo = new nodo();
	nodo *aux;
	nuevo_nodo -> dato = n;
	nuevo_nodo -> siguiente = NULL;
	if (lista == NULL){ //SI LA LISTA ESTA VACIA
		lista = nuevo_nodo;
	} else {
		aux = lista; //aux apunta al inicio de la lista
		while (aux -> siguiente != NULL){
			aux = aux -> siguiente; //Avanza posiciones
		}
		aux -> siguiente = nuevo_nodo;
	}
}

void mostrarlista(nodo *lista){
	while (lista != NULL){ //Mientras no sea el final
		cout << lista -> dato << "->";
		lista = lista ->siguiente; //Avanzamos una posicion en la lista
	}
}

int calcularmayormenor(nodo *lista, int &menor){
	int mayor = 0;
	while (lista != NULL){ //Recorrer la lista
		if (lista -> dato > mayor){
			mayor = lista -> dato;
		}
		if (lista -> dato < menor){
			menor = lista -> dato;
		}
		lista = lista -> siguiente;
	}
	return mayor;
}
