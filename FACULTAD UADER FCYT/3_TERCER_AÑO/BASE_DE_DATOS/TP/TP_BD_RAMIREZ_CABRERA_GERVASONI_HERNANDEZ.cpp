#include <iostream>
#include <algorithm>
using namespace std;

/// TRABAJO PRACTICO N1
/// INTEGRANTES : HERNANDEZ, RAMIREZ, CABRERA, GERVASONI

/// ESTRUCTURAS USADAS
struct Area_datos {
	int clave;
	string dato;
	int dir;
};

struct Area_indices {
	int clave;
	int dir;
};

/// INICIALIZAMOS LOS VALORES CON 0
void inicializar_areas(Area_datos *datos[], Area_indices *indices[], int OMAX, int cant_bloques) {
	for (int i = 0; i < OMAX; i++) { // PARA LOS DATOS
		datos[i] = new Area_datos{0, "", 0};
	}
	
	for (int i = 0; i < cant_bloques; i++) { // PARA LOS INDICES
		indices[i] = new Area_indices{0, 0};
	}
}


/// FUNCION PARA CONSULTA DE DATOS
string consulta(Area_datos* datos[], Area_indices* indices[], int OMAX, int OVER, int cant_bloques, int clave, int n) {
	
	if (indices[0]->clave <= clave) { // Si la primer clave del índice es MAYOR que la clave que buscamos NO realizamos la busqueda en el area principal
		
		for (int i = 0; i < cant_bloques; i++) {  // RECORREMOS LOS BLOQUES
			if (indices[i]->clave <= clave) {
				int dir_bloque = indices[i]->dir;    // BLOQUE ENCONTRADO! BUSCAMOS AHI
				for (int j = dir_bloque; j < dir_bloque + n; j++) {
					if (datos[j]->clave == clave) {
						return datos[j]->dato; // ENCONTRADO!
					}
				}
			}
		}
	}
	
	// Si no lo encontramos en el AREA PRINCIPAL, buscamos en el OVERFLOW
	for (int i = OVER; i < OMAX; i++) {
		if (datos[i]->clave == clave) {
			return datos[i]->dato; // ENCONTRADO!
		}
	}
	
	// SI NO SE ENCUENTRA LA CLAVE EN LA MATRIZ (AREA DE DATOS + OVERFLOW)
	return "Dato no encontrado";
}


/*
Caso 1:
1-consultar si hay un indice que no este ocupado
2-ingresar a la direccion de ese indices
3-insertar nuevo registro

Caso 2:
1-consultar si hay un indice ocupado
2-ingresar a la direccion de ese indice;
3-recorrer el bloque (van a haber varios casos en esta situacion):
#Caso 1: Si el bloque ya cumple con la condicion del n/2 y el numero de la clave 
esta por encima de la clave del ultimo registro del bloque se debera iniciar un nuevo bloque.
#Caso 2: Si el bloque ya cumple con la condicio n/2 pero el numero de la clave del registro a ingresar 
esta en el rango de claves de un bloque debera ser ingresado en ese bloque, solo si hay espacio
de lo contrario sera enviado al overflow.

Caso 3:
Si el area principal de datos ya esta llena (si los bloques estan llenos) el proximo dato ingresado
debera ir al overflow, donde si el valor de la clave esta entre los valores de las claves de un bloque 
el ultimo registro de ese bloque debera llevar la direccion del registro ingresado en el overflow
ejemplo:
bloque 2[3,5,7,8 direccion (0)]
bloque 3[10,17,23,45 direccion (1)]
overflow[9,50]

En caso de que se ingrese nuevamente otro dato que cumpla con la condicion aterior pero el ultimo registro del bloque ya tenga un direccion 
al overflow se le debera dar la direccion del dato ingresado al anterior dato ingresado al overflow.

Ejemplo: 
se ingresa el 30
Overflow[10,20(2),30].

Caso 4: Si el archivo se llena, se devuelve un mensaje de error.
*/


/// comentario
/// ORDENAMIENTO
/// Ejemplo de uso: ordenar_bloque(datos, indices[i]->dir, n);

/// ORDENAMIENTO Y ACTUALIZACION DEL INDICE
void ordenar_bloque(Area_datos* datos[], Area_indices* indices[], int inicio, int n, int indice_bloque) {
	// Ordenamos solo los datos dentro del bloque ignorando los vacios (clave 0)
	sort(datos + inicio, datos + inicio + n, [](Area_datos* a, Area_datos* b) {
		if (a->clave == 0) return false;
		if (b->clave == 0) return true;
		return a->clave < b->clave;
	});
	indices[indice_bloque]->clave = datos[inicio]->clave;
}


