#include <iostream>
#include <fstream>
using namespace std;

///STRUCT
struct peliculas{
	string codigo;
	string titulo;
	float estrellas;
	string comentario;
	int resenias = 0;
	float totalestrellas = 0;
	float minimo = 0;
	float maximo = 999;
	float maxpuntuacion = 0;
	float minpuntuacion = 0;
	float promedio = 0;
};

/// FUNCIONES
int buscador(string codigox, peliculas datos1[], int contador);
int cuenta_caracteres(string comentario);
int cuenta_miedo(string comentario);
int cuenta_terror(string comentario);
int cuenta_suspenso(string comentario);

/// MAIN
int main(int argc, char *argv[]) {
	
	peliculas datos1[500];
	peliculas datos2[500];
	
	///VARIABLES
	int cont_peliculas = 0;
	int cont_comentarios = 0;
	
	///LECTURA DE ARCHIVOS
	ifstream archivo;
	archivo.open("peliculas.txt");
	if (archivo.fail()){
		cout << "Error al encontrar el txt";
		return 1;
	} else {
		while (getline(archivo,datos1[cont_peliculas].codigo)){
			getline(archivo,datos1[cont_peliculas].titulo);
			cont_peliculas++;
		}
	}
	archivo.close();
	archivo.open("comentarios.txt");
	if (archivo.fail()){
		cout << "Error al encontrar el txt";
		return 1;
	} else {
		while (getline(archivo,datos2[cont_comentarios].codigo)){
			archivo >> datos2[cont_comentarios].estrellas;
			archivo.ignore();
			getline(archivo,datos2[cont_comentarios].comentario);
			cont_comentarios++;
		}
	}
	archivo.close();

	/// ANALISIS DE LAS PELICULAS, SE BUSCA POR POSICION DE CODIGO
	for(int i = 0; i < cont_comentarios; i++){
		int pos = buscador(datos2[i].codigo, datos1, cont_peliculas);
		if (pos != -1){
			datos1[pos].resenias++;
			datos1[pos].totalestrellas += datos2[i].estrellas;
			if (datos2[i].estrellas > datos1[pos].minimo){
				datos1[pos].minimo = datos2[i].estrellas;
				datos1[pos].maxpuntuacion = datos2[i].estrellas;
			}
			if (datos2[i].estrellas < datos1[pos].maximo){
				datos1[pos].maximo = datos2[i].estrellas;
				datos1[pos].minpuntuacion = datos2[i].estrellas;
			}
		}
	}
	
	/// SACANDO CALIFICACION PROMEDIO DE CADA PELICULA, Y SEGUN EL PROMEDIO, LA MEJOR Y PEOR CALIFICADA
	float max = 999;
	float min = 0;
	string mejorpeli = "";
	string peorpeli = "";
	
	for (int  i = 0; i < cont_peliculas; i++){
		datos1[i].promedio = datos1[i].totalestrellas / datos1[i].resenias;
		if (datos1[i].promedio > min){
			min = datos1[i].promedio;
			mejorpeli = datos1[i].titulo;
		}
		if (datos1[i].promedio < max){
			max = datos1[i].promedio;
			peorpeli = datos1[i].titulo;
		}
	}
	
	/// INFORME 1
	for(int i = 0; i < cont_peliculas; i++){
		cout << "CODIGO DE PELICULA: " << datos1[i].codigo << endl;
		cout << "TITULO: " << datos1[i].titulo << endl;
		cout << "CANTIDAD DE RESENIAS: " << datos1[i].resenias << endl;
		cout << "CALIFICACION PROMEDIO: " << datos1[i].promedio << endl;
		cout << "CALIFICAION MINIMA: " << datos1[i].minpuntuacion << " CALIFICACION MAXIMA: " << datos1[i].maxpuntuacion << endl;
		cout << "*******************************************************" << endl;
	}
	cout << "PELICULA MEJOR CALIFICADA: " << mejorpeli << endl;
	cout << "PELICULA PEOR CALIFICADA: " << peorpeli << endl;
	
	cout << "-----------------------------------" << endl;
	
	/// INFORME 2
	/// SABER QUE PELICULA ES LA QUE MAYOR COMENTARIOS TIENE
	min = 0;
	string mascomentarios = "";
	for(int i = 0; i < cont_comentarios; i++){
		if (datos1[i].resenias > min){
			min = datos1[i].resenias;
			mascomentarios = datos1[i].codigo;
		}
	}
	ofstream archivo2;
	string nombrearchivo = "./analisis_[" + mascomentarios + "].txt";
	archivo2.open(nombrearchivo);
	for(int i = 0; i < cont_comentarios; i++){
		if (datos2[i].codigo == mascomentarios){
			archivo2 << "CALIFICACION: " << datos2[i].estrellas << endl;
			if (datos2[i].estrellas > 3.0){
				archivo2 << "LE GUSTO LA MOVIE? LA RESPUESTA ES SI" << endl; 
			} else {
				archivo2 << "LE GUSTO LA MOVIE? LA RESPUESTA ES NO, NT" << endl;
			}
			int longitud = cuenta_caracteres(datos2[i].comentario);
			archivo2 << "CANTIDAD DE CARACTERES DEL COMENTARIO: " << longitud << endl;
			archivo2  << "TEXTO COMENTARIO: " << datos2[i].comentario << endl;
			int miedo_total = cuenta_miedo(datos2[i].comentario);
			int terror_total = cuenta_terror(datos2[i].comentario);
			int suspenso_total = cuenta_suspenso(datos2[i].comentario);
			archivo2  << "VECES QUE APARECE MIEDO: " << miedo_total << endl;
			archivo2  << "VECES QUE APARECE TERROR: " << terror_total << endl;
			archivo2  << "VECES QUE APARECE SUSPENSO: " << suspenso_total << endl;
			archivo2  << "............................................" << endl;
		}
	}
	
	return 0;
}

int cuenta_miedo(string comentario){
	int contador = 0;
	int pos = comentario.find("miedo", 0);
	while (pos != -1){
		contador++;
		pos = comentario.find("miedo", pos + 1);
	}
	return contador;
}

int cuenta_terror(string comentario){
	int contador = 0;
	int pos = comentario.find("terror", 0);
	while (pos != -1){
		contador++;
		pos = comentario.find("terror", pos + 1);
	}
	return contador;
}

int cuenta_suspenso(string comentario){
	int contador = 0;
	int pos = comentario.find("suspenso", 0);
	while (pos != -1){
		contador++;
		pos = comentario.find("suspenso", pos + 1);
	}
	return contador;
}

int buscador(string codigox, peliculas datos1[], int contador){
	for (int i = 0; i < contador; i++){
		if (codigox == datos1[i].codigo){
			return i;
		}
	}
	return -1;
}

int cuenta_caracteres(string comentario){
	int total = comentario.size();
	return total;
}
