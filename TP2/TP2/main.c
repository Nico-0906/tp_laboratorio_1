#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>

#include "arrayemployees.h"
#include "utn.h"

#define TAMEMP 1000

int main()
{
    char salir = 'n';   //variable para continuar o salir del programa
    int gatillo = 0;     //gatillo para verificar entrada a las opciones
    int proximoId = 0;   //autoid incremental para los empleados

    eEmployee employee[TAMEMP];
    initEmployees(employee, TAMEMP);

    do{
        switch(menuOpciones()){

            case 1:
                if(addEmployee(proximoId, employee, TAMEMP)){
                    proximoId++;
                    gatillo++;
                }
                break;

            case 2:
                if(gatillo > 0){
                modificarEmpleado(employee, TAMEMP);
                }else{
                    printf("\n PRIMERO DEBE INGRESAR UN EMPLEADO \n");
                    __fpurge(stdin);
                    getchar();
                }
                break;

            case 3:
                if(gatillo > 0){
                    if(removeEmployee(employee, TAMEMP)){
                        gatillo--;
                    }
                }else{
                    printf("\n PRIMERO DEBE INGRESAR UN EMPLEADO \n");
                    __fpurge(stdin);
                    getchar();
                }
                break;

            case 4:
                if(gatillo > 0){
                infoEmployees(employee, TAMEMP);
                }else{
                    printf("\n PRIMERO DEBE INGRESAR UN EMPLEADO \n");
                    __fpurge(stdin);
                    getchar();
                }
                break;

            case 5:
                printf("\nConfirma salida? s/n \n");
                getCharConfirmValidado(&salir);
                break;

            default:
                printf("\n***** Opcion incorrecta *****\n");
                __fpurge(stdin);
                getchar();
                break;
        }

    }while(salir == 'n');

    return 0;
}

