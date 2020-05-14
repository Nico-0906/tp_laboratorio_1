#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>

#include "arrayemployees.h"

#define TAMEMP 1000

int main()
{
    char seguir = 's';
    char confirma;
    //int gatillo = 0;
    int proximoId = 0;
    int auxid;
    eEmployee employee[TAMEMP];

    initEmployees(employee, TAMEMP);

    do{
        switch(menuOpciones()){
            case 1:
                printf("Alta \n");
                if(addEmployee(proximoId, employee, TAMEMP)){
                    proximoId++;
                }
                break;
            case 2:
                printf("Modificar\n");
                modificarEmpleado(employee, TAMEMP);
                break;
            case 3:
                system("clear");
                printf("Baja\n");
                printf("Ingrese id empleado: ");
                scanf("%d", &auxid);
                getchar();
                removeEmployee(employee, TAMEMP, auxid);
                break;
            case 4:
                printf("Informar\n");
                break;
            case 5:
                printf("\nConfirma salida? s/n \n");
                __fpurge(stdin);
                scanf("%c", &confirma);

                if(confirma == 's'){
                    seguir = 'n';
                }
                break;
        }

    }while(seguir == 's');

    return 0;
}

