#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct Evento {
	int nro;
	char descripcion[100];
	char tipoDeNotificacion;
};

void generarArchivo() {
	ofstream archivo("eventos.dat", ios::binary);
	if (archivo.fail()) {
		cout << "Error al abrir el archivo." << endl;
		return;
	}
	// Crear evento
	Evento evento1;
	evento1.nro = 1;
	archivo.write(reinterpret_cast<const char*>(&evento1.nro), sizeof(evento1.nro));
	strncpy(evento1.descripcion, "Evento importante", sizeof(evento1.descripcion) - 1);
	evento1.descripcion[sizeof(evento1.descripcion) - 1] = '\0'; // Asegurar el terminador nulo
	archivo.write(evento1.descripcion, sizeof(evento1.descripcion));
	evento1.tipoDeNotificacion = 'T';
	archivo.write(&evento1.tipoDeNotificacion, sizeof(evento1.tipoDeNotificacion));
	
	Evento evento2;
	evento2.nro = 2;
	archivo.write(reinterpret_cast<const char*>(&evento2.nro), sizeof(evento2.nro));
	strncpy(evento2.descripcion, "Mensaje por consola", sizeof(evento2.descripcion) - 1);
	evento2.descripcion[sizeof(evento2.descripcion) - 1] = '\0'; // Asegurar el terminador nulo
	archivo.write(evento2.descripcion, sizeof(evento2.descripcion));
	evento2.tipoDeNotificacion = 'C';
	archivo.write(&evento2.tipoDeNotificacion, sizeof(evento1.tipoDeNotificacion));
	
	Evento evento3;
	evento3.nro = 3;
	archivo.write(reinterpret_cast<const char*>(&evento3.nro), sizeof(evento3.nro));
	strncpy(evento3.descripcion, "Archivo binario", sizeof(evento3.descripcion) - 1);
	evento3.descripcion[sizeof(evento3.descripcion) - 1] = '\0'; // Asegurar el terminador nulo
	archivo.write(evento3.descripcion, sizeof(evento3.descripcion));
	evento3.tipoDeNotificacion = 'B';
	archivo.write(&evento3.tipoDeNotificacion, sizeof(evento3.tipoDeNotificacion));
	
	archivo.close();
	cout << "Archivo generado con éxito!" << endl;
}

int main() {
	generarArchivo();
	return 0;
}
