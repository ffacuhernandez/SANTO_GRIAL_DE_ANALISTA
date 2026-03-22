#include <iostream>
using namespace std;

class persona{
private:
	string nombre;
	int edad;
public:
	persona(string, int);
	void mostrarpersona();
};

class empleado : public persona{
private:
	float sueldo;
public:
	empleado(string, int, float);
	void mostrarempleado();
};

class estudiante : public persona{
private:
	float notafinal;
public:
	estudiante(string, int, float);
	void mostrarestudiante();
};

class universitario : public estudiante{
private:
	string carrera;
public:
	universitario(string, int, float, string);
	void mostraruniversitario();
};

persona::persona(string _nombre, int _edad){
	nombre = _nombre;
	edad = _edad;
}

empleado::empleado(string _nombre, int _edad, float _sueldo) : persona(_nombre, _edad){
	sueldo = _sueldo;
}

estudiante::estudiante(string _nombre, int _edad, float _notafinal) : persona(_nombre, _edad){
	notafinal = _notafinal;
}

universitario::universitario (string _nombre, int _edad, float _notafinal, string _carrera) : estudiante (_nombre, _edad, _notafinal){
	carrera = _carrera;
}

void universitario::mostraruniversitario(){
	mostrarestudiante();
	cout << "Carrera: " << carrera << endl;
}

void estudiante::mostrarestudiante(){
	mostrarpersona();
	cout << "Nota final: " << notafinal << endl;
}

void empleado::mostrarempleado(){
	mostrarpersona();
	cout << "Sueldo: " << sueldo << endl;
}

void persona::mostrarpersona(){
	cout << "Nombre:" << nombre << endl;
	cout << "Edad: " << edad << endl;
}
int main(int argc, char *argv[]) {
	universitario p1("Luchito", 20, 13.5, "Entry Fragger del team");
	p1.mostraruniversitario();
	
	cout << "-----------" << endl;
	
	estudiante p2("Facundo", 17, 11);
	p2.mostrarestudiante();
	
	cout << "-----------" << endl;
	
	persona p3 ("Maldonado", 12);
	p3.mostrarpersona();
	
	return 0;
}
