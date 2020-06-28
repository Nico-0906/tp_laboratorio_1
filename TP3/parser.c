#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "Controller.h"
#include "parser.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE *pFile, LinkedList *pArrayEmployee)
{
	int error = 1;
	int cont;
	Employee *empleado;
	char buffer[4][128];

	cont = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1],
			buffer[2], buffer[3]);

	if (cont == 4)
	{
		empleado = employee_new();
		empleado->id = atoi(buffer[0]);
		strcpy(empleado->nombre, buffer[1]);
		empleado->horasTrabajadas = atoi(buffer[2]);
		empleado->sueldo = atoi(buffer[3]);
		ll_add(pArrayEmployee, empleado);
		error = 0;
	}
	return error;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE *pFile, LinkedList *pArrayEmployee)
{
	int error = 1;
	Employee* empleado;

	empleado = employee_new();

	fread(empleado, sizeof(Employee), 1, pFile);

	if (empleado->id != 0)
	{
		ll_add(pArrayEmployee, empleado);
		error = 0;
	}
	return error;
}
