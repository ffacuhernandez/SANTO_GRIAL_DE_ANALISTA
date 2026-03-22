#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Enteros{
protected:
	vector<int> datos;
public:
	void mostrar(){
		for (const auto& bucle : datos){
			cout << bucle << " ";
		}
		cout << endl;
	}
	void tamanio(){
		int tamanio = datos.size();
		cout << "EL TAMANIO DEL VECTOR ES: " << tamanio << endl;
	}
};

class Conjunto : public Enteros{
public:
	void agregar(int numero){
		for (const auto& bucle : datos){
			if (numero == bucle){
				cout << "EL DATO " << numero << " YA SE ENCUENTRA EN LA LISTA" << endl;
				return;
			}
		}
		datos.push_back(numero);
		cout << "DATO " << numero << " AGREGADO A LA LISTA" << endl;
	}
};

class ConjuntoOrdenado : public Enteros{
public:
	void agregar(int numero){
		if (find(datos.begin(), datos.end(), numero) != datos.end()) {
			cout << "EL DATO " << numero << " YA SE ENCUENTRA EN LA LISTA" << endl;
			return;
		}
		// Insertar en el lugar correcto para mantener el orden
		auto pos = lower_bound(datos.begin(), datos.end(), numero);
		datos.insert(pos, numero);
		cout << "DATO " << numero << " AGREGADO A LA LISTA ORDENADA" << endl;
	}
};

class Lista : public Enteros{
public:
	void agregar(int numero){
		datos.push_back(numero);
		cout << "DATO " << numero << " AGREGADO A LA LISTA" << endl;
	}
};

class Listaordenada : public Enteros{
public:
	void agregar(int numero){
		// Insertar en el lugar correcto para mantener el orden
		auto pos = lower_bound(datos.begin(), datos.end(), numero);
		datos.insert(pos, numero);
		cout << "DATO " << numero << " AGREGADO A LA LISTA ORDENADA" << endl;
	}
};

class Vectordinamico : public Enteros{
public:
	void agregar(int numero){
		datos.push_back(numero);
		
	}
};

class Pila : public Enteros{
public:
	void agregar(int numero){
		datos.push_back(numero);
		cout << "Elemento " << numero << " agregado a la pila" << endl;
	}
	void eliminar(){
		if (!empty()){
			cout << "Elemento " << numero << " eliminado de la pila" << endl;
			datos.pop_back();
		} else {
			cout << "LA PILA ESTA VACIA" << endl;
		}
	}
	void superior(){
		
	}
};

int main(int argc, char *argv[]) {
	//PUNTO A
	Conjunto numeros;
	cout << "---- PUNTO A ----" << endl;
	numeros.agregar(1);
	numeros.agregar(2);
	numeros.agregar(2);
	numeros.agregar(3);
	numeros.agregar(2);
	numeros.agregar(4);
	numeros.agregar(70);
	numeros.agregar(5);
	numeros.agregar(5);
	cout << "CONJUNTO SIN ORDENAR: ";
	numeros.mostrar();
	cout << endl;
	
	cout << "---- PUNTO B ----" << endl;
	ConjuntoOrdenado numerosOrdenados;
	numerosOrdenados.agregar(5);
	numerosOrdenados.agregar(3);
	numerosOrdenados.agregar(1);
	numerosOrdenados.agregar(4);
	numerosOrdenados.agregar(2);
	cout << "Conjunto ordenado: ";
	numerosOrdenados.mostrar();
	cout << endl;
	
	cout << "---- PUNTO C ----" << endl;
	Lista numeroslista;
	numeroslista.agregar(1);
	numeroslista.agregar(3);
	numeroslista.agregar(4);
	numeroslista.agregar(4);
	numeroslista.agregar(5);
	numeroslista.mostrar();
	cout << endl;
	
	cout << "---- PUNTO D ----" << endl;
	Listaordenada numerolistaord;
	numerolistaord.agregar(5);
	numerolistaord.agregar(4);
	numerolistaord.agregar(3);
	numerolistaord.agregar(3);
	numerolistaord.agregar(1);
	numerolistaord.agregar(2);
	numerolistaord.mostrar();
	numerolistaord.tamanio();
	cout << endl;
	
	cout << "---- PUNTO E ----" << endl;
	Vectordinamico numerovector;
	numerovector.agregar(1);
	numerovector.agregar(3);
	numerovector.agregar(2);
	numerovector.mostrar();
	numerovector.tamanio();
	
	cout << "---- PUNTO F ----" << endl;
	return 0;
}

