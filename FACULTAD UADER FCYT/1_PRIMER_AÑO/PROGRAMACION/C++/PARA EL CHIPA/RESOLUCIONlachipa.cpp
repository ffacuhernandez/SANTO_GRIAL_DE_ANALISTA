#include <iostream>
#include <fstream>
#include <string>

/*
	Final 30-11-2023
	Resolucion by Chotawer
*/

using namespace std;

/// Struct
struct ALUMNO{
	string DNI;
	string NyA; // Nombre y Apellido
	string fecha_Inicio;
	int tipo_entrenamiento; // 1,2,3,4,5
	string situacion = "Alta";
	int antiguedad; // En meses
	bool NoParticipa = false; // Indica si el alumno NO participa, al principio arranca falso porque no sabemos quienes NO participarán.
};

/// Funciones
int obtenerAntiguedad(string fecha_inscripcion);
void ordenar(ALUMNO alumnos[], int MAX);

int main(int argc, char *argv[]) {
	/// Variables
	const int MAX = 500;
	int cant_alumnos = 0; // Cantidad de alumnos
	ALUMNO alumnos[MAX];
	
	/// Lectura de datos
	ifstream archivo; archivo.open("./ALUMNOS.txt");
	if (archivo.fail())
		return 1;
	else 
		while(getline(archivo,alumnos[cant_alumnos].DNI)){
			getline(archivo,alumnos[cant_alumnos].NyA);
			archivo >> alumnos[cant_alumnos].fecha_Inicio 
				>> alumnos[cant_alumnos].tipo_entrenamiento;
			archivo.ignore();
			
			cant_alumnos++;
		}
	archivo.close(); 
	
	archivo.open("./ACTUALIZACION.txt");
	if (archivo.fail())
		return 1;
	else 
		while(getline(archivo,alumnos[cant_alumnos].DNI)){
			getline(archivo,alumnos[cant_alumnos].NyA);
			archivo >> alumnos[cant_alumnos].tipo_entrenamiento 
				>> alumnos[cant_alumnos].fecha_Inicio 
				>> alumnos[cant_alumnos].situacion;
			archivo.ignore();
			
			cant_alumnos++;
		}
	archivo.close(); 
		
	/// Antiguedad
	for (int i = 0; i < cant_alumnos; i++)
		alumnos[i].antiguedad = obtenerAntiguedad(alumnos[i].fecha_Inicio);
	
	/// Punto A
	ordenar(alumnos,cant_alumnos);
	cout << "DNI" << "   Nombre y Apellido" << "  Antigüedad" << endl;
	for (int i = 0; i < cant_alumnos; i++)
		if ((alumnos[i].antiguedad >= 6) && (alumnos[i].situacion == "Alta"))
			cout << alumnos[i].DNI << "  " << alumnos[i].NyA << "  " << alumnos[i].antiguedad << endl;
		else
			alumnos[i].NoParticipa = true;
	cout << endl;
	
	/// Punto B
	int MatrizB[5][5] = {0};
	for (int i = 0; i < cant_alumnos; i++){
		int indice = alumnos[i].tipo_entrenamiento -1;
		if (alumnos[i].antiguedad >= 31)
			MatrizB[indice][4]++;
		else if (alumnos[i].antiguedad >= 25)
			MatrizB[indice][3]++;
		else if (alumnos[i].antiguedad >= 19)
			MatrizB[indice][2]++;
		else if (alumnos[i].antiguedad >= 13)
			MatrizB[indice][1]++;
		else if (alumnos[i].antiguedad >= 6)
			MatrizB[indice][0]++;
		}
	
	string entrenamiento[]{"Semipersonalizado","Personalizado","Funcional","Crossfit","Calistenia"};
	for (int i = 0; i < 5; i++){
		cout << entrenamiento[i] << "  ";
		for (int j = 0; j < 5; j++)
			cout << MatrizB[i][j] << "  ";
		cout << endl;	
	}	

	/// Punto C
	ofstream no_participan; no_participan.open("./ALUMNOS-QUE-NO-PARTICIPAN.txt");
	for (int i = 0; i < cant_alumnos; i++){
		if (alumnos[i].NoParticipa){
			no_participan << alumnos[i].DNI << " | " << alumnos[i].NyA << " | ";
			if (alumnos[i].situacion == "Baja")
				no_participan << "Baja" << endl;
			else 
				no_participan << "Antiguedad insuficiente" << endl;
		}
	}
	no_participan.close();
	
	return 0;
}

int obtenerAntiguedad(string fi){
	int antiguedad, 
		mes_actual = 10,
		anio_actual = 2023;
	int anio_ingreso = stoi(fi.substr(0,4));	// AAAA
	int mes_ingreso = stoi(fi.substr(5,2));		// MM
	
	/*
		Solo vamos a utilizar los meses para simplificar el calculo; 
		La forma de saber la antiguedad es simple, en caso de haber ingresado un año anterior
		a 2023, calculamos la cantidad de años de antiguedad y multiplicamos por 12 para
		obtener directamente los meses, y luego le sumamos la cantidad de meses de antiguedad.
		Notese que si entro en un mes posterior a 10 se descontarán meses.
	*/
	
	if (anio_ingreso < 2023){
		antiguedad = (anio_actual - anio_ingreso) * 12;
		antiguedad += (mes_actual - mes_ingreso);
	} else 
		antiguedad = mes_actual - mes_ingreso;
	
	return antiguedad;
}
	
void ordenar(ALUMNO a[], int MAX){
	for (int i = 0; i < MAX-1; i++)
		for (int j = i+1; j < MAX; j++)
			if (a[i].antiguedad < a[j].antiguedad){
				ALUMNO aux = a[i];
				a[i] = a[j];
				a[j] = aux;
			}
}
