/*
 * bibliotecaAllende.h
 *
 *  Created on: 11 abr. 2022
 *      Author: Lucas
 */

#ifndef BIBLIOTECAALLENDE_H_
#define BIBLIOTECAALLENDE_H_





#endif /* BIBLIOTECAALLENDE_H_ */


//funcion menu

/// @fn int mostrarMenu(int, int, int)
/// @brief esta funcion mostrara un menu
///
/// @param x representa a los kilometros ingresados por el usuario
/// @param y representa al precio de aerolineas
/// @param z representa al precio de latam
/// @return retornara la opcion elegida por el usuario
int mostrarMenu(int x,int y,int z);

/// @fn float calcularConDebito(int)
/// @brief esta funcion va a calcular el precio final abonando con debito
///
/// @param numero representa al precio original
/// @return retorna el resultado del calculo
float calcularConDebito(int numero);

/// @fn float calcularConCredito(int)
/// @brief  esta funcion va a calcular el precio final abonando con credito
///
/// @param numero representa al precio original
/// @return retorna el resultado del calculo
float calcularConCredito(int numero);

/// @fn float calcularBitcoins(int)
/// @brief esta funcion va a calcular el precio final abonando con bitcoins
///
/// @param numero  representa al precio original
/// @return retorna el resultado del calculo
float calcularBitcoins(int numero);

/// @fn float calcularPrecioUnitario(int, int)
/// @brief esta funcion va a calcular el precio por kilometro del vuelo
///
/// @param x representa a los kilometros ingresados por el usuario
/// @param precio representa al precio original
/// @return retorna el resultado del calculo
float calcularPrecioUnitario(int x, int precio);

/// @fn int diferenciaPrecios(int, int)
/// @brief esta funcion va a calcular la diferencia de precio entre las aerolineas
///
/// @param y representa al precio de aerolineas
/// @param z representa al precio de latam
/// @return retorna el resultado del calculo
int diferenciaPrecios(int y, int z);
