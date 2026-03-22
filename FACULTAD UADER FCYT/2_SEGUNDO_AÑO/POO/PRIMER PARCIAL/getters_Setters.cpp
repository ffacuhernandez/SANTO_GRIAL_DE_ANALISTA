#include <iostream>
using namespace std;

class punto{
private:
	int x,y;
public:
	punto();
	void setpunto(int, int);
	int getpuntoX();
	int getpuntoY();
};

punto::punto(){
}

// ESTABLECER VALORES A ATRIBUTOS
void punto::setpunto(int _x, int _y){
	x = _x;
	y = _y; 
}

int punto::getpuntoX(){
	return x;
}

int punto::getpuntoY(){
	return y;
}

int main(int argc, char *argv[]) {
	punto punto1;
	punto1.setpunto(15, 10);
	cout << punto1.getpuntoX() << endl;
	cout << punto1.getpuntoY() << endl;
	return 0;
}

