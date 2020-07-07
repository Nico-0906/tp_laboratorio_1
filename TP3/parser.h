/*
 * parser.h
 *
 *  Created on: 27 jun. 2020
 *      Author: Nico
 */

#ifndef DEBUG_PARSER_H_
#define DEBUG_PARSER_H_



#endif /* DEBUG_PARSER_H_ */

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE *pFile, LinkedList *pArrayEmployee);

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE *pFile, LinkedList *pArrayEmployee);
