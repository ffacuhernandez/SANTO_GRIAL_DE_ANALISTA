#include <iostream>
using namespace std;

int acumulado(int vector[], int n) {
	if (n <= 0) {
		return 0; //si no hay elementos
	}
	return vector[n - 1] + acumulado(vector, n - 1); // Suma el último elemento y llama recursivamente con el resto del vector
}

float promedio(int vector[], int n) {
	float suma =  acumulado(vector, 10); // Usa la función sumaVector para obtener la suma total
	return suma / n; // Calcula el promedio usando la suma y el número de elementos
}

int main() {
	int vector[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // Vector de 10 enteros
	float promediototal = promedio(vector, 10);
	cout << "El promedio total es: " << promediototal << endl;
	return 0;
}
