#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#include <ctype.h>

#include "utn.h"

/**
* \brief lee del teclado hasta un \n y lo reemplaza por \0
* \param cadena donde se guarda el resultado obtenido
* \param tamaño de dicha cadena
* \return retorna 0 si completo con exito la tarea o -1 si no.
*/
int myGets(char cadena[], int tam){
    int retorno = -1;

    if(cadena != NULL && tam > 0 && fgets(cadena, tam, stdin) == cadena){
        __fpurge(stdin);
        if(cadena[strlen(cadena)-1] == '\n'){
            cadena[strlen(cadena)-1] = '\0';
        }
        retorno = 0;
    }
    return retorno;
}

/**
* \brief verifica si la cadena que se ingreso es numerica
* \param pResultado es el puntero al espacio de memoria donde se deja el resultado de la funcion
* \return retorna 0 si completo con exito la tarea o -1 si no.
*/
int getInt(int* pResultado){
    int retorno = -1;
    char buffer[64];

    if(pResultado != NULL){
        if(myGets(buffer, sizeof(buffer)) == 0 && esNumerica(buffer)){
            *pResultado = atoi(buffer);
            retorno = 0;
        }
    }
    return retorno;
}

/**
* \brief verifica si la cadena que se ingreso es numerica
* \param cadena de caracteres a ser analizada
* \return retorna 1 si la cadena es numerica y 0 si no lo es
*/
int esNumerica(char cadena[]){
    int i = 0;
    int retorno = 1;
    if(cadena != NULL && strlen(cadena) > 0){
        while(cadena[i] != '\0'){
            if(cadena[i] > '0' || cadena[i] > '9'){
                retorno = 0;
                break;
            }
            i++;
        }
    }
    return retorno;
}

/**
* \brief solicita un numero al usuario enviando un mensaje con cantidad de intentos
*        limitada y mensaje de error.
* \param puntero a donde se dejara el resultado de la funcion
* \param mensaje es el mensaje a ser mostrado
* \param mensajeError mensaje de error a mostrar
* \param minimo es el tope minimo de numero a ingresar
* \param maximo es el tope maximo de numero a ingresar
* \param intentos es la cantidad de intentos que se le da al usuario
* \return retorna 0 si completo con exito la tarea o -1 si no.
*/
int utn_getNumero(int* pResultado, char mensaje[], char mensajeError[], int minimo, int maximo, int reintentos){
    int bufferInt;
    int retorno = -1;
    while(reintentos > 0){
        reintentos--;
        printf("%s", mensaje);
        if(getInt(&bufferInt) == 0){
            if(bufferInt >= minimo && bufferInt <= maximo){
                *pResultado = bufferInt;
                retorno = 0;
                break;
            }
        }
        printf("%s", mensajeError);
    }
    return retorno;

}

/**
* \brief modifica la cadena de caracteres para que quede como un Nombre
* \param cadena que se desea modificar
* \param tamaño de dicha cadena
*/
void tipoNombre(char vec[], int tam){
    vec[0] = toupper(vec[0]);

    for(int i = 1 ; i < tam ; i++){
        vec[i] = tolower(vec[i]);
    }
}

/**
* \brief toma una cadena de caracteres como fgets pero elimina el enter final
* \param lugar donde se guardara la cadena obtenida
* \param tamaño de dicha cadena
*/
void getStr(char cadena[], int tam){

    fgets(cadena, tam, stdin);

    for(int i = 0; i < tam; i++){
        if(cadena[i] == '\n'){
            cadena[i] = '\0';
        }
    }
}

/**
* \brief solicita al usuario una confirmacion unicamente permite 's' o 'n'
* \param puntero a caracter donde se guardara la opcion ingresada*
*/
void getCharConfirmValidado(char* caracter){
    int bucle = 0;
    char opcion;

    while(bucle == 0){
        __fpurge(stdin);
        scanf("%c", &opcion);
        opcion = tolower(opcion);

        if(opcion == 's' || opcion == 'n'){
            *caracter = opcion;
            bucle = 1;
        }else{
            printf("\n Opcion incorrecta, ingrese S o N : ");
        }
    }
}

/**
* \brief solicita un sueldo validado
* \param sueldo puntero donde se desea guardar el sueldo
*/
int getSueldo(float* sueldo){
    int retorno = 0;
    float aux;
    int scan;

    printf("Ingrese sueldo: \n");
    scan = scanf("%f", &aux);

    if(scan == 0 || aux < 0){
        printf("\nSueldo incorrecto\n");
        getchar();
    }else{
        *sueldo = aux;
        retorno = 1;
    }

    return retorno;
}

/**
* \brief solicita un nombre, lo valida y lo pone en formato Nombre
* \param nombre cadena dondse se cuardara el nombre ingresado
* \param tam tamaño de la cadena
*/
int getNombre(char nombre[], int tam){
    int retorno = 1;
    int leng;
    char auxCadena[tam];

    __fpurge(stdin);
    getStr(auxCadena, tam);

    leng = strlen(auxCadena);

    for(int i= 0; i < leng ; i++){
        if(!((auxCadena[i] > 64 && auxCadena[i] < 91) || (auxCadena[i] > 96 && auxCadena[i] < 123) || (auxCadena[i] > 127 && auxCadena[i] < 167))){
            printf("Error en cadena entrante. SOLO LETRAS \n");
            getchar();
            retorno = 0;
            break;
        }
    }
    if(retorno == 1){
        tipoNombre(auxCadena, tam);
        strcpy(nombre, auxCadena);
    }
    return retorno;
}
