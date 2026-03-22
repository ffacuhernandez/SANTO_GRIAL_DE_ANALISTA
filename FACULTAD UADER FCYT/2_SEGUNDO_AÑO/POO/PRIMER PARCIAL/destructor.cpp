#include <iostream>
using namespace std;

class perro{
private:
	string nombre, raza;
public:
	perro(string, string);
	~perro();
	void mostrardatos();
	void jugar();
};

perro::perro(string _nombre, string _raza){
	nombre = _nombre;
	raza = _raza;
}

///DESTRUCTOR
perro::~perro(){
}

void perro::mostrardatos(){
	cout << "NOMBRE: " << nombre << endl;
	cout << "RAZA: " << raza << endl;
}

void perro::jugar(){
	cout << "El perro " << nombre << " esta jugando" << endl;
}
int main(int argc, char *argv[]) {
	perro perro1("Mike", "Bulldog");
	perro1.mostrardatos();
	perro1.jugar();
	return 0;
}

