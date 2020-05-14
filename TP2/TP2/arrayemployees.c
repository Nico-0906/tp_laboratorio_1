#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>

#include "arrayemployees.h"

int initEmployees(eEmployee employee[], int tamemp){
    int retorno = -1;
    for(int i = 0 ; i < tamemp ; i++){
        employee[i].isEmpty = 1;
        retorno = 0;
    }
    return retorno;
}

int addEmployee(int idx, eEmployee employee[], int tamemp){
    int retorno = 0;

    system("clear");

    printf("****** Add employee ******\n\n");

    int lugar;
    eEmployee auxEmpleado;

    lugar = buscarLibre(employee, tamemp);

    if(lugar == -1){

    printf("\nNo hay lugar sistema completo. \n\n");

    }else{


    auxEmpleado.id = idx;

    printf("Ingrese nombre: \n");
    __fpurge(stdin);


    gets(auxEmpleado.name);

    printf("Ingrese apellido: \n");
    gets(auxEmpleado.lastName);

    printf("Ingrese sueldo: \n");
    scanf("%f", &auxEmpleado.salary);

    printf("Ingrese sector  \n");
    scanf("%d", &auxEmpleado.sector);

    printf("\nEmpleado agregado con exito.!");

    auxEmpleado.isEmpty = 0;

    employee[lugar] = auxEmpleado;

    retorno = 1;
    }

    return retorno;
}

int removeEmployee(eEmployee employee[], int tamemp, int id){
    int retorno = -1;
        for(int i = 0 ; i < tamemp ; i++){
            if(employee[i].id == id){
                employee[i].isEmpty = 1;
                retorno = 0;
            }
        }
    if(retorno == -1){
        printf("Empleado no encontrado o ID incorrecto. \n");
        getchar();
    }else{
        printf("Empleado removido con exito! \n");
        getchar();
    }
    return retorno;
}

int sortEmployee(eEmployee employee[], int tamemp, int order){
    int retorno = -1;
    eEmployee auxEmployee;
    for(int i = 0; i < tamemp - 1 ; i++){
        for(int j = i + 1 ; j < tamemp ; j++){
            if(order == 1){
                if(employee[i].sector < employee[j].sector){
                    auxEmployee = employee[i];
                    employee[i] = employee[j];
                    employee[j] = auxEmployee;
                    retorno = 0;
                }else if(employee[i].sector == employee[j].sector && employee[i].lastName < employee[j].lastName){
                    auxEmployee = employee[i];
                    employee[i] = employee[j];
                    employee[j] = auxEmployee;
                    retorno = 0;
                }
            }else if(order == 0){
                if(employee[i].sector > employee[j].sector){
                    auxEmployee = employee[i];
                    employee[i] = employee[j];
                    employee[j] = auxEmployee;
                    retorno = 0;
                }else if(employee[i].sector == employee[j].sector && employee[i].lastName > employee[j].lastName){
                    auxEmployee = employee[i];
                    employee[i] = employee[j];
                    employee[j] = auxEmployee;
                    retorno = 0;
                }
            }

        }
    }

    return retorno;
}

int buscarEmployee(eEmployee employee[], int tamemp){
    int retorno = 0;
    for(int i = 0; i < tamemp ; i++){
        if(employee[i].isEmpty == 0){
            retorno = 1;
        }
    }
    return retorno;
}

int printEmployees(eEmployee employee[], int tamemp){
    int retorno = -1;
    int buscador;
    buscador = buscarEmployee(employee, tamemp);

    system("clear");
    printf("****** Empleados ****** \n\n");
    printf("Name     LastName      Salary     Sector\n");

    if(buscador){
        for(int i = 0 ; i < tamemp ; i++){
            printf("%10s     %10s    %5.2f    %4d \n", employee[i].name, employee[i].lastName, employee[i].salary, employee[i].sector);
        }
    }else{
        printf("No hay empleados.\n");
    }
    return retorno;
}

void informesEmpleados(eEmployee employee[], int tamemp){

    char seguir = 's';
    char confirma;
    do{
        switch(menuInformar())
        {
            case 1:

                break;
            case 2:

                break;
            case 3:
                printf("\nConfirma salida? s/n \n");
                __fpurge(stdin);
                scanf("%c", &confirma);
                if(confirma == 's'){
                    seguir = 'n';
                }
                break;
        }

        __fpurge(stdin);
        getchar();

    }while(seguir == 's');
}

