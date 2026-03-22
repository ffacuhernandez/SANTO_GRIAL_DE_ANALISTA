#include <iostream>
using namespace std;

class NumeroComplejo{
private:
	float real;
	float imaginaria;
public:
	NumeroComplejo(float r, float i){
		real = r;
		imaginaria = i;
	}
	NumeroComplejo sumar (NumeroComplejo otro){
		float suma_real = real + otro.real;
		float suma_imaginaria = imaginaria + otro.imaginaria;
		return NumeroComplejo(suma_real, suma_imaginaria);
	}
	NumeroComplejo restar (NumeroComplejo otro){
		float resta_real = real - otro.real;
		float resta_imaginaria = imaginaria - otro.imaginaria;
		return NumeroComplejo(resta_real, resta_imaginaria);
	}
	NumeroComplejo multiplicar (NumeroComplejo otro){
		float multi_real = real * otro.real - imaginaria * otro.imaginaria;
		float multi_imaginaria = real * otro.imaginaria + imaginaria * otro.real;
		return NumeroComplejo(multi_real, multi_imaginaria);
	}
	NumeroComplejo dividir(NumeroComplejo otro) {
		float denominador = otro.real * otro.real + otro.imaginaria * otro.imaginaria;
		float nuevaReal = (real * otro.real + imaginaria * otro.imaginaria) / denominador;
		float nuevaImaginaria = (imaginaria * otro.real - real * otro.imaginaria) / denominador;
		return NumeroComplejo(nuevaReal, nuevaImaginaria);
	}
	void mostrar(){
		cout << real;
		if (imaginaria >= 0){
			cout << " + " << imaginaria << "i";
		} else {
			cout << " - " << -imaginaria << "i";
		}
	}
};

int main(int argc, char *argv[]) {
	NumeroComplejo num1(3.5, 4.2);
	NumeroComplejo num2(1.5, 2.8);
	
	//MOSTRANDO LOS NUMERINES
	cout << "Los numeros empleados son < ";
	num1.mostrar();  // Imprime el primer número complejo
	cout << " y ";
	num2.mostrar();  // Imprime el segundo número complejo
	cout << " > y ahora se le hacen operaciones: " << endl;
	
	//SUMA
	cout << "SUMA: ";
	NumeroComplejo resultadosuma = num1.sumar(num2);
	resultadosuma.mostrar();  // Imprime el resultado de la suma
	cout << endl;
	
	//RESTA
	cout << "RESTA: ";
	NumeroComplejo resultadoresta = num1.restar(num2);
	resultadoresta.mostrar();
	cout << endl;
	
	//MULTIPLICACION
	cout << "MULTIPLICACION: ";
	NumeroComplejo resultadomulti = num1.multiplicar(num2);
	resultadomulti.mostrar();
	cout << endl;
	
	//DIVISION
	cout << "DIVISION: ";
	NumeroComplejo resultadodivision = num1.dividir(num2);
	resultadodivision.mostrar();
	
	return 0;
}

