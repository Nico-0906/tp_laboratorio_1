#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include <ctype.h>

#include "arrayemployees.h"
#include "utn.h"

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

        if(getNombre(auxEmpleado.name, 51)){
            printf("Ingrese apellido: \n");

            if(getNombre(auxEmpleado.lastName, 51)){

                if(getSueldo(&auxEmpleado.salary)){

                    printf("Ingrese sector  \n");
                    scanf("%d", &auxEmpleado.sector);
                    auxEmpleado.isEmpty = 0;
                    employee[lugar] = auxEmpleado;
                    printf("\nEmpleado agregado con exito.!");
                    __fpurge(stdin);
                    getchar();
                    retorno = 1;
                }
            }
        }
    }

    return retorno;
}


int removeEmployee(eEmployee employee[], int tamemp){
    int retorno = 0;
    char confirm;
    int flag = 0;
    int id;

    system("clear");
    printf("****** Baja employee ******\n\n");

    printEmployees(employee, tamemp);

    printf("\n\nIngrese id empleado: ");
    scanf("%d", &id);
    getchar();

            for(int i = 0 ; i < tamemp ; i++){
                if(employee[i].id == id && employee[i].isEmpty == 0){
                    printf("\n Confirma baja? s/n  ");
                    getCharConfirmValidado(&confirm);

                    if(confirm == 's'){
                        employee[i].isEmpty = 1;
                        printf("\n\nEmpleado removido con exito! \n");
                        retorno = 1;
                        getchar();
                    }else{
                        printf("\n\nSe cancelo la baja.");
                        getchar();
                    }

                    flag = 1;
                }
            }
            if(flag == 0){
                printf("\nNo se encontro empleado con ese ID");
            }
            getchar();
        return retorno;
}


int sortEmployee(eEmployee employee[], int tamemp, int order){
    int retorno = -1;
    eEmployee auxEmployee;

    for(int i = 0; i < tamemp - 1 ; i++){
        for(int j = i + 1 ; j < tamemp ; j++){
            if(order == 1){
                if(employee[i].sector > employee[j].sector){
                    auxEmployee = employee[i];
                    employee[i] = employee[j];
                    employee[j] = auxEmployee;
                    retorno = 0;
                }else if((employee[i].sector == employee[j].sector) && (strcmp(employee[i].lastName, employee[j].lastName) > 0)){
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
                }else if((employee[i].sector == employee[j].sector) && (strcmp(employee[i].lastName, employee[j].lastName) < 0)){
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
    printf("ID       Name         LastName      Salary     Sector\n\n");

    if(buscador){
        for(int i = 0 ; i < tamemp ; i++){
            if(employee[i].isEmpty == 0){
                printf("%d   %10s      %10s    $%8.2f       %d\n", employee[i].id, employee[i].name, employee[i].lastName, employee[i].salary, employee[i].sector);
                retorno = 1;
            }
        }
    }else{
        printf("\nNo hay empleados.\n");
    }
    return retorno;
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
    int bandera = 0;
    system("clear");

    printf("****** Gestion de empleados ****** \n\n");
    printf("1. Altas \n");
    printf("2. Modificar \n");
    printf("3. Baja \n");
    printf("4. Informar \n");
    printf("5. Salir \n");
    printf("Ingrese opcion: ");
    __fpurge(stdin);

    while(bandera == 0){
        scanf("%d", &retorno);
        if(retorno <= 5 && retorno >= 1){
            bandera = 1;
        }else{
            printf("\nOpcion incorrecta, ingrese opcion: ");
            __fpurge(stdin);
        }
    }

    return retorno;
}


int menuInformar(){
    int retorno;
    int bandera = 0;
    system("clear");

    printf("****** Menu de informes ******\n\n");

    printf("1. Empleados ordenados ordenados alfabeticamente por Apellido y Sector  \n");
    printf("2. Total y prom de salarios y cant de empleados que superan salario prom \n");
    printf("3. Salir\n");
    printf("Ingrese opcion: ");
    __fpurge(stdin);

    while(bandera == 0){
        scanf("%d", &retorno);
        if(retorno <= 3 && retorno >= 1){
            bandera = 1;
        }else{
            printf("\nOpcion incorrecta, ingrese opcion: ");
            __fpurge(stdin);
        }
    }

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
    printf("%d   %10s   %10s    $%.2f       %d\n", employee.id , employee.name, employee.lastName, employee.salary, employee.sector);
}


void modificarEmpleado(eEmployee employee[], int tamemp){
    system("clear");
    int auxId;
    int busqueda;
    char confirmacion;
    float auxSueldo;
    char auxNombre[51];
    int opcion;

    printf("***** MODIFICAR EMPLEADO ***** \n\n");

    printEmployees(employee, tamemp);

    printf("\nIngrese ID de empleado: \n");
    scanf("%d", &auxId);
    getchar();

    busqueda = findEmployeeById(auxId, employee, tamemp);

    if(busqueda != -1){

        printf("\nID         Name     LastName      Salary     Sector\n\n");
        printEmployee(employee[busqueda]);

        printf("Que desea modificar: \n\n1- Nombre\n 2- Apllido\n 3- Salario \n 4- Sector \n 5- Cancelar \n\n");

        scanf("%d", &opcion);

    switch(opcion){

        case 1:
            printf("Ingrese nuevo nombre: \n");
            __fpurge(stdin);
            getStr(auxNombre, 51);
            tipoNombre(auxNombre, 51);


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
            getStr(auxNombre, 51);
            tipoNombre(auxNombre, 51);

            printf("\nDesea confirmar la modificacion? s/n \n\n");
            __fpurge(stdin);
            getCharConfirmValidado(&confirmacion);

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


void infoEmployees(eEmployee employee[], int tamemp){
    char salir = 'n';

    while(salir == 'n'){
        switch(menuInformar()){

            case 1:
                sortEmployee(employee, tamemp, 1);
                printEmployees(employee, tamemp);
                __fpurge(stdin);
                getchar();
                break;

            case 2:
                totalYPromSalary(employee, tamemp);
                break;

            case 3:
                printf("\nDesea salir? s/n\n");
                __fpurge(stdin);
                getCharConfirmValidado(&salir);
                break;
        }
    }
}


void totalYPromSalary(eEmployee employee[], int tamemp){
    float total = 0;
    float promedio = 0;
    int contador = 0;
    int cantProm = 0;

        for(int i = 0; i < tamemp ; i++){
            if(employee[i].isEmpty == 0){
                total += employee[i].salary;
                contador++;
            }
        }

        promedio = total / contador;

        for(int i = 0 ; i < tamemp ; i++){
            if(employee[i].salary > promedio && employee[i].isEmpty == 0){
                cantProm++;
            }
        }

    system("clear");
    printf("***** Total, promedio y sueldos mayores a promedio *****\n\n");

    printf("El total de los salarios es %.2f \n", total);
    printf("El promedio de los salarios es %.2f \n", promedio);
    printf("Los empleados que superan el promedio son %d \n", cantProm);

    __fpurge(stdin);
    getchar();

}
