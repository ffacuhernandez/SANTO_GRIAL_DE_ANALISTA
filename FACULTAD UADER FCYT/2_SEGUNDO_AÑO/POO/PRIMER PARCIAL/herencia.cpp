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

class alumno : public persona{
private:
	string codigoalumno;
	float notafinal;
public:
	alumno(string, int, string, float);
	void mostraralumno();
};

persona::persona(string _nombre, int _edad){
	nombre = _nombre;
	edad = _edad;
}

alumno::alumno(string _nombre, int _edad, string _codigoalumno, float _notafinal) : persona (_nombre, _edad){
	codigoalumno = _codigoalumno;
	notafinal = _notafinal;
}

void persona::mostrarpersona(){
	cout << "Nombre: " << nombre << " Edad: " << edad << endl;
}

void alumno::mostraralumno(){
	mostrarpersona();
	cout << "Codigo alumno: " << codigoalumno << endl;
	cout << "Nota final: " << notafinal << endl;
}

int main(int argc, char *argv[]) {
	alumno alumno1("Manuel", 20, "23232323", 15.6);
	alumno1.mostraralumno();
	
	return 0;
}

