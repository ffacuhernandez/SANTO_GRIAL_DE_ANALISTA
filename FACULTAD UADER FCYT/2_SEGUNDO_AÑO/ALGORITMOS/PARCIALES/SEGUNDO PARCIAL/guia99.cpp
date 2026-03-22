#include <iostream>
#include <stdlib.h>
using namespace std;


///ESTRUCTURAS
struct nodo_grafo{
	int id_nodo; // IDENTIFICA EL NODO
	struct nodo_arco* lista_arco; // UN PUNTERO A LA LISTA DE CONEXIONES QUE SALEN DEL NODO
	struct nodo_grafo* link; // PUNTERO AL SIGUIENTE NODO EN LA LISTA DE NODOS
};
typedef struct nodo_grafo NGrafo;

struct nodo_arco{
	int id_arco;
	struct nodo_grafo* destino;
	struct nodo_arco* link;
};
typedef struct nodo_arco NArco;

///FUNCIONES
void opcion1(NGrafo* lista_n);
void opcion2(NGrafo* &lista_n);
void opcion3(NGrafo* &lista_n);
void opcion4(NGrafo* &lista_n);


int main(int argc, char *argv[]) {
	NGrafo* lista_n = NULL; // Inicializa la lista de nodos vacía
	int opcion = 0;
	do {
		// Menú de opciones
		cout << endl;
		cout << "************Menu de Opciones************\n";
		cout << endl;
		cout << "1- Mostrar.\n";
		cout << "2- Insertar Nodo.\n";
		cout << "3- Insertar Arco.\n";
		cout << "4- Eliminar un Arco.\n";
		cout << "           0- Salir\n";
		cout << endl;
		cout << "                        Ingrese opcion: ";
		cin >> opcion;
		cout << endl;
		cout << endl;
		switch(opcion)
		{
		case 1:
			opcion1(lista_n); // Muestra el grafo
			break;
		case 2:
			opcion2(lista_n); // Agrega un nodo
			break;
		case 3:
			opcion3(lista_n); // Agrega un arco
			break;
		case 4:
			opcion4(lista_n); //Elimina un arco
			break;
		}
	} while ( opcion != 0); // Continúa hasta que el usuario elija salir
	return 0;
}

void opcion1(NGrafo* lista_n){
	cout << "GRAFO COMPLETITO: " << endl;
	while (lista_n != NULL)
	{
		cout << "Nodo " << lista_n->id_nodo << ":" << endl;
		NArco* aux_la = lista_n->lista_arco;
		while (aux_la != NULL)
		{
			cout << "  Arco " << aux_la->id_arco << " -> Nodo " << aux_la->destino->id_nodo << endl;
			aux_la = aux_la->link; // SE MUEVE AL ARCO QUE VIENE
		}
		
		lista_n = lista_n->link; //SE MUEVE UN NODO
	}
	cout << endl;
	cout << endl;
}
	
void opcion2(NGrafo* &lista_n){
	int id_nodo;
	cout << "Ingrese el id_nodo del nodo que desea incorporar: ";
	cin >> id_nodo;
	NGrafo* aux = lista_n;
	// Verificamos si que no exista ya el id_nodo.
	while (aux != NULL){
		if (aux->id_nodo == id_nodo){
			cout << "!!! Error: Ya existe un nodo con ese id_nodo." << endl;
			return; // Sale de la función si el nodo ya existe.
		}
		aux = aux->link; // Mueve al siguiente nodo en la lista.
	}
	
	// Crear un nuevo nodo si no existe.
	aux = new NGrafo; // Crea una nueva instancia de nodo.
	aux->id_nodo = id_nodo; // Asigna el id al nuevo nodo.
	aux->lista_arco = NULL; // Inicializa la lista de arcos como NULL.
	aux->link = lista_n; // Enlaza el nuevo nodo a la lista.
	lista_n = aux; // Actualiza la lista para que el nuevo nodo sea el primero.
}

void opcion3(NGrafo* &lista_n){
	int id_arco, id_nodo_origen, id_nodo_destino;
	cout << "Ingrese el id_arco del arco que desea incorporar: ";
	cin >> id_arco;
	cout << "Ingrese el id_nodo del nodo desde donde sale el arco: ";
	cin >> id_nodo_origen;
	cout << "Ingrese el id_nodo del nodo a donde llega el arco: ";
	cin >> id_nodo_destino;
	NGrafo* nodo_origen = lista_n;
	NGrafo* nodo_destino = lista_n;
	
	while (nodo_origen != NULL && nodo_origen->id_nodo != id_nodo_origen)
		nodo_origen = nodo_origen->link;
	while (nodo_destino != NULL && nodo_destino->id_nodo != id_nodo_destino)
		nodo_destino = nodo_destino->link;
	// Verificamos si existen id_nodo_origen y id_nodo_destino.
	if (nodo_origen == NULL || nodo_destino == NULL){
		cout << "!!! Error: Alguno de los nodos no existe." << endl;
		return;
	}
	// Verificamos que no exista ya el id_arco.
	NArco* aux = new (NArco);
	aux->id_arco = id_arco;
	aux->destino = nodo_destino;
	aux->link = nodo_origen->lista_arco;
	nodo_origen->lista_arco = aux;
}

void opcion4(NGrafo* &lista_n){
	int id_nodo_origen, id_nodo_destino;
	cout << "Ingrese el ID del nodo origen: " << endl;
	cin >> id_nodo_origen;
	cout << "Ingrese el ID del nodo destino: " << endl;
	cin >> id_nodo_destino;
	NGrafo* nodo_origen = lista_n;
	NGrafo* nodo_destino = lista_n;
	while (nodo_origen != NULL && nodo_origen->id_nodo != id_nodo_origen)
		nodo_origen = nodo_origen->link;
	while (nodo_destino != NULL && nodo_destino->id_nodo != id_nodo_destino)
		nodo_destino = nodo_destino->link;
	// Verificamos si existen id_nodo_origen y id_nodo_destino.
	if (nodo_origen == NULL || nodo_destino == NULL){
		cout << "!!! Error: Alguno de los nodos no existe." << endl;
		return;
	}
}
