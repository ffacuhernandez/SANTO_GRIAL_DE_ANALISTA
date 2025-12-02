#include <iostream>
#include <stdlib.h>
using namespace std;

struct nodo{
	int dato;
	nodo *siguiente;
};

void insertarlista(nodo *&lista, int n);
void mostrarlista(nodo *lista);
void buscarlista(nodo *lista, int n);
void eliminarnodo(nodo *&lista, int n);
void eliminarlista(nodo *&lista, int &n);

int main(int argc, char *argv[]) {
	nodo *lista = NULL;
	int dato;
	int opcion;
	do {
		cout << "--------- MENU ---------" << endl;
		cout << "1)Insertar elemento a la lista" << endl;
		cout << "2)Mostrar los elementos de la lista" << endl;
		cout << "3)Buscar elemento en la lista" << endl;
		cout << "4)Eliminar un nodo de la lista" << endl;
		cout << "5)Vaciar lista/Eliminar lista" << endl;
		cout << "6)SALIR" << endl;
		cin >> opcion;
		switch(opcion){
		case 1: cout << "Digite un numero: " << endl << ">";
				cin >> dato;
				insertarlista(lista, dato);
			break;
		case 2: mostrarlista(lista);
				cout << endl;
			break;
		case 3: cout << "Ingrese un numero a buscar: " << endl;
				cin >> dato;
				buscarlista(lista, dato);
				cout << endl;
			break;
		case 4: cout << "Digite elemento que desea eliminar: " << endl;
				cin >> dato;
				eliminarnodo(lista, dato);
				cout << endl;
			break;
		case 5: while (lista != NULL){ //Mientras no sea el final de la lista
				eliminarlista(lista, dato);
				cout << dato << " ->";
			}
		cout << endl;
			break;
		case 6:break;
		}
	} while (opcion != 6);
	
	return 0;
}

void insertarlista(nodo *&lista, int n){
	nodo *nuevo_nodo = new nodo();
	nuevo_nodo -> dato = n;
	nodo *aux1 = lista;
	nodo *aux2;
	while ((aux1 != NULL) && (aux1 -> dato < n)){
		aux2 = aux1;
		aux1 = aux1 -> siguiente;
	}
	
	if (lista == aux1){
		lista = nuevo_nodo;
	} else {
		aux2 -> siguiente = nuevo_nodo;
	}
	nuevo_nodo -> siguiente = aux1;
}
	
void mostrarlista(nodo *lista){
	nodo *actual = new nodo();
	actual = lista;
	
	while (actual != NULL){
		cout << actual -> dato << " -> ";
		actual = actual -> siguiente;
	}
}

void buscarlista(nodo *lista, int n){
	bool band = false;
	nodo *actual = new nodo();
	actual = lista;
	
	while ((actual != NULL) && (actual -> dato <= n)){
		if (actual -> dato == n){
			band = true;
		}
		actual = actual -> siguiente;
	}
	
	if (band == true){
		cout << "Elemento " << n << " SI a sido encontrado en la lista" << endl;
	} else {
		cout << "Elemento " << n << " No a sido encontrado en la lista" << endl;
	}
}

void eliminarnodo(nodo *&lista, int n){
	//Preguntar si lista esta vacia
	if (lista != NULL){
		nodo *aux_borrar;
		nodo *anterior = NULL;
		
		aux_borrar = lista;
		
		//Recorrer la lista
		while ((aux_borrar != NULL) && (aux_borrar -> dato != n)){
			anterior = aux_borrar;
			aux_borrar = aux_borrar -> siguiente;
		}
		
		//Elemento no encontrado
		if (aux_borrar == NULL){
			cout << "ELEMENTO NO ENCONTRADO" << endl;
		} else if (anterior == NULL){
			lista = lista -> siguiente;
			delete aux_borrar;
		} else { // El elemento esta en la lista, pero no es el primer nodo
			anterior -> siguiente = aux_borrar -> siguiente;
			delete aux_borrar;
		}
	}
}

// Vaciar lista
void eliminarlista(nodo *&lista, int &n){
	nodo *aux = lista;
	n = aux -> dato;
	lista = aux -> siguiente;
	delete aux;
}
