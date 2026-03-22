#include <iostream>
using namespace std;

int division_entera(int num1, int num2, int& resto){
	int cociente = num1 / num2;
	resto = num1 % num2;
	return cociente;
}
int main(int argc, char *argv[]) {
	int num1 = 0, num2 = 0, resto;
	cout << "Ingrese el primer numero por el cual se va a dividir: " << endl << ">";
	cin >> num1;
	cout << "Ingrese el numero por el cual se va a dividir el primero: " << endl << ">";
	cin >> num2;
	int resultado = division_entera(num1,num2, resto);
	cout << "EL RESULTADO ES " << resultado << " Y EL RESTO ES " << resto;
	return 0;
}

