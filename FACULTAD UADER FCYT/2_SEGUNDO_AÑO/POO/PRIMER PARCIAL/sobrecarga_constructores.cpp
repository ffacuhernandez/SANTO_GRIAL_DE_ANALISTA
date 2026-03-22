#include <iostream>
using namespace std;

class tiempo{
private:
	int horas, minutos, segundos;
public:
	tiempo(int, int, int);
	tiempo(int);
	void mostrarhora();
};

tiempo::tiempo(int _horas, int _minutos, int _segundos){
	horas = _horas;
	minutos = _minutos;
	segundos = _segundos;
}

tiempo::tiempo(int tiemposeg){
	horas = tiemposeg/3600;
	tiemposeg %= 3600;
	minutos = tiemposeg / 60;
	segundos = tiemposeg % 60;
}

void tiempo::mostrarhora(){
	cout << "La hora es: " << horas << ":" << minutos << ":" << segundos << endl;
}
int main(int argc, char *argv[]) {
	tiempo horaactual(16,23,30);
	tiempo tiemposegundos(54410);
	horaactual.mostrarhora();
	tiemposegundos.mostrarhora();
	return 0;
}

