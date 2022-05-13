/*
 * arrayPassenger.c
 *
 *  Created on: 27 abr. 2022
 *      Author: Lucas
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "input.h"
#include "arrayPassenger.h"




void printOnePassenger(sPassenger myPassenger)
{
	printf("|%-4d	|%10s	|%12s	|%16.2f |%15s |%10d   |%12d |	\n",myPassenger.id,
										myPassenger.name,
										myPassenger.lastname,
										myPassenger.price,
										myPassenger.flycode,
										myPassenger.typePassenger,
										myPassenger.statusFlight);

	printf("========================================================================================================\n");
}


int initPassengers(sPassenger* list, int len)
{
	int todoOk = 0;

	if(list !=NULL && len>0)
	{
		for(int i=0; i<len; i++)
		{
			list[i].isEmpty = 0;
		}
		todoOk = 1;
	}
	return todoOk;
}


int searchFree(sPassenger list[], int len)
{
	int index;
	index = -1;

	if(list !=NULL && len>0)
	{
		for(int i=0; i<len; i++)
		{
			if(list[i].isEmpty == 0)
			{
				index = i;
				break;
			}
		}
	}
	return index;
}

int addPassenger(sPassenger* list,	int len,
									int id,
									char name[],
									char lastName[],
									float price,
									char flyCode[],
									int typePassenger,
									int statusFlight
									)
{
	printf("=======================\n");
	printf("|| ALTA DE PASAJEROS ||\n");
	printf("=======================\n");

	int todoOk = 0;
	int index;
	sPassenger aux;

	if(list != NULL && len > 0 && name != NULL && lastName != NULL)
	{
		index = searchFree(list, len);
		if(index == -1)
		{
			printf("No hay lugar en el sistema \n");
		}
		else
		{
			aux.id = id;

			pedirCadena(aux.name, "Ingrese el Nombre del pasajero\n");
			validarLetras(aux.name);
			primerLetraMayuscula(aux.name);
			pedirCadena(aux.lastname, "Ingrese el Apellido del pasajero\n");
			validarLetras(aux.lastname);
			primerLetraMayuscula(aux.lastname);
			pedirFlotante(&aux.price, "Ingrese el Precio del vuelo (entre 10.000 y 250.000","ERROR precio invalido",10000,250000);
			pedirCadena(aux.flycode, "Ingrese el codigo de vuelo\n");
			pedirEntero(&aux.typePassenger, "Ingrese el tipo de pasajero 1(VIP) 2(TURISTA) 3(EMPLEADO)\n","ERROR ingrese opcion valida",1,3);
			pedirEntero(&aux.statusFlight,"Ingrese 1(Vuelo Activo) 2(Vuelo Inactivo)","ERROR ingrese opcion valida",1,2);


			aux.isEmpty = 1;

			list[index] = aux;
			todoOk = 1;
		}
	}
	return todoOk;
}

int printPassengers(sPassenger* listPassenger, int len)
{
	int todoOk = 0;

	if(listPassenger !=NULL && len>0)
	{
		printf("=============================\n");
		printf("||	LISTA DE PASAJEROS ||\n");
		printf("=============================\n\n\n");

		printf("========================================================================================================\n");
		printf("|Id     |     Nombre    |     Apellido  |        Precio   |          Codigo|         Tipo|       Estado\n\n");
		printf("========================================================================================================\n");
		for(int i=0; i<len; i++)
		{
			if(listPassenger[i].isEmpty == 1)
			{
				printOnePassenger(listPassenger[i]);
			}
			todoOk=1;

		}
	}
	return todoOk;
}

int findPassengerById(sPassenger* listPassenger, int len, int id)
{
	int index = -1;

	if(listPassenger != NULL && len > 0)
	{
		for(int i=0; i<len; i++)
		{
			if(listPassenger[i].isEmpty == 1 && listPassenger[i].id == id)
			{
				index = i;
				break;
			}
		}
	}

	return index;
}


int removePassenger(sPassenger* listPassenger, int len, int id)
{
	int todoOk = 0;
	int index;
	char confirm;

	if(listPassenger !=NULL && len>0)
	{
		printf("==========================\n");
		printf("||    BAJA PASAJEROS	||\n");
		printf("==========================\n");
		printf("Ingrese ID: ");
		scanf("%d", &id);

		index = findPassengerById(listPassenger,len,id);
		if(index == -1)
		{
			printf("No existe un empleado con el ID %d \n", id);
		}
		else
		{
			printOnePassenger(listPassenger[index]);
			printf("Confirma la baja?: ");
			fflush(stdin);
			scanf("%c",&confirm);
			if(confirm == 's')
			{
				listPassenger[index].isEmpty = 0;
				todoOk = 1;
			}
			else
			{
				printf("Se ha cancelado la baja \n");
			}
		}

	}
	return todoOk;
}


int menuModification()
{
	int option;

	 printf("   1-Modificar Nombre\n");
	 printf("   2-Modificar Apellido\n");
	 printf("   3-Modificar Valor del vuelo\n");
	 printf("   4-Modificar Codigo de vuelo\n");
	 printf("   5-Modificar Tipo de pasajero\n");
	 printf("   6-Modificar Estado del vuelo\n");

	 printf("Ingrese opcion: ");
	 scanf("%d", &option);


	return option;
}


int modificationPassenger(sPassenger* listPassenger, int len, int id)
{
	int todoOk = 0;
	int index;
	char confirm;

	sPassenger aux;

	if(listPassenger != NULL && len > 0)
	{
		printf("===========================\n");
		printf("||   Modificar Persona   ||		\n");
		printf("===========================\n");
		printf("Ingrese id ");
		scanf("%d", &id);

		index = findPassengerById(listPassenger,len,id);
		if(index == -1)
		{
			printf("No existe un empleado con el id %d \n", id);
		}
		else
		{
			printOnePassenger(listPassenger[index]);

			printf("Presione s para confirmar modificacion: ");
			fflush(stdin);
			scanf("%c", &confirm);
			if(confirm == 's')
			{
				switch(menuModification())
				{
				case 1:
					pedirCadena(aux.name, "Ingrese el nuevo nombre");
					strcpy(listPassenger[index].name, aux.name );
					break;
				case 2:
					pedirCadena(aux.lastname, "Ingrese el nuevo apellido");
					strcpy(listPassenger[index].lastname, aux.lastname);
					break;
				case 3:
					pedirFlotante(&aux.price, "Ingrese el nuevo Precio del vuelo (entre 10.000 y 250.000","ERROR precio invalido",10000,250000);
					listPassenger[index].price = aux.price;
					break;
				case 4:
					pedirCadena(aux.flycode, "Ingrese el nuevo codigo del vuelo");
					strcpy(listPassenger[index].flycode, aux.flycode);
					break;
				case 5:
					pedirEntero(&aux.typePassenger, "Ingrese el nuevo tipo 1(VIP) 2(TURISTA) 3(EMPLEADO)","ERROR ingrese opcion valida",1,3);
					listPassenger[index].typePassenger = aux.typePassenger;
					break;
				case 6:
					pedirEntero(&aux.statusFlight, "Ingrese el nuevo estado del vuelo 1(Vuelo Activo) 2(Vuelo Inactivo)","ERROR ingrese opcion valida",1,2);
					listPassenger[index].statusFlight = aux.statusFlight;
					break;
				default:
					printf("Opcion invalida!!! \n");
					break;
				}
			todoOk = 1;

			}
			else
			{
				printf("Se ha cancelado la modificacion \n");
			}
		}
	}

	return todoOk;
}

int menuOrder()
{
	int option;

		printf("   0-Ordenar Descendente \n");
	    printf("   1-Ordenar Ascendente \n");

	    printf("Ingrese opcion: ");
	    scanf("%d", &option);

	    return option;
}


int sortPassengersByLastName(sPassenger* listPassenger, int len, int order)
{
	int todoOk = 0;
	sPassenger aux;


		for(int i=0; i<len-1; i++)
		{
			for(int j= i+1; j<len; j++)
			{

				if(order == 1)
				{
					if((strcmp(listPassenger[i].lastname, listPassenger[j].lastname)>0) || (strcmp(listPassenger[i].lastname, listPassenger[j].lastname) ==0 && listPassenger[i].typePassenger > listPassenger[j].typePassenger))
					{
						aux = listPassenger[i];
						listPassenger[i] = listPassenger[j];
						listPassenger[j] = aux;
					}
				}
				else
				{
					if(order == 0)
					{
						if(strcmp(listPassenger[i].lastname, listPassenger[j].lastname)<0 || (strcmp(listPassenger[i].lastname, listPassenger[j].lastname) ==0 && listPassenger[i].typePassenger < listPassenger[j].typePassenger))
						{
							aux = listPassenger[i];
							listPassenger[i] = listPassenger[j];
							listPassenger[j] = aux;
						}
					}
				}
			}
		}
		printPassengers(listPassenger,len);
	return todoOk;
}


int sortPassengersByCode(sPassenger* listPassenger, int len, int order)
{
	int todoOk = 0;
	sPassenger aux;
	if(listPassenger != NULL && len>0)
	{
		for(int i=0; i<len-1; i++)
		{
			for(int j= i+1; j<len; j++)
			{
				if(order == 1)
				{
					if((strcmp(listPassenger[i].flycode, listPassenger[j].flycode)>0) || (strcmp(listPassenger[i].flycode, listPassenger[j].flycode) ==0 && listPassenger[i].statusFlight > listPassenger[j].statusFlight))
					{
						aux = listPassenger[i];
						listPassenger[i] = listPassenger[j];
						listPassenger[j] = aux;
					}
				}
				else
				{
					if(order == 0)
					{
						if((strcmp(listPassenger[i].flycode, listPassenger[j].flycode)<0) || (strcmp(listPassenger[i].flycode, listPassenger[j].flycode) ==0 && listPassenger[i].statusFlight < listPassenger[j].statusFlight))
						{
							aux = listPassenger[i];
							listPassenger[i] = listPassenger[j];
							listPassenger[j] = aux;
						}
					}
				}
			}
		}
		todoOk=1;
	}
	printPassengers(listPassenger,len);
	return todoOk;
}


void initListPassengers(sPassenger listPassenger[])
{
	sPassenger aux[] = {

						{1001,"Juan", "Perez", 67500.55, "BA75",1,1,1},
						{1002,"Matias", "Rodriguez", 150000,"USA51",3,2,1},
						{1003,"Maia", "Perez", 35000, "USA14",2,1,1},
						{1004,"Leandro","Acosta",250600.60,"BA75",1,2,1},
						{1005,"Agustina","Zaragoza",67500,"JAP12",3,1,1}
						};
	for(int i=0; i<5; i++)
	{
		listPassenger[i] = aux[i];
	}
}


int flagReset(sPassenger listPassenger[], int len, int* flag)
{
	int todoOk = 0;

	if(listPassenger != NULL && len > 0)
	{
		for(int i=0; i<len; i++)
		{
			if(listPassenger[i].isEmpty == 1)
			{
				*flag = 1;
				todoOk = 1;
				break;
			}
			else
			{
				*flag = 0;
			}
		}
	}
	return todoOk;
}




int subMenuInformation(sPassenger* listPassenger, int len)
{
	int todoOk=0;
	int option;
	int order;

	if(listPassenger != NULL && len > 0)
	{

			printf("   1.Mostrar pasajeros ordenados por Apellido y tipo\n");
		    printf("   2.Mostrar pasajeros ordenados por Codigo de vuelo y\n");
		    printf("   3.Mostrar precio total y precio promedio de los pasajes \n");
		    printf("   4.Mostrar pasajeros por codigo de vuelo y vuelo activo \n");


		    printf("Ingrese opcion: ");
		    scanf("%d", &option);

		    switch(option)
		    {
		    case 1:
		    	order = menuOrder();
		    	sortPassengersByLastName(listPassenger, len,order);
		    	break;
		    case 2:
		    	order = menuOrder();
		    	sortPassengersByLastName(listPassenger,len,order);
		    	break;
		    case 3:
		    	priceAcumulator(listPassenger,len);
		    	break;
		    case 4:
		    	listPassengersFlyCodeAndStatus(listPassenger,len);
		    	break;
		    case 5:

		    	break;
		    default:
		    	printf("Opcion invalida!!");
		    	break;
		    }
	todoOk = 1;
	}

		    return todoOk;

}

int priceAcumulator(sPassenger* listPassenger,int len)
{
	int todoOk =0;
	float acumulator = 0;
	int acountant = 0;
	float average =0;
	int acountantHighPrice = 0;

	if(listPassenger !=NULL && len>0)
	{
		for(int i=0; i<len; i++)
		{
			if(listPassenger[i].isEmpty == 1)
			{
				acumulator += listPassenger[i].price;
				acountant++;
				todoOk = 1;
			}
		}
		if(acountant !=0)
		{
			average = acumulator/acountant;
		}
		else
		{
			printf("No se ingresaron empleados \n");
		}

		for(int i=0; i<len; i++)
		{
			if(listPassenger[i].isEmpty == 1 && listPassenger[i].price > average)
			{
				acountantHighPrice++;
			}
		}

		printf("La suma total de sueldos es %.2f \n",acumulator);
		printf("El promedio de sueldos es %.2f \n", average);
		printf("Hay un total de pasajeros con un precio de pasaje mayor al promedio de %d",acountantHighPrice);
	}
	return todoOk;
}

int listPassengersFlyCodeAndStatus(sPassenger* listPassenger,int len)
{
	int todoOk=0;

	if(listPassenger !=NULL && len>0)
	{
		for(int i=0; i<len;i++)
		{
			if(listPassenger[i].isEmpty == 1 && listPassenger[i].statusFlight == 1)
			{
				printOnePassenger(listPassenger[i]);
			}
		}

	}
	return todoOk;
}



















