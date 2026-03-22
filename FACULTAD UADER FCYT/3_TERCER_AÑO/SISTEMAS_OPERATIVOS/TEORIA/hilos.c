/**
 * Calculo de numeros primos en C, para la materia Sistemas Operativos.
 *
 * Archivo de codigo fuente en C, su objetivo es calcular numeros primos, tanto
 * en mononucleo, como utilizando hilos, midiendo el tiempo de ejecución de ambos e identificar la diferencia. 
 * de encontrar X numeros primos con ambos metodos.
 *
 * LICENSE:  Este archivo es el codigo fuente de un pequeño programa 
 * parte de la catedra Sistema Operativos de FCyT UADER.
 * Primos C is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Primos C is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with EMA Libre.  If not, see <http://www.gnu.org/licenses/>.
 *
 * @copyright  Copyright (c) 2022 Exequiel Aramburu
 * @license    https://www.gnu.org/licenses/gpl-3.0.html GPL License
 * @version    3.0
 * @link       https://www.gugler.com.ar
 * @since      File available since Release 3.0
 */

/***************************************
 ***  DECLARACIONES INICIALES    ******
 **************************************/

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <pthread.h>
# include <stdbool.h>
# include <math.h>
# include <sys/time.h>
# include <sys/syscall.h>

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"


/*Estructura para los Hilos */ 

typedef struct thread_data {
	int x;
	int y;
	int inicio;
	int fin;
    int resultado;
} thread_data;

/* Metodo que identifica si un numero es primo o no.*/ 

bool es_primo(int numero)
 {
	if (numero == 0 || numero == 1) return 0;
	if (numero == 4) return 0;
    for (int i=2; i<numero ; i++){
    if (numero%i == 0) return false;
    }
    return true;
 }

/* Metodo En Hilos*/ 

void *primos_h (void *arg) 
	{
	int i,count=0;
	thread_data *tdata=(thread_data *)arg;
	pid_t tid = syscall(SYS_gettid);
	for (i=tdata->inicio+1; i<=tdata->fin; i=i+1 )
			{
		     printf("\033[%d;%dH%d\t%d \n", tdata->x,tdata->y, tid, i);
			 if(es_primo(i)){count++;}
			}
	tdata->resultado = count;
	pthread_exit(NULL);
	}

/* Metodo Mononucleo */ 
int CalcularSinHilos(int a)
		{
		 int count = 0;	
		 for (int i = 0; i<=a; i++ )
			{
			 printf("%s\033[%d;%dH%d\n",KWHT, 6,60, i);
			 if(es_primo(i)){count++;}
			}
		 return count;
		}


