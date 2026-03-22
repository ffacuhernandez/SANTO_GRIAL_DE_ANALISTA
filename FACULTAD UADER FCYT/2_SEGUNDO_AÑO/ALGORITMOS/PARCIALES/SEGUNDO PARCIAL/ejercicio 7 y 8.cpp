#include <iostream>
using namespace std;

// DEFINICION DE TIPOS.

struct nodo_grafo
{
	int id_nodo;
	struct nodo_arco* lista_arco;
	struct nodo_grafo* link;
};
typedef struct nodo_grafo NGrafo;

struct nodo_arco
{
	int id_arco;
	struct nodo_grafo* destino;
	struct nodo_arco* link;
};
typedef struct nodo_arco NArco;

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
const int MAX_NODOS = 100;
int conjunto_maximal(int maximal[],NGrafo * lista_n){
	int contador=0;
	NGrafo * actual=lista_n;
	while actual !=nullptr){
		bool es_independiente=true;// Asume que el nodo actual es independiente
		for (int i=0;i<contador;i++){
			Ngrafo * nodo_en_maximal=buscar_nodo(list_n, maximal[i]);
			NArco * arco = nodo_en_maximal->list_arco;
			while (arco =! NULL){
				if(arco->destino->id_nodo== actual->id_nodo){
					es_independiente= false;
					break;
				}
				arco=arco->link;
			}
			if(!es_independiente) break;
		}
		if(es_independiente && contador<MAX_NODOS){
			maximal[contador++]=actual->id_nodo;
		}
		actual=actual->link;
	}
}
void mostrar_maximal(Ngrafo * lista_n){
	int maximal[MAX_NODOS];
	int tam_maximal=conjunto_maximal(maximal,lista_n);
	cout<<"conjunto de maximal"<<":";
	for(int i=0;i<tam_maximal;i++){
		cout<<maximal[i]<<" ";
	}
	
	
}
/*Bucle principal (while en conjunto_maximal): Recorre todos los nodos del grafo.
		Verificación de independencia: Para cada nodo actual, comprueba que no tenga arcos que lo conecten con algún nodo en el conjunto maximal ya creado.
		Impresión del conjunto maximal: mostrar_conjunto_maximal muestra los nodos del conjunto maximal en pantalla.
	*/

	
	
	
	int conjunto_minimal(minimal[],Ngrafo* lista_n){
		bool cubierto[MAX_NODOS]=false;
		int contador=0;
		NGrafo * actual=lista_n;
		while(lista_n!=nullptr){
			NArco * arco= actual->lista_arco;
				while(arco!=NULL){
					cubierto[arco->id_arco]=true;
					arco=arco->link;
				
		}
				// Agregar el nodo actual al conjunto minimal
		minimal[contador++]=actual->id_nodo;
				
				// Verificamos si todos los arcos están cubiertos
				bool todos_cubiertos = true; // Variable para verificar si todos los arcos están cubiertos
				for (int i = 0; i < MAX_NODOS; ++i) {
					if (cubierto[i] == false) { // Si hay un arco no cubierto
						todos_cubiertos = false; // No todos los arcos están cubiertos
						break; // Termina la verificación
					}
				}
				
				if (todos_cubiertos) // Si todos los arcos están cubiertos, salimos del bucle
					break;
				
				actual = actual->link; // Avanza al siguiente nodo en la lista del grafo
		}
		
		return count; // Retorna el tamaño del conjunto minimal
	}
		
		// Función que muestra el conjunto minimal en pantalla
		void mostrar_conjunto_minimal(NGrafo* lista_n) {
			int minimal[MAX_NODOS]; // Define un arreglo para almacenar el conjunto minimal
			int tam_minimal = conjunto_minimal(minimal, lista_n); // Llama a la función para obtener el conjunto minimal y su tamaño
			
			cout << "Conjunto minimal del grafo: { "; // Imprime el inicio del conjunto
			for (int i = 0; i < tam_minimal; ++i) { // Recorre cada nodo en el conjunto minimal
				cout << minimal[i] << " "; // Imprime el id del nodo en el conjunto
			}
			cout << "}" << endl; // Cierra la representación del conjunto y pasa a la siguiente línea
		}
