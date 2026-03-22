#include <iostream>
using namespace std;

template <class TIPO>
void mostrarvalor(TIPO numero);

int main(int argc, char *argv[]) {
	
	int num1 = -4;
	float num2 = -23.23;
	double num3 = -123.56768;
	mostrarvalor(num1);
	mostrarvalor(num2);
	mostrarvalor(num3);
	
	return 0;
}

template <class TIPO>
	void mostrarvalor(TIPO numero){
	if (numero < 0){
		numero = numero * -1; 
	}
	cout << "EL VALOR ABSOLUTO ES: " << numero << endl;
}
