#include <stdio.h>
#include <stdlib.h>
#include "herramientas.h"

int sumar(int a, int b){
    int rta;
    rta = a + b;
    return rta;
}


int restar(int a, int b){
    int rta;
    rta = a - b;
    return rta;
}


int multiplicar(int a, int b){
    int rta;
    rta = a * b;
    return rta;
}


float dividir(int a, int b){
    float rta;
    rta = (float) a / b;
    return rta;
}


double factorizar(int a){
    double rta;

    if(a <= 1){
        rta = 1;
    }else{
        rta = a * factorizar(a - 1);
    }

    return rta;
}

int getIntPositivo(){
    int rta;

    while(scanf("%d", &rta) != 1 || rta < 0){
        printf("Error, solo numeros ENTEROS POSITIVOS, reintente por favor:\n\n");
        fflush(stdin);
    }
    return rta;
}
