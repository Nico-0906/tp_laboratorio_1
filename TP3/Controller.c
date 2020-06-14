#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "LinkedList.h"
#include "Employee.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    int error = 1;
    char buffer[4][120];
    int cant;
    Employee* auxEmployee;
    FILE* f;
    f = fopen(path, "r");

    while(!feof(f)){
        cant = fscanf(f, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);
        if(cant == 4){

            auxEmployee = employee_new();
            auxEmployee->id = atoi(buffer[0]);
            strcpy(auxEmployee->nombre, buffer[1]);
            auxEmployee->horasTrabajadas = atoi(buffer[2]);
            auxEmployee->sueldo = atoi(buffer[3]);
            ll_add(pArrayListEmployee, auxEmployee);
            error = 0;
        }
    }
    if(error == 1){
        printf("\nNo se pudieron cargar los datos desde el documento.");
    }else{
        printf("\nDatos cargados con exito!");
    }

    fclose(f);

    return error;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    int error = 1;
    Employee* auxEmployee;

    FILE* f;
    f = fopen(path, "rb");


    while(!feof(f)){
        auxEmployee = employee_new();
        fread(auxEmployee , sizeof(Employee) , 1 , f);

        ll_add(pArrayListEmployee, auxEmployee);
        error = 0;

    }

    if(error == 1){
        printf("\nNo se pudieron cargar los datos desde el documento.");
    }else{
        printf("\nDatos cargados con exito!");
    }

    fclose(f);

    return error;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

