#include <iostream>
using namespace std;

///Realice una clase que represente una Fracción.
///	a) Un objeto fracción solo se puede construir a partir de un numerador y denominador.
///	b) Un objeto fracción debe poder sumar, restar, multiplicar y dividir.
///	c) Un objeto fracción debe poder simplificarse

class fraccion{
private:
	int numerador;
	int denominador;
	
	int mcd(int a, int b) { // PARA SIMPLIFICAR FRACCION USAMOS ALGORITMO DE EUCLIDES
		while (b != 0) {  // Mientras que b no sea 0
			int aux = b;
			b = a % b;      // El resto de a dividido por b
			a = aux;       // Cambiamos a por b y b por el resto
		}
		return a;  // Cuando b es 0, a contiene el MCD
	}
public:
	fraccion(int n, int d){
		numerador = n;
		denominador = d;
	}
	fraccion sumar(fraccion otro){
		int newnumer = numerador * otro.denominador + denominador * otro.numerador;
		int newdenom = denominador * otro.denominador;
		return fraccion(newnumer, newdenom);
	}
	fraccion restar(fraccion otro){
		int newnumer = numerador * otro.denominador - denominador * otro.numerador;
		int newdenom = denominador * otro.denominador;
		return fraccion(newnumer, newdenom);
	}
	// Método para simplificar la fracción
	void simplificar() {
		int num_mcd = mcd(abs(numerador), abs(denominador)); // Calcula el MCD
		numerador /= num_mcd; // Divide el numerador por el MCD
		denominador /= num_mcd; // Divide el denominador por el MCD
		
		// Si el denominador es negativo, hacer que el denominador sea positivo
		if (denominador < 0) {
			numerador = -numerador;
			denominador = -denominador;
		}
	}
	void mostrar(){
		if (numerador < 0 && denominador < 0){
			cout << -numerador << "/" << -denominador << "NASHEENTROO";
		} else {
			cout << numerador << "/" << denominador;
		}
	}
};
int main(int argc, char *argv[]) {
	fraccion num1(-2, -3);
	fraccion num2(-7, 14);
	fraccion num3(8, 4);
	
	//SUMA
	fraccion sum_resul = num1.sumar(num2);
	sum_resul.simplificar();
	sum_resul.mostrar();
	cout << endl;
	
	//RESTA
	fraccion res_resul = num1.restar(num2);
	res_resul.simplificar();
	res_resul.mostrar();
	cout << endl;
	
	// SIMPLIFICO PA PROBAR
	num3.simplificar();
	num3.mostrar();
	
	return 0;
}

