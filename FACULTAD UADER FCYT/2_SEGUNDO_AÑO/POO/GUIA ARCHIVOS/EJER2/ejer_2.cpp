#include <iostream>
#include <vector>
#include <fstream>
#include <cstring>
using namespace std;

class Contacto{
private:
	char tipo[30];
	char valor[30];
public:
	Contacto(){}
	void setcontacto(const char* t, const char* v){
		strncpy(tipo, t, sizeof(tipo));
		strncpy(valor, v, sizeof(valor));
	}
	void mostrar() const {
		cout << "TIPO: " << tipo << " || VALOR: " << valor << endl;
	}
	void guardarcontacto(ofstream &archivo) const {
		archivo.write(tipo, sizeof(tipo));
		archivo.write(valor, sizeof(valor));
	}
	void cargardatoscon(ifstream &archivo) {
		archivo.read(tipo, sizeof(tipo));
		archivo.read(valor, sizeof(valor));
	}
};

class Persona{
private:
	char nombre[30];
	char apellido[30];
	char direccion[30];
	vector<Contacto> contactos;
public:
	Persona(){}
	void setpersona(const char* n, const char* a, const char* d){
		strncpy(nombre, n, sizeof(nombre));
		strncpy(apellido, a, sizeof(apellido));
		strncpy(direccion, d, sizeof(direccion));
	}
	void setcontacto(const Contacto &c){
		contactos.push_back(c);
	}
	void mostrardatos() {
		cout << "NOMBRE Y APELLIDO: " << nombre << " " << apellido << endl;
		cout << "DIRECCION: " << direccion << endl;
		for (const auto& bucle : contactos){
			bucle.mostrar();
		}
	}
	bool getnombre(const char* nombrebusc) const {
		return strcmp(nombre, nombrebusc) == 0;
	}
	void guardararchivo(ofstream &archivo){
		archivo.write(nombre, sizeof(nombre));
		archivo.write(apellido, sizeof(apellido));
		archivo.write(direccion, sizeof(direccion));
		int cant = contactos.size();
		archivo.write(reinterpret_cast<const char*>(&cant), sizeof(int));
		for (const auto& bucle : contactos){
			bucle.guardarcontacto(archivo);
		}
	}
	void cargardatos(ifstream &archivo){
		archivo.read(nombre, sizeof(nombre));
		archivo.read(apellido, sizeof(apellido));
		archivo.read(direccion, sizeof(direccion));
		int cantidad;
		archivo.read(reinterpret_cast<char*>(&cantidad), sizeof(int));
		contactos.clear();
		for (int i = 0; i < cantidad; i++){
			Contacto c;
			c.cargardatoscon(archivo);
			contactos.push_back(c);
		}
	}
};

void guardarpersona(Persona &p){
	ofstream archivo("agenda.bin", ios::binary | ios :: app);
	if (!archivo){
		cout << "ERRO AL ABRIR EL ARHCHIVO" << endl;
		return;
	}
	p.guardararchivo(archivo);
	archivo.close();
}

void buscarpersona(const char* nombre){
	ifstream archivo("agenda.bin", ios::binary);
	if (!archivo){
		cout << "Error al abrir el archivo" << endl;
		return;
	}
	Persona p;
	while (archivo.peek() != EOF){
		p.cargardatos(archivo);
		if (p.getnombre(nombre)){
			p.mostrardatos();
			archivo.close();
			return;
		}
	}
	cout << "Ese mono no existe amigo" << endl;
	archivo.close();
}

void menu(){
	int opcion;
	do{
		cout << "1. Agregar persona" << endl;
		cout << "2. Buscar persona" << endl;
		cout << "3. Salir" << endl;
		cout << "Opción: " << endl << ">";
		cin >> opcion;
		cin.ignore();
		
		if(opcion==1){
			char nombre[50], apellido[50], direccion[100];
			cout << "Nombre: ";
			cin.getline(nombre,50);
			cout << "Apellido: ";
			cin.getline(apellido,50);
			cout << "Direccion: ";
			cin.getline(direccion,100);
			
			Persona p;
			p.setpersona(nombre,apellido,direccion);
			
			int numContactos;
			cout << "Cantidad de contactos: " << endl << ">";
			cin >> numContactos;
			cin.ignore();
			for (int i = 0; i < numContactos; i++){
				char tipo[20], valor[20];
				cout << "Tipo de contacto numero " << i + 1 << ":";
				cin.getline(tipo,20);
				cout<<"valor de contacto numero " << i + 1 << ":";
				cin.getline(valor,20);
				Contacto c;
				c.setcontacto(tipo, valor);
				p.setcontacto(c);
			}
			guardarpersona(p);
		} else if (opcion == 2){
			char nombre[50];
			cout << "Ingrese nombre de la persona: ";
			cin.getline(nombre,50);
			buscarpersona(nombre);
		}
		cout << "-------------------------------" << endl;
	} while(opcion != 3);
}
int main(int argc, char *argv[]) {
	menu();
	return 0;
}

