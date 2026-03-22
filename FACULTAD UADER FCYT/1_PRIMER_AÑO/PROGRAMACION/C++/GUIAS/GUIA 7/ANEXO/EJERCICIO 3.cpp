#include <iostream>
using namespace std;

bool EsImpar(int a){
	return a % 2 == 0;
}
	
int main(int argc, char *argv[]) {
	int num;
	cout << "Ingrese un numero para saber si es par o no: " << endl << ">";
	cin >> num;
	if (EsImpar(num)){
		cout << "El numero es par";
	} else{
		cout << "El numero es impar";
	}
	return 0;
}

