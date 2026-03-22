#include <iostream>
using namespace std;
int elmenor(int a, int b){
	int x;
	if (a < b){
		x = a;
	} else {
		x = b;
	}
	return (x);
}
int main(int argc, char *argv[]) {
	int num1, num2;
	cout << "Ingrese dos numeros: " << endl << ">";
	cin >> num1 >> num2;
	int menor = elmenor(num1, num2);
	cout << "EL NUMERO MENOR ES: " << menor;
	return 0;
}

