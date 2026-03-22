#include <iostream>
#include <fstream>
using namespace std;
float funcion_cuadratica(int a, int b, int c, int x){
	float y;
	y = (a * x * 2) + (b * x) + c;
	return (y);
}
int main(int argc, char *argv[]) {
	ofstream archivo;
	int a, b, c, contador = 0;
	cout << "Ingrese los valores de a, b, c: " << endl << ">";
	cin >> a >> b >> c;
	archivo.open("LOTE_EJERCICIO1.txt", ios::app);
	while (contador < 10){
		int x = 1 + (rand() % 1000);
		float resultadoy = funcion_cuadratica(a, b, c, x);
		archivo << x << "   " << resultadoy << endl;
		contador++;
	}
	
	
	return 0;
}

