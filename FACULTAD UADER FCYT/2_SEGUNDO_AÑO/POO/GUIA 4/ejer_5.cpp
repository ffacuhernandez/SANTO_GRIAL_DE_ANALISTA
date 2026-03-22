#include <iostream>
using namespace std;

class Alumno{
private:
	int notas[4];
public:
	Alumno(int n1, int n2, int n3, int n4){
		notas[0] = n1;
		notas[1] = n2;
		notas[2] = n3;
		notas[3] = n4;
	}
	float calcular_promedio(){
		int acum = 0;
		for (int i = 0; i < 4; i++){
			acum += notas[i];
		}
		return acum / 4.0;
	}
	void mostrar_notas(){
		for (int i = 0; i < 4; i++){
			cout << "NOTA " << i + 1 << ": " << notas[i] << endl;
		}
		cout << "CON UN PROMEDIO DE: " << calcular_promedio() << endl;
	}
};

class salon{
private:
	Alumno *alumnos[20];
	int cantidad_alumnos;
public:
	salon(){
		cantidad_alumnos = 0;
	}
	void agregar_alumno(Alumno *nuevo){
		if (cantidad_alumnos < 20) {
			alumnos[cantidad_alumnos] = nuevo; 
			cantidad_alumnos++;
		} else {
			cout << "El curso está lleno." << endl;
		}
	}
	void mostrar_notas_alumnos(){
		for (int i = 0; i < cantidad_alumnos; i++){
			cout << "ALUMNO NUMERO " << i + 1 << endl;
			alumnos[i] -> mostrar_notas();
			cout << endl;
		}
	}
	void promedio_salon(){
		float acumulador = 0;
		for (int i = 0; i < cantidad_alumnos; i++){
			acumulador += alumnos[i]->calcular_promedio();
		}
		cout << "EL PROMEDIO DEL SALON ES: " << acumulador / cantidad_alumnos << endl;
	}
};
int main(int argc, char *argv[]) {
	
	salon misalon;
	
	Alumno a1(10, 8, 7, 9); // Notas del primer alumno
	Alumno a2(6, 7, 8, 9);  // Notas del segundo alumno
	Alumno a3(5, 6, 7, 8);  // Notas del tercer alumno
	

	misalon.agregar_alumno(&a1);
	misalon.agregar_alumno(&a2);
	misalon.agregar_alumno(&a3);
	

	misalon.mostrar_notas_alumnos();
	misalon.promedio_salon();
	return 0;
}

