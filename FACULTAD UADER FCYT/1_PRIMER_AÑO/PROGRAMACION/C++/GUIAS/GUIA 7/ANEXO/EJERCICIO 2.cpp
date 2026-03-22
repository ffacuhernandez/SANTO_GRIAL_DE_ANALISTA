#include <iostream>
using namespace std;
void intercambiador(int &a, int &b){
	int aux = a;
	a = b;
	b = aux;
}

int main(int argc, char *argv[]) {
	int n1, n2;
	cout << "Ingrese el primer numero: " << endl << ">";
	cin >> n1;
	cout << "Ingrese el segundo numero: " << endl << ">";
	cin >> n2;
	cout << "Valores originales: " << n1 << " y " << n2 << endl;
	intercambiador(n1, n2);
	cout << "Valores intercambiados: " << n1 << " y " << n2 << endl;
	
	return 0;
}

