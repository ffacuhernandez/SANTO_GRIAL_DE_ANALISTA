#include <iostream>
using namespace std;

/// Realice una clase Cadena que permita representar una cadena cstring. La cadena debe
/// permitir:
/// 	a) Saber cuantos caracteres tiene la cadena
/// 	b) Agregar un carácter al final
/// 	c) Agregar un carácter al principio
/// 	d) Remover la primera ocurrencia de un carácter pasado por parámetro.
/// 	e) Retornar una cadena en mayúscula.

class cadena{
private:
	char texto[100];
	int longitud;
public:
	cadena(const char* t){
		int i = 0;
		while(t[i] != '\0'){
			texto[i]= t[i];
			i++;
		}
		texto[i] = '\0';
		longitud = i;
	}
	void mostrar(){
		cout << texto;
	}
	void longitud_cadena(){
		cout << longitud;
	}
	void agregar_al_final(char c){
		texto[longitud] = c;
		texto[longitud + 1] = '\0';
		longitud++;
	}
	void agregar_al_principio(char c) {
		if (longitud < 99) {  // Comprobamos que haya espacio en el array
			// Desplazamos los caracteres a la derecha
			for (int i = longitud - 1; i >= 0; i--) {
				texto[i + 1] = texto[i];
			}
			texto[0] = c;
			longitud++;
			texto[longitud] = '\0';
		}
	}
	void quitar_ocurrencia(char c){
		int pos = -1;
		for (int i = 0; i < longitud; i++){
			if (c == texto[i]){
				pos = i;
			}
		}
		if (pos != -1){
			for (int i = pos; i < longitud - 1; i++){
				texto[i] = texto[i + 1];
			}
			texto[longitud - 1] = '\0';
			longitud--;
		} else {
			cout << "NO SE ENCONTRO EL DATO BUSCADO, SE MANTIENE LA CADENA" << endl;
		}
	}
	void hacer_mayuscula(){
		for (int i = 0; i < longitud; i++){
			texto[i] = toupper(texto[i]);
		}
	}
};

int main(int argc, char *argv[]) {
	cadena palabra("sexo");
	palabra.mostrar();
	cout << endl;
	palabra.longitud_cadena();
	cout << endl;
	palabra.agregar_al_final('!');
	palabra.mostrar();
	cout << endl;
	palabra.agregar_al_principio('$');
	palabra.mostrar();
	cout << endl;
	palabra.quitar_ocurrencia('o');
	palabra.mostrar();
	cout << endl;
	palabra.hacer_mayuscula();
	palabra.mostrar();
	return 0;
}

