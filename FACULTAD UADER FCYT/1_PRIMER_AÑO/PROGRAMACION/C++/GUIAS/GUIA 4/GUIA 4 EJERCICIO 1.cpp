#include <iostream>
#include <string>
using namespace std;
/// EJERCICIO 1 Dadas 3 cadenas de caracteres, ordenarlas de acuerdo a su orden alfabético.
int main(int argc, char *argv[]) {
	
	string cad1, cad2, cad3;
	cout << "Ingrese 3 cadena de caracteres: ";
	getline (cin, cad1);
	getline (cin, cad2);
	getline (cin, cad3);
	if ((cad1<cad2) && (cad1<cad3) && (cad2<cad3))
	{
		cout<<cad1<<endl<<cad2<<endl<<cad3;
	}
	else if ((cad1<cad2) && (cad1<cad3) && (cad3<cad2))
	{
		cout<<cad1<<endl<<cad3<<endl<<cad2;
	}
	else if ((cad2<cad1) && (cad2<cad3) && (cad1<cad3))
	{
		cout<<cad2<<endl<<cad1<<endl<<cad3;
	}
	else if ((cad2<cad1) && (cad2<cad3) && (cad3<cad1))
	{
		cout<<cad2<<endl<<cad3<<endl<<cad1;
	}
	else if ((cad3<cad1) && (cad3<cad2) && (cad1<cad2))
	{
		cout<<cad3<<endl<<cad1<<endl<<cad2;
	}
	else if ((cad3<cad1) && (cad3<cad2) && (cad2<cad1))
	{
		cout<<cad3<<endl<<cad2<<endl<<cad1;
	}
	return 0;
}

