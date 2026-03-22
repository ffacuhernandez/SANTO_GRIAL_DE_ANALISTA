#include <iostream>
using namespace std;
int mayornumero(int a, int b, int c){
	int x;
	if ((a > b) && (a > c)){
		x = a;
	} else if ((b > a) && (b > c)){
		x = b;
	} else if ((c > a) && (c > b)){
		x = c;
	}
	return (x);
}
int main(int argc, char *argv[]) {
	int num1, num2, num3;
	cout << "Ingrese el primer numero: " << endl << ">";
	cin >> num1;
	cout << "Ingrese el segundo numero: " << endl << ">";
	cin >> num2;
	cout << "Ingrese el tecer numero: " << endl << ">";
	cin >> num3;
	int mayor = mayornumero(num1, num2, num3);
	cout << "EL MAYOR NUMERO DE LOS TRES ES: " << mayor << " KRAKEN.";
	return 0;
}

