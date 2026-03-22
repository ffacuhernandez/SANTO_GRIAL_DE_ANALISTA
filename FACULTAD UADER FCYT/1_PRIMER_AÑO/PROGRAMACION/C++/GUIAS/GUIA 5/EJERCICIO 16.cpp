#include <iostream>
#include <string>
using namespace std;

int main(int argc, char *argv[]) {
	int reactivos[16] = {0},numeros[15][15] = {0}, cod, cantvendida, codreactivo, calctotal, vnacionales = 0, vinternacionales = 0;
	string trabajadores[15][15], nya, tipoventa;
	for (int i = 0; i < 15; i++){
		cout << "Ingrese el precio del reactivo numero " << i + 1<< ":" << endl << ">";
		cin >> reactivos[i];
	}
	int c = 0;
	do{
		cout << "Ingrese codigo de vendedor: " << endl << ">";
		cin >> cod;
		cin.ignore();
		cout << "Ingrese nombre y apellido del trabajor con el codigo " << cod << ":" << endl << ">";
		getline(cin,nya);
		trabajadores[cod-1][0] = nya;
		c++;
	} while(c < 10);
	cod = 0; /// LO VUELVO A INICIALIZAR EN 0;
	cout << "Ingrese codigo de vendedor: " << endl << ">";
	cin >> cod;
	while (cod != 99){
		cout << "Vendedor " << trabajadores[cod-1][0] << " ingrese codigo de reactivo: " << endl << ">";
		cin >> codreactivo;
		cout << "Ingrese cantidad vendida: " << endl << ">";
		cin >> cantvendida;
		numeros[cod-1][0]+= cantvendida;
		calctotal = cantvendida* reactivos[codreactivo-1];
		numeros[cod-1][1]+=calctotal;
		cin.ignore();
		cout << "Ingrese tipo de venta (n: nacional i:internacional): " << endl << ">";
		cin >> tipoventa;
		if( tipoventa == "n"){
			vnacionales++;
		} else if (tipoventa == "i"){
			vinternacionales++;
		}
		cout << "Ingrese codigo de vendedor: " << endl << ">";
		cin >> cod;
	}
	
	for(int i = 0; i < 10 ; i++){
		cout << "VENDEDOR: " << trabajadores[i][0] << " CON UN TOTAL EN CANTIDAD DE " << numeros[i][0] << " Y UN MONTO FINAL: " << numeros[i][1] << endl;
	}
	cout << "TOTAL DE VENTAS NACIONALES: " << vnacionales << endl;
	cout << "TOTAL DE VENTAS INTERNACIONALES: " << vinternacionales;
	return 0;
}

