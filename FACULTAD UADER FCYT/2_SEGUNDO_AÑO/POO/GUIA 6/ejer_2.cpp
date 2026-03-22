#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

class Secuencias{
public:
	virtual void mostrar() = 0;
	virtual bool verificar(int respuesta) = 0;
	virtual ~Secuencias(){};
};

class Pares : public Secuencias{
public:
	void mostrar() override{
		cout << "SECUENCIA DE: 2, 4, __, 8" << endl;
	}
	bool verificar(int respuesta) override{
		return respuesta == 6;
	}
};

class Impares : public Secuencias{
public:
	void mostrar() override {
		cout << "Secuencia de impares: 1, 3, __, 7" << endl;
	}
	bool verificar(int respuesta) override {
		return respuesta == 5;
	}
};

class Fibonacci : public Secuencias{
public:
	void mostrar() override {
		cout << "Secuencia de Fibonacci: 0, 1, __, 3" << endl;
	}
	bool verificar(int respuesta) override {
		return respuesta == 2;
	}
};

class Gestor{
private:
	int puntaje;
	vector<Secuencias*> secuencias;
public:
	Gestor() : puntaje(0){};
	
	void agregarsecuencia(Secuencias* secuen){
	secuencias.push_back(secuen);
	}
	
	void jugar(){
		for (const auto& bucle : secuencias){
			int respuesta;
			bucle->mostrar();
			cout << "Ingrese el numero que falta de la secuen: " << endl << ">";
			cin >> respuesta;
			if (bucle -> verificar(respuesta)){
				cout << "SEEE PERRI LA CLAVASTE +1" << endl;
				puntaje++;
			} else {
				cout << "BURRO MAL, PERDES UNO POR PETON -1" << endl;
				puntaje--;
			}
		}
		if (puntaje <= 0){
			cout << "PERDISTE GOVIRRR, TENES QUE TENER DE 1 PA ARRIBA" << endl;
			cout << "PUNTAJE FINAL: " << puntaje;
		} else {
			cout << "LA ROMPISTE AMIGO, GG WEL PLEY" << endl;
			cout << "PUNTAJE FINAL: " << puntaje << endl;
		}
	}
	
};


int main(int argc, char *argv[]) {
	Gestor gestor;
	
	// Crear secuencias
	Pares* pares = new Pares();
	Impares* impares = new Impares();
	Fibonacci* fibonacci = new Fibonacci();
	
	// Agregar secuencias al gestor
	gestor.agregarsecuencia(pares);
	gestor.agregarsecuencia(pares);
	gestor.agregarsecuencia(pares);
	
	// Iniciar el juego
	gestor.jugar();
	
	// Liberar memoria
	delete pares;
	delete impares;
	delete fibonacci;
	return 0;
}

