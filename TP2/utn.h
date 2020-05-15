#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED



#endif // UTN_H_INCLUDED

/**
* \brief verifica si la cadena que se ingreso es numerica
* \param cadena de caracteres a ser analizada
* \return retorna 1 si la cadena es numerica y 0 si no lo es
*/
int esNumerica(char cadena[]);

/**
* \brief verifica si la cadena que se ingreso es numerica
* \param pResultado es el puntero al espacio de memoria donde se deja el resultado de la funcion
* \return retorna 0 si completo con exito la tarea o -1 si no.
*/
int getInt(int* pResultado);

/**
* \brief lee del teclado hasta un \n y lo reemplaza por \0
* \param cadena donde se guarda el resultado obtenido
* \param tamaño de dicha cadena
* \return retorna 0 si completo con exito la tarea o -1 si no.
*/
int myGets(char cadena[], int tam);

/**
* \brief solicita un numero al usuario enviando un mensaje con cantidad de intentos
*        limitada y mensaje de error.
* \param puntero a donde se dejara el resultado de la funcion
* \param mensaje es el mensaje a ser mostrado
* \param mensajeError mensaje de error a mostrar
* \param minimo es el tope minimo de numero a ingresar
* \param maximo es el tope maximo de numero a ingresar
* \param intentos es la cantidad de intentos que se le da al usuario
* \return retorna 0 si completo con exito la tarea o -1 si no.
*/
int utn_getNumero(int* pResultado, char mensaje[], char mensajeError[], int minimo, int maximo, int reintentos);

/**
* \brief modifica la cadena de caracteres para que quede como un Nombre
* \param cadena que se desea modificar
* \param tamaño de dicha cadena
*/
void tipoNombre(char vec[], int tam);

/**
* \brief toma una cadena de caracteres como fgets pero elimina el enter final
* \param lugar donde se guardara la cadena obtenida
* \param tamaño de dicha cadena
*/
void getStr(char cadena[], int tam);

/**
* \brief solicita al usuario una confirmacion unicamente permite 's' o 'n'
* \param puntero a caracter donde se guardara la opcion ingresada*
*/
void getCharConfirmValidado(char* caracter);

/**
* \brief solicita un sueldo validado
* \param sueldo puntero donde se desea guardar el sueldo
*/
int getSueldo(float* sueldo);

/**
* \brief solicita un nombre, lo valida y lo pone en formato Nombre
* \param nombre cadena dondse se cuardara el nombre ingresado
* \param tam tamaño de la cadena
*/
int getNombre(char nombre[], int tam);
