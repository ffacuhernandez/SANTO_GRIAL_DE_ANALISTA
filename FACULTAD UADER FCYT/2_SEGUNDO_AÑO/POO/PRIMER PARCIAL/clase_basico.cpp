#include <iostream>
using namespace std;

class rectangulo{
private:
	float largo;
	float ancho;
public:
	rectangulo(float, float);
	void perimetro();
	void area();
};

rectangulo::rectangulo(float _largo, float _ancho){
	largo = _largo;
	ancho = _ancho;
}

void rectangulo::perimetro(){
	float _perimetro = (2*largo) + (2*ancho);
	cout << "El perimetro es: " << _perimetro << endl;
}

void rectangulo::area(){
	float _area = (largo * ancho);
	cout << "El area es :" << _area;
}

int main(int argc, char *argv[]) {
	rectangulo p1(2, 5);
	p1.perimetro();
	p1.area();
	return 0;
}

