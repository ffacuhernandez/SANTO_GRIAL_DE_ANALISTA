#include <iostream>
#include <stdlib.h>
using namespace std;

class persona{
private:
	string nombre;
	int edad;
public:
	persona(string, int);
	virtual void mostrar();
};

class alumno : public persona{
private:
	float notafinal;
public:
	alumno(string, int, float);
	void mostrar();
};

class profesor : public persona{
private:
	string materia;
public:
	profesor(string, int, string);
	void mostrar();
};

persona::persona(string _nombre, int _edad){
	nombre = _nombre;
	edad = _edad;
}

alumno::alumno(string _nombre, int _edad, float _notafinal) : persona (_nombre, _edad){
	notafinal = _notafinal;
}

profesor::profesor(string _nombre, int _edad, string _materia) : persona (_nombre, _edad){
	materia = _materia;
}

void persona::mostrar(){
	cout << "Nombre: " << nombre << endl;
	cout << "Edad: " << edad << endl;
}

void alumno::mostrar(){
	persona::mostrar();
	cout << "Nota final: " << notafinal << endl;
}

void profesor::mostrar(){
	persona::mostrar();
	cout << "Materia: " << materia << endl;
}

int main(int argc, char *argv[]) {
	persona *vector[3];
	vector[0] = new alumno("Facundo", 20, 19.3);
	vector[1] = new alumno ("Tuco", 19, 15.5);
	vector[2] = new profesor("Granero", 30, "Sexologia");
	
	vector[0] -> mostrar();
	cout << endl;
	vector[1] -> mostrar();
	cout << endl;
	vector[2] -> mostrar();
	
	return 0;
}

