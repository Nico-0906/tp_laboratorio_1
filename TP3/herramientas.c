#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "herramientas.h"
/*
 * herramientas.c
 *
 *  Created on: 19 jun. 2020
 *      Author: Nico
 */



int menuOpciones(void){
	int opcion;
	system("cls");

	printf("******  MENU DE OPCIONES ******\n\n");
	printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto)\n");
	printf("2. Cargar los datos de los empleados desde el archivo data.bin (modo binario)\n");
	printf("3. Alta de empleado\n");
	printf("4. Modificar datos de empleado\n");
	printf("5. Baja de empleado\n");
	printf("6. Listar empleados\n");
	printf("7. Ordenar empleados\n");
	printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto)\n");
	printf("9. Guardar los datos de los empleados en el archivo data.csv (modo binario)\n");
	printf("10. Salir\n\n");
	printf("Ingrese opcion: ");

	scanf("%d", &opcion);
	return opcion;
}


int h_getName(char* nombre, int tam)
{
	int error = 1;
    char aux[tam];
    if(!h_fgets(aux, tam)){
        strcpy(nombre, aux);
    	error = 0;
    }

    return error;
}

int h_fgets(char* cadena, int tam)
{
	int error = 1;
    char aux[tam];
    int i = 0;
    fgets(aux,tam,stdin);
    if(cadena != NULL && tam > 0){
    	while(aux[i] != '\n'){
    			cadena[i] = aux[i];
    			i++;
    			error = 0;
    	}
    }
    return error;
}
