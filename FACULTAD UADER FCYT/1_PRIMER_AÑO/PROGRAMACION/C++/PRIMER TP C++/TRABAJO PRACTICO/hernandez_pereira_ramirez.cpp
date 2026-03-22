#include <iostream>
#include <string>
#include <iomanip>  /// SE AGREGA BIBLIOTECA IOMANIP PARA UTILIZAE SETW

using namespace std;

int main(int argc, char *argv[]) {
	string bulonera; ///NOMBRE DE LA BULONERA
	int mes;///MES A PROCESAR
	int anio;///ANIO A PROCESAR
	float valor_pesos; ///VALOR DE REFERENCIA EN PESOS PARA PONDERAR
	string rubroydescri[500][2]; ///Rubro al que pertenece; Descripcion del producto
	int stock[500][3]; ///0: Valor mi­nimo de stock; 1: Stock actual; 2: Stock Final
	float valor_unitario[500]; ///Valor unitario a ponderar
	float precio_unitario[500]; ///Precio unitario de cada producto
	int cont_productos; ///CONTADOR DE PRODUCTOS
	int matriz_b[500][500]; ///Matriz para contar por producto y por dia
	int dia; ///DIA DE VENTA
	int cant_vend; ///CANTIDAD VENDIDA DEL PRODUCTO
	int reponer_stock; ///CANTIDAD DE PRODUCTOS QUE DEBEN ACTUALIZAR SU STOCK
	cont_productos= 0;///CONTADOR DE PRODUCTOS 
	reponer_stock= 0;///CONTADOR DE SOTCK
	int max_dia; /// VARIABLE PARA SABER EL MAXIMO DIA DE UN MES
	int codigo_p; /// VARIABLE PARA SABER CODIGO DEL PRODUCTO
	string auxrubro;///SE DECLARARON LAS SIGUIENTES VARIABLES
	float auxvalor;///SE DECLARARON LAS SISGUIENTES VARIABLES
	
	///CARGA DE PRIMEROS DATOS
	cout << "Ingrese el nombre de la bulonera: ";  /// OPERADOR MAL USADO (>>) EN REALIDAD HAY QUE USAR <<
	getline(cin, bulonera);
	cout << "Mes a procesar (1 a 12): ";
	cin >> mes;
	cout << "Anio a procesar: ";
	cin >> anio;  /// FALTABA EL PUNTO Y COMA AL FINAL DEL CODIGO
	cout << "Valor de referencia en pesos: $ ";
	cin >> valor_pesos;
	cout<<endl;
	
	/// PARA SABER SI EL AÑO ES BISIESTO Y LUEGO SABER EL MAXIMO DE DIAS DE UN MES
	if(mes == 2) { 
		bool aniobisiesto = ((anio % 4 == 0 && anio % 100 != 0) || (anio % 100 == 0 && anio % 400 == 0));
		if (aniobisiesto)
			max_dia = 29;
		else
			max_dia= 28;
	}else if ( mes == 4 or mes == 6 or mes == 8 or mes == 10 or mes == 12){   /// SE LE AGREGAN LAS LLAVES Y LOS DEMAS MESES PARA UTILIZAR LA VARIABLE max_dia
		max_dia= 30;
	} else {
		max_dia= 31;
	}
	
	
	///CARGA DE DATOS DE TODOS LOS PRODUCTOS
	cout<<"CARGA DE DATOS DE LOS PPRODUCTOS..."<<endl;
	cout<<"Codigo de producto: ";
	cin >> codigo_p;  /// CODIGO PRODUCTO
	while (codigo_p != 0)  /// OPERADOR MAL UTILIZADO, EL OPERADOR CORRECTO DE "DISTINTO DE" ES !=. EL BUCLE FRENA AL INGRESAR EL CODIGO 0
	{
		cin.get();
		cout<<"Rubro: ";
		getline(cin, rubroydescri[codigo_p][0]); /// USAMOS EL CODIGO DE PRODUCTO PARA SABER EN QUE FILA COLOCAR EL RUBRO
		cout<<"Descripcion: ";
		getline(cin, rubroydescri[codigo_p][1]); /// USAMOS EL CODIGO DE PRODUCTO PARA SABER EN QUE FILA COLOCAR LA DESCRIPCION DEL ANTERIOR RUBRO, YA QUE SIGUE EN LA MISMA FILA
		cout<<"Stock minimo: ";
		cin>>stock[codigo_p][0]; /// USAMOS CODIGO DE PRODUCTO PARA SABER EN QUE FILA GUARDAR EL STOCK MINIMO
		cout<<"Valor unitario a ponderar: ";
		cin>>valor_unitario[codigo_p];  /// GUARDAMOS EL VALOR UNITARIO A PONDERAR
		precio_unitario[codigo_p]= valor_unitario[codigo_p] * valor_pesos;  ///CALCULO DE PRECIO UNITARIO DEL PRODUCTO, EL CUAL SE GUARDA EN LA VARIABLE PRECIO UNITARIO DEL PRODUCTO INGRESADO
		cout<<"Stock actual: ";
		cin>>stock[codigo_p][1]; /// SE GUARDA EL STOCK ACTUAL USANDO EL CODIGO DE PRODUCTO, PARA ASI SABER AL PRODUCTO QUE SE ESTA GUARDANDO
		stock[codigo_p][2]=0;  /// SE INICIALIZA PARA CALCULO DE STOCK FINAL
		cont_productos++; /// CONTADOR DE PRODUCTOS INGRESADOS
		cout<<"Codigo de producto: ";
		cin>>codigo_p; /// SE INGRESA DEVUELTA PARA ASI SABER SI EL USUARIO DESEA CORTAR EL BUCLE (INGRESANDO 0)
	}
	
	///CARGA DE DATOS DE LAS VENTAS REALIZADAS EN EL PERIODO
	cout << endl << "CARGA DE DATOS DE LAS VENTAS..." << endl;
	cout << "Dia: ";
	cin >> dia;
	while (dia != 99){ /// OPERADOR MAL UTILIZADO, EL OPERADOR CORRECTO DE "DISTINTO DE" ES !=	
		while (dia > max_dia)    /// SE AGREGA WHILE PARA COMPROBAR SI EL DIA CORRESPONDE AL MES INGRESADO POR EL USUARIO.
		{
			cout << "ERROR. Ingrese un dia correspondiente al mes: ";
			cin >> dia;
		}
			cout << "Codigo de producto: ";
			cin >> codigo_p;
			cout << "Cantidad Vendida: ";
			cin >> cant_vend;
			matriz_b[codigo_p][dia]= matriz_b[codigo_p][dia] + cant_vend; /// ACUMULADOR PARA SABER LAS VENTAS TOTALES EN UN DIA
			stock[codigo_p][2]= stock[codigo_p][2] + cant_vend;  /// CALCULO DE STOCK FINAL
			cout << "Dia: "; /// SE INGRESA DEVUELTA PARA ASI SABER SI EL USUARIO DESEA CORTAR EL BUCLE (INGRESANDO 99)
			cin >> dia;
	}
	
	///INFORME 1
	cout << "-----------------------------------------------------------------" << endl;
	cout << "Stock INICIAL  - Periodo: " << mes << "/" << anio << endl;
	cout << setw (5) << "CODIGO" << setw(15) << "RUBRO" << setw(25) << "DESCRIPCION" << setw(25) << "STOCK INICIAL" << setw(25) << "PRECIO UNITARIO" << endl;
	for(int i=1; i<=cont_productos; i++)  /// SE REALIZA UN FOR, EL CUAL MUESTRE TODOS LOS PRODUCTOS CON SUS CODIGOS, RUBRO, DESCRIPCION, STOCK INICIAL Y PRECIO UNITARIO CORRESPONDIENTE. EL FOR CORTA AL ALCANZAR EL CONTADOR DE PRODUCTOS
		cout << setw(5) << i << setw(15) << rubroydescri[i][0] << setw(25) << rubroydescri[i][1] << setw(25) << stock[i][1] << setw(25) << precio_unitario[i] << endl;  /// ARRAYS EN DONDE SE GUARDARON LOS DATOS DECLARADOS PREVIAMENTE
		
	
	///INFORME 2
	cout << endl << "-----------------------------------------------------------------" << endl;
	cout << endl << "BULONERA " << bulonera << endl;
	cout << "VENTAS MENSUALES  - Periodo " << mes << "/" << anio <<endl; /// SE CORRIGIO EL OPERADOR DEL COUT YA QUE ESTABAN SEPARADOS (< < A <<)
	cout << "CODIGO    ";
	for(int i=1; i<=max_dia; i++) /// SE CREA UN FOR EL CUAL CREA LA FILA DE DIAS CORRESPONDIENTE AL MES INGRESADO
	cout << i << setw(6); 
	
	for (int i=1; i<=cont_productos; i++) 
	{
		cout << endl << setw(5) << i;     /// FOR EL CUAL LEE TODOS LOS CASILLEROS DE PRODUCTOS Y DIAS, Y SI ENCUENTRA ALGUN DATO MUESTRA EL VALOR, SINO MUESTRA UN 0
		for (int j = 1; j<=max_dia; j++)
			cout << setw(6) << matriz_b [i][j];
		
	}

	
	///INFORME 3
	cout<<endl<<"-----------------------------------------------------------------"<<endl;
	cout<<endl<<"BULONERA " << bulonera << endl;
	cout<<"PRODUCTOS BAJO DE STOCK  - Periodo "<<mes<<"/"<<anio<<endl;
	cout << "CODIGO	STOCK FINAL" << endl;
	for (int i = 1; i <= cont_productos; i++) {
		int stock_a_reponer = stock[i][1] - stock[i][2]; /// VARIABLE LA CUAL GUARDA EL STOCK A REPONER
		if (stock_a_reponer < stock[i][0]) { /// Solo muestra los productos que necesitan ser reabastecidos
			cout << setw(5) << i << setw(14) << stock_a_reponer << setw(16) << endl;
			reponer_stock += 1; /// Acumula la cantidad total de productos a reabastecer
		}
	}
	
	cout << "Total de productos a reponer: " << reponer_stock << endl; 
	
	///INFORME 4
	
	cout<<endl<<"-----------------------------------------------------------------"<<endl;
	cout<<endl<<"BULONERA "<<bulonera<<endl;
	cout<<"STOCK COMPLETO ACTUALIZADO Y PONDERADO  - Periodo "<<mes<<"/"<<anio<<endl;
	cout<<"CODIGO-RUBRO  STOCK FINAL    VALOR PONDERADO"<<endl;
	///"          "
	for (int i = 1; i <= cont_productos; i++) {
		int stock_final = stock[i][1] - stock[i][2];
		if (stock_final > 0) { /// CONDICIONAL QUE COMPRUEBA QUE EL STOCK FINAL SEA MAYOR A CERO
			auxrubro = rubroydescri[i][0].substr(0, 2); /// OBTENEMOS LAS DOS INICIALES DEL RUBRO
			auxvalor = stock_final * precio_unitario[i]; /// AUXILIAR PARA CALCULO DE VALOR
			cout << i << "-" << auxrubro << setw(14) << stock_final << setw(18) << auxvalor << endl;
		}
	}
	
	return 0;
}


