#include <iostream>
#include <string>

using namespace std;

struct pendejos {
	string nombre_pendejo;
	string nombre_progenitor;
	int edad;
	float distancia;
	int telefono;
	string salita;
};

struct nodoLDE {
	pendejos* dato;
	nodoLDE* siguiente;
	nodoLDE* anterior;
};

struct nodoPila {
	pendejos* dato;
	nodoPila* link;
};

void pilaAgregar(nodoPila* &pila, pendejos* dato) {
	nodoPila* nuevo_nodo = new nodoPila();
	nuevo_nodo->dato = dato;
	nuevo_nodo->link = pila;
	pila = nuevo_nodo;
}

void EliminarNodo(nodoLDE* &lista) {
	nodoLDE* aux = lista;
	if (lista->anterior == NULL) {
		lista = lista->siguiente;
		delete aux;
	} else {
		if (aux->siguiente != NULL)
			aux->siguiente->anterior = aux->anterior;
		aux->anterior->siguiente = aux->siguiente;
		delete aux;
	}
}

void funcionej1(nodoLDE* &lista) {
	nodoPila* salitaVerde = NULL;
	nodoPila* salitaNegra = NULL;
	nodoLDE* aux = lista;
	nodoLDE* aux2;
	while (aux != NULL) {
		aux2 = aux->siguiente;
		if (aux->dato->edad < 4 && aux->dato->edad > 2 && aux->dato->distancia > 2) {  // Modificado a distancia > 2 para Salita Verde
			pilaAgregar(salitaVerde, aux->dato);
			if (aux == lista) {
				EliminarNodo(lista);
			} else {
				EliminarNodo(aux);
			}
		} else if (aux->dato->edad < 6 && aux->dato->edad >= 4 && aux->dato->distancia > 2) {
			pilaAgregar(salitaNegra, aux->dato);
			if (aux == lista) {
				EliminarNodo(lista);
			} else {
				EliminarNodo(aux);
			}
		}
		aux = aux2;
	}
}

void mostrarPila(nodoPila* pila) {
	while (pila != NULL) {
		cout << pila->dato->nombre_pendejo << " (" << pila->dato->edad << " años, " << pila->dato->distancia << " km)" << endl;
		pila = pila->link;
	}
}

void mostrarLista(nodoLDE* lista) {
	nodoLDE* actual = lista;
	while (actual != NULL) {
		cout << actual->dato->nombre_pendejo << " (" << actual->dato->edad << " años, " << actual->dato->distancia << " km)" << endl;
		actual = actual->siguiente;
	}
}

int main() {
	nodoLDE* lista = NULL;
	nodoLDE* ultimo = NULL;
	
	// Insertar algunos niños en la lista
	pendejos* p1 = new pendejos{"Juan Pérez", "Ana Pérez", 3, 3.5, 123456789, ""};
	pendejos* p2 = new pendejos{"Ana López", "Carlos López", 5, 4.0, 987654321, ""};
	pendejos* p3 = new pendejos{"Carlos Díaz", "María Díaz", 2, 1.0, 555555555, ""};
	pendejos* p4 = new pendejos{"Marta Gómez", "Jorge Gómez", 4, 2.5, 444444444, ""};
	
	// Crear los nodos de la lista y enlazarlos
	nodoLDE* n1 = new nodoLDE{p1, NULL, NULL};
	nodoLDE* n2 = new nodoLDE{p2, NULL, n1};
	nodoLDE* n3 = new nodoLDE{p3, NULL, n2};
	nodoLDE* n4 = new nodoLDE{p4, NULL, n3};
	n1->siguiente = n2;
	n2->siguiente = n3;
	n3->siguiente = n4;
	
	lista = n1;
	ultimo = n4;
	
	// Mostrar la lista antes de clasificar
	cout << "Lista antes de clasificar:" << endl;
	mostrarLista(lista);
	cout << endl;
	
	// Clasificar los niños
	funcionej1(lista);
	
	// Mostrar los niños clasificados
	cout << "Niños en Salita Verde:" << endl;
	mostrarPila(salitaVerde);
	cout << endl;
	
	cout << "Niños en Salita Negra:" << endl;
	mostrarPila(salitaNegra);
	cout << endl;
	
	// Mostrar los niños que permanecen en la lista
	cout << "Niños que permanecen en la LDE:" << endl;
	mostrarLista(lista);
	
	return 0;
}
