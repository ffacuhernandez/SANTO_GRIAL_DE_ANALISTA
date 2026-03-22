#include <iostream>
using namespace std;
/*Escribir un programa que lea una matriz de enteros de 4 filas y 4 columnas 
y a continuación intercambie la fila i con la fila j, siendo i y j dos valores introducidos por teclado.*/
int main(int argc, char *argv[]) {
	int matriz [4][4], fila1, fila2;
	
	for (int i=0; i<4; i++){
		for (int j=0; j<4; j++){
			cout << "Ingrese valor de fila " << i << " y columna " << j << endl << ">";
			cin >> matriz[i][j];
		}
	}
	
	cout << "Matriz original: " << endl;
	for (int i=0; i<4; i++){
		cout << endl;
		for (int j=0; j<4; j++){
			cout << matriz[i][j] << " ";
		}
	}
	cout << endl;
	cout << "Ingrese las dos filas que quiere intercambiar sus valores: " << endl << ">";
	cin >> fila1 >> fila2;
	
	if ((fila1<4)&&(fila2<4)){
		for (int  i = 0; i < 4; i++){
			int anterior = matriz[fila1][i];
			matriz[fila1][i] = matriz[fila2][i];
			matriz[fila2][i] = anterior;
		}
	} else { cout<<"La/s filas seleccionadas no existen   ";
	}
	cout << endl;
	
	cout << "Matriz con fila " << fila1 << " y fila " << fila2 << " intercambiados: " << endl;
	if ((fila1 < 4) && (fila2 < 4))
	{
		for (int  i = 0; i < 4; i++)
		{
			for (int k =0; k < 4;k++)
			{
				cout << matriz[i][k] << "  ";
			}
			cout << endl;
		}
		
	}
	
	return 0;
}

