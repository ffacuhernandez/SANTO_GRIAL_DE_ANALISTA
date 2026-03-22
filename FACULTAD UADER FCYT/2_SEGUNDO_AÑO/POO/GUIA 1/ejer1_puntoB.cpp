#include <iostream>
using namespace std;

int facto(int numero) {
	int resultado = 1;
	for (int i = 1; i <= numero; i++) {
		resultado *= i;
	}
	return resultado;
}


int main(int argc, char *argv[]) {
	int num = 0;
	cout << "Ingrese el numero pa saber su factorial: " << endl << ">";
	cin >> num;
	int factorial = facto(num);
	cout << "El factorial del numero es: " << factorial << endl;
	return 0;
}