/// FUNCION PARA LA INSERCION DE DATOS
bool alta_registro(Area_datos* datos[], Area_indices* indices[], int OMAX,int OVER, int cant_bloques, int n, int clave, string nombre, int &elementos, int &espacio_overflow){
	
	if (elementos >= OMAX) {
		cout << "Los datos estan llenos. No se pueden insertar mas registros.\n";
		return false;
	}
	
	for(int i = 0; i < cant_bloques; i++){
		/// CASO 1
		if (indices[i]->clave == 0) {
			
			// Calculo la posicion donde deberia comenzar el nuevo bloque
			int inicio_bloque = i * n; // 0 * 4 = 0 || 1 * 4 || 2 * 4
			
			// Guardamos el dato
			datos[inicio_bloque]->clave = clave;
			datos[inicio_bloque]->dato = nombre;
			datos[inicio_bloque]->dir = 0; // sin overflow
			
			// Actualizamos el indice
			indices[i]->clave = clave;
			indices[i]->dir = inicio_bloque;
			
			cout << "AGREGANDO PRIMER ELEMENTO EN EL BLOQUE " << i + 1 << "..." << endl;
			// Ordenamos el bloque
			ordenar_bloque(datos, indices, inicio_bloque, n, i);
			elementos++;
			return true;
		}
		
		/// CASO 2
		if (indices[i]->clave <= clave && (i + 1 == cant_bloques || indices[i + 1]->clave > clave || indices[i + 1]->clave == 0)) {
			int dir_bloque = indices[i]->dir;
			int contador = 0;  // Contamos registros en el bloque
			int ultimo_dato = dir_bloque; // Ultima posicion del bloque
			
			for (int j = dir_bloque; j < dir_bloque + n; j++) {
				if (datos[j]->clave == clave){
					cout << "CLAVE REPETIDA\n";
					return false;
				}
				if (datos[j]->clave != 0) {
					contador++;
					ultimo_dato = j;
				}
			}
			
			// Si el bloque tiene menos de n/2, podemos insertar directamente
			if (contador < n / 2) {
				for (int j = dir_bloque; j < dir_bloque + n; j++) {
					if (datos[j]->clave == 0) { // TA VACIO, ASIGNAMOS
						datos[j]->clave = clave;
						datos[j]->dato = nombre;
						datos[j]->dir = 0; // Sin overflow
						ordenar_bloque(datos, indices, dir_bloque, n, i);
						cout << "AGREGANDO AL BLOQUE " << i + 1 << "..." << endl;
						elementos++;
						return true;
					}
				}
			}
			
			// Si ya tiene n/2 registros, verificamos el caso
			if (contador >= n / 2) {
				if (clave > datos[ultimo_dato]->clave) { // La clave es mayor a la ultima clave del bloque, tenemos que crear nuevo bloque
					if (i + 1 < cant_bloques - 1 && indices[i + 1]->clave == 0) {
						int nuevo_inicio = (i + 1) * n;
						datos[nuevo_inicio]->clave = clave;
						datos[nuevo_inicio]->dato = nombre;
						datos[nuevo_inicio]->dir = 0;
						
						indices[i + 1]->clave = clave;
						indices[i + 1]->dir = nuevo_inicio;
						
						ordenar_bloque(datos, indices, nuevo_inicio, n, i + 1);
						cout << "NUEVO BLOQUE CREADO, SE AGREGA AL COMIENZO DEL NUEVO BLOQUE " << i + 2 << endl;
						elementos++;
						return true;
					} else { // ESTE "ELSE" ES PARA SABER SI EL VALOR VA UN BLOQUE YA LLENO, PERO NO ES UN VALOR INTERMEDIO, AL OVERFLOW
						for (int j = OVER; j < OMAX; j++) {
							if (espacio_overflow >= 8) {
								cout << "NO HAY MAS ESPACIO EN EL OVERFLOW;\n";
								return false;
							}
							if (datos[j]->clave == 0) {
								datos[j]->clave = clave;
								datos[j]->dato = nombre;
								datos[j]->dir = 0;
								if (datos[ultimo_dato]->dir == 0){ // CHECKEAR SI EL ULTIMO DATO DEL BLOQUE NO TIENE DIRECCION
									datos[ultimo_dato]->dir = j; // Le damos valor al ultimo registro del bloque con el overflow
									cout << "AGREGANDO AL OVERFLOW...\n";
									elementos++;
									espacio_overflow++;
								} else { // YA TIENE UNA DIRECCION DEL OVERFLOW, LA DIRECCION LA CONTIENE EL ANTERIOR DATO DEL OVERFLOW
									datos[j - 1]->dir = j;
									elementos++;
									espacio_overflow++;
								}
								return true;
							}
						}
					}
				} else { // La clave esta dentro del rango del bloque (DATO INTERMEDIO), lo insertamos si hay espacio
					for (int j = dir_bloque; j < dir_bloque + n; j++) {
						if (datos[j]->clave == 0) {
							datos[j]->clave = clave;
							datos[j]->dato = nombre;
							datos[j]->dir = 0; 
							ordenar_bloque(datos, indices, dir_bloque, n, i);
							cout << "AGREGANDO AL BLOQUE " << i + 1 << "..." << endl;
							elementos++;
							return true;
						}
					}
				}
			}
		}
	}
	
	/// ERRROR AL INGRESAR EL DATO
	return false;
}
	
