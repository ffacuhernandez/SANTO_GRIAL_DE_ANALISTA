#include <iostream>
#include <stdlib.h>
using namespace std;

struct nodo{
	int dato;
	nodo *der;
	nodo *izq;
	nodo *padre;
};

nodo *crearnodo(int n, nodo *padre);
void insertarnodo(nodo *&arbol, int n, nodo *padre);
void mostrararbol(nodo *arbol, int contador);
bool busqueda(nodo *arbol, int n);
void preorden(nodo *arbol);
void inorden(nodo *arbol);
void postorden(nodo *arbol);
void eliminar(nodo *arbol, int n);
void eliminarnodo(nodo *nodoeliminar);
nodo *minimo(nodo *arbol);
void reemplazar(nodo *arbol, nodo *nuevonodo);
void destruirnodo(nodo *nodo);

int main(int argc, char *argv[]) {
	nodo *arbol = NULL;
	int dato, opcion, contador = 0;
	do {
		cout << "MENU" << endl;
		cout << "1)INSERTAR UN NUEVO NODO" << endl;
		cout << "2)MOSTRAR EL ARBOL COMPLETO" << endl;
		cout << "3)BUSCAR UN ELEMENTO EN EL ARBOL" << endl;
		cout << "4)RECORRER ARBOL EN PREORDEN" << endl;
		cout << "5)RECORRER EL ARBOL EN INORDEN" << endl;
		cout << "6)RECORRER EL ARBOL EN POSTORDEN" << endl;
		cout << "7)ELIMINAR UN NODO DEL ARBOL" << endl;
		cout << "8)SALIR" << endl << ">";
		cin >> opcion;
		switch (opcion){
		case 1: cout << "Digite un numero: " << endl << ">";
			cin >> dato;
			insertarnodo(arbol, dato, NULL);
			cout << endl;
			break;
		case 2: cout << "Mostrando el arbol completo: " << endl;
			mostrararbol(arbol, contador);
			cout << endl;
			break;
		case 3: cout << "Ingrese el elemento a buscar: " << endl << ">";
			cin >> dato;
			if (busqueda(arbol, dato) == true){
				cout << "ELEMENTO " << dato << " A SIDO ENCONTRADO EN EL ARBOL" << endl;
			} else {
				cout << "ELEMENTO NO ENCONTRADO" << endl;
			}
		case 4: cout << "RECORRIDO EN PREORDEN: " << endl;
			preorden(arbol);
			cout << endl;
			break;
		case 5: cout << "RECORRIDO EN INORDEN: " << endl;
			inorden(arbol);
			cout << endl;
			break;
		case 6: cout << "RECORRIDO EN POSTORDEN: " << endl;
			postorden(arbol);
			cout << endl;
			break;
		case 7: cout << "Digite el nodo que quiere eliminar: " << endl << ">";
			cin >> dato;
			eliminar(arbol, dato);
			cout << endl;
			break;
		case 8: break;
		}
	} while (opcion != 8);
	
	return 0;
}

// FUNCION PARA CREAR NUEVO NODO
nodo *crearnodo(int n, nodo *padre){
	nodo *nuevo_nodo = new nodo();
	nuevo_nodo -> dato = n;
	nuevo_nodo -> der = NULL;
	nuevo_nodo -> izq = NULL;
	nuevo_nodo -> padre = padre;
	return nuevo_nodo;
}

// FUNCION PARA INSERTAS ELEMENTOS EN EL ARBOL
void insertarnodo(nodo *&arbol, int n, nodo *padre){
	if (arbol == NULL){ // SI EL ARBOL ESTA VACIO
		nodo *nuevo_nodo = crearnodo(n, padre);
		arbol = nuevo_nodo;
	} else { // SI EL ARBOL TIENE UN NODO O MAS
		int valoraiz = arbol -> dato; //OBTENEMOS VALOR DE LA RAIZ
		if (n < valoraiz){ // SI EL ELEMENTO ES MENOR A LA RAIZ A LA IZQUIERDA PA
			insertarnodo(arbol -> izq, n, arbol);
		} else {
			insertarnodo(arbol -> der, n, arbol);
		}
	}
}

