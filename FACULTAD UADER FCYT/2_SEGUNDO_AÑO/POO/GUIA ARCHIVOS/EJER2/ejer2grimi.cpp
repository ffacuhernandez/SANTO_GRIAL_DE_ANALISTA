#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
using namespace std;

//2. Debe realizar una agenda que permita guardar personas con sus contactos.
//	? Una persona tiene un nombre, apellido, dirección y contactos
//	? Un contacto tiene un tipo (email, teléfono, celular, fax, whatsapp, etc) y un valor
//	La agenda debe guardar los contactos en un archivo binario y debe permitir buscar personas para saber sus datos.

class Contacto{
private:
	char tipo[20];
	char valor[20];
public:
	Contacto(){}
	void setContacto(const char* t,const char* a){
		strncpy(tipo,t,sizeof(tipo));
		strncpy(valor,a,sizeof(valor));
	}
	
	void mostrar() const {
		cout << "Tipo: " << tipo << ", Valor: " << valor << endl;
	}
	
	const char* getTipo() const { return tipo; }
	const char* getValor() const { return valor; }
	
	void guardar(ofstream &out) const{
		out.write(tipo,sizeof(tipo));
		out.write(valor,sizeof(valor));
	}
	void cargar(ifstream &in){
		in.read(tipo,sizeof(tipo));
		in.read(valor,sizeof(valor));
	}
};

class Persona{
private:
	char nombre[50],apellido[50],direccion[100];
	vector<Contacto> contactos;
public:
	Persona(){}
	void setPersona(const char* n,const char* a,const char* d){
		strncpy(nombre,n,sizeof(nombre));
		strncpy(apellido,a,sizeof(apellido));
		strncpy(direccion,d,sizeof(direccion));
	}
	void agregarContacto(const Contacto &c) {
		contactos.push_back(c);
	}
	void mostrar() const {
		cout << "Nombre: " << nombre << ", Apellido: " << apellido << ", Dirección: " << direccion << endl;
		for (const auto &c : contactos) {
			c.mostrar();
		}
	}
	const char* getNombre() const { return nombre; }
	void guardar(ofstream &out) const{
		out.write(nombre,sizeof(nombre));
		out.write(apellido,sizeof(apellido));
		out.write(direccion,sizeof(direccion));
		int cant=contactos.size();
		out.write(reinterpret_cast<const char*>(&cant),sizeof(int));
		for (const auto &c : contactos){
			c.guardar(out);
		}
	}
	void cargar(ifstream &in){
		in.read(nombre,sizeof(nombre));
		in.read(apellido,sizeof(apellido));
		in.read(direccion,sizeof(direccion));
		int cant;
		in.read(reinterpret_cast<char*>(&cant),sizeof(int));
		contactos.resize(cant);
		for (auto &c : contactos){
			c.cargar(in);
		}
	}
};

void guardar(const Persona &p){
	ofstream archivo("agenda.bin",ios::binary | ios::app);
	if (!archivo){
		cerr<<"Error al abrir el archivo"<<endl;
		return;
	}
	p.guardar(archivo);
	archivo.close();
}

void buscar(const char* nombre){
	ifstream archivo("agenda.bin", ios::binary);
	if (!archivo){
		cerr << "Error al abrir el archivo"<< endl;
		return;
	}
	Persona p;
	while(archivo.peek() != EOF){
		p.cargar(archivo);
		if (strcmp(p.getNombre(),nombre) == 0){
			p.mostrar();
			archivo.close();
			return;
		}
	}
	cout<<"Persona no encontrada"<<endl;
	archivo.close();
}

int main(int argc, char *argv[]) {
	
	int opcion;
	do{
		cout << "1. Agregar persona" << endl;
		cout << "2. Buscar persona" << endl;
		cout << "3. Salir" << endl;
		cout << "Opción: ";
		cin >> opcion;
		cin.ignore();
		
		if(opcion==1){
			char nombre[50],apellido[50],direccion[100];
			cout<<"nombre: ";cin.getline(nombre,50);
			cout<<"apellido: ";cin.getline(apellido,50);
			cout<<"direccion: ";cin.getline(direccion,100);
			
			Persona p;
			p.setPersona(nombre,apellido,direccion);
			int numContactos;
			cout<<"cantidad de contactos: ";cin>>numContactos;
			cin.ignore();
			
			for (int i=0;i<numContactos;i++){
				char tipo[20],valor[20];
				cout<<"tipo de contacto: ";cin.getline(tipo,20);
				cout<<"valor de contacto: ";cin.getline(valor,20);
				Contacto c;
				c.setContacto(tipo, valor);
				p.agregarContacto(c);
			}
			
			guardar(p);
		}else if(opcion==2){
			char nombre[50];
			cout<<"ingrese nombre de la persona: ";cin.getline(nombre,50);
			buscar(nombre);
		}
	} while(opcion != 3);
	
	return 0;
}

