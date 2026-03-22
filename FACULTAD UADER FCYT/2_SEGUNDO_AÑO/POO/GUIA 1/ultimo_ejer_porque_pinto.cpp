#include <iostream>
using namespace std;

bool es_vocal(char n){
	if (n == 'a' || n == 'e' || n == 'i' || n == 'o' || n == 'u'){
		return true;
	} else 
	return false;
}

int main(int argc, char *argv[]) {
	char letra;
	cout << "Ingrese una letra: " << endl << ">";
	cin >> letra;
	bool resultado = es_vocal(letra);
	if (resultado){
		cout << "LA LETRA " << letra << " ES UNA VOCAL" << endl;
	} else {
		cout << "LA LETRA " << letra << " NO ES UNA VOCAL" << endl;
	}
	return 0;
}

