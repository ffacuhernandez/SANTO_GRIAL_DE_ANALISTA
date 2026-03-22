#include <iostream>
using namespace std;
/* Escribir un programa que pida 10 números enteros por teclado, los almacene en un vector llamado NUM y luego emita los siguientes informes: a) Cuántos de esos números son pares. 
b) Cuál es el valor del número máximo. c) Cuál es el valor del número mínimo. d) Se ingrese un valor entero e indique si este número está entre los almacenados en el arreglo.*/
int main(int argc, char *argv[]) {
	int numeros[10]={0};
	int a=0, min = 999, max=0;
	cout << "Ingrese 10 valores enteros: " << endl;
	
	for (int i = 0; i < 10; i++){
		cin >> numeros[i];
		if (numeros[i] % 2 == 0){
			a++;
		}
		if (numeros[i] > max){
			max = numeros[i];
		} 
		if (numeros[i] < min){
			min = numeros[i];
		}     
	}
	
	cout << "Cantidad de numeros pares: " << a << endl;
	cout << "Numero maximo: " << max << endl;
	cout << "Numero minimo: " << min << endl;
	
	int valorIngresado;
	std::cout << "Ingrese un valor entero: ";
	std::cin >> valoringresado;
	
	// Inicializar una bandera para indicar si el valor está en el arreglo
	bool encontrado = false;
	
	// Iterar a través del arreglo y verificar si el valor está presente
	for (int i = 0; i < 10; i++) {
		if (valoringresado == numeros[i]) {
			encontrado = true;
		}
	}
	
	// Mostrar el resultado
	if (encontrado) {
		cout << "El valor " << valoringresado << " está en el arreglo." << endl;
	} else {
		cout << "El valor " << valoringresado << " no está en el arreglo." << endl;
	}
	return 0;
}

