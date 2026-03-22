#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

class Gastos{
protected:
	vector<const char*> descripcion;
	vector<int> precios;
public:
	void mostrar_gastos(){
		int tope = descripcion.size();
		for (int i = 0; i < tope; i++){
			cout << descripcion[i] << " ..............$" << precios[i] << endl;
		}
	}
	~Gastos() {  // Destructor para liberar la memoria
		for (const auto& d : descripcion) {
			delete[] d;  // Liberar la memoria de cada cadena
		}
	}
};

class Gastocompra : public Gastos{
public:
	void agregar(const char* descri, int precio){
		char cadena[100];
		strcpy(cadena, "Gasto extraordinario ");
		strcat(cadena, descri);  // Concatenamos el texto
		
		// Asignamos memoria dinámica para la cadena
		char* nuevaCadena = new char[strlen(cadena) + 1];
		strcpy(nuevaCadena, cadena);  // Copiamos la cadena al nuevo espacio
		
		descripcion.push_back(nuevaCadena);
		precios.push_back(precio);
	}
};

class Gastoservicio : public Gastos{
public:
	void agregar(const char* descri, int precio){
		char cadena[100];
		strcpy(cadena, "Gasto extraordinario ");
		strcat(cadena, descri);  // Concatenamos el texto
		
		// Asignamos memoria dinámica para la cadena
		char* nuevaCadena = new char[strlen(cadena) + 1];
		strcpy(nuevaCadena, cadena);  // Copiamos la cadena al nuevo espacio
		
		descripcion.push_back(nuevaCadena);
		precios.push_back(precio);
	}
};

class Gastoextraordinario : public Gastos{
public:
	void agregar(const char* descri, int precio){
		char cadena[100];
		strcpy(cadena, "Gasto extraordinario ");
		strcat(cadena, descri);  // Concatenamos el texto
		
		// Asignamos memoria dinámica para la cadena
		char* nuevaCadena = new char[strlen(cadena) + 1];
		strcpy(nuevaCadena, cadena);  // Copiamos la cadena al nuevo espacio
		
		descripcion.push_back(nuevaCadena);
		precios.push_back(precio);
	}
};

int main(int argc, char *argv[]) {
	int opcion;
	Gastocompra compra;
	compra.agregar("productos de limpieza", 3000);
	Gastoservicio servicio;
	servicio.agregar("ServiLimp", 2500);
	Gastoextraordinario extraordinario;
	extraordinario.agregar("Medialunas para la reunión", 100);
	cout << "Ingrese una opcion: " << endl;
	cout << "1 - MOSTRAR GASTOS POR COMPRA" << endl;
	cout << "2 - MOSTRAR GASTOS POR SERVICIO" << endl;
	cout << "3 - MOSTRAR GASTOS EXTRAORDINARIOS" << endl;
	cout << "4 - MOSTRAR TODOS LOS GASTOS HECHOS" << endl;
	cout << ">";
	cin >> opcion;
	switch (opcion){
	case 1:
		cout << "Gastos por Compra:" << endl;
		compra.mostrar_gastos();
		break;
	case 2:
		cout << "Gastos por Servicio:" << endl;
		servicio.mostrar_gastos();
		break;
	case 3:
		cout << "Gastos Extraordinarios:" << endl;
		extraordinario.mostrar_gastos();
		break;
	case 4:
		cout << "GASTOS EN TOTAL: " << endl;
		compra.mostrar_gastos();
		servicio.mostrar_gastos();
		extraordinario.mostrar_gastos();
	}
	return 0;
}

