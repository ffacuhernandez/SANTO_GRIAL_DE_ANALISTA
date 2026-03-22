#include <iostream>
#include <cstdlib>
using namespace std;
int main(int argc, char const *argv[])
{
    /*8. Debe generar un vector de N posiciones con números obtenidos al azar entre 1 y C con las
    siguientes restricciones:
    - el vector debe ir llenándose en orden desde la posición 1 hasta la N.
    - los números obtenidos podrán almacenarse si dicho número es mayor al almacenado en la
    posición anterior.
    Apunte elaborado por la cátedra Fundamentos de Programación – Sede Oro Verde Pág. Nro. 1
    - los números obtenidos podrán almacenarse sólo si permiten que el vector pueda ser llenado
    en su totalidad (sin pasar el valor C en la posición N)
    Los valores de N y C se ingresan al inicio*/
    int N,C, numeros[500];
    cout<<"Ingrese la cantidad de posiciones del array "<<endl;
    cin>>N;
    cout<<"Ingrese el rango de el random"<<endl;
    cin>>C;
    numeros[0]=0;
    for (int i = 1; i <= N+1; i++)
    {
        int randomnum = 1 + rand()%C;
        if (randomnum>numeros[i-1])
        numeros[i]=randomnum;
        else i--;
    }
    cout<<"Numeros generados: "<<endl;
    for (int i = 1; i <= N; i++)
    {
        cout<<numeros[i]<<" - ";
    }
    
    return 0;
}
