/*
 ============================================================================
 Name        : TP_2_1B.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "input.h"

#include "arrayPassenger.h"


#define TAM 2000



int main(void) {
	setbuf(stdout, NULL);

	sPassenger listPassengers[TAM];

	int option;
	int nextId = 1;
	int flag=0;
	int answerMenu;


	if(initPassengers(listPassengers, TAM) == -1)
	{
		printf("Ocurrio un problema al inicializar pasajeros");
	}


	do
	{
		answerMenu = pedirEntero(&option,"\n======================\n|| Menu de Opciones ||      \n======================\n  ||Elegir opcion ||\n======================\n1.Alta pasajero\n2.Modificar pasajero\n3.Baja Pasajeros\n4.Informes\n5.Carga forzada de datos \n6.Salir \n","Error opcion invalida!!!",1,8);

		if(answerMenu == 0)
		{
			switch(option)
					{
					case 1:
						if(addPassenger(listPassengers,TAM,nextId,listPassengers->name,listPassengers->lastname,listPassengers->price,listPassengers->flycode,listPassengers->typePassenger,listPassengers->statusFlight))
						{
							printf("Alta exitosa!! \n");
							nextId++;
							flag =1;
						}
						else
						{
							printf("Hubo un problema al realizar el alta \n");
						}
						break;
					case 2:
						if(flag == 0)
						{
							printf("No se ingreso ningun pasajero \n");
						}
						else
						{
							if(modificationPassenger(listPassengers, TAM, nextId))
							{
								printf("Modificacion exitosa \n");
							}
							else
							{
								printf("Hubo un problema al modificar");
							}
						}
						break;
					case 3:
						if(flag == 0)
						{
							printf("No se ingreso ningun pasajero \n");
						}
						else
						{
							if(removePassenger(listPassengers, TAM, nextId))
							{
								printf("Baja exitosa!! \n");
								flagReset(listPassengers, TAM, &flag);
							}
							else
							{
								printf("Ocurrio un problema al realizar la baja \n");
							}
						}
						break;
					case 4:
						if(flag == 0)
						{
							printf("No hay pasajeros para mostrar \n");
						}
						else
						{
							subMenuInformation(listPassengers,TAM);
						}
						break;
					case 5:
						initListPassengers(listPassengers);
						printf("carga exitosa \n");
						flag = 1;
						break;
					case 6:
						break;
					}



		}


	}while(option !=6);

	return EXIT_SUCCESS;
}


