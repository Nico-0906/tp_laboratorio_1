/*
 * herramientas.h
 *
 *  Created on: 19 jun. 2020
 *      Author: Nico
 */

#ifndef HERRAMIENTAS_H_
#define HERRAMIENTAS_H_



#endif /* HERRAMIENTAS_H_ */

/**
 * @brief menu de opciones del programa
 * @return	retorna la opcion ingresada por el usuario
 */
int menuOpciones(void);

/**
 * @brief obtiene un nombre y lo guarda en la variable nombre indicada
 * @param nombre	variable nombre donde se guardara
 * @param tam	tamaño de la variable nombre
 * @return	retorna 0 si fallo o 1 si lo realizo con exito
 */
int h_getName(char* nombre, int tam);

/**
 * @brief obtiene una cadena de caracteres
 * @param cadena	variable cadena donde se guardara la cadena de caracteres
 * @param tam	tamaño de la cadena
 * @return	retorna 0 si falla o 1 si realiza la tarea con exito
 */
int h_fgets(char* cadena, int tam);
