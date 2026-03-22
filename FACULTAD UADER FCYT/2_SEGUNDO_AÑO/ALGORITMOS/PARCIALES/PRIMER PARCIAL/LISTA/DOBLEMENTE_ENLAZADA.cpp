#include <iostream>
#include <stdlib.h>
using namespace std;

struct nodo{
	string nombre;
	string tutor;
	int edad;
	float distancia;
	string telefono;
	string salita;
	nodo *siguiente;
	nodo *anterior;
};

struct nodopila {
	nodo *nino;
	nodopila *siguiente;
};

/*Esta función agrega un nuevo nodo al inicio de la lista. Crea un nuevo nodo, establece su dato, 
siguiente (apuntando al antiguo primer nodo de la lista), y anterior (nullptr ya que será el primer nodo). 
Si la lista no está vacía, actualiza el puntero anterior del antiguo primer nodo para que apunte al nuevo nodo. 
Finalmente, actualiza el puntero de la lista para que apunte al nuevo nodo. */

void agregarinicio(nodo *&lista, string nombre, string tutor, int edad, float distancia, string telefono);
void agregarpila(nodopila *&pila, nodo *nino);
void distribuirninos(nodo *&lista, nodopila *&salitaverde, nodopila *&salitanegra);
void imprimirlista(nodo *lista);
void imprimirpila(nodopila *pila);

int main(int argc, char *argv[]) {
	nodo *lista = NULL;
	nodopila *salitaverde = NULL;
	nodopila *salitanegra = NULL;
	agregarinicio(lista, "Juan Perez", "Maria Lopez", 3, 3.5, "123456789");
	agregarinicio(lista, "Ana Garcia", "Carlos Garcia", 5, 2.5, "987654321");
	agregarinicio(lista, "Luis Martinez", "Juana Martinez", 2, 1.0, "111222333");
	agregarinicio(lista, "Sofia Hernandez", "Laura Hernandez", 4, 3.0, "444555666");
	
	// Imprimir la lista
	cout << "Lista en orden: ";
	imprimirlista(lista);
	
	// Distribuir los ninos en las pilas
	distribuirninos(lista, salitaverde, salitanegra);
	
	// Imprimir las pilas
	cout << "Salita Verde:" << endl;
	imprimirpila(salitaverde);
	
	cout << "Salita Negra:" << endl;
	imprimirpila(salitanegra);
	
	// Imprimir la lista después de la distribución
	cout << "Lista después de la distribucion:" << endl;
	imprimirlista(lista);
	return 0;
}

/*Esta función agrega un nuevo nodo al inicio de la lista. Crea un nuevo nodo, establece su dato, 
siguiente (apuntando al antiguo primer nodo de la lista), y anterior (nullptr ya que será el primer nodo). 
Si la lista no está vacía, actualiza el puntero anterior del antiguo primer nodo para que apunte al nuevo nodo. 
Finalmente, actualiza el puntero de la lista para que apunte al nuevo nodo. */

void agregarinicio(nodo *&lista, string nombre, string tutor, int edad, float distancia, string telefono){
	nodo *nuevo_nodo = new nodo();
	nuevo_nodo -> nombre = nombre;
	nuevo_nodo -> tutor = tutor;
	nuevo_nodo -> edad = edad;
	nuevo_nodo -> distancia = distancia;
	nuevo_nodo -> telefono = telefono;
	nuevo_nodo -> salita = "";
	nuevo_nodo -> siguiente = lista;
	nuevo_nodo -> anterior = NULL;
	
	if (lista != NULL){
		lista -> anterior = nuevo_nodo;
	}
	lista = nuevo_nodo;
}

void agregarpila(nodopila *&pila, nodo *nino) {
	nodopila *nuevonodo = new nodopila();
	nuevonodo -> nino = nino;
	nuevonodo -> siguiente = pila;
	pila = nuevonodo;
}

void distribuirninos(nodo *&lista, nodopila *&salitaverde, nodopila *&salitanegra) {
	nodo *actual = lista;
	while (actual != NULL) {
		nodo *aux = actual;
		actual = actual -> siguiente;
		bool eliminar = false;
		
		if ((aux -> edad < 4 && aux -> edad > 2 && aux -> distancia > 2)) {
			aux -> salita = "Verde";
			agregarpila(salitaverde, aux);
			eliminar = true;
		} else if (aux -> edad >= 4 && aux -> edad < 6 && aux -> distancia > 2) {
			aux -> salita = "Negra";
			agregarpila(salitanegra, aux);
			eliminar = true;
		}
		
		// Eliminar el nodo de la lista
		if (eliminar) {
			if (aux -> anterior != NULL) {
				aux -> anterior -> siguiente = aux -> siguiente;
			} else {
				lista = aux -> siguiente;
			}
			
			if (aux->siguiente != NULL) {
				aux -> siguiente -> anterior = aux -> anterior;
			}
		}
	}
}

void imprimirlista(nodo *lista){
	nodo *aux = lista;
	while (aux != NULL) {
		cout << "Nombre: " << aux -> nombre << ", Tutor: " << aux -> tutor << ", Edad: " << aux -> edad << ", Distancia: " << aux -> distancia
			<< " km, Telefono: " << aux -> telefono << ", Salita: " << aux -> salita << endl;
		aux = aux -> siguiente;
	}
	cout << endl;
}

void imprimirpila(nodopila *pila) {
	nodopila *aux = pila;
	while (aux != NULL){
		nodo *nino = aux -> nino;
		cout << nino -> nombre << " (" << nino -> edad<< " años, " << nino -> distancia << " km)" << endl;
		aux = aux -> siguiente;
	}
	cout << endl;
}
