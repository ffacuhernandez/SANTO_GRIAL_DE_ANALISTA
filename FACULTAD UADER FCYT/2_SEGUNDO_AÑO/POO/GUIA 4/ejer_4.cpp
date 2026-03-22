#include <iostream>
#include <stdlib.h>
using namespace std;

class VectorDinamico{
private:
	int cantidad;
	int *matriz;
public:
	VectorDinamico(){ ///CONSTRUCTOR
		cantidad = 0;
		matriz = new int[cantidad];
	}
	void cantidad_elementos(){
		cout << cantidad;
	}
	void agregar_dato(int n){
		int *aux = new int [cantidad + 1];
		for (int i = 0; i < cantidad; i++){
			aux[i] = matriz[i];
		}
		aux[cantidad] = n;
		delete[] matriz;
		matriz = aux;
		cantidad++;
	}
	void remover_elemento(int dato){
		int pos = -1;
		for (int i = 0; i < cantidad; i++){
			if (dato == matriz[i]){
				pos = i;
			}
		}
		if (pos != -1){
			for (int i = pos; i < cantidad - 1; i++){
				matriz[i] = matriz[i + 1];
			}
			cantidad--;
		}
	}
	void promedio(){
		int acumulador = 0;
		for (int i = 0; i < cantidad; i++){
			acumulador += matriz[i];
		}
		float promedio = acumulador / cantidad;
		cout << "EL PROMEDIO DE LA MATRIZ ES: " << promedio;
	}	
	void mostrar(){
		for (int i = 0; i < cantidad; i++){
			cout << matriz[i] << " ";
		}
	}
	~VectorDinamico(){
		delete[] matriz;
	}
}; 
	
int main(int argc, char *argv[]) {
	VectorDinamico datos;
	cout << "Cantidad de elementos en el vector: ";
	datos.cantidad_elementos();
	cout << endl;
	datos.agregar_dato(1);
	datos.agregar_dato(2);
	datos.agregar_dato(3);
	cout << "ELEMENTOS DEL VECTOR: ";
	datos.mostrar();
	cout << "CON UNA CANTIDAD DE: ";
	datos.cantidad_elementos();
	cout << endl;
	cout << "SACANDO EL 2: " << endl;
	datos.remover_elemento(2);
	datos.mostrar();
	cout << endl;
	datos.agregar_dato(2);
	datos.agregar_dato(4);
	datos.agregar_dato(5);
	datos.agregar_dato(6);
	datos.promedio();
	return 0;
}

