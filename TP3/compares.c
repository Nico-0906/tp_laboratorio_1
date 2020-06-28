/*
 * compares.c
 *
 *  Created on: 27 jun. 2020
 *      Author: Nico
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "compares.h"
#include "Employee.h"

/** \brief Compara los ID de dos empleados
 *
 *  \param void primer empleado
 *  \param void primer empleado
 *  \return retorno Retorna 0 si los ID son iguales, retorna -1
 *  				si el primero es mayor al segundo y retorna 1
 *  				si el segundo es mayor al primero
 */
int compareId(void* emp1, void* emp2){
	int retorno;

	Employee* uno = (Employee*) emp1;
	Employee* dos = (Employee*) emp2;

	if(uno->id == dos->id){
		retorno = 0;
	}else if(uno->id > dos->id){
		retorno = -1;
	}else{
		retorno = 1;
	}

	return retorno;
}

/** \brief Compara los Nombres de dos empleados
 *
 *  \param void primer empleado
 *  \param void primer empleado
 *  \return retorno Retorna 0 si los nombres son iguales, retorna -1
 *  				si el primero es mayor al segundo y retorna 1
 *  				si el segundo es mayor al primero
 */
int compareNombre(void* emp1, void* emp2){
	int retorno;

	Employee* uno = (Employee*) emp1;
	Employee* dos = (Employee*) emp2;

	retorno = strcmp(dos->nombre, uno->nombre);

	return retorno;
}

/** \brief Compara las horas trabajadas de dos empleados
 *
 *  \param void primer empleado
 *  \param void primer empleado
 *  \return retorno Retorna 0 si la cantidad de horas son iguales, retorna -1
 *  				si las del primero son mas al segundo y retorna 1
 *  				si el segundo es mayor al primero
 */
int compareHoras(void* emp1, void* emp2){
	int retorno;

	Employee* uno = (Employee*) emp1;
	Employee* dos = (Employee*) emp2;

	if(uno->horasTrabajadas == dos->horasTrabajadas){
		retorno = 0;
	}else if(uno->horasTrabajadas > dos->horasTrabajadas){
		retorno = -1;
	}else{
		retorno = 1;
	}

	return retorno;
}

int compareSueldo(void* emp1, void* emp2){
	int retorno;

	Employee* uno = (Employee*) emp1;
	Employee* dos = (Employee*) emp2;

	if(uno->sueldo == dos->sueldo){
		retorno = 0;
	}else if(uno->sueldo > dos->sueldo){
		retorno = -1;
	}else{
		retorno = 1;
	}

	return retorno;

}