//MOSTRANDO ARBOL COMPLETO
void mostrararbol(nodo *arbol, int contador){
	if (arbol == NULL){ // ARBOL VACIO?
		return;
	} else {
		mostrararbol(arbol -> der, contador+1);
		for (int i = 0; i < contador; i++){
			cout << "   ";
		}
		cout << arbol -> dato << endl;
		mostrararbol(arbol -> izq, contador+1);
	}
}

//FUNCION PARA BUSCAR ELEMENTO EN EL ARBOL
bool busqueda(nodo *arbol, int n){
	if(arbol == NULL){ //SI EL ARBOL ESTA VACIO
		return false;
	} else if(arbol -> dato == n){ // SI EL NODO ES IGUAL AL ELEMENTO
		return true;
	} else if(n < arbol -> dato){
		return busqueda(arbol -> izq, n);
	} else {
		return busqueda(arbol -> der, n);
	}
}

	
void preorden(nodo *arbol){
	if (arbol == NULL){ // ARBOL VACIO?
		return;
	} else{
		cout << arbol -> dato << " - "; //RAIZ
		preorden(arbol -> izq);
		preorden(arbol -> der);
	}
}
	
void inorden(nodo *arbol){
	if (arbol == NULL){
		return;
	} else {
		inorden(arbol -> izq);
		cout << arbol -> dato << " - ";
		inorden(arbol -> der);
	}
}
	
void postorden(nodo *arbol){
	if (arbol == NULL){
		return;
	} else {
		postorden(arbol -> izq);
		postorden(arbol -> der);
		cout << arbol -> dato << " - ";
	}
}

void eliminar(nodo *arbol, int n){
	if (arbol == NULL){ //ARBOL VACIO
		return;
	} else if (n < arbol -> dato){ // SI EL VALOR ES MENOR BUSCAR POR LA IZQUIERDA
		eliminar(arbol -> izq, n);
	} else if (n > arbol -> dato){ // SI EL VALOR ES MAYOR BUSCA POR LA DERECHA
		eliminar(arbol -> der, n);
	} else { // SI YA LO ENCONTRASTE
		eliminarnodo(arbol);
	}
}

// FUNCION ELIMINAR NODO
void eliminarnodo(nodo *nodoeliminar){
	if (nodoeliminar -> izq && nodoeliminar -> der){ //SI EL NODO TIENE HIJO IZQ Y DER
		nodo *menor = minimo(nodoeliminar -> der);
		nodoeliminar -> dato = menor -> dato;
		eliminarnodo(menor);
	}else if (nodoeliminar -> izq){ // SI TIENE HIJO IZQUIERDO
		reemplazar(nodoeliminar, nodoeliminar -> izq);
		destruirnodo(nodoeliminar);
	} else if(nodoeliminar -> der){ // SI TIENE UN HIJO DER
		reemplazar(nodoeliminar, nodoeliminar -> der);
		destruirnodo(nodoeliminar);
	} else { //NO TIENE HIJOS
		reemplazar(nodoeliminar, NULL);
		destruirnodo(nodoeliminar);
	}
	
}
// FUNCION PARA DETERMINAR EL NODO MAS IZQ POSIBLE
nodo *minimo(nodo *arbol){
	if (arbol == NULL){ // si el arbol esta vacio
		return NULL; //retorna nulo
	}
	if (arbol -> izq){ // SI TIENE HIJO IZQ
		return minimo(arbol -> izq); // BUSCAMOS LA PARTE MAS IZQ POSIBLE
	} else { // SI NO TIENE HIJO IZQUIERDO
		return arbol; // RETORNAMOS EL MISMO NODO
	}
}

// FUNCION PARA REEMPLAZAR DOS NODOS
void reemplazar(nodo *arbol, nodo *nuevonodo){
	if (arbol -> padre){
		// arbol -> padre asignarle su nuevo hijo
		if (arbol -> dato == arbol -> padre -> izq -> dato){
			arbol -> padre -> izq = nuevonodo;
		} else if (arbol -> dato == arbol -> padre -> der -> dato){
			arbol -> padre -> der = nuevonodo;
		}
	}
	if (nuevonodo){
		// asignarle su nuevo padre
		nuevonodo -> padre = arbol -> padre;
	}
}
	
// FUNCION PARA DESTRUIR UN NODO
void destruirnodo(nodo *nodo){
	nodo -> izq = NULL;
	nodo -> der = NULL;
	
	delete nodo;
}
