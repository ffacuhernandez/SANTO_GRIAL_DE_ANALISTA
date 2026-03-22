#include <iostream>
using namespace std;


string masvendido(int cantA, int cantB, int cantC);

int main(int argc, char *argv[]) {
	float puA, puB, puC;
	string modelo;
	int pedidos[10][3] = {0}, i, j, numDist, cantidad;
	cout<<"Ingrese el pecio unitario del modelo A: ";
	cin>>puA;
	cout<<"Ingrese el pecio unitario del modelo B: ";
	cin>>puB;
	cout<<"Ingrese el pecio unitario del modelo C: ";
	cin>>puC;
	cout<<"Ingrese número de distribuidor: ";
	cin>>numDist;
	while(numDist!=999){
		j=0;
		cout<<"Ingrese el modelo: ";
		cin>>modelo;
		if(modelo=="A"){
			j=0;
		} else if (modelo=="B"){
			j=1;
		} else if(modelo=="C"){
			j=2;
		}
		cout<<"Ingrese cantidad pedida:";
		cin>>cantidad;
		pedidos[numDist-1][j] += cantidad;
		cout<<"Ingrese número de distribuidor: ";
		cin>>numDist;
	}
	for(i=0; i<10;i++){
		cout<<"Nro de Distribuidor: "<<i+1<<endl;
		cout<<"Modelo Cantidad pedida  Monto"<<endl;
		cout<<"   A  "<<pedidos[i][0]<<" "<<pedidos[i][0] * puA<<endl;
		cout<<"   B  "<<pedidos[i][1]<<" "<<pedidos[i][1] * puB<<endl;
		cout<<"   C  "<<pedidos[i][2]<<" "<<pedidos[i][2] * puC<<endl;
	}
		
	for(i=0;i<10;i++){
		cout<<"El nombre del modelo más vendido por el distribuidor "<<i+1<<" es el: "<< masvendido(pedidos[i][0], pedidos[i][1], pedidos[i][2])<<endl;
	}
		
		
	return 0;
}

string masvendido(int cantA, int cantB, int cantC){
	string m="ninguno";
	if((cantA>cantB)&&(cantA>cantC))
		m="A";
	if((cantB>cantA)&&(cantB>cantC))
		m="B";
	if((cantC>cantB)&&(cantC>cantA))
		m="C";
	
	return (m);
}
	
