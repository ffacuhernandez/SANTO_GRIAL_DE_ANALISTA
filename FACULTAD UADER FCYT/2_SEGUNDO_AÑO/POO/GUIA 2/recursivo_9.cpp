#include <iostream>
using namespace std;

int calcular_mcd(int a, int b){
	if (a == b){
		return a;
	} else if (a > b){ // (a-b,b)
		a = a - b;
		return calcular_mcd(a, b);
	} else { // (a,b-a)
		b = b - a;
		return calcular_mcd(a, b);
	}
}

int main(int argc, char *argv[]) {
	int primero, segundo;
	cout << "Ingrese el primer numero: " << endl << ">";
	cin >> primero;
	cout << "Ingrese el segundo numero: " << endl << ">";
	cin >> segundo;
	int total = calcular_mcd(primero,segundo);
	cout << "EL MCD ENTRE " << primero << " y " << segundo << " es: " << total;
	return 0;
}

