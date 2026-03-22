#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

int main(int argc, char *argv[]) {
	int dni, n1,n2, documento[3], nota1[3],nota2[3], i=0, aux, j;
	string nya,nyaa[3], auxs;
	
	cout<<"Ingresar DNI del alumno: ";
	cin>>dni;
	while(dni!=0){
		cin.ignore();
		cout<<"Ingrese nombre y apellido: ";
		getline(cin, nya);
		
		cout<<"Ingrese la nota del primer parcial: ";
		cin>>n1;
		
		cout<<"Ingrese la nota del segundo parcial: ";
		cin>>n2;
		
		documento[i]=dni;
		nota1[i]=n1;
		nota2[i]=n2;
		nyaa[i]=nya;
		
		cout<<"Ingrese DNI del alumno: ";
		cin>>dni;
		
		
		i++;
	}
	
	///Ordenamiento
	for(i=0;i<(3-1); i++){
		for(j=i+1; j<3; j++){
			if(documento[i]>documento[j]){
				aux=documento[i];
				documento[i]=documento[j];
				documento[j]=aux;
				
				aux=nota1[i];
				nota1[i]=nota1[j];
				nota1[j]=aux;
				
				aux=nota2[i];
				nota2[i]=nota2[j];
				nota2[j]=aux;
				
				auxs=nyaa[i];
				nyaa[i]=nyaa[j];
				nyaa[j]=auxs;
			}
		}
	}
	
	ofstream archivo;
	archivo.open("FUPRO_2.TXT",ios::out);
	
	if(archivo.fail()){
		cout<<"hubo un error en abrir el archivo.";
	}else{
		for(int i = 0;i<2;i++){
			archivo<<"Nombre y apellido: "<<nyaa[i]<<setw(10)<<"DNI: "<<documento[i]<<endl;
			archivo<<"Nota 1: "<<nota1[i]<<setw(10)<<"nota 2: "<<nota2[i]<<endl;
		}
		archivo.close();
	}
	return 0;
}

