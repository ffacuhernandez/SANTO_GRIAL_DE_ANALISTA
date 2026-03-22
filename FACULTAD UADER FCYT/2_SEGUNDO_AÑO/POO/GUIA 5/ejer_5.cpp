#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

///Deseamos diseñar un software que mantenga los catálogos de la música, una canción tiene
///un autor que pudo componer varias canciones. A la vez un disco esta compuesto por un
///conjunto de canciones que no necesariamente son de un solo autor. 

class Cancion{
protected:
	char autor[100];
	char nombre[100];
public:
	Cancion (const char* aut, const char* nom){
		strcpy(autor, aut);
		strcpy(nombre, nom);
	}
	void mostrar(){
		cout << "Canción: " << nombre << " | Autor: " << autor << endl;
	}
};

class Artista{
private:
	char nombre[100];
	vector<Cancion*> canciones;
public:
	Artista(const char* nom){
		strcpy(nombre, nom);
	}
	void agregar(Cancion* can){
		canciones.push_back(can);
	}
	void mostrar(){
		for (const auto& bucle : canciones){
			bucle->mostrar();
		}
	}
};

class Disco {
private:
	char nombre[100];
	vector<Cancion*> canciones_disco;
public:
	Disco(const char* nom){
		strcpy(nombre, nom);
	}
	void agregar(Cancion* can){
		canciones_disco.push_back(can);
	}
	void mostrar() {
		cout << "Disco: " << nombre << endl;
		for (const auto& cancion : canciones_disco) {
			cancion->mostrar();
		}
	}
};


int main(int argc, char *argv[]) {
	// Crear un artista
	Artista artista("The Beatles");
	
	// Crear canciones
	Cancion* cancion1 = new Cancion("The Beatles", "Let It Be");
	Cancion* cancion2 = new Cancion("The Beatles", "Hey Jude");
	Cancion* cancion3 = new Cancion("Zarcort", "Battlefield 4 Rap");
	
	// Agregar canciones al artista
	artista.agregar(cancion1);
	artista.agregar(cancion2);
	artista.agregar(cancion3);
	
	// Crear un disco
	Disco disco("Greatest Hits");
	disco.agregar(cancion1);
	disco.agregar(cancion2);
	disco.agregar(cancion3);
	
	// Mostrar información
	artista.mostrar();
	disco.mostrar();
	
	// Liberar memoria
	delete cancion1;
	delete cancion2;
	return 0;
}

