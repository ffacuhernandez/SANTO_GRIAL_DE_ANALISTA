/**
 * Incrementar una variable global, utilizando 10 hilosen C, para la materia Sistemas Operativos.
 *
 * Archivo de codigo fuente en C, su objetivo es demostrar la condicion de carrera.
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
 **/

/***************************************
 ***  DECLARACIONES INICIALES    ******
 **************************************/


#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#ifndef NUM_THREADS
#define NUM_THREADS 10
#endif

int shared = 0;

void *func3(void* param)
{
    printf("Hilo incrementando la variable compartida...\n");
    for (int i = 0; i < 10000; ++i) {
        shared += 1;
    }
    return 0;
}

int main()
{
    pthread_t threads[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; ++i) {
        pthread_create(&threads[i], NULL, func3, NULL);
    }

    for (int i = 0; i < NUM_THREADS; ++i) {
        pthread_join(threads[i], NULL);
    }

    printf("%d\n", shared);
    exit(EXIT_SUCCESS);
}
