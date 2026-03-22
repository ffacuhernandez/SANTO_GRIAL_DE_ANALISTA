#include <iostream>
using namespace std;

///6) Se dispone de una lista con el número de documento de un grupo de alumnos. De cada uno de ellos
///se dispone además de las 3 notas obtenidas en una materia durante el año.
///Se pide realizar un listado ordenado en forma decreciente por promedio del alumno con el siguiente
///formato:
///DOCUMENTO NOTA 1 NOTA 2 NOTA 3 PROMEDIO
///xxxxxxxx 99 99 99 99

int main(int argc, char *argv[]) {
	
	int matriz[10][5],n,i,j,aux=0;
	
	cout << "Ingrese cantidad de alumnos: " << endl;
	cin >> n;
	
	for(i = 0;i < n;i++){
		cout<<"Ingrese dni:"<<endl;
		cin>>matriz[i][0];
		cout<<"Ingrese nota 1:"<<endl;
		cin>>matriz[i][1];
		cout<<"Ingrese nota 2:"<<endl;
		cin>>matriz[i][2];
		cout<<"Ingrese nota 3:"<<endl;
		cin>>matriz[i][3];
		matriz[i][4]=(matriz[i][1]+matriz[i][2]+matriz[i][3])/3;
	}

	///INFORME DE MANERA DECRECIENTE
	for (i=0; i<(n-1); i++){
		for (j=i+1; j<n; j++){
			if (matriz[i][4] > matriz[j][4])
			{
				aux= matriz[i][4];
				matriz[i][4] = matriz[j][4];
				matriz[j][4] = aux;
				aux= matriz[i][0];
				matriz[i][0] = matriz[j][0];
				matriz[j][0] = aux;
				aux= matriz[i][1];
				matriz[i][1] = matriz[j][1];
				matriz[j][1] = aux;
				aux= matriz[i][2];
				matriz[i][2] = matriz[j][2];
				matriz[j][2] = aux;
				aux = matriz[i][3];
				matriz[i][3] = matriz[j][3];
				matriz[j][3] = aux;
			}
		}
	}
	cout<<endl;
	cout<<endl<<"ARREGLO ORDENADO DE MAYOR A MENOR"<<endl;
	for (i=n-1; i>=0; i--){
		for(j=0;j<5;j++){
			cout<<matriz[i][j]<<"   ";
		}
		cout<<endl;
	}
	
	return 0;
}