/* PRINCIPAL */ 
int main ( int argc , char * argv []) 
{
	//Variables
	int CantidadSinHilos=0;
	int CantidadConHilos=0;
	pthread_t h1,h2,h3,h4,h5,h6,h7,h8,h9,h10,h11,h12;
	thread_data tdata1,tdata2,tdata3,tdata4,tdata5,tdata6,tdata7,tdata8,tdata9,tdata10,tdata11,tdata12;
	struct timeval start, end;
    long mtime,mtime2,seconds,seconds2, useconds,useconds2;
    int valor_max;
    int hilos;
	int aux = 0;
	int S_N = 1;
	//Inicio
	system("clear");
	printf ("%sBUSCADOR DE NUMERO PRIMOS - Mi PID es: %d\n",KWHT,getpid());
	printf ("%sNumero Máximo: ",KWHT);
	scanf("%d", &valor_max);
	printf ("%sRealizar busqueda MonoNucleo[1-Si/2-no]: ",KWHT);
	scanf("%d", &S_N);
	if(S_N != 2 ){S_N=1;}
	if(valor_max <1 || valor_max > 2147483647) {printf("%sNumero maximo invalido, tiene que estar en el rango de 1 a 2147483647.\n",KRED);return 0; } 
	printf("Hilos [2-12]: ");
    scanf("%d", &hilos);
	if(hilos <2 || hilos > 12) {printf("%sNumero de hilos invalido, tiene que estar en el rango de 2 a 12.\n",KRED);return 0; } 
	if(hilos > valor_max) {printf("%s No se puede generar esa cantidad de hilos con un numero tan pequeño.\n",KRED);return 0; } 
	int rangos= trunc(valor_max/hilos);	
	int rango_inicio[12] = {0,0,0,0,0,0,0,0,0,0,0,0}; 
	int rango_fin[12] = {0,0,0,0,0,0,0,0,0,0,0,0}; 

	for(int i=0; i<hilos;i++)
	{
		rango_inicio[i] = aux;
		aux= aux + rangos;
		rango_fin[i] = aux;
		if(i == (hilos-1)) {rango_fin[i] = valor_max;}
	}
	
    tdata1.inicio=rango_inicio[0];tdata2.inicio=rango_inicio[1];tdata3.inicio=rango_inicio[2];tdata4.inicio=rango_inicio[3];tdata5.inicio=rango_inicio[4];tdata6.inicio=rango_inicio[5];
	tdata7.inicio=rango_inicio[6];tdata8.inicio=rango_inicio[7];tdata9.inicio=rango_inicio[8];tdata10.inicio=rango_inicio[9];tdata11.inicio=rango_inicio[10];tdata12.inicio=rango_inicio[11];
	tdata1.fin=rango_fin[0];tdata2.fin=rango_fin[1];tdata3.fin=rango_fin[2];tdata4.fin=rango_fin[3];tdata5.fin=rango_fin[4];tdata6.fin=rango_fin[5];
	tdata7.fin=rango_fin[6];tdata8.fin=rango_fin[7];tdata9.fin=rango_fin[8];tdata10.fin=rango_fin[9];tdata11.fin=rango_fin[10];tdata12.fin=rango_fin[11];
	tdata1.x = 11;tdata1.y = 60;tdata2.x = 12;tdata2.y = 60;tdata3.x = 13;tdata3.y = 60;tdata4.x = 14;tdata4.y = 60; tdata5.x = 15;tdata5.y = 60;tdata6.x = 16;tdata6.y = 60;
	tdata7.x = 17;tdata7.y = 60;tdata8.x = 18;tdata8.y = 60;tdata9.x = 19;tdata9.y = 60;tdata10.x = 20;tdata10.y = 60; tdata11.x = 21; tdata11.y = 60; tdata12.x = 22;tdata12.y = 60;
	tdata1.resultado = 0; tdata2.resultado = 0; tdata3.resultado = 0; tdata4.resultado = 0; tdata5.resultado = 0; tdata6.resultado = 0; 
	tdata7.resultado = 0; tdata8.resultado = 0; tdata9.resultado = 0; tdata10.resultado = 0; tdata11.resultado = 0;	tdata12.resultado = 0;
	
	
	//*******************************************************/
 	//***COMIENZA LA BUSQUEDA CON UN NUCLEO *****************/
	//*******************************************************/

	gettimeofday(&start, NULL);
	if(S_N == 1)
	{
	printf("\033[%d;%dH%s\n", 5,0, "Descripción Mononucleo");
	printf("\033[%d;%dH%s\n", 5,60, "Buscando");
	CantidadSinHilos = CalcularSinHilos(valor_max);
	printf("\n");
	// Termino la ejecución de mononucleo
	gettimeofday(&end, NULL);
	seconds  = end.tv_sec  - start.tv_sec;
    useconds = end.tv_usec - start.tv_usec;
    mtime = ((seconds) * 1000 + useconds/1000.0) + 0.5;
	printf("\033[%d;%dH%s[0,%d]: %d\n", 6,0, "Mononucleo",valor_max,CantidadSinHilos);
	printf("%s\033[%d;%dHTiempo(ms):%ld",KNRM,7,0,mtime);
	printf("%s\033[%d;%dHTiempo(s):%f",KNRM,7,30,mtime/1000.0);
	printf("%s\033[%d;%dH%s[0,%d]: %d\n",KYEL, 8,0, "Numeros Primos Encontrados",valor_max,CantidadSinHilos);
	}
	
	//*******************************************************/
 	//***COMIENZA LA BUSQUEDA CON  HILOS    *****************/
	//*******************************************************/

	printf("%s\n", KWHT);
	printf("\033[%d;%dH%s\n", 10,0, "ESTADO\t\tHILO\tRANGO\t\t\tRESULTADO");
	printf("\033[%d;%dH%s\n", 10,60, "PID");	
	printf("\033[%d;%dH%s\n", 10,73, "Buscando");	
	gettimeofday(&start, NULL);
	 switch (hilos) {
		case 2:
				 pthread_create (&h1 , NULL , (void *) primos_h, (void *) &tdata1);
				 pthread_create (&h2 , NULL , (void *) primos_h, (void *) &tdata2);
			     printf("\033[%d;%dHEjecutando\t%s\t[%d,%d]\n", 11,0, " 1", tdata1.inicio, tdata1.fin);	
			     printf("\033[%d;%dHEjecutando\t%s\t[%d,%d]\n", 12,0, " 2", tdata2.inicio, tdata2.fin);
				 pthread_join (h1 , NULL ); printf("%s\033[%d;%dHTerminado \t%s\t[%d,%d]           %d%s\n",KYEL, 11,0, " 1", tdata1.inicio, tdata1.fin,tdata1.resultado,KWHT);
				 pthread_join (h2 , NULL ); printf("%s\033[%d;%dHTerminado \t%s\t(%d,%d]           %d%s\n",KYEL, 12,0, " 2", tdata2.inicio, tdata2.fin,tdata2.resultado,KWHT);	 
				 break;
		case 3:
				 pthread_create (&h1 , NULL , (void *) primos_h, (void *) &tdata1);
				 pthread_create (&h2 , NULL , (void *) primos_h, (void *) &tdata2);
				 pthread_create (&h3 , NULL , (void *) primos_h, (void *) &tdata3);		 
			     printf("\033[%d;%dHEjecutando\t%s\t[%d,%d]\n", 11,0, " 1", tdata1.inicio, tdata1.fin);	
			     printf("\033[%d;%dHEjecutando\t%s\t[%d,%d]\n", 12,0, " 2", tdata2.inicio, tdata2.fin);
			     printf("\033[%d;%dHEjecutando\t%s\t[%d,%d]\n", 13,0, " 3", tdata3.inicio, tdata3.fin);
				 pthread_join (h1 , NULL ); printf("%s\033[%d;%dHTerminado \t%s\t[%d,%d]           %d%s\n",KYEL, 11,0, " 1", tdata1.inicio, tdata1.fin,tdata1.resultado,KWHT);
				 pthread_join (h2 , NULL ); printf("%s\033[%d;%dHTerminado \t%s\t(%d,%d]           %d%s\n",KYEL, 12,0, " 2", tdata2.inicio, tdata2.fin,tdata2.resultado,KWHT);
				 pthread_join (h3 , NULL ); printf("%s\033[%d;%dHTerminado \t%s\t(%d,%d]           %d%s\n",KYEL, 13,0, " 3", tdata3.inicio, tdata3.fin,tdata3.resultado,KWHT); 			 
				 break;
		case 4:
				 pthread_create (&h1 , NULL , (void *) primos_h, (void *) &tdata1);
				 pthread_create (&h2 , NULL , (void *) primos_h, (void *) &tdata2);
				 pthread_create (&h3 , NULL , (void *) primos_h, (void *) &tdata3);
				 pthread_create (&h4 , NULL , (void *) primos_h, (void *) &tdata4);		 
			     printf("\033[%d;%dHEjecutando\t%s\t[%d,%d]\n", 11,0, " 1", tdata1.inicio, tdata1.fin);	
			     printf("\033[%d;%dHEjecutando\t%s\t[%d,%d]\n", 12,0, " 2", tdata2.inicio, tdata2.fin);
			     printf("\033[%d;%dHEjecutando\t%s\t[%d,%d]\n", 13,0, " 3", tdata3.inicio, tdata3.fin);
			     printf("\033[%d;%dHEjecutando\t%s\t[%d,%d]\n", 14,0, " 4", tdata4.inicio, tdata4.fin);
				 pthread_join (h1 , NULL ); printf("%s\033[%d;%dHTerminado \t%s\t[%d,%d]           %d%s\n",KYEL, 11,0, " 1", tdata1.inicio, tdata1.fin,tdata1.resultado,KWHT);
				 pthread_join (h2 , NULL ); printf("%s\033[%d;%dHTerminado \t%s\t(%d,%d]           %d%s\n",KYEL, 12,0, " 2", tdata2.inicio, tdata2.fin,tdata2.resultado,KWHT);
				 pthread_join (h3 , NULL ); printf("%s\033[%d;%dHTerminado \t%s\t(%d,%d]           %d%s\n",KYEL, 13,0, " 3", tdata3.inicio, tdata3.fin,tdata3.resultado,KWHT);
				 pthread_join (h4 , NULL ); printf("%s\033[%d;%dHTerminado \t%s\t(%d,%d]           %d%s\n",KYEL, 14,0, " 4", tdata4.inicio, tdata4.fin,tdata4.resultado,KWHT); 	
				 break;
		case 5:
				 pthread_create (&h1 , NULL , (void *) primos_h, (void *) &tdata1);
				 pthread_create (&h2 , NULL , (void *) primos_h, (void *) &tdata2);
				 pthread_create (&h3 , NULL , (void *) primos_h, (void *) &tdata3);
				 pthread_create (&h4 , NULL , (void *) primos_h, (void *) &tdata4);
				 pthread_create (&h5 , NULL , (void *) primos_h, (void *) &tdata5);
			     printf("\033[%d;%dHEjecutando\t%s\t[%d,%d]\n", 11,0, " 1", tdata1.inicio, tdata1.fin);	
			     printf("\033[%d;%dHEjecutando\t%s\t[%d,%d]\n", 12,0, " 2", tdata2.inicio, tdata2.fin);
			     printf("\033[%d;%dHEjecutando\t%s\t[%d,%d]\n", 13,0, " 3", tdata3.inicio, tdata3.fin);
			     printf("\033[%d;%dHEjecutando\t%s\t[%d,%d]\n", 14,0, " 4", tdata4.inicio, tdata4.fin);
			     printf("\033[%d;%dHEjecutando\t%s\t[%d,%d]\n", 15,0, " 5", tdata5.inicio, tdata5.fin);
				 pthread_join (h1 , NULL ); printf("%s\033[%d;%dHTerminado \t%s\t[%d,%d]           %d%s\n",KYEL, 11,0, " 1", tdata1.inicio, tdata1.fin,tdata1.resultado,KWHT);
				 pthread_join (h2 , NULL ); printf("%s\033[%d;%dHTerminado \t%s\t(%d,%d]           %d%s\n",KYEL, 12,0, " 2", tdata2.inicio, tdata2.fin,tdata2.resultado,KWHT);
				 pthread_join (h3 , NULL ); printf("%s\033[%d;%dHTerminado \t%s\t(%d,%d]           %d%s\n",KYEL, 13,0, " 3", tdata3.inicio, tdata3.fin,tdata3.resultado,KWHT);
				 pthread_join (h4 , NULL ); printf("%s\033[%d;%dHTerminado \t%s\t(%d,%d]           %d%s\n",KYEL, 14,0, " 4", tdata4.inicio, tdata4.fin,tdata4.resultado,KWHT);
				 pthread_join (h5 , NULL ); printf("%s\033[%d;%dHTerminado \t%s\t(%d,%d]           %d%s\n",KYEL, 15,0, " 5", tdata5.inicio, tdata5.fin,tdata5.resultado,KWHT);	 	 
				 break;

		case 6:
				 pthread_create (&h1 , NULL , (void *) primos_h, (void *) &tdata1);
				 pthread_create (&h2 , NULL , (void *) primos_h, (void *) &tdata2);
				 pthread_create (&h3 , NULL , (void *) primos_h, (void *) &tdata3);
				 pthread_create (&h4 , NULL , (void *) primos_h, (void *) &tdata4);
				 pthread_create (&h5 , NULL , (void *) primos_h, (void *) &tdata5);
				 pthread_create (&h6 , NULL , (void *) primos_h, (void *) &tdata6);
			     printf("\033[%d;%dHEjecutando\t%s\t[%d,%d]\n", 11,0, " 1", tdata1.inicio, tdata1.fin);	
			     printf("\033[%d;%dHEjecutando\t%s\t[%d,%d]\n", 12,0, " 2", tdata2.inicio, tdata2.fin);
			     printf("\033[%d;%dHEjecutando\t%s\t[%d,%d]\n", 13,0, " 3", tdata3.inicio, tdata3.fin);
			     printf("\033[%d;%dHEjecutando\t%s\t[%d,%d]\n", 14,0, " 4", tdata4.inicio, tdata4.fin);
			     printf("\033[%d;%dHEjecutando\t%s\t[%d,%d]\n", 15,0, " 5", tdata5.inicio, tdata5.fin);
			     printf("\033[%d;%dHEjecutando\t%s\t[%d,%d]\n", 16,0, " 6", tdata6.inicio, tdata6.fin);
				 pthread_join (h1 , NULL ); printf("%s\033[%d;%dHTerminado \t%s\t[%d,%d]           %d%s\n",KYEL, 11,0, " 1", tdata1.inicio, tdata1.fin,tdata1.resultado,KWHT);
				 pthread_join (h2 , NULL ); printf("%s\033[%d;%dHTerminado \t%s\t(%d,%d]           %d%s\n",KYEL, 12,0, " 2", tdata2.inicio, tdata2.fin,tdata2.resultado,KWHT);
				 pthread_join (h3 , NULL ); printf("%s\033[%d;%dHTerminado \t%s\t(%d,%d]           %d%s\n",KYEL, 13,0, " 3", tdata3.inicio, tdata3.fin,tdata3.resultado,KWHT);
				 pthread_join (h4 , NULL ); printf("%s\033[%d;%dHTerminado \t%s\t(%d,%d]           %d%s\n",KYEL, 14,0, " 4", tdata4.inicio, tdata4.fin,tdata4.resultado,KWHT);
				 pthread_join (h5 , NULL ); printf("%s\033[%d;%dHTerminado \t%s\t(%d,%d]           %d%s\n",KYEL, 15,0, " 5", tdata5.inicio, tdata5.fin,tdata5.resultado,KWHT);	 
				 pthread_join (h6 , NULL ); printf("%s\033[%d;%dHTerminado \t%s\t(%d,%d]           %d%s\n",KYEL, 16,0, " 6", tdata6.inicio, tdata6.fin,tdata6.resultado,KWHT);
				 break;
		case 7:
				 pthread_create (&h1 , NULL , (void *) primos_h, (void *) &tdata1);
				 pthread_create (&h2 , NULL , (void *) primos_h, (void *) &tdata2);
				 pthread_create (&h3 , NULL , (void *) primos_h, (void *) &tdata3);
				 pthread_create (&h4 , NULL , (void *) primos_h, (void *) &tdata4);
				 pthread_create (&h5 , NULL , (void *) primos_h, (void *) &tdata5);
				 pthread_create (&h6 , NULL , (void *) primos_h, (void *) &tdata6);
				 pthread_create (&h7 , NULL , (void *) primos_h, (void *) &tdata7);	 
			     printf("\033[%d;%dHEjecutando\t%s\t[%d,%d]\n", 11,0, " 1", tdata1.inicio, tdata1.fin);	
			     printf("\033[%d;%dHEjecutando\t%s\t[%d,%d]\n", 12,0, " 2", tdata2.inicio, tdata2.fin);
			     printf("\033[%d;%dHEjecutando\t%s\t[%d,%d]\n", 13,0, " 3", tdata3.inicio, tdata3.fin);
			     printf("\033[%d;%dHEjecutando\t%s\t[%d,%d]\n", 14,0, " 4", tdata4.inicio, tdata4.fin);
			     printf("\033[%d;%dHEjecutando\t%s\t[%d,%d]\n", 15,0, " 5", tdata5.inicio, tdata5.fin);
			     printf("\033[%d;%dHEjecutando\t%s\t[%d,%d]\n", 16,0, " 6", tdata6.inicio, tdata6.fin);
			     printf("\033[%d;%dHEjecutando\t%s\t[%d,%d]\n", 17,0, " 7", tdata7.inicio, tdata7.fin);
				 pthread_join (h1 , NULL ); printf("%s\033[%d;%dHTerminado \t%s\t[%d,%d]           %d%s\n",KYEL, 11,0, " 1", tdata1.inicio, tdata1.fin,tdata1.resultado,KWHT);
				 pthread_join (h2 , NULL ); printf("%s\033[%d;%dHTerminado \t%s\t(%d,%d]           %d%s\n",KYEL, 12,0, " 2", tdata2.inicio, tdata2.fin,tdata2.resultado,KWHT);
				 pthread_join (h3 , NULL ); printf("%s\033[%d;%dHTerminado \t%s\t(%d,%d]           %d%s\n",KYEL, 13,0, " 3", tdata3.inicio, tdata3.fin,tdata3.resultado,KWHT);
				 pthread_join (h4 , NULL ); printf("%s\033[%d;%dHTerminado \t%s\t(%d,%d]           %d%s\n",KYEL, 14,0, " 4", tdata4.inicio, tdata4.fin,tdata4.resultado,KWHT);
				 pthread_join (h5 , NULL ); printf("%s\033[%d;%dHTerminado \t%s\t(%d,%d]           %d%s\n",KYEL, 15,0, " 5", tdata5.inicio, tdata5.fin,tdata5.resultado,KWHT);	 
				 pthread_join (h6 , NULL ); printf("%s\033[%d;%dHTerminado \t%s\t(%d,%d]           %d%s\n",KYEL, 16,0, " 6", tdata6.inicio, tdata6.fin,tdata6.resultado,KWHT);
				 pthread_join (h7 , NULL ); printf("%s\033[%d;%dHTerminado \t%s\t(%d,%d]           %d%s\n",KYEL, 17,0, " 7", tdata7.inicio, tdata7.fin,tdata7.resultado,KWHT);
				 break;
		case 8:
				 pthread_create (&h1 , NULL , (void *) primos_h, (void *) &tdata1);
				 pthread_create (&h2 , NULL , (void *) primos_h, (void *) &tdata2);
				 pthread_create (&h3 , NULL , (void *) primos_h, (void *) &tdata3);
				 pthread_create (&h4 , NULL , (void *) primos_h, (void *) &tdata4);
				 pthread_create (&h5 , NULL , (void *) primos_h, (void *) &tdata5);
				 pthread_create (&h6 , NULL , (void *) primos_h, (void *) &tdata6);
				 pthread_create (&h7 , NULL , (void *) primos_h, (void *) &tdata7);
				 pthread_create (&h8 , NULL , (void *) primos_h, (void *) &tdata8);	 
			     printf("\033[%d;%dHEjecutando\t%s\t[%d,%d]\n", 11,0, " 1", tdata1.inicio, tdata1.fin);	
			     printf("\033[%d;%dHEjecutando\t%s\t[%d,%d]\n", 12,0, " 2", tdata2.inicio, tdata2.fin);
			     printf("\033[%d;%dHEjecutando\t%s\t[%d,%d]\n", 13,0, " 3", tdata3.inicio, tdata3.fin);
			     printf("\033[%d;%dHEjecutando\t%s\t[%d,%d]\n", 14,0, " 4", tdata4.inicio, tdata4.fin);
			     printf("\033[%d;%dHEjecutando\t%s\t[%d,%d]\n", 15,0, " 5", tdata5.inicio, tdata5.fin);
			     printf("\033[%d;%dHEjecutando\t%s\t[%d,%d]\n", 16,0, " 6", tdata6.inicio, tdata6.fin);
			     printf("\033[%d;%dHEjecutando\t%s\t[%d,%d]\n", 17,0, " 7", tdata7.inicio, tdata7.fin);
			     printf("\033[%d;%dHEjecutando\t%s\t[%d,%d]\n", 18,0, " 8", tdata8.inicio, tdata8.fin);
				 pthread_join (h1 , NULL ); printf("%s\033[%d;%dHTerminado \t%s\t[%d,%d]           %d%s\n",KYEL, 11,0, " 1", tdata1.inicio, tdata1.fin,tdata1.resultado,KWHT);
				 pthread_join (h2 , NULL ); printf("%s\033[%d;%dHTerminado \t%s\t(%d,%d]           %d%s\n",KYEL, 12,0, " 2", tdata2.inicio, tdata2.fin,tdata2.resultado,KWHT);
				 pthread_join (h3 , NULL ); printf("%s\033[%d;%dHTerminado \t%s\t(%d,%d]           %d%s\n",KYEL, 13,0, " 3", tdata3.inicio, tdata3.fin,tdata3.resultado,KWHT);
				 pthread_join (h4 , NULL ); printf("%s\033[%d;%dHTerminado \t%s\t(%d,%d]           %d%s\n",KYEL, 14,0, " 4", tdata4.inicio, tdata4.fin,tdata4.resultado,KWHT);
				 pthread_join (h5 , NULL ); printf("%s\033[%d;%dHTerminado \t%s\t(%d,%d]           %d%s\n",KYEL, 15,0, " 5", tdata5.inicio, tdata5.fin,tdata5.resultado,KWHT);	 
				 pthread_join (h6 , NULL ); printf("%s\033[%d;%dHTerminado \t%s\t(%d,%d]           %d%s\n",KYEL, 16,0, " 6", tdata6.inicio, tdata6.fin,tdata6.resultado,KWHT);
				 pthread_join (h7 , NULL ); printf("%s\033[%d;%dHTerminado \t%s\t(%d,%d]           %d%s\n",KYEL, 17,0, " 7", tdata7.inicio, tdata7.fin,tdata7.resultado,KWHT);
				 pthread_join (h8 , NULL ); printf("%s\033[%d;%dHTerminado \t%s\t(%d,%d]           %d%s\n",KYEL, 18,0, " 8", tdata8.inicio, tdata8.fin,tdata8.resultado,KWHT);
				 break;
		case 9:
				 pthread_create (&h1 , NULL , (void *) primos_h, (void *) &tdata1);
				 pthread_create (&h2 , NULL , (void *) primos_h, (void *) &tdata2);
				 pthread_create (&h3 , NULL , (void *) primos_h, (void *) &tdata3);
				 pthread_create (&h4 , NULL , (void *) primos_h, (void *) &tdata4);
				 pthread_create (&h5 , NULL , (void *) primos_h, (void *) &tdata5);
				 pthread_create (&h6 , NULL , (void *) primos_h, (void *) &tdata6);
				 pthread_create (&h7 , NULL , (void *) primos_h, (void *) &tdata7);
				 pthread_create (&h8 , NULL , (void *) primos_h, (void *) &tdata8);
				 pthread_create (&h9 , NULL , (void *) primos_h, (void *) &tdata9);		 
			     printf("\033[%d;%dHEjecutando\t%s\t[%d,%d]\n", 11,0, " 1", tdata1.inicio, tdata1.fin);	
			     printf("\033[%d;%dHEjecutando\t%s\t[%d,%d]\n", 12,0, " 2", tdata2.inicio, tdata2.fin);
			     printf("\033[%d;%dHEjecutando\t%s\t[%d,%d]\n", 13,0, " 3", tdata3.inicio, tdata3.fin);
			     printf("\033[%d;%dHEjecutando\t%s\t[%d,%d]\n", 14,0, " 4", tdata4.inicio, tdata4.fin);
			     printf("\033[%d;%dHEjecutando\t%s\t[%d,%d]\n", 15,0, " 5", tdata5.inicio, tdata5.fin);
			     printf("\033[%d;%dHEjecutando\t%s\t[%d,%d]\n", 16,0, " 6", tdata6.inicio, tdata6.fin);
			     printf("\033[%d;%dHEjecutando\t%s\t[%d,%d]\n", 17,0, " 7", tdata7.inicio, tdata7.fin);
			     printf("\033[%d;%dHEjecutando\t%s\t[%d,%d]\n", 18,0, " 8", tdata8.inicio, tdata8.fin);
			     printf("\033[%d;%dHEjecutando\t%s\t[%d,%d]\n", 19,0, " 9", tdata9.inicio, tdata9.fin);
				 pthread_join (h1 , NULL ); printf("%s\033[%d;%dHTerminado \t%s\t[%d,%d]           %d%s\n",KYEL, 11,0, " 1", tdata1.inicio, tdata1.fin,tdata1.resultado,KWHT);
				 pthread_join (h2 , NULL ); printf("%s\033[%d;%dHTerminado \t%s\t(%d,%d]           %d%s\n",KYEL, 12,0, " 2", tdata2.inicio, tdata2.fin,tdata2.resultado,KWHT);
				 pthread_join (h3 , NULL ); printf("%s\033[%d;%dHTerminado \t%s\t(%d,%d]           %d%s\n",KYEL, 13,0, " 3", tdata3.inicio, tdata3.fin,tdata3.resultado,KWHT);
				 pthread_join (h4 , NULL ); printf("%s\033[%d;%dHTerminado \t%s\t(%d,%d]           %d%s\n",KYEL, 14,0, " 4", tdata4.inicio, tdata4.fin,tdata4.resultado,KWHT);
				 pthread_join (h5 , NULL ); printf("%s\033[%d;%dHTerminado \t%s\t(%d,%d]           %d%s\n",KYEL, 15,0, " 5", tdata5.inicio, tdata5.fin,tdata5.resultado,KWHT);	 
				 pthread_join (h6 , NULL ); printf("%s\033[%d;%dHTerminado \t%s\t(%d,%d]           %d%s\n",KYEL, 16,0, " 6", tdata6.inicio, tdata6.fin,tdata6.resultado,KWHT);
				 pthread_join (h7 , NULL ); printf("%s\033[%d;%dHTerminado \t%s\t(%d,%d]           %d%s\n",KYEL, 17,0, " 7", tdata7.inicio, tdata7.fin,tdata7.resultado,KWHT);
				 pthread_join (h8 , NULL ); printf("%s\033[%d;%dHTerminado \t%s\t(%d,%d]           %d%s\n",KYEL, 18,0, " 8", tdata8.inicio, tdata8.fin,tdata8.resultado,KWHT);
				 pthread_join (h9 , NULL ); printf("%s\033[%d;%dHTerminado \t%s\t(%d,%d]           %d%s\n",KYEL, 19,0, " 9", tdata9.inicio, tdata9.fin,tdata9.resultado,KWHT);	 
				 break;
		case 10:
				 pthread_create (&h1 , NULL , (void *) primos_h, (void *) &tdata1);
				 pthread_create (&h2 , NULL , (void *) primos_h, (void *) &tdata2);
				 pthread_create (&h3 , NULL , (void *) primos_h, (void *) &tdata3);
				 pthread_create (&h4 , NULL , (void *) primos_h, (void *) &tdata4);
				 pthread_create (&h5 , NULL , (void *) primos_h, (void *) &tdata5);
				 pthread_create (&h6 , NULL , (void *) primos_h, (void *) &tdata6);
				 pthread_create (&h7 , NULL , (void *) primos_h, (void *) &tdata7);
				 pthread_create (&h8 , NULL , (void *) primos_h, (void *) &tdata8);
				 pthread_create (&h9 , NULL , (void *) primos_h, (void *) &tdata9);
				 pthread_create (&h10 , NULL , (void *) primos_h, (void *) &tdata10);
			     printf("\033[%d;%dHEjecutando\t%s\t[%d,%d]\n", 11,0, " 1", tdata1.inicio, tdata1.fin);	
			     printf("\033[%d;%dHEjecutando\t%s\t[%d,%d]\n", 12,0, " 2", tdata2.inicio, tdata2.fin);
			     printf("\033[%d;%dHEjecutando\t%s\t[%d,%d]\n", 13,0, " 3", tdata3.inicio, tdata3.fin);
			     printf("\033[%d;%dHEjecutando\t%s\t[%d,%d]\n", 14,0, " 4", tdata4.inicio, tdata4.fin);
			     printf("\033[%d;%dHEjecutando\t%s\t[%d,%d]\n", 15,0, " 5", tdata5.inicio, tdata5.fin);
			     printf("\033[%d;%dHEjecutando\t%s\t[%d,%d]\n", 16,0, " 6", tdata6.inicio, tdata6.fin);
			     printf("\033[%d;%dHEjecutando\t%s\t[%d,%d]\n", 17,0, " 7", tdata7.inicio, tdata7.fin);
			     printf("\033[%d;%dHEjecutando\t%s\t[%d,%d]\n", 18,0, " 8", tdata8.inicio, tdata8.fin);
			     printf("\033[%d;%dHEjecutando\t%s\t[%d,%d]\n", 19,0, " 9", tdata9.inicio, tdata9.fin);
			     printf("\033[%d;%dHEjecutando\t%s\t[%d,%d]\n", 20,0, "10", tdata10.inicio, tdata10.fin);
				 pthread_join (h1 , NULL ); printf("%s\033[%d;%dHTerminado \t%s\t[%d,%d]           %d%s\n",KYEL, 11,0, " 1", tdata1.inicio, tdata1.fin,tdata1.resultado,KWHT);
				 pthread_join (h2 , NULL ); printf("%s\033[%d;%dHTerminado \t%s\t(%d,%d]           %d%s\n",KYEL, 12,0, " 2", tdata2.inicio, tdata2.fin,tdata2.resultado,KWHT);
				 pthread_join (h3 , NULL ); printf("%s\033[%d;%dHTerminado \t%s\t(%d,%d]           %d%s\n",KYEL, 13,0, " 3", tdata3.inicio, tdata3.fin,tdata3.resultado,KWHT);
				 pthread_join (h4 , NULL ); printf("%s\033[%d;%dHTerminado \t%s\t(%d,%d]           %d%s\n",KYEL, 14,0, " 4", tdata4.inicio, tdata4.fin,tdata4.resultado,KWHT);
				 pthread_join (h5 , NULL ); printf("%s\033[%d;%dHTerminado \t%s\t(%d,%d]           %d%s\n",KYEL, 15,0, " 5", tdata5.inicio, tdata5.fin,tdata5.resultado,KWHT);	 
				 pthread_join (h6 , NULL ); printf("%s\033[%d;%dHTerminado \t%s\t(%d,%d]           %d%s\n",KYEL, 16,0, " 6", tdata6.inicio, tdata6.fin,tdata6.resultado,KWHT);
				 pthread_join (h7 , NULL ); printf("%s\033[%d;%dHTerminado \t%s\t(%d,%d]           %d%s\n",KYEL, 17,0, " 7", tdata7.inicio, tdata7.fin,tdata7.resultado,KWHT);
				 pthread_join (h8 , NULL ); printf("%s\033[%d;%dHTerminado \t%s\t(%d,%d]           %d%s\n",KYEL, 18,0, " 8", tdata8.inicio, tdata8.fin,tdata8.resultado,KWHT);
				 pthread_join (h9 , NULL ); printf("%s\033[%d;%dHTerminado \t%s\t(%d,%d]           %d%s\n",KYEL, 19,0, " 9", tdata9.inicio, tdata9.fin,tdata9.resultado,KWHT);
				 pthread_join (h10 , NULL );printf("%s\033[%d;%dHTerminado \t%s\t(%d,%d]           %d%s\n",KYEL, 20,0, "10", tdata10.inicio, tdata10.fin,tdata10.resultado,KWHT);
				 break;
		case 11:
				 pthread_create (&h1 , NULL , (void *) primos_h, (void *) &tdata1);
				 pthread_create (&h2 , NULL , (void *) primos_h, (void *) &tdata2);
				 pthread_create (&h3 , NULL , (void *) primos_h, (void *) &tdata3);
				 pthread_create (&h4 , NULL , (void *) primos_h, (void *) &tdata4);
				 pthread_create (&h5 , NULL , (void *) primos_h, (void *) &tdata5);
				 pthread_create (&h6 , NULL , (void *) primos_h, (void *) &tdata6);
				 pthread_create (&h7 , NULL , (void *) primos_h, (void *) &tdata7);
				 pthread_create (&h8 , NULL , (void *) primos_h, (void *) &tdata8);
				 pthread_create (&h9 , NULL , (void *) primos_h, (void *) &tdata9);
				 pthread_create (&h10 , NULL , (void *) primos_h, (void *) &tdata10);
				 pthread_create (&h11 , NULL , (void *) primos_h, (void *) &tdata11);
			     printf("\033[%d;%dHEjecutando\t%s\t[%d,%d]\n", 11,0, " 1", tdata1.inicio, tdata1.fin);	
			     printf("\033[%d;%dHEjecutando\t%s\t[%d,%d]\n", 12,0, " 2", tdata2.inicio, tdata2.fin);
			     printf("\033[%d;%dHEjecutando\t%s\t[%d,%d]\n", 13,0, " 3", tdata3.inicio, tdata3.fin);
			     printf("\033[%d;%dHEjecutando\t%s\t[%d,%d]\n", 14,0, " 4", tdata4.inicio, tdata4.fin);
			     printf("\033[%d;%dHEjecutando\t%s\t[%d,%d]\n", 15,0, " 5", tdata5.inicio, tdata5.fin);
			     printf("\033[%d;%dHEjecutando\t%s\t[%d,%d]\n", 16,0, " 6", tdata6.inicio, tdata6.fin);
			     printf("\033[%d;%dHEjecutando\t%s\t[%d,%d]\n", 17,0, " 7", tdata7.inicio, tdata7.fin);
			     printf("\033[%d;%dHEjecutando\t%s\t[%d,%d]\n", 18,0, " 8", tdata8.inicio, tdata8.fin);
			     printf("\033[%d;%dHEjecutando\t%s\t[%d,%d]\n", 19,0, " 9", tdata9.inicio, tdata9.fin);
			     printf("\033[%d;%dHEjecutando\t%s\t[%d,%d]\n", 20,0, "10", tdata10.inicio, tdata10.fin);
			 	 printf("\033[%d;%dHEjecutando\t%s\t[%d,%d]\n", 21,0, "11", tdata11.inicio, tdata11.fin);
				 pthread_join (h1 , NULL ); printf("%s\033[%d;%dHTerminado \t%s\t[%d,%d]           %d%s\n",KYEL, 11,0, " 1", tdata1.inicio, tdata1.fin,tdata1.resultado,KWHT);
				 pthread_join (h2 , NULL ); printf("%s\033[%d;%dHTerminado \t%s\t(%d,%d]           %d%s\n",KYEL, 12,0, " 2", tdata2.inicio, tdata2.fin,tdata2.resultado,KWHT);
				 pthread_join (h3 , NULL ); printf("%s\033[%d;%dHTerminado \t%s\t(%d,%d]           %d%s\n",KYEL, 13,0, " 3", tdata3.inicio, tdata3.fin,tdata3.resultado,KWHT);
				 pthread_join (h4 , NULL ); printf("%s\033[%d;%dHTerminado \t%s\t(%d,%d]           %d%s\n",KYEL, 14,0, " 4", tdata4.inicio, tdata4.fin,tdata4.resultado,KWHT);
				 pthread_join (h5 , NULL ); printf("%s\033[%d;%dHTerminado \t%s\t(%d,%d]           %d%s\n",KYEL, 15,0, " 5", tdata5.inicio, tdata5.fin,tdata5.resultado,KWHT);	 
				 pthread_join (h6 , NULL ); printf("%s\033[%d;%dHTerminado \t%s\t(%d,%d]           %d%s\n",KYEL, 16,0, " 6", tdata6.inicio, tdata6.fin,tdata6.resultado,KWHT);
				 pthread_join (h7 , NULL ); printf("%s\033[%d;%dHTerminado \t%s\t(%d,%d]           %d%s\n",KYEL, 17,0, " 7", tdata7.inicio, tdata7.fin,tdata7.resultado,KWHT);
				 pthread_join (h8 , NULL ); printf("%s\033[%d;%dHTerminado \t%s\t(%d,%d]           %d%s\n",KYEL, 18,0, " 8", tdata8.inicio, tdata8.fin,tdata8.resultado,KWHT);
				 pthread_join (h9 , NULL ); printf("%s\033[%d;%dHTerminado \t%s\t(%d,%d]           %d%s\n",KYEL, 19,0, " 9", tdata9.inicio, tdata9.fin,tdata9.resultado,KWHT);
				 pthread_join (h10 , NULL );printf("%s\033[%d;%dHTerminado \t%s\t(%d,%d]           %d%s\n",KYEL, 20,0, "10", tdata10.inicio, tdata10.fin,tdata10.resultado,KWHT);
				 pthread_join (h11 , NULL );printf("%s\033[%d;%dHTerminado \t%s\t(%d,%d]           %d%s\n",KYEL, 21,0, "11", tdata11.inicio, tdata11.fin,tdata11.resultado,KWHT);
				 break;			 
		case 12:
				 pthread_create (&h1 , NULL , (void *) primos_h, (void *) &tdata1);
				 pthread_create (&h2 , NULL , (void *) primos_h, (void *) &tdata2);
				 pthread_create (&h3 , NULL , (void *) primos_h, (void *) &tdata3);
				 pthread_create (&h4 , NULL , (void *) primos_h, (void *) &tdata4);
				 pthread_create (&h5 , NULL , (void *) primos_h, (void *) &tdata5);
				 pthread_create (&h6 , NULL , (void *) primos_h, (void *) &tdata6);
				 pthread_create (&h7 , NULL , (void *) primos_h, (void *) &tdata7);
				 pthread_create (&h8 , NULL , (void *) primos_h, (void *) &tdata8);
				 pthread_create (&h9 , NULL , (void *) primos_h, (void *) &tdata9);
				 pthread_create (&h10 , NULL , (void *) primos_h, (void *) &tdata10);
				 pthread_create (&h11 , NULL , (void *) primos_h, (void *) &tdata11);
				 pthread_create (&h12 , NULL , (void *) primos_h, (void *) &tdata12);			 
			     printf("\033[%d;%dHEjecutando\t%s\t[%d,%d]\n", 11,0, " 1", tdata1.inicio, tdata1.fin);	
			     printf("\033[%d;%dHEjecutando\t%s\t[%d,%d]\n", 12,0, " 2", tdata2.inicio, tdata2.fin);
			     printf("\033[%d;%dHEjecutando\t%s\t[%d,%d]\n", 13,0, " 3", tdata3.inicio, tdata3.fin);
			     printf("\033[%d;%dHEjecutando\t%s\t[%d,%d]\n", 14,0, " 4", tdata4.inicio, tdata4.fin);
			     printf("\033[%d;%dHEjecutando\t%s\t[%d,%d]\n", 15,0, " 5", tdata5.inicio, tdata5.fin);
			     printf("\033[%d;%dHEjecutando\t%s\t[%d,%d]\n", 16,0, " 6", tdata6.inicio, tdata6.fin);
			     printf("\033[%d;%dHEjecutando\t%s\t[%d,%d]\n", 17,0, " 7", tdata7.inicio, tdata7.fin);
			     printf("\033[%d;%dHEjecutando\t%s\t[%d,%d]\n", 18,0, " 8", tdata8.inicio, tdata8.fin);
			     printf("\033[%d;%dHEjecutando\t%s\t[%d,%d]\n", 19,0, " 9", tdata9.inicio, tdata9.fin);
			     printf("\033[%d;%dHEjecutando\t%s\t[%d,%d]\n", 20,0, "10", tdata10.inicio, tdata10.fin);
			 	 printf("\033[%d;%dHEjecutando\t%s\t[%d,%d]\n", 21,0, "11", tdata11.inicio, tdata11.fin);
			     printf("\033[%d;%dHEjecutando\t%s\t[%d,%d]\n", 22,0, "12", tdata12.inicio, tdata12.fin);
				 pthread_join (h1 , NULL ); printf("%s\033[%d;%dHTerminado \t%s\t[%d,%d]           %d%s\n",KYEL, 11,0, " 1", tdata1.inicio, tdata1.fin,tdata1.resultado,KWHT);
				 pthread_join (h2 , NULL ); printf("%s\033[%d;%dHTerminado \t%s\t(%d,%d]           %d%s\n",KYEL, 12,0, " 2", tdata2.inicio, tdata2.fin,tdata2.resultado,KWHT);
				 pthread_join (h3 , NULL ); printf("%s\033[%d;%dHTerminado \t%s\t(%d,%d]           %d%s\n",KYEL, 13,0, " 3", tdata3.inicio, tdata3.fin,tdata3.resultado,KWHT);
				 pthread_join (h4 , NULL ); printf("%s\033[%d;%dHTerminado \t%s\t(%d,%d]           %d%s\n",KYEL, 14,0, " 4", tdata4.inicio, tdata4.fin,tdata4.resultado,KWHT);
				 pthread_join (h5 , NULL ); printf("%s\033[%d;%dHTerminado \t%s\t(%d,%d]           %d%s\n",KYEL, 15,0, " 5", tdata5.inicio, tdata5.fin,tdata5.resultado,KWHT);	 
				 pthread_join (h6 , NULL ); printf("%s\033[%d;%dHTerminado \t%s\t(%d,%d]           %d%s\n",KYEL, 16,0, " 6", tdata6.inicio, tdata6.fin,tdata6.resultado,KWHT);
				 pthread_join (h7 , NULL ); printf("%s\033[%d;%dHTerminado \t%s\t(%d,%d]           %d%s\n",KYEL, 17,0, " 7", tdata7.inicio, tdata7.fin,tdata7.resultado,KWHT);
				 pthread_join (h8 , NULL ); printf("%s\033[%d;%dHTerminado \t%s\t(%d,%d]           %d%s\n",KYEL, 18,0, " 8", tdata8.inicio, tdata8.fin,tdata8.resultado,KWHT);
				 pthread_join (h9 , NULL ); printf("%s\033[%d;%dHTerminado \t%s\t(%d,%d]           %d%s\n",KYEL, 19,0, " 9", tdata9.inicio, tdata9.fin,tdata9.resultado,KWHT);
				 pthread_join (h10 , NULL );printf("%s\033[%d;%dHTerminado \t%s\t(%d,%d]           %d%s\n",KYEL, 20,0, "10", tdata10.inicio, tdata10.fin,tdata10.resultado,KWHT);
				 pthread_join (h11 , NULL );printf("%s\033[%d;%dHTerminado \t%s\t(%d,%d]           %d%s\n",KYEL, 21,0, "11", tdata11.inicio, tdata11.fin,tdata11.resultado,KWHT);
				 pthread_join (h12 , NULL );printf("%s\033[%d;%dHTerminado \t%s\t(%d,%d]           %d%s\n",KYEL, 22,0, "12", tdata12.inicio, tdata12.fin,tdata12.resultado,KWHT);
				 break;
		default:
			printf ("El numero de hilos no esta entre 2 y 12");
		}
	
	// Termino la ejecución de los hilos
	printf("\n");	
	gettimeofday(&end, NULL);
	seconds2  = end.tv_sec  - start.tv_sec;
    useconds2 = end.tv_usec - start.tv_usec;
    mtime2 = ((seconds2) * 1000 + useconds2/1000.0) + 0.5;
	CantidadConHilos = tdata1.resultado + tdata2.resultado + tdata3.resultado + tdata4.resultado + tdata5.resultado + tdata6.resultado + tdata7.resultado + tdata8.resultado + tdata9.resultado + tdata10.resultado + tdata11.resultado + tdata12.resultado;
	printf("%s\033[%d;%dHTiempo(ms):%ld",KNRM,23,0,mtime2);
	printf("%s\033[%d;%dHTiempo(s):%f",KNRM,23,30,mtime2/1000.0);
	printf("%s\033[%d;%dH%s[%d,%d]: %d\n",KYEL, 24,0, "Numeros Primos Encontrados", tdata1.inicio, valor_max,CantidadConHilos);
	
	//*******************************************************/
 	//*** RESULTADO DE DIFERENCIA           *****************/
	//*******************************************************/
	
	printf("%s\nDiferencia(s): %f\n", KWHT,(mtime-mtime2)/1000.0);
	printf("%sDiferencia (X mas rapido): %ld\n", KWHT,(mtime/mtime2));
	printf("%s\n", KWHT);

}
