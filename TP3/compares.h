/*
 * compares.h
 *
 *  Created on: 27 jun. 2020
 *      Author: Nico
 */

#ifndef COMPARES_H_
#define COMPARES_H_



#endif /* COMPARES_H_ */
/**
 * @brief compara los ids de los dos empleados
 * @param emp1	primer empleado a comparar
 * @param emp2	segundo empleado a comparar
 * @return	retorna 0 si tienen el mismo id, si el id del primero es mayo devuelve -1 y sino devuelve 1
 */
int compareId(void* emp1, void* emp2);
/**
 * @brief compara los nombres de los dos empleados
 * @param emp1	primer empleado a comparar
 * @param emp2	segundo empleado a comparar
 * @return	retorna 0 si tienen el mismo nombre, si el nombre del primero es mayo devuelve -1 y sino devuelve 1
 */
int compareNombre(void* emp1, void* emp2);
/**
 * @brief compara las horas de los dos empleados
 * @param emp1	primer empleado a comparar
 * @param emp2	segundo empleado a comparar
 * @return	retorna 0 si tienen la misma hora, si la hora del primero es mayo devuelve -1 y sino devuelve 1
 */
int compareHoras(void* emp1, void* emp2);
/**
 * @brief compara los sueldos de los dos empleados
 * @param emp1	primer empleado a comparar
 * @param emp2	segundo empleado a comparar
 * @return	retorna 0 si tienen el mismo sueldo, si el sueldo del primero es mayo devuelve -1 y sino devuelve 1
 */
int compareSueldo(void* emp1, void* emp2);
