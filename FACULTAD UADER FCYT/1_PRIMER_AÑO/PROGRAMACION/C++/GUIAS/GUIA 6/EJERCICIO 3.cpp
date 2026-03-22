#include <iostream>
using namespace std;
/*Una distribuidora de Alimentos para Mascotas dispone de una lista con los códigos de cliente (números) y su saldo. 
La cantidad  de clientes se lee al inicio. Se pide ingresar el código de cliente y a través de ese dato informar su saldo. 
De no existir el código ingresado informar un mensaje que indique “CLIENTE INEXISTENTE”.*/
int main(int argc, char *argv[]) {
	int n, cod, clientes [5][3], busqueda, saldo;
	cout << "Ingrese la cantidad de clientes: " << endl << ">";
	cin >> n;
	int i = 0;
	for (int i = 0; i < n; i++){
		cout << "Ingrese el codigo del cliente numero " << i + 1 << ":" << endl << ">";
		cin >> cod;
		clientes [i][0] = cod;
		cout << "Ingrese el saldo del cliente: " << endl << ">";
		cin >> saldo;
		clientes [i][1] = saldo;
	}
	cout << "Ingrese el codigo de cliente que desea conocer el saldo: " << endl << ">";
	cin >> busqueda;
	int bandera = 0;
	int pos = 0;
	i = 0;
	while (i < n){
		if ( busqueda == clientes[i][0]){
			bandera = 1;
			pos = i;
			i = n;
		}
		i++;
	}
	if (bandera == 0){
		cout << "CLIENTE INEXISTENTE";
	} else{
		cout << "EL SALDO ES DE: " << clientes[pos][1];
	}
	return 0;
}

