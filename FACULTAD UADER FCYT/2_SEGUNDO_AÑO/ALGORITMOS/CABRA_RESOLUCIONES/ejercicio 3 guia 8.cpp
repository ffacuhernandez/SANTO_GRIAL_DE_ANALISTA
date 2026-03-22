#include <iostream>
using namespace std;

struct nodo_grafo{
	int id_nodo;
	struct nodo_arco* lista_arco;
	struct nodo_grafo* link;
};
typedef struct nodo_grafo NGrafo;

struct nodo_arco{
	int id_arco;
	struct nodo_grafo* destino;
	struct nodo_arco* link;
};
typedef struct nodo_arco NArco;

void grafo_mostrar(NGrafo* lista_n);
void grafo_agregar_nodo(NGrafo* &lista_n, int id_nodo);
void grafo_agregar_arco(NGrafo* lista_n, int id_arco, int id_nodo_origen, int id_nodo_destino);

int NodosAdyacentes(NGrafo* lista_n, int id_nodo){
	NGrafo* nodo = lista_n;
	int cont = 0;
	
	while(nodo != nullptr && nodo->id_nodo != id_nodo){
		nodo = nodo->link;
	}
	
	if(nodo->id_nodo == id_nodo){
		NArco* nuevo_arco = nodo->lista_arco;
		
		while(nuevo_arco != nullptr){
			
			nuevo_arco = nuevo_arco->link;
			cont++;
		}
		
	}else{
		cout<<"No se encontro ningun nodo dentro del digrafo con el sigueinte id "<<id_nodo;
		return 0;
	}
	
	return cont;
}

	void menu_opcion1 (NGrafo* lista_n)
	{
		grafo_mostrar(lista_n);
	}
	
	void menu_opcion2 (NGrafo* &lista_n)
	{
		int id_nodo;
		
		cout << "Ingrese el id_nodo del nodo que desea incorporar: ";
		cin >> id_nodo;
		grafo_agregar_nodo (lista_n, id_nodo);
		cout << endl;
		cout << endl;
	}
	
	void menu_opcion3 (NGrafo* &lista_n)
	{
		int id_arco, id_nodo_origen, id_nodo_destino;
		
		cout << "Ingrese el id_arco del arco que desea incorporar: ";
		cin >> id_arco;
		cout << "Ingrese el id_nodo del nodo desde donde sale el arco: ";
		cin >> id_nodo_origen;
		cout << "Ingrese el id_nodo del nodo a donde llega el arco: ";
		cin >> id_nodo_destino;
		
		grafo_agregar_arco (lista_n, id_arco, id_nodo_origen, id_nodo_destino);
		
		cout << endl;
		cout << endl;
	}
	
	void menu_opcion4 (NGrafo* lista_n){
		int x,y;
		
		cout<<"ingrese la id del nodo: ";
		cin>>x;
		
		y = NodosAdyacentes(lista_n,x);
		
		cout<<"la cantidad de nodos adyacentes que tiene el nodo: "<<x<<" es de: "<<y<<endl<<endl;
	}
	
	void grafo_mostrar (NGrafo* lista_n)
	{
		cout << "Grafo:\n\n";
		
		while (lista_n != NULL)
		{
			cout << "Nodo " << lista_n->id_nodo << ":" << endl;
			
			NArco* aux_la = lista_n->lista_arco;
			while (aux_la != NULL)
			{
				cout << "  Arco " << aux_la->id_arco << " -> Nodo " << aux_la->destino->id_nodo << endl;
				aux_la = aux_la->link;
			}
			
			lista_n = lista_n->link;
		}
		cout << endl;
		cout << endl;
	}
	
	void grafo_agregar_nodo (NGrafo* &lista_n, int id_nodo)
	{
		NGrafo* aux = lista_n;
		
		// Verificamos si que no exista ya el id_nodo.
		while (aux != NULL)
		{
			if (aux->id_nodo == id_nodo)
			{
				cout << "!!! Error: Ya existe un nodo con ese id_nodo." << endl;
				return;
			}
			aux = aux->link;
		}
		
		aux = new (NGrafo);
		aux->id_nodo = id_nodo;
		aux->lista_arco = NULL;
		aux->link = lista_n;
		lista_n = aux;
	}
	
	void grafo_agregar_arco (NGrafo* lista_n, int id_arco, int id_nodo_origen, int id_nodo_destino)
	{
		NGrafo* nodo_origen = lista_n;
		NGrafo* nodo_destino = lista_n;
		
		while (nodo_origen != NULL && nodo_origen->id_nodo != id_nodo_origen)
			nodo_origen = nodo_origen->link;
		
		while (nodo_destino != NULL && nodo_destino->id_nodo != id_nodo_destino)
			nodo_destino = nodo_destino->link;
		
		// Verificamos si existen id_nodo_origen y id_nodo_destino.
		if (nodo_origen == NULL || nodo_destino == NULL)
		{
			cout << "!!! Error: Alguno de los nodos no existe." << endl;
			return;
		}
		
		NArco* arco_actual = nodo_origen->lista_arco;
		while(arco_actual != nullptr){
			
			if(arco_actual->id_arco == id_arco){
				cout<<"El arco ya existe papi."<<endl;
				return;
			}
			arco_actual = arco_actual->link;
		}
		
		NArco* aux = new (NArco);
		aux->id_arco = id_arco;
		aux->destino = nodo_destino;
		aux->link = nodo_origen->lista_arco;
		nodo_origen->lista_arco = aux;
	}

int main(int argc, char *argv[]) {
	NGrafo* lista_n = NULL;
	
	int opcion = 0;
	do {
		cout << "************Menu de Opciones************\n";
		cout << endl;
		cout << "****** Grafos ******\n";
		cout << endl;
		cout << "1- Mostrar.\n";
		cout << "2- Insertar Nodo.\n";
		cout << "3- Insertar Arco.\n";
		cout << "4- Nodos Adyacentes De Un Nodo.\n";
		cout << endl;
		cout << "    0- Salir\n";
		cout << endl;
		cout << "                        Ingrese opcion: ";
		cin >> opcion;
		cout << endl;
		cout << endl;
		
		switch(opcion)
		{
		case 1:
			menu_opcion1 (lista_n);
			break;
		case 2:
			menu_opcion2 (lista_n);
			break;
		case 3:
			menu_opcion3 (lista_n);
			break;
		case 4:
			menu_opcion4 (lista_n);
		}
	} while ( opcion != 0);
	return 0;
}

