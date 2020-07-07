#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Employee.h"

Employee* employee_new()
{
	Employee *emp;
	emp = (Employee*) malloc(sizeof(Employee));

	return emp;
}

int employee_getNombre(Employee *this, char* nombre)
{
	int error = 1;

	if (this != NULL && nombre != NULL)
	{
		strcpy(nombre, this->nombre);
		error = 0;
	}
	return error;
}

int employee_getHorasTrabajadas(Employee *this, int* horas)
{
	int error = 1;

	if (this != NULL)
	{
		*horas = this->horasTrabajadas;
		error = 0;
	}
	return error;

}

int employee_getSueldo(Employee *this, int* salario)
{
	int error = 1;

	if (this != NULL)
	{
		*salario = this->sueldo;
		error = 0;
	}
	return error;
}

int employee_getId(Employee *this, int* id)
{
	int error = 1;

	if (this != NULL)
	{
		*id = this->id;
		error = 0;
	}
	return error;
}

void employee_mostrar(Employee* this)
{
    if (this!=NULL)
    {
        printf(" %4d %15s               %6d    %6d\n",this->id,this->nombre,this->horasTrabajadas,this->sueldo);
    }
}

int employee_setNombre(Employee* this, char* name){
	int error = 1;
	if(this != NULL && name != NULL){
		strcpy(this->nombre, name);
		error = 0;
	}

	return error;
}

int employee_setHorasTrabajadas(Employee* this, int horas){
	int error = 1;

	if(this != NULL && horas > 0){
		this->horasTrabajadas = horas;
		error = 0;
	}

	return error;
}

int employee_setSueldo(Employee* this, int salario){
	int error = 1;

	if(this != NULL && salario >= 1000 && salario < 1000000){
		this->sueldo = salario;
		error = 0;
	}

	return error;
}

int employee_setId(Employee* this, int id){
	int error = 1;

	if(this != NULL && id > 0){
		this->id = id;
		error = 0;
	}

	return error;
}
