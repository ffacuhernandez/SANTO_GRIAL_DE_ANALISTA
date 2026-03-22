#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
using namespace std;

class Comercio {
public:
	virtual void actualizar(double porcentaje = 0) = 0;
	virtual void agregararchivo(ofstream &archivo) = 0;
	virtual ~Comercio() {}
};

class Electrodomesticos : public Comercio {
private:
	int code;
	char nombre[50];
	char marca[20];
	char tipo;
	double precio;
public:
	Electrodomesticos() {};
	void setdatos(int cod, const char* nom, const char* mar, char tip, double pre) {
		code = cod;
		strncpy(nombre, nom, sizeof(nombre) - 1);
		nombre[sizeof(nombre) - 1] = '\0';
		strncpy(marca, mar, sizeof(marca) - 1);
		marca[sizeof(marca) - 1] = '\0';
		tipo = tip;
		precio = pre;
	}
	void actualizar(double porcentaje) override {
		if (tipo == 'N') {
			precio += precio * 0.02;
		} else if (tipo == 'I') {
			precio += precio * (porcentaje / 100);
		}
	}
	void agregararchivo(ofstream &archivo) override {
		archivo.write(reinterpret_cast<const char*>(&code), sizeof(int));
		archivo.write(nombre, sizeof(nombre));
		archivo.write(marca, sizeof(marca));
		archivo.write(&tipo, sizeof(char));
		archivo.write(reinterpret_cast<const char*>(&precio), sizeof(double));
	}
};

class ProductosJardin : public Comercio {
private:
	int code;
	char nombre[50];
	char marca[20];
	char tipo;
	double precio;
public:
	ProductosJardin() {};
	void setdatos(int cod, const char* nom, const char* mar, char tip, double pre) {
		code = cod;
		strncpy(nombre, nom, sizeof(nombre) - 1);
		nombre[sizeof(nombre) - 1] = '\0';
		strncpy(marca, mar, sizeof(marca) - 1);
		marca[sizeof(marca) - 1] = '\0';
		tipo = tip;
		precio = pre;
	}
	void actualizar(double porcentaje = 0) override {
		precio += precio * (0.10 / 12);
	}
	void agregararchivo(ofstream &archivo) override {
		archivo.write(reinterpret_cast<const char*>(&code), sizeof(int));
		archivo.write(nombre, sizeof(nombre));
		archivo.write(marca, sizeof(marca));
		archivo.write(&tipo, sizeof(char));
		archivo.write(reinterpret_cast<const char*>(&precio), sizeof(double));
	}
};

void reemplazarvalores(vector<Comercio*> &productos) {
	ofstream archivo("productos.dat", ios::binary | ios::trunc);
	if (archivo.fail()) {
		cout << "ERROR AL ABRIR EL ARCHIVO" << endl;
		return;
	}
	for (const auto& producto : productos) {
		producto->agregararchivo(archivo);
	}
	archivo.close();
}

void leerarchivo() {
	ifstream archivo("productos.dat", ios::binary);  // Corrección aquí
	if (archivo.fail()) {
		cout << "ERROR AL ABRIR EL ARCHIVO" << endl;
		return;
	}
	
	vector<Comercio*> productos;
	double porcentaje;
	cout << "CUAL ES EL PORCENTAJE QUE SUBIO EL DOLAR?" << endl << ">";
	cin >> porcentaje;
	
	while (archivo.peek() != EOF) {
		int code;
		char nombre[50], marca[20], tipo;
		double precio;
		
		archivo.read(reinterpret_cast<char*>(&code), sizeof(int));
		archivo.read(nombre, sizeof(nombre));
		archivo.read(marca, sizeof(marca));
		archivo.read(&tipo, sizeof(char));
		archivo.read(reinterpret_cast<char*>(&precio), sizeof(double));
		
		if (tipo == 'N' || tipo == 'I') {
			Electrodomesticos *e = new Electrodomesticos();
			e->setdatos(code, nombre, marca, tipo, precio);
			e->actualizar(porcentaje);
			productos.push_back(e);
		} else if (tipo == 'J') {
			ProductosJardin* pj = new ProductosJardin();
			pj->setdatos(code, nombre, marca, tipo, precio);
			pj->actualizar();
			productos.push_back(pj);
		}
	}
	archivo.close();
	
	if (!productos.empty()) {
		reemplazarvalores(productos);
	}
	
	// Liberar memoria
	for (const auto& p : productos) {
		delete p;
	}
}

int main() {
	leerarchivo();
	return 0;
}
