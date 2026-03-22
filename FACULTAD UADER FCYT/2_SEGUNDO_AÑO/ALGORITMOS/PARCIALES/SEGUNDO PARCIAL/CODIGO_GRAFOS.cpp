#include <iostream>
#include <stdlib.h>
using namespace std;

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

// DECLARACION DE FUNCIONES.
void menu_opcion1 (NGrafo* lista_n);
void menu_opcion2 (NGrafo* &lista_n);
void menu_opcion3 (NGrafo* &lista_n);
void menu_opcion4(NGrafo* lista_n);
void menu_opcion5(NGrafo* lista_n);
void menu_opcion6(NGrafo* lista_n);
void menu_opcion7(NGrafo* lista_n);
void menu_opcion8(NGrafo* lista_n);

void grafo_mostrar (NGrafo* lista_n);
void grafo_agregar_nodo (NGrafo* &lista_n, int id_nodo);
void grafo_agregar_arco (NGrafo* lista_n, int id_arco, int id_nodo_origen, int id_nodo_destino);


int main(int argc, char *argv[]) {
	
	NGrafo* lista_n = NULL; // Inicializa la lista de nodos vacía
	int opcion = 0;
	do {
		// Menú de opciones
		cout << "************Menu de Opciones************\n";
		cout << endl;
		cout << "****** Grafos ******\n";
		cout << endl;
		cout << "1- Mostrar.\n";
		cout << "2- Insertar Nodo.\n";
		cout << "3- Insertar Arco.\n";
		cout << "4- Mostrar el total de arcos" << endl;
		cout << "5- Mostrar cantidad de nodos adyacentes de un nodo en especifico" << endl;
		cout << "6- Mostrar el conjunto right de un nodo en especifico" << endl;
		cout << "7- Mostrar el conjunto left de un nodo en especifico" << endl;
		cout << "8- Determinar el conjunto MAXIMAL de un grafo" << endl; // FALTA HACERLO
		cout << "    0- Salir\n";
		cout << endl;
		cout << "                        Ingrese opcion: ";
		cin >> opcion;
		cout << endl;
		cout << endl;
		switch(opcion)
		{
		case 1:
			menu_opcion1(lista_n); // Muestra el grafo
			break;
		case 2:
			menu_opcion2(lista_n); // Agrega un nodo
			break;
		case 3:
			menu_opcion3(lista_n); // Agrega un arco
			break;
		case 4:
			menu_opcion4(lista_n); // Muestra el total de arcos
			break;
		case 5: 
			menu_opcion5(lista_n); // Muestra los nodos adyacentes
			break;
		case 6:
			menu_opcion6(lista_n); //Conjunto right de un nodo
			break;
		case 7:
			menu_opcion7(lista_n);
			break;
		case 8:
			menu_opcion8(lista_n);
			break;
		}
	} while ( opcion != 0); // Continúa hasta que el usuario elija salir
	return 0;
}

void menu_opcion1(NGrafo* lista_n){
	grafo_mostrar (lista_n);
}
	
void grafo_mostrar (NGrafo* lista_n){
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
	
void menu_opcion2 (NGrafo* &lista_n){
	int id_nodo;
	cout << "Ingrese el id_nodo del nodo que desea incorporar: ";
	cin >> id_nodo;
	grafo_agregar_nodo(lista_n, id_nodo);
}
	
void grafo_agregar_nodo (NGrafo* &lista_n, int id_nodo){
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
	
void menu_opcion3 (NGrafo* &lista_n){
	int id_arco, id_nodo_origen, id_nodo_destino;
	cout << "Ingrese el id_arco del arco que desea incorporar: ";
	cin >> id_arco;
	cout << "Ingrese el id_nodo del nodo desde donde sale el arco: ";
	cin >> id_nodo_origen;
	cout << "Ingrese el id_nodo del nodo a donde llega el arco: ";
	cin >> id_nodo_destino;

	grafo_agregar_arco (lista_n, id_arco, id_nodo_origen, id_nodo_destino);
}
	
void grafo_agregar_arco (NGrafo* lista_n, int id_arco, int id_nodo_origen, int id_nodo_destino){
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
	// Tarea :) Ponga aquí su código.
	NArco* aux = new (NArco);
	aux->id_arco = id_arco;
	aux->destino = nodo_destino;
	aux->link = nodo_origen->lista_arco;
	nodo_origen->lista_arco = aux;
}
	
void menu_opcion4(NGrafo* lista_n){
	int totalarcos = 0;
	while (lista_n != NULL){
		NArco* aux_la = lista_n->lista_arco;
		while (aux_la != NULL)
		{
			aux_la = aux_la->link; // SE MUEVE AL ARCO QUE VIENE
			totalarcos++;
		}
		
		lista_n = lista_n->link; //SE MUEVE UN NODO
	}
	cout << "El total de arcos es: " << totalarcos << endl;
}
	
void menu_opcion5(NGrafo* lista_n){
	int dato, totaladyacentes = 0;
	cout << "Ingrese el nodo que queres saber su nodos adyacentes: " << endl;
	cin >> dato;
	while (lista_n != NULL){
		if (lista_n->id_nodo == dato){
			cout << "NODO ENCONTRADO!" << endl;
			NArco* aux = lista_n->lista_arco;
			while (aux != NULL)
			{
				cout << aux->destino->id_nodo << " ";
				totaladyacentes++;
				aux = aux->link; // SE MUEVE AL ARCO QUE VIENE
			}
			cout << "El numero total de nodos adyacentes son: " << totaladyacentes;
			return;
		}
		lista_n = lista_n->link; // Mueve al siguiente nodo en la lista.
	}
	cout << "NODO NO ENCONTRADO :( MAL AHI PERRI" << endl;
}
	
void menu_opcion6(NGrafo* lista_n){
	int dato;
	cout << "Ingrese el nodo que queres saber su conjunto RIGHT: " << endl;
	cin >> dato;
	while (lista_n != NULL){
		if (lista_n->id_nodo == dato){
			cout << "NODO ENCONTRADO!" << endl;
			NArco* aux = lista_n->lista_arco;
			cout << "El conjunto RIGHT del nodo " << dato << " es R = {";
			while (aux != NULL)
			{
				cout << aux->destino->id_nodo << " ";
				aux = aux->link; // SE MUEVE AL ARCO QUE VIENE
			}
			cout << "}" << endl;
			return;
		}
		lista_n = lista_n->link; // Mueve al siguiente nodo en la lista.
	}
	cout << "NODO NO ENCONTRADO :( MAL AHI PERRI" << endl;
}

void menu_opcion7(NGrafo* lista_n){
	int dato;
	cout << "Ingrese el nodo que queres saber su conjunto LEFT: " << endl;
	cin >> dato;
	cout << "El conjunto LEFT del nodo " << dato << " es L = { ";
	while (lista_n != NULL){
		NArco* aux = lista_n->lista_arco;
		while (aux != NULL){
			if (aux->destino->id_nodo == dato){
				cout << lista_n->id_nodo << " ";
			}
			aux = aux->link; // SE MUEVE AL ARCO QUE VIENE
		}
		lista_n = lista_n->link; // Mueve al siguiente nodo en la lista.
	}
	cout << "}" << endl;
}
	
void son_isomorfos(NGrafo* lista_n, NGrafo* lista_n2){
	
}
