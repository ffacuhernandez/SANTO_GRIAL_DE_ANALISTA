#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main(int argc, char *argv[]) {
	string palabras[100], p;
	int matriz[100][3], c = 0;
	int n;
	cout << "Ingrese la cantidad de palabras: ";
	cin >> n;
	cin.ignore();
	for (int i = 0; i < n; i++){
		cout << "Ingrese la palabra numero " << i + 1<< endl << ">";
		getline(cin,p);
		palabras[i] = p; 
	}
	
	for (int i = 0; i < n; i++){
		char largo = palabras[i].size();
		matriz[i][0] = largo;
	}
	
	for( int i=0;i<=n;i++){    ///SACAR LA CANTIDAD DE VOCALES, ASÍ PODES SACAR LA CANTIDAD DE CONSONANTES
		int a = palabras[i].find("a");        ///a
		while (a != -1){
			c++;
			a = palabras[i].find("a",a+1);
		}
		int e = palabras[i].find("e");        ///e
		while (e != -1){
			c++;
			e = palabras[i].find("e",e+1);
		}
		int ii = palabras[i].find("i");        ///i
		while (ii != -1){
			c++;
			ii = palabras[i].find("i",ii+1);
		}
		int o = palabras[i].find("o");        ///o
		while (o != -1){
			c++;
			o = palabras[i].find("o",o+1);
		}
		int u = palabras[i].find("u");        ///u
		while (u != -1){
			c++;
			u = palabras[i].find("u",u+1);
		}
		matriz[i][1] = c;
		c = 0;
	}
	
	for (int i = 0; i<=n; i++){
		matriz[i][2] = matriz[i][0] - matriz[i][1];
	}
	
	cout << "PALABRA " << setw(8)<< "LARGO" << setw(15) << "CONSONANTES" << setw(12) << "VOCALES" << setw(20) << "OTROS CARACTERES" << endl; 
	for (int i = 0; i < n; i++){
		cout << setw(5) << palabras[i] << setw(9) << matriz[i][0] << setw(11) << matriz[i][2] << setw(13) << matriz[i][1] << endl; 
	}
	return 0;
}

