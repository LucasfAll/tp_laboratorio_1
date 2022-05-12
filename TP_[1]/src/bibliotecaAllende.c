/*
 * bibliotecaAllende.c
 *
 *  Created on: 11 abr. 2022
 *      Author: Lucas
 */


#include <stdio.h>
#include <stdlib.h>
#include "bibliotecaAllende.h"


// funcion menu
int mostrarMenu( int x, int y, int z)
{
	int opcion;
	   system("cls");
	        printf("Elegir opcion\n\n");

            printf("1. Ingresar Kilometros \n");
            printf("2. Ingresar Precio de Vuelos \n");
            printf("3. Calcular todos los costos \n");
            printf("4. Informar resultados \n");
            printf("5. Carga forzada de datos \n");
            printf("6. Salir \n");

            printf("Ingrese opcion");
            fflush(stdin);
            scanf("%d", &opcion);

    return opcion;
}

//calcular con tarjeta de debito
float calcularConDebito(int numero)
{
    float resultado;

        resultado =(float) (numero * 90) / 100;

    return resultado;
}
///////////////////////////////////////////////
float calcularConCredito(int numero)
{
   float resultado;

    resultado = (float) (numero * 125) /100;

   return resultado;
}
///////////////////////////////////////////////
float calcularBitcoins(int numero)
{
    float resultado;

    resultado =(float) numero / 4606954.55;

    return resultado;
}
///////////////////////////////////////
float calcularPrecioUnitario(int x, int precio)
{
    float resultado;

        resultado = (f / x;

    return resultado;
}

/////////////////////////////////////////////////
int diferenciaPrecios(int y, int z)
{
    int resultado;
        resultado = z - y;
    return resultado;
}
//////////////////////////////////////