void mostrar_todo(Area_datos* datos[], Area_indices* indices[], int OMAX, int OVER, int cant_bloques, int n) {
	cout << "===== AREA DE DATOS PRINCIPAL =====\n";
	for (int i = 0; i < cant_bloques; i++) {
		if (indices[i]->clave != 0) {
			cout << "Bloque " << i + 1 << " (indice " << indices[i]->clave << "):\n";
			for (int j = indices[i]->dir; j < indices[i]->dir + n; j++) {
				if (datos[j]->clave != 0)
					cout << "- Clave: " << datos[j]->clave << ", Dato: " << datos[j]->dato << ", Dir: " << datos[j]->dir << endl;
			}
		}
	}
	
	cout << "\n===== AREA DE OVERFLOW =====\n";
	for (int i = OVER; i < OMAX; i++) {
		if (datos[i]->clave != 0) {
			cout << "- Clave: " << datos[i]->clave << ", Dato: " << datos[i]->dato << ", Dir: " << datos[i]->dir << endl;
		}
	}
	cout << "==================================\n\n";
}
	
	
	
int main() {
	/// DATOS QUE USAMOS
	int n = 4;
	int PMAX = 11;
	int OVER = PMAX + 1;
	const int OMAX = 20;
	const int cant_bloques = 4; // CALCULO --> BLOQUES = OVER / n
	int elementos = 0; // CONTADOR PARA SABER CUANTOS ELEMENTOS VAMOS, ASI SABER SI SE COMPLETO O NO
	int espacio_overflow = 0;
	
	/// CREACION DE LOS ARRAYS
	Area_datos* datos[OMAX];
	Area_indices* indices[cant_bloques];
	
	/// INICIALIZAMOS CON 0 AREAS ANTES DE USARLAS
	inicializar_areas(datos, indices, OMAX, cant_bloques);
	
	/// MENU PARA COMENZAR
	int opcion;
	int clave;
	cout << "Ingrese una opcion: " << endl;
	cout << "- 1 - INSERTAR UN ELEMENTO:\n";
	cout << "- 2 - CONSULTAR SOBRE UN ELEMENTO:\n";
	cout << "- 3 - MOSTRAR TODOS LOS DATOS\n";
	cout << "- 0 - SALIR\n";
	cout << ">";
	cin >> opcion;
	while (opcion != 0){
		switch(opcion){
			case 1: {
				string nombre;
				cout << "Ingrese clave: ";
				cin >> clave;
				cout << "Ingrese nombre: ";
				cin >> nombre;
				bool resultado1 = alta_registro(datos, indices, OMAX, OVER, cant_bloques, n, clave, nombre, elementos, espacio_overflow);
				if (resultado1) {
					cout << "ELEMENTO AGREGADO CORRECTAMENTE!\n";
				} else {
					cout << "EL ELEMENTO NO SE PUDO AGREGAR\n";
				}
			break;
			}
			case 2:{
				cout << "Ingrese la clave que desea consultar:\n";
				cin >> clave;
				string resultado2 = consulta(datos, indices, OMAX, OVER, cant_bloques, clave, n);
				cout << resultado2 << endl;
				break;
			}
			case 3: {
				mostrar_todo(datos, indices, OMAX, OVER, cant_bloques, n);
				break;	
			}
		}
		cout << "Ingrese una opcion: " << endl << ">";
		cin >> opcion;
	}
	return 0;
}
	
	
