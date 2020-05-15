#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include <ctype.h>

#include "arrayemployees.h"
#include "utn.h"

/**
* \brief inicializa la cadena de empleados colocando los isEmpty en 1
* \param employee cadena que se desea inicializar
* \param tamemp tamaño de dicha cadena
* \return retorna -1 si no se pudo inicializar con exito o 0 si se pudo
*/
int initEmployees(eEmployee employee[], int tamemp){
    int retorno = -1;
    for(int i = 0 ; i < tamemp ; i++){
        employee[i].isEmpty = 1;
        retorno = 0;
    }
    return retorno;
}

/**
* \brief agrega un nuevo empleado tomandole los datos
* \param idx id que se le va a asignar al empleado nuevo
* \param vector donde se almacenara el empleado
* \param tamemp tamaño del vector de empleados
* \return retorna 1 si se pudo dar el alta con exito o 0 si no se pudo
*/
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
        getStr(auxEmpleado.name, 51);
        tipoNombre(auxEmpleado.name, 51);

        printf("Ingrese apellido: \n");
        getStr(auxEmpleado.lastName, 51);
        tipoNombre(auxEmpleado.lastName, 51);

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

/**
* \brief elimina un empleado del sistema colocando isEmpty en 1
* \param employee vector del empleado que se desea dar de baja
* \param tamemp tamaño de dicho vector
* \return retorna 1 si se dio de baja con exito o 0 si no se pudo
*/
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

/**
* \brief ordena los empleados segun el enunciado del tp
* \param employee cadena de empleados que se desea ordenar
* \param tamemp tamaño de dicha cadena
* \param order orden con que se desea ordenar la cadena
* \return retorna -1 si no se pudo ordenar o 0 si se pudo satisfactoriamente
*/
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
                }else if(employee[i].sector == employee[j].sector && strcmp(employee[i].lastName, employee[j].lastName)){
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
                }else if(employee[i].sector == employee[j].sector && strcmp(employee[i].lastName, employee[j].lastName)){
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

/**
* \brief verifica si hay algun empleado cargado
* \param employee vector que se desea verificar
* \param tamemp tamaño de dicha cadena
* \return retorna 1 si hay empleados cargados o 0 si no los hay
*/
int buscarEmployee(eEmployee employee[], int tamemp){
    int retorno = 0;
    for(int i = 0; i < tamemp ; i++){
        if(employee[i].isEmpty == 0){
            retorno = 1;
        }
    }
    return retorno;
}

/**
* \brief imprime por pantalla la lista de empleados
* \param employee cadena que se desea imprimir
* \param tamemp tamaño de dicha cadena
* \return retorna -1 si no se pudo o 1 si se pudo con exito
*/
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
                printf("%d   %10s      %10s    $%.2f       %d\n", employee[i].id, employee[i].name, employee[i].lastName, employee[i].salary, employee[i].sector);
                retorno = 1;
            }
        }
    }else{
        printf("\nNo hay empleados.\n");
    }
    return retorno;
}

/**
* \brief busca un lugar libre en el vector y devuelve la posicion
* \param employee cadena donde se busca un lugar libre
* \param tamsec tamaño de la cadena employee
* \return retorna la ubicacion libre del vector encontrada
*/
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

/**
* \brief imprime el menu de opciones por pantalla
* \return retorna la opcion ingresada por el usuario
*/
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

/**
* \brief imprime el menu de informes
* \return retorna la opcion ingresada por el usuario
*/
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

/**
* \brief busca la posicion de un empleado mediante el id
* \param id que se desea buscar
* \param employee cadena de empleados que se desea analizar
* \param tamemp tamaño de dicha cadena
* \return retorna -1 si no se encontro nada o retorna la ubicacion del empleado
*/
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

/**
* \brief imprime un empleado individualmente
* \param ubicacion del empleado a imprimir
*/
void printEmployee(eEmployee employee){
    printf("%d   %10s   %10s    $%.2f       %d\n", employee.id , employee.name, employee.lastName, employee.salary, employee.sector);
}

/**
* \brief modifica los campos del empleado pasado por referencia
* \param employee empleado que se desea modificar
* \param tamemp tamaño de cadena de empleados
*/
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

/**
* \brief funciones del menu de funciones
* \param employee vector de empleados
* \param tamemp tamaño de dicho vector
*/
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

/**
* \brief calcula el total de salarios, promedios y sueldos superiores a promedio
* \param employee vector de empleados
* \param tamemp tamaño de dicho vector
*/
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
