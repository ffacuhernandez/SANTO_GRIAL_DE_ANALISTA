#include <iostream>
#include <string>
using namespace std;

/*Ingrese una cadena que contenga la palabra 
“pero”. Reemplace dicha palabra por “sin embargo”. */

int main(int argc, char *argv[]) {
	string cadena;
	
	cout << "Ingrese una cadena que contenga la palabra *pero*: " << endl;
	getline (cin,cadena);
	int n = cadena.find("pero");
	cadena.replace(n, 4, "sin embargo");
	cout << cadena;
	
	return 0;
}

