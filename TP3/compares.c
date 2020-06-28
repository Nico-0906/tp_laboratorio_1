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

int compareNombre(void* emp1, void* emp2){
	int retorno;

	Employee* uno = (Employee*) emp1;
	Employee* dos = (Employee*) emp2;

	retorno = strcmp(dos->nombre, uno->nombre);

	return retorno;
}

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
