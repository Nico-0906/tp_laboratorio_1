#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

/**
 * @brief	reserva espacio en memoria para un nuevo empleado
 * @return	retorna la direccion de memoria para el nuevo empleado
 */
Employee* employee_new();

/**
 * @brief
 * @param idStr
 * @param nombreStr
 * @param horasTrabajadasStr
 * @return
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr);

void employee_delete();

/**
 * @brief 	asigna el id a la estructura this si no es NULL
 * @param this	estructura donde se asignara el ID
 * @param id	id a asignar
 * @return		retorna 1 si falla o 0 si realiza la tarea con exito
 */
int employee_setId(Employee* this,int id);

/**
 * @brief 	busca el id del empleado y lo guarda en la variable id
 * @param this	empleado que se desea sacarle el id
 * @param id	variable donde se guardara el id del empleado
 * @return	retorna 1 si falla o 0 si realiza la tarea con exito
 */
int employee_getId(Employee* this,int* id);

/**
 * @brief 	asigna el nombre a la estructura this si no es NULL
 * @param this	estructura donde se asignara el nombre
 * @param nombre	nombre a asignar
 * @return		retorna 1 si falla o 0 si realiza la tarea con exito
 */
int employee_setNombre(Employee* this,char* nombre);

/**
 * @brief 	busca el nombre del empleado y lo guarda en la variable nombre
 * @param this	empleado que se desea sacarle el nombre
 * @param nombre	variable donde se guardara el nombre del empleado
 * @return	retorna 1 si falla o 0 si realiza la tarea con exito
 */
int employee_getNombre(Employee* this,char* nombre);

/**
 * @brief 	asigna las horas trabajadas a la estructura this si no es NULL
 * @param this	estructura donde se asignaran las horas trabajadas
 * @param horasTrabajadas	horas a asignar
 * @return		retorna 1 si falla o 0 si realiza la tarea con exito
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);

/**
 * @brief 	busca las horas trabajadas del empleado y lo guarda en la variable horastrabajadas
 * @param this	empleado que se desea sacarle las horas trabajadas
 * @param horasTrabajadas	variable donde se guardaran las horas trabajadas del empleado
 * @return	retorna 1 si falla o 0 si realiza la tarea con exito
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

/**
 * @brief 	asigna un sueldo a la estructura this si no es NULL
 * @param this	estructura donde se asignara el sueldo
 * @param sueldo	sueldo a asignar
 * @return		retorna 1 si falla o 0 si realiza la tarea con exito
 */
int employee_setSueldo(Employee* this,int sueldo);

/**
 * @brief 	busca el sueldo del empleado y lo guarda en la variable sueldo
 * @param this	empleado que se desea sacarle el sueldo
 * @param sueldo	variable donde se guardara el sueldo del empleado
 * @return	retorna 1 si falla o 0 si realiza la tarea con exito
 */
int employee_getSueldo(Employee* this,int* sueldo);

/**
 * @brief  muestra un empleado indicado
 * @param this	empleado que se desea mostrar
 */
void employee_mostrar(Employee* this);

#endif // employee_H_INCLUDED
