#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

/// Una empresa nos contrata para diseñar su software de tipo red social. Un usuario puede estar
///	conectado con otros usuarios por medio de relaciones, amistad, familia, etc. El usuario
///	puede definir sus relaciones. A la vez un usuario puede tener relaciones no solo con otros
///	usuarios sino también con grupos o paginas web. 

class Usuario{
public:
	virtual void mostrar() = 0;
	virtual ~Usuario(){};
};

class Persona : public Usuario{
private:
	char nombre[100];
public:
	Persona(const char* nom){
		strncpy(nombre, nom, sizeof(nombre) - 1);
		nombre[sizeof(nombre) - 1] = '\0';
	}
	void mostrar(){
		cout << "Usuario " << nombre << endl;
	}
}

class Grupo

class Relaciones : public Usuario{
private:
	Usuario *destino;
	char relacion[100];
public:
	Relaciones (Usuario *obj, const char* tiporel){
		destino = obj;
		strncpy(destino, dest, sizeof(destino) - 1);
		destino[sizeof(destino) - 1] = '\0';
		strncpy(relacion, tiporel, sizeof(relacion) - 1);
		relacion[sizeof(relacion) - 1]  = '\0';
	}
	void mostrar() override {
		cout << "RELACION CON " << destino << " DE TIPO " << relacion;
	}
};

class Gestor{
private:
	vector<Usuario*> usuarios;
public:
	void agregaruser(Usuario* user){
		usuarios.push_back(user);
	}
	void mostrarrelaciones(){
		for (const auto& bucle : usuarios){
			bucle->mostrar();
		}
	}
};

int main(int argc, char *argv[]) {
	Relaciones *relacion = new Relaciones("ANA JAULA GOATBONE", "POLOLA HERMOSA <3");
	Gestor usuario;
	usuario.agregaruser(relacion);
	usuario.mostrarrelaciones();
	delete relacion;
	return 0;
}

