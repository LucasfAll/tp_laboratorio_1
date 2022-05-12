/*
 ============================================================================
 Name        : TP_[1].c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "bibliotecaAllende.h"

int main(void) {

		setbuf(stdout, NULL);

	    char seguir = 's';
	    int kilometrosIngresados;
	    int precioAerolineas;
	    int precioLatam;
	    int banderaKilometros;
	    int banderaPrecios;
	    int banderaCalculos;
	    /////////////////////////////////
	    float resultadoLatamConDebito;
	    float resultadoLatamConCredito;
	    float resultadoLatamConBitcoin;
	    float resultadoLatamUnitario;
	////////////////////////////////////////
	    float resultadoAerolineasConDebito;
	    float resultadoAerolineasConCredito;
	    float resultadoAerolineasConBitcoin;
	    float resultadoAerolineasUnitario;
	//////////////////////////////////////
	    int diferenciaDePrecio;

	    banderaKilometros = 0;
	    banderaPrecios = 0;
	    banderaCalculos = 0;

	        do
	        {
	            switch(mostrarMenu(kilometrosIngresados,precioAerolineas,precioLatam))
	            {
	                case 1:
	                    printf("Ingrese los kilometros del vuelo \n");
	                    scanf("%d", &kilometrosIngresados);
	                    banderaKilometros = 1;
	                        while(kilometrosIngresados < 1)
	                        {
	                            printf("No existen vuelos de CERO kilometros \n");
	                            scanf("%d", &kilometrosIngresados);
	                            banderaKilometros = 1;
	                        }
	                    break;
	                case 2:
	                    if(banderaKilometros == 0)
	                    {
	                        printf("Antes de ingresar los precios debemos ingresar los kilometros del vuelo\n");
	                    }
	                    else
	                    {
	                        printf("Ingrese el precio volando con Aerolineas \n");
	                        scanf("%d", &precioAerolineas);
	                        printf("Ingrese el precio volando con Latam \n");
	                        scanf("%d", &precioLatam);
	                        banderaPrecios = 1;
	                            while(precioLatam < 1)
	                            {
	                                printf("Latam no brinda vuelos gratis!! REINGRESE precio volando con Latam \n");
	                                scanf("%d", &precioLatam);
	                                banderaPrecios = 1;
	                            }
	                            while(precioAerolineas < 1)
	                            {
	                                printf("Aerolineas no brinda vuelos gratis!! REINGRESE precio volando con Aerolineas \n");
	                                scanf("%d", &precioAerolineas);
	                                banderaPrecios = 1;
	                            }
	                    }
	                    break;
	                case 3:
	                        if(banderaPrecios < 1)
	                        {
	                            printf("\n\nNo se pueden calcular los costos sin ingresar los precios \n");
	                        }
	                        else
	                        {
	                            banderaCalculos = 1;
	                            //calculos latam
	                            resultadoLatamConDebito = calcularConDebito(precioLatam);
	                            resultadoLatamConCredito = calcularConCredito(precioLatam);
	                            resultadoLatamConBitcoin = calcularBitcoins(precioLatam);
	                            resultadoLatamUnitario = calcularPrecioUnitario(kilometrosIngresados, precioLatam);
	                            //calculos aerolineas
	                            resultadoAerolineasConDebito = calcularConDebito(precioAerolineas);
	                            resultadoAerolineasConCredito = calcularConCredito(precioAerolineas);
	                            resultadoAerolineasConBitcoin = calcularBitcoins(precioAerolineas);
	                            resultadoAerolineasUnitario = calcularPrecioUnitario(kilometrosIngresados, precioAerolineas);
	                            //calculo diferencia de precios
	                                if(precioAerolineas < precioLatam)
	                                {
	                                    diferenciaDePrecio = diferenciaPrecios(precioAerolineas, precioLatam);
	                                }
	                                else
	                                {
	                                   diferenciaDePrecio = diferenciaPrecios(precioLatam, precioAerolineas);
	                                }
	                            printf("Se han calculado los precios correctamente \n\n");
	                        }
	                    break;
	                case 4:
	                        if(banderaPrecios == 0)
	                        {
	                            printf("\n\nNo se pueden informar los costos sin antes calcularlos \n");
	                        }
	                        else
	                        {
	                            printf("\nkilometros Ingresados: %d \n\n", kilometrosIngresados);

	                            printf("Precio Aerolineas: %d \n", precioAerolineas);
	                            printf("a) Precio con tarjeta de debito: %.2f \n", resultadoAerolineasConDebito);
	                            printf("b) Precio con tarjeta de credito: %.2f \n", resultadoAerolineasConCredito);
	                            printf("c) Precio pagando con BitCoin: %.3f \n", resultadoAerolineasConBitcoin);
	                            printf("d) Mostrar precio unitario: %.2f \n\n\n", resultadoAerolineasUnitario);

	                            printf("Precio Latam: %d \n", precioLatam);
	                            printf("a) Precio con tarjeta de debito: %.2f \n", resultadoLatamConDebito);
	                            printf("b) Precio con tarjeta de credito: %.2f \n", resultadoLatamConCredito);
	                            printf("c) Precio pagando con BitCoin: %.3f \n", resultadoLatamConBitcoin);
	                            printf("d) Mostrar precio unitario: %.2f \n\n\n", resultadoLatamUnitario);

	                            printf("La diferencia de precio es de: %d \n\n", diferenciaDePrecio);
	                        }
	                    break;
	                case 5:
	                            printf("\nkilometros Ingresados: 7090 \n\n");

	                            printf("Precio Aerolineas: 162965 \n");
	                            printf("a) Precio con tarjeta de debito: %.2f \n", calcularConDebito(162965));
	                            printf("b) Precio con tarjeta de credito: %.2f \n", calcularConCredito(162965));
	                            printf("c) Precio pagando con BitCoin: %.3f \n", calcularBitcoins(162965));
	                            printf("d) Mostrar precio unitario: %.2f \n\n\n", calcularPrecioUnitario(7090, 162965));

	                            printf("Precio Latam: 159339 \n");
	                            printf("a) Precio con tarjeta de debito: %.2f \n", calcularConDebito(159339));
	                            printf("b) Precio con tarjeta de credito: %.2f \n", calcularConCredito(159339));
	                            printf("c) Precio pagando con BitCoin: %.3f \n", calcularBitcoins(159339));
	                            printf("d) Mostrar precio unitario: %.2f \n\n\n", calcularPrecioUnitario(7090, 159339));

	                            printf("La diferencia de precio es de: %d \n\n", diferenciaPrecios(159339, 162965));
	                    break;
	                case 6:
	                    seguir = 'n';
	                    break;
	                default:
	                    printf("opcion invalida \n");
	                    break;
	            }
	        }
	        while(seguir == 's');

	    return 0;




}
