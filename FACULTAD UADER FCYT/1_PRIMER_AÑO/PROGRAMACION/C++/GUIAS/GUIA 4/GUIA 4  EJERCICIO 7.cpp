#include <iostream>
#include <string>
using namespace std;
/*Dadas 3 cadenas de caracteres, ordenarlas de acuerdo a su largo. */
int main(int argc, char *argv[]) {
	string cad1, cad2, cad3;
	cout << "Ingrese las tres cadenas de caracteres: " << endl;
	getline (cin, cad1);
	getline (cin, cad2);
	getline (cin, cad3);
	int a = cad1.size();
	int n = cad2.size();
	int c = cad3.size();
	if ((n>a)&&(n>c)&&(a>c)){
		cout<<cad2<<endl<<cad1<<endl<<cad3;   
	} else if ((n>a)&&(n>c)&&(c>a)){
		cout<<cad2<<endl<<cad3<<endl<<cad1;     
	} else if ((a>n)&&(a>c)&&(c>n)){
		cout<<cad1<<endl<<cad3<<endl<<cad2;
	} else if ((a>n)&&(a>c)&&(n>c)){
		cout<<cad1<<endl<<cad2<<endl<<cad3;
	} else if ((c>n)&&(c>a)&&(n>a)){
		cout<<cad3<<endl<<cad2<<endl<<cad1;
	} else if ((c>n)&&(c>a)&&(a>n)) {
		cout<<cad3<<endl<<cad1<<endl<<cad2;
	}
	return 0;
}

