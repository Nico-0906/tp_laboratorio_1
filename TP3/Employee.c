#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "LinkedList.h"
#include "Employee.h"
#include "Controller.h"
#include "parser.h"

Employee* employee_new(){
    Employee* auxEmployee;
    auxEmployee = (Employee*) malloc(sizeof(Employee));

    if(auxEmployee!= NULL){
        auxEmployee->id = 0;
        strcpy(auxEmployee->nombre, "");
        auxEmployee->horasTrabajadas = 0;
        auxEmployee->sueldo = 0;
    }

    return auxEmployee;
}
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr){
    Employee* auxEmployee;
    auxEmployee = employee_new();

    if(auxEmployee != NULL){
        if(validarId(auxEmployee) == 0 && validarNombre(auxEmployee) == 0 && validarHorasTrabajadas(auxEmployee) == 0 && validarSueldo(auxEmployee) == 0){
            auxEmployee->id = atoi(idStr);
            strcpy(auxEmployee->nombre, nombreStr);
            auxEmployee->horasTrabajadas = atoi(horasTrabajadasStr);
            auxEmployee->sueldo = atoi(sueldoStr);
        }else{
            free(auxEmployee);
            auxEmployee = NULL;
        }
    }

    return auxEmployee;
}

int employee_delete(Employee* employee){
    int error = 1;
    if(employee != NULL){
        free(employee);
        error = 0;
    }
    return error;
}

int employee_setId(Employee* this,int id){
    int error = 1;

    if(this != NULL && id <= 20000 && id >= 10000){
        this->id = id;
        error = 0;
    }
    return error;
}
int employee_getId(Employee* this,int* id){
    int error = 1;
    if(id != NULL && this != NULL){
    *id = this->id;
    error = 0;
    }
    return error;
}

int employee_setNombre(Employee* this,char* nombre){
    int error = 1;

    if(this != NULL && strlen(nombre) >= 3 && strlen(nombre) < 20){
        strcpy(this->nombre, nombre);
        error = 0;
    }
    return error;
}
int employee_getNombre(Employee* this,char* nombre){
    int error = 1;

    if(this != NULL && nombre != NULL && strlen(nombre) > 19){
        strcpy(nombre, this->nombre);
        error = 0;
    }
    return error;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas){
    int error = 1;

    if(this != NULL){
        this->horasTrabajadas = horasTrabajadas;
        error = 0;
    }
    return error;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas){
    int error = 1;
    if(horasTrabajadas != NULL && this != NULL){
    *horasTrabajadas = this->horasTrabajadas;
    error = 0;
    }
    return error;
}

int employee_setSueldo(Employee* this,int sueldo){
    int error = 1;

    if(this != NULL){
        this->sueldo = sueldo;
        error = 0;
    }
    return error;
}
int employee_getSueldo(Employee* this,int* sueldo){
    int error = 1;
    if(sueldo != NULL && this != NULL){
    *sueldo = this->sueldo;
    error = 0;
    }
    return error;
}

int validarId(Employee* employee){
    int error = 1;
        error = 0;
    return error;
}
int validarNombre(Employee* employee){
     int error = 1;
        error = 0;
    return error;
}
int validarHorasTrabajadas(Employee* employee){
    int error = 1;
        error = 0;
    return error;
}
int validarSueldo(Employee* employee){
    int error = 1;
        error = 0;
    return error;
}

/*
int mostrarEmployee(Employee* employee){
    int error = 1;

    if(employee != NULL){
        error = 0;

        printf("%d    %10s     %d       %d\n", employee->id, employee->nombre, employee->horasTrabajadas, employee->sueldo);

    }

    return error;
}
int mostrarEmployees(LinkedList* lista){
    int error = 1;
    int bandera = 1;
    int tam;
    tam = ll_len(lista);
    Employee* auxEmployee;


    if(lista != NULL){
        printf("\nID         NOMBRE     HORAS TRABAJADAS     SUELDO\n\n");
        error = 0;
        for(int i = 0 ; i < tam ; i++){

            auxEmployee = (Employee*) ll_get(lista, i);
            if( auxEmployee != NULL){
                mostrarEmployee(auxEmployee);
                bandera = 0;
            }
        }
        if(bandera == 1){
            printf("No hay personas para mostrar\n");
        }
    error = 0;
    }

    return error;

}
*/
