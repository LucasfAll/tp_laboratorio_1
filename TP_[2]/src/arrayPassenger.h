
#ifndef ARRAYPASENGER_H_

#define ARRAYPASENGER_H_

typedef struct{

	int id;
	char name[51];
	char lastname[51];
	float price;
	char flycode[10];
	int typePassenger;
	int statusFlight;
	int isEmpty;
}sPassenger;


#endif /* ARRAYPASENGER_H_ */


/**
 * @fn void printOnePassenger(sPassenger)
 * @brief Esta funcion muestra un solo pasajero
 *
 * @param myPassenger
 */
void printOnePassenger(sPassenger myPassenger);

/**
 * @fn int initPassengers(sPassenger*, int)
 * @brief Esta funcion inicializa el campo isEmpty en 0
 *
 * @param list lista de pasajeros
 * @param len tamaño de la lista
 * @return
 */
int initPassengers(sPassenger* list, int len);

/**
 * @fn int searchFree(sPassenger[], int)
 * @brief Buscara campos isEmpty en 0 para podes guardar datos
 *
 * @param list lista de pasajeros
 * @param len tamaño de la lista
 * @return retorna el indice libre
 */
int searchFree(sPassenger list[], int len);

/**
 * @fn int addPassenger(sPassenger*, int, int, char[], char[], float, char[], int, int)
 * @brief Funcion que da de alta pasajeros
 *
 * @param list lista de pasajeros
 * @param len tamaño de la lista
 * @param id id pasajero
 * @param name nombre pasajero
 * @param lastName apellido pasajero
 * @param price precio del pasaje
 * @param flyCode codigo de vuelo
 * @param typePassenger tipo de pasajero
 * @param statusFlight estado de vuelo
 * @return retorna si se realizo todo con exito o si hubo un error
 */
int addPassenger(sPassenger* list,	int len,
									int id,
									char name[],
									char lastName[],
									float price,
									char flyCode[],
									int typePassenger,
									int statusFlight);

/**
 * @fn int printPassengers(sPassenger*, int)
 * @brief  Muestra a todos los pasajeros ingresados
 *
 * @param listPassenger lista pasajeros
 * @param len tamaño de la lista
 * @return
 */
int printPassengers(sPassenger* listPassenger, int len);

/**
 * @fn int findPassengerById(sPassenger*, int, int)
 * @brief Funcion que busca un pasajero por su id
 *
 * @param listPassenger lista de pasajeros
 * @param len tamaño de la lista
 * @param id id pasajero
 * @return retorna indice libre
 */
int findPassengerById(sPassenger* listPassenger, int len, int id);

/**
 * @fn int removePassenger(sPassenger*, int, int)
 * @brief  Funcion que realiza una baja logica del sistema (isEmpty en 0)
 *
 * @param listPassenger lista pasajeros
 * @param len tamaño de pasajeros
 * @param id  id pasajero
 * @return retorna si se realizo todo con exito o si hubo un error
 */
int removePassenger(sPassenger* listPassenger, int len, int id);

/**
 * @fn int menuModification()
 * @brief Menu de modificaciones de datos
 *
 * @return retorna la opcion elegida
 */
int menuModification();

/**
 * @fn int modificationPassenger(sPassenger*, int, int)
 * @brief Funcion para modificar pasajeros
 *
 * @param listPassenger lista de pasajeros
 * @param len tamaño de la lista
 * @param id  id del pasajero
 * @return retorna si se realizo todo con exito o si hubo un error
 */
int modificationPassenger(sPassenger* listPassenger, int len, int id);

/**
 * @fn int menuOrder()
 * @brief  menu que define si el ordenamiento sera ascendente o descendente
 *
 * @return retorna la opcion elegida
 */
int menuOrder();

/**
 * @fn int sortPassengersByLastName(sPassenger*, int, int)
 * @brief  Ordena pasajeros por apellido y tipo de pasajero
 *
 * @param listPassenger lista de pasajeros
 * @param len tamaño de la lista
 * @param order criterio elegido
 * @return retorna la opcion elegida
 */
int sortPassengersByLastName(sPassenger* listPassenger, int len, int order);

/**
 * @fn int sortPassengersByCode(sPassenger*, int, int)
 * @brief Ordena pasajeros por codigo de vuelo
 *
 * @param listPassenger lista de pasajeros
 * @param len tamaño de pasajeros
 * @param order criterio de ordenamiento
 * @return retorna la opcion elegida
 */
int sortPassengersByCode(sPassenger* listPassenger, int len, int order);

/**
 * @fn void initListPassengers(sPassenger[])
 * @brief realiza una carga forzada de datos
 *
 * @param listPassenger
 */
void initListPassengers(sPassenger listPassenger[]);

/**
 * @fn int flagReset(sPassenger[], int, int*)
 * @brief reinicia la bandera en caso de que todos los campos isEmpty en 0
 *
 * @param list lista de pasajeros
 * @param len tamaño de la lista
 * @param flag bandera por parametro
 * @return
 */
int flagReset(sPassenger list[], int len, int* flag);





