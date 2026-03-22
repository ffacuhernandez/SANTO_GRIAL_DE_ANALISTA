#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main(int argc, char *argv[]) {
	int codigop, preciou[12] = {0}, cantvendida, cantotal[12] = {0}, total[12] = {0}, sumatotal[12] = {0}, menor=9999, prodmenor;
	string descri[12];
	for (int i=0; i<12; i++){
		cout << "Ingrese la descripcion del producto " << i+1 << ":" << endl;
		getline (cin,descri[i]);
		cout << "Ingrese el precio unitario del producto " << i+1 << ":" << endl;
		cin >> preciou[i];
		cin.get();
	}
	cout << "Ingrese numero de producto (1 a 12): " << endl << ">";
	cin >> codigop;
	while (codigop != 0){
		cout << "Ingrese cantidad vendida de ese producto: " << endl;
		cin >> cantvendida;
		total[codigop-1]+=(preciou[codigop-1]*cantvendida);//calculo de totales para cada producto
		sumatotal[codigop-1]+=cantvendida;//calculo de cantidades vendidas para el punto b;
		cout << "Ingrese numero de producto: " << endl << ">";
		cin >> codigop;
		if (sumatotal[codigop-1]< menor)
		{
			menor = sumatotal[codigop-1];
			prodmenor= codigop;
		}
	}
	
	cout << "NRO DE PRODUCTO: " << setw(10) << " DESCRIPCION: " <<  setw(10)  << " CANTIDAD TOTAL VENDIDA: " <<  setw(22) << " IMPORTE TOTAL: " << endl;
	for (int i=0; i<12; i++){
		cout << i + 1 <<  setw(25) << descri[i] << setw(25)  <<  cantotal[i] << setw(25)  <<sumatotal[i] << endl;
	}
	cout << "Producto menos vendido: " << prodmenor;
	return 0;
}

