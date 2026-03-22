#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

void guardarenarchivo(const char* tweet, int contador){
	ofstream archivo ("tweetsbinarios.dat", ios :: binary | ios :: app);
	if (!archivo){
		cout << "ERROR AL ABRIR EL ARCHIVO";
		return;
	}
	int longitud = strlen(tweet);
	archivo.write(reinterpret_cast<const char*>(&contador), sizeof(int));
	archivo.write(reinterpret_cast<const char*>(&longitud), sizeof(int));
	archivo.write(tweet, longitud);
}

void leerarchivo(){
	ifstream archivo("tweets.txt");
	if (!archivo){
		cout << "ERROR AL ABRIR EL ARCHIVO";
		return;
	}
	char linea[200];
	int cuentalineas = 0;
	while (archivo.getline(linea, 200)){
		cuentalineas++;
		linea[140] = '\0';
		guardarenarchivo(linea, cuentalineas);
	}
	archivo.close();
}
	
void leerarchivobinario(){
	ifstream archivo("tweetsbinarios.dat", ios :: binary);
	if (!archivo) {
		cout << "ERROR AL ABRIR EL ARCHIVO" << endl;
		return;
	}
	while (archivo.peek() != EOF){
		int numtweet, longitud;
		archivo.read(reinterpret_cast<char*>(&numtweet), sizeof(int));
		archivo.read(reinterpret_cast<char*>(&longitud), sizeof(int));
		char* tweet = new char[longitud + 1];
		archivo.read(tweet, longitud);
		tweet[longitud] = '\0';
		cout << "TWEET #" << numtweet << ": " << tweet << endl;
		delete[] tweet;
	}
	archivo.close();
}

int main(int argc, char *argv[]) {
	leerarchivo();
	leerarchivobinario();
	return 0;
}

