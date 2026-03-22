#include <iostream>
#include <string>
using namespace std;

int main(int argc, char *argv[]) {
	string cad1, cad2, cad3;
	
	cout << "Ingrese las 3 cadenas: " << endl;
	getline(cin, cad1);
	getline(cin, cad2);
	getline(cin, cad3);
	
	
	if ((cad2.find(cad1) != -1) && (cad3.find(cad1) != -1)){
		cout << "Cadena 1 esta incluida en la cadena 2 y cadena 3" << endl;
	} 
	else if (cad2.find(cad1) != -1){
		cout << "Cadena 1 esta incluida en la cadena 2" << endl;
	}
	else if (cad3.find(cad1) != -1){
		cout << "Cadena 1 esta incluida en la cadena 3" << endl;
	}
	
	
	
	if ((cad1.find(cad2) != -1) && (cad3.find(cad2) != -1)){
		cout << "Cadena 2 esta incluida en la cadena 1 y cadena 3" << endl; 
	}
		else if (cad1.find(cad2) != -1){
			cout << "Cadena 2 esta incluida en la cadena 1" << endl;
	}
		else if (cad3.find(cad2) != -1){
				cout << "Cadena 2 esta incluida en la cadena 3" << endl;
		}

	if ((cad1.find(cad3) != -1) && (cad2.find(cad3) !=-1)){
			cout << "Cadena 3 esta incluida en la cadena 1 y 3";
	} 	
		else if ( cad1.find(cad3) != -1){
			cout << "Cadena 3 esta incluida en la cadena 1";
	}
		else if (cad2.find(cad3) != -1){
			cout << "Cadena 3 esta incluida en cadena 2";
		}

	return 0;
}

