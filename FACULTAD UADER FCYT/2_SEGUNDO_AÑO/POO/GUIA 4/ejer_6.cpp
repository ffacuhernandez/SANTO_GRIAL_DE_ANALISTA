#include <iostream>
#include <vector>

using namespace std;

class cajero{
private:
	int monto;
	vector<int> denominaciones;
public:
	cajero(int m){
		monto = m;
		denominaciones = {1000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
	}
	vector<int> devolver_cambio(){
		vector<int> vuelto;
		int cant_bichetes = denominaciones.size();
		for (int i = 0; i < cant_bichetes; i++){
			while (monto >= denominaciones[i]){
				monto -= denominaciones[i];
				vuelto.push_back(denominaciones[i]); // SE AGREGA ESE BILLETE
			}
		}
		return vuelto;
	}
};
int main(int argc, char *argv[]) {
	int monto;
	cout << "Ingresa el monto pa: " << endl << ">";
	cin >> monto;
	cajero pago(monto);
	vector<int> vuelto = pago.devolver_cambio();
	cout << "LOS BILLETES Y MONEDAS QUE DEVOLVER SON: " << endl;
	int cantidad_vuelto = vuelto.size();
	for (int i = 0; i < cantidad_vuelto; i++){
		cout << vuelto[i] << " ";
	}
	
	return 0;
}

