#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
using namespace std;

class Eventos{
private:
	int nro;
	char descripcion[100];
	char TipoDeNotificacion;
public:
	Eventos(){}
	void setdatos(int num, const char* desc, char tipo){
		nro = num;
		strncpy(descripcion,desc, sizeof(descripcion) - 1);
		descripcion[sizeof(descripcion) - 1] = '\0';
		TipoDeNotificacion = tipo;
	}
	void mostrardatos() const {
		cout << "NUMERO: " << nro << endl;
		cout << "DESCRIPCION: " << descripcion << endl;
		cout << "TIPO DE NOTI: " << TipoDeNotificacion << endl;
	}
	int getnro() const {
		return nro;
	}
	const char* getdescri() const {
		return descripcion;
	}
	char gettiponotificacion() const {
		return TipoDeNotificacion;
	}
};

void leerdatos(vector<Eventos> &totaleventos){
	for (const auto& bucle : totaleventos){
		if (bucle.gettiponotificacion() == 'T'){
			ofstream archivo ("notificaciones.txt", ios :: app);
			if (archivo.fail()){
				cout << "ERROR AL ABRIR EL ARCHIVO" << endl;
				return;
			}
			archivo << "NRO: " << bucle.getnro() << " | DESCRIPCION: " << bucle.getdescri();
			archivo.close();
		} else if (bucle.gettiponotificacion() == 'C'){
			cout << "NRO: " << bucle.getnro() << " | DESCRIPCION: " << bucle.getdescri();
		} else if (bucle.gettiponotificacion() == 'B'){
			int num = bucle.getnro();
			ofstream archivo2 ("notificaciones.dat", ios :: binary | ios :: app);
			archivo2.write(reinterpret_cast<char*>(&num), sizeof(int));
			archivo2.write(bucle.getdescri(), sizeof(bucle.getdescri()));
			archivo2.close();
		}
	}
}

void leerarchivo(){
	ifstream archivo("eventos.dat", ios :: binary);
	if (!archivo){
		cout << "ERROR AL ABRIR EL ARCHIVO" << endl;
		return;
	}
	vector<Eventos> totaleventos;
	int num = 0;
	char descripcion[100], tiponot;
	while (archivo.peek() != EOF){
		Eventos e;
		archivo.read(reinterpret_cast<char*>(&num), sizeof(num));
		archivo.read(descripcion, sizeof(descripcion));
		archivo.read(&tiponot, sizeof(tiponot));
		e.setdatos(num, descripcion, tiponot);
		totaleventos.push_back(e);
	}
	archivo.close();
	leerdatos(totaleventos);
}

int main(int argc, char *argv[]) {
	leerarchivo();
	return 0;
}