int buscarLibre(eEmployee employee[], int tamsec){
    int posicion = -1;
        for(int i = 0 ; i < tamsec ; i++){
            if(employee[i].isEmpty == 1){
                posicion = i;
                break;
            }
        }
    return posicion;
}

int menuOpciones(){
    int retorno;
    system("clear");

    printf("****** Gestion de empleados ****** \n\n");
    printf("1. Altas \n");
    printf("2. Modificar \n");
    printf("3. Baja \n");
    printf("4. Informar \n");
    printf("5. Salir \n");
    printf("Ingrese opcion: ");
    __fpurge(stdin);
    scanf("%d", &retorno);

    return retorno;
}

int menuInformar(){
    int retorno;
    system("clear");

    printf("****** Menu de informes ******\n\n");

    printf("1. Empleados ordenados ordenados alfabeticamente por Apellido y Sector  \n");
    printf("2. Total y promedio de salarios y cantidad de empleados que superan salario promdio \n");
    printf("3. Salir\n");
    printf("Ingrese opcion: ");
    __fpurge(stdin);

    scanf("%d", &retorno);
    return retorno;
}

int findEmployeeById(int id, eEmployee employee[], int tamemp){
    int retorno = -1;
    for(int i = 0 ; i < tamemp ; i++){
        if(employee[i].id == id && employee[i].isEmpty == 0){
            retorno = i;
            break;
        }
    }
    return retorno;
}

void printEmployee(eEmployee employee){
    printf("%4d   %10s    %10s      %8.2f  %d \n", employee.id , employee.name, employee.lastName, employee.salary, employee.sector);
}


void modificarEmpleado(eEmployee employee[], int tamemp){
    system("clear");
    int auxId;
    int busqueda;
    char confirmacion;
    float auxSueldo;
    char auxNombre[20];
    int opcion;

    printf("***** MODIFICAR EMPLEADO ***** \n\n");

    printf("Ingrese ID de empleado: \n");
    scanf("%d", &auxId);
    getchar();

    busqueda = findEmployeeById(auxId, employee, tamemp);

    if(busqueda != -1){
        printEmployee(employee[busqueda]);

        printf("Que desea modificar: \n\n1- Nombre\n 2- Apllido\n 3- Salario \n 4- Sector \n 5- Cancelar \n\n");

        scanf("%d", &opcion);

    switch(opcion){
        case 1:
            printf("Ingrese nuevo nombre: \n");
            __fpurge(stdin);
            gets(auxNombre);

            printf("\nDesea confirmar la modificacion? s/n \n\n");
            __fpurge(stdin);
            scanf("%c", &confirmacion);

            if(confirmacion == 's'){
                strcpy(employee[busqueda].name, auxNombre);
                printf("\nModificado con exito.! \n\n");
            }else{
                printf("\nOperacion cancelada. \n\n");
            }
            break;
        case 2:
            printf("Ingrese nuevo apellido: \n");
             __fpurge(stdin);
            gets(auxNombre);

            printf("\nDesea confirmar la modificacion? s/n \n\n");
            __fpurge(stdin);
            scanf("%c", &confirmacion);

            if(confirmacion == 's'){
                strcpy(employee[busqueda].lastName, auxNombre);
                printf("\nModificado con exito.! \n\n");
            }else{
                printf("\nOperacion cancelada. \n\n");
            }
            break;
        case 3:
            printf("Ingrese nueva salario: \n");
            scanf("%f", &auxSueldo);
            printf("\nDesea confirmar la modificacion? s/n \n\n");
            __fpurge(stdin);
            scanf("%c", &confirmacion);

            if(confirmacion == 's'){
                employee[busqueda].salary = auxSueldo;
                printf("\nModificado con exito.! \n\n");
            }else{
                printf("\nOperacion cancelada. \n\n");
            }
            break;
        case 4:
            printf("Ingrese nuevo sector: \n");
            scanf("%d", &auxId);
            printf("\nDesea confirmar la modificacion? s/n \n\n");
            __fpurge(stdin);
            scanf("%c", &confirmacion);

            if(confirmacion == 's'){
                employee[busqueda].sector = auxId;
                printf("\nModificado con exito.! \n\n");
            }else{
                printf("\nOperacion cancelada. \n\n");
            }
            break;
        case 5:
            break;
        }

    }else{
        printf("\nEmpleado no encontrado. \n\n");
        getchar();
    }
}

