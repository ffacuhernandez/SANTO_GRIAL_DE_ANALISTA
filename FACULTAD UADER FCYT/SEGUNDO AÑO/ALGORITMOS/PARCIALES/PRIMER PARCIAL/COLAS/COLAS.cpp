#include <iostream>
#include <stdlib.h>
using namespace std;

struct nodo{
	int dato;
	nodo *siguiente;
};

void insertarcola(nodo *&frente, nodo *&fin, int n);
bool colavacia(nodo *frente);
void suprimircola(nodo *&frente, nodo *&fin, int &n);

int main(int argc, char *argv[]) {
	nodo *frente = NULL;
	nodo *fin = NULL;
	
	int dato;
	
	cout << "Ingrese el numero para meter en la cola (iiiiiiii): " << endl << ">";
	cin >> dato;
	insertarcola(frente, fin, dato);
	cout << "Ingrese el numero para meter en la cola (iiiiiiii): " << endl << ">";
	cin >> dato;
	insertarcola(frente, fin, dato);
	cout << "Ingrese el numero para meter en la cola (iiiiiiii): " << endl << ">";
	cin >> dato;
	insertarcola(frente, fin, dato);
	
	/// SACANDO ELEMENTOS
	cout << "Sacando de la cola... " << endl;
	while(frente != NULL){
		suprimircola(frente, fin, dato);
		if (frente != NULL){
			cout <<  dato << ",";
		} else {
			cout << dato << ".";
		}
	}
	return 0;
}

void insertarcola(nodo *&frente, nodo *&fin, int n){
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
	
/// DETERMINAR SI COLA ESTA VACIA O NO
bool colavacia(nodo *frente){
	return (frente ==  NULL)? true : false;
}
	
void suprimircola(nodo *&frente, nodo *&fin, int &n){
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
