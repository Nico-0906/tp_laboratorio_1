#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "LinkedList.h"
#include "Employee.h"
#include "string.h"
#include "herramientas.h"
#include "Controller.h"
#include "parser.h"
#include "compares.h"

int ll_obtIndiceXId(LinkedList *this, int id)
{
	int error = 1;
	int tam;
	Employee *emp;
	tam = ll_len(this);
	for (int i = 0; i < tam; i++)
	{
		emp = ll_get(this, i);
		if (emp->id == id)
		{
			error = i;
		}
	}
	free(emp);
	return error;
}

int obtenerId(int *id)
{
	int error = 1;

	*id = 1001;

	FILE *f;
	f = fopen("proxId.bin", "rb");

	if (f != NULL)
	{
		fread(id, sizeof(int), 1, f);
		fclose(f);
		error = 0;
	}

	return error;
}

int actualizarId(int id)
{
	int error = 1;
	int proxId = ++id;
	FILE *f = fopen("proxId.bin", "wb");

	if (f != NULL)
	{
		error = 0;
		fwrite(&proxId, sizeof(int), 1, f);
		fclose(f);
	}
	return error;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char *path, LinkedList *pArrayEmployee)
{
	int error = 1;

	FILE *f;

	if (path != NULL && pArrayEmployee != NULL)
	{
		f = fopen(path, "r");

		if (f != NULL)
		{
			while (!feof(f))
			{
				if (!parser_EmployeeFromText(f, pArrayEmployee))
				{
					error = 0;
				}
			}

			fclose(f);
		}

		if (error == 1)
		{
			printf(
					"\nNo se pudieron cargar los datos, el documento pudo haber sido eliminado o estar dañado.\n");
			fflush(stdin);
			getchar();
		}

	}
	return error;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char *path, LinkedList *pArrayEmployee)
{
	int error = 1;

	FILE *f;

	if (path != NULL && pArrayEmployee != NULL)
	{
		f = fopen(path, "rb");

		if (f != NULL)
		{
			while (!feof(f))
			{
				if(!parser_EmployeeFromBinary(f, pArrayEmployee)){
					error = 0;
				}
			}
			fclose(f);
		}

		if (error == 1)
		{
			printf(
					"\nNo se pudieron cargar los datos, el documento pudo haber sido eliminado o estar dañado.\n");
			getchar();
		}
	}
	return error;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList *pArrayEmployee)
{
	int error = 1;
	int id;
	Employee *empleado = employee_new();

	system("cls");
	printf("****** Nuevo Empleado ******\n\n");

	if (empleado != NULL)
	{
		obtenerId(&id);
		empleado->id = id;

		printf("El ID del nuevo empleado es: %d\n\n", empleado->id);
		printf("Ingrese el nombre del empleado: ");
		h_getName(empleado->nombre, 128);
		printf("\n\nIngrese horas trabajadas: ");
		scanf("%d", &empleado->horasTrabajadas);
		printf("\n\nIngrese el sueldo del empleado: ");
		scanf("%d", &empleado->sueldo);
		error = ll_add(pArrayEmployee, empleado);
		fflush(stdin);

		if (error == 1)
		{
			printf("\n\nHubo un error y no se pudo conseguir memoria. ");
			getchar();
		}
		else
		{
			printf("\n\nEmpleado agregado con exito!");
			actualizarId(empleado->id);
			getchar();
			free(empleado);
		}
	}
	else
	{
		printf("\nNo se pudo conseguir memoria!");
	}
	return error;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList *pArrayEmployee)
{
	system("cls");
	int error = 1;
	int opcion = 0;
	int indice;
	char auxNombre[128];
	int auxSalario;
	int auxHoras;

	Employee *emp;

	if(pArrayEmployee != NULL){

	controller_ListEmployee(pArrayEmployee);
	printf("\nIngrese id del empleado que desea modificar: ");
	scanf("%d", &indice);
	indice--;
	while (opcion != 4)
	{
		system("cls");
		printf("****** Editar empleado ******\n\n");

		emp = (Employee*) ll_get(pArrayEmployee, indice);
		employee_mostrar(emp);

		printf("\n1-. Editar nombre de empleado.\n");
		printf("2-. Editar sueldo de empleado. \n");
		printf("3-. Editar horas trabajadas del empleado. \n");
		printf("4-. Cancelar edicion.\n\n");
		printf("Ingrese opcion: ");
		scanf("%d", &opcion);
		fflush(stdin);

		switch (opcion)
		{
		case 1:
			printf("\n\nIngrese nuevo nombre de empleado: ");
			h_getName(auxNombre, 128);

			if(!employee_setNombre(emp, auxNombre)){
				printf("\n\nCambio realizado con exito!!");
				opcion = 4;
				fflush(stdin);
				getchar();
			}
			break;
		case 2:
			printf("\n\nIngrese nuevo sueldo del empleado: ");
			scanf("%d", &auxSalario);
			if(!employee_setSueldo(emp, auxSalario)){
				printf("\n\nCambio realizado con exito!!");
				opcion = 4;
				fflush(stdin);
				getchar();
			}
			break;
		case 3:
			printf("\n\nIngrese nuevas horas trabajadas del empleado: ");
			scanf("%d", &auxHoras);
			if(!employee_setHorasTrabajadas(emp, auxHoras)){
				printf("\n\nCambio realizado con exito!!");
				opcion = 4;
				fflush(stdin);
				getchar();
			}
			break;
		}
	}
	}

	return error;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList *pArrayEmployee)
{
	int error = 1;
	Employee* emp;
	int indice;
	char opcion;

	if(pArrayEmployee != NULL){
	controller_ListEmployee(pArrayEmployee);
	printf("\nIngrese id del empleado que desea dar de baja: ");
	scanf("%d", &indice);
	indice--;
	if(indice > 0){
		emp = (Employee*) ll_get(pArrayEmployee, indice);
		employee_mostrar(emp);
		printf("\n\nConfirma la baja de empleado? s/n: ");
		fflush(stdin);
		scanf("%c", &opcion);
		if(opcion == 's' || opcion == 'S'){
			ll_remove(pArrayEmployee, indice);
			error = 0;
			printf("\n\nEmpleado dado de baja con exito!");
			fflush(stdin);
			getchar();
		}
	}
	free(emp);
	}
	return error;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList *pArrayEmployee)
{
	int cant;
	int error = 1;
	Employee *emp;
	cant = ll_len(pArrayEmployee);
	system("cls");
	printf("****** Lista de Empleados ******\n\n");
	if (cant > 0)
	{
		printf("   ID          Nombre     Horas trabajadas    Sueldo\n\n");
		for (int i = 0; i < cant; i++)
		{
			emp = (Employee*) ll_get(pArrayEmployee, i);
			employee_mostrar(emp);
		}
		error = 0;
	}
	else
	{
		printf("\nNo hay empleados para mostrar. Primero deben ser cargados\n");
	}
	free(emp);
	return error;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList *pArrayEmployee)
{
	int error = 1;
	int opcion = 0;

	while(opcion != 9){
		opcion = menuOpcionesSort();
		fflush(stdin);
		switch(opcion){
		case 1:
			if(ll_sort(pArrayEmployee, compareId ,0) != -1){
				printf("\nOrdenados con exito!");
				getchar();
				error = 0;
			}
			break;
		case 2:
			if(ll_sort(pArrayEmployee, compareNombre, 0) != -1){
				printf("\nOrdenados con exito!");
				getchar();
				error = 0;
			}
			break;
		case 3:
			if(ll_sort(pArrayEmployee, compareHoras, 0) != -1){
				printf("\nOrdenados con exito!");
				getchar();
				error = 0;
			}
			break;
		case 4:
			if(ll_sort(pArrayEmployee, compareSueldo, 0) != -1){
				printf("\nOrdenados con exito!");
				getchar();
				error = 0;
			}
			break;
		case 5:
			if(ll_sort(pArrayEmployee, compareId, 1) != -1){
				printf("\nOrdenados con exito!");
				getchar();
				error = 0;
			}
			break;
		case 6:
			if(ll_sort(pArrayEmployee, compareNombre, 1) != -1){
				printf("\nOrdenados con exito!");
				getchar();
				error = 0;
			}
			break;
		case 7:
			if(ll_sort(pArrayEmployee, compareHoras, 1) != -1){
				printf("\nOrdenados con exito!");
				getchar();
				error = 0;
			}
			break;
		case 8:
			if(ll_sort(pArrayEmployee, compareSueldo, 1) != -1){
				printf("\nOrdenados con exito!");
				getchar();
				error = 0;
			}
			break;
		}
	}
	return error;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char *path, LinkedList *pArrayEmployee)
{
	int error = 1;
	int cant;
	char nombre[150];
	int horas;
	int salario;
	int id;

	Employee *emp;
	FILE *f;
	f = fopen(path, "w");
	cant = ll_len(pArrayEmployee);

	for (int i = 0; i < cant; i++)
	{
		emp = (Employee*) ll_get(pArrayEmployee, i);

		employee_getNombre(emp, nombre);
		employee_getHorasTrabajadas(emp, &horas);
		employee_getSueldo(emp, &salario);
		employee_getId(emp, &id);

		error = fprintf(f, "%d,%s,%d,%d\n", id, nombre, horas, salario);
		if (error < 0)
		{
			break;
		}

	}
	if (error < 0)
	{
		printf("No se pudo guardar los datos en el documento");
		getchar();
	}
	else
	{
		printf("Datos guardados con exito!\n");
		error = 0;
		getchar();
	}

	free(emp);
	fclose(f);
	return error;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char *path, LinkedList *pArrayEmployee)
{
	int error = 1;
	int cant;
	Employee *emp;
	FILE *f;
	f = fopen(path, "wb");
	cant = ll_len(pArrayEmployee);
	for (int i = 0; i < cant; i++)
	{
		emp = (Employee*) ll_get(pArrayEmployee, i);
		fwrite(emp, sizeof(Employee), 1, f);
	}

	if (error < 0)
	{
		printf("No se pudo guardar los datos en el documento");
		getchar();
	}
	else
	{
		printf("Datos guardados con exito!\n");
		error = 0;
		getchar();
	}

	free(emp);
	fclose(f);
	return error;
}

int menuOpcionesSort(){
	int opcion;
	system("cls");

	printf("******  Menu de ordenamientos  ******\n\n");
	printf(" 1. Ordenar Emp por ID Ascendente.\n");
	printf(" 2. Ordenar Emp por nombre Ascendente.\n");
	printf(" 3. Ordenar Emp por Horas de Trabajo Ascendente.\n");
	printf(" 4. Ordenar Emp por Sueldo Ascendente.\n");
	printf(" 5. Ordenar Emp por ID Desendente.\n");
	printf(" 6. Ordenar Emp por nombre Desendente.\n");
	printf(" 7. Ordenar Emp por Horas de Trabajo Desendente.\n");
	printf(" 8. Ordenar Emp por Sueldo Desendente.\n");
	printf(" 9. Salir\n");
	printf("\nIngrese opcion y aguarde unos segundos por favor: ");
	fflush(stdin);
	scanf("%d",&opcion);

	return opcion;
}
