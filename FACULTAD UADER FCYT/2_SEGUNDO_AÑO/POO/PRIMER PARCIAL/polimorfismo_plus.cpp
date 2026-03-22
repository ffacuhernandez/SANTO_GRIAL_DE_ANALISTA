#include <iostream>
using namespace std;

class animal{
private:
	int edad;
public:
	animal(int);
	virtual void comer();
};

class humano : public animal{
private:
	string nombre;
public:
	humano(int, string);
	void comer();
};

class perro : public animal{
private: 
	string nombre, raza;
public:
	perro(int, string, string);
	void comer();
};

perro::perro(int _edad, string _nombre, string _raza) : animal(_edad){
	nombre = _nombre;
	raza = _raza;
}

humano::humano(int _edad, string _nombre) : animal(_edad){
	nombre = _nombre;
}
animal::animal(int _edad){
	edad = _edad;
}

void animal::comer(){
	cout << "Yo como ";
}

void humano::comer(){
	animal::comer();
	cout << "en una mesa sentado en la silla" << endl;
}

void perro::comer(){
	animal::comer();
	cout << "en el suelo con su plato" << endl;
}

int main(int argc, char *argv[]) {
	animal *animales[2];
	animales[0] = new perro(5, "Gordo", "Pastor aleman");
	animales[1] = new humano(99, "Adolf");
	
	animales[0] -> comer();
	animales[1] -> comer();
	
	return 0;
}

