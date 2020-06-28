#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "herramientas.h"

int main()
{
	int opcion = 0;
	int bandera = 0;
	int guardar = 0;
	char confirm;

    LinkedList* listaEmpleados = ll_newLinkedList();

    do{
    	opcion = menuOpciones();
    	fflush(stdin);

    	switch(opcion)
        {
            case 1:
            	if(bandera == 0){
            		if(!controller_loadFromText("data.csv", listaEmpleados)){
                		bandera = 1;
            			printf("\nDatos cargados con exito!\n");
            			getchar();
            		}
            	}else{
            		printf("\nYa se han cargado datos en el sistema.\n\n");
                    getchar();
            	}
                break;
            case 2:
            	if(bandera == 0){
            		if(!controller_loadFromBinary("data.bin", listaEmpleados)){
                		bandera = 1;
            			printf("\nDatos cargados con exito!\n");
            		    getchar();
            		}
            	}else{
            		printf("\nYa se han cargado datos en el sistema.\n\n");
                    getchar();
            	}
            	break;
            case 3:
            	if(bandera == 1){
            		if(!controller_addEmployee(listaEmpleados)){
            			guardar = 1;
            		}
            	}else{
            		printf("\nNo se han cargado datos en el sistema.\n\n");
                    getchar();
            	}
            	break;
            case 4:
            	if(bandera == 1){
            		if(!controller_editEmployee(listaEmpleados)){
            			guardar = 1;
            		}
            	}else{
            		printf("\nNo se han cargado datos en el sistema.\n\n");
                    getchar();
            	}
            	break;
            case 5:
            	if(bandera == 1){
            		if(!controller_removeEmployee(listaEmpleados)){
            			guardar = 1;
            		}
            	}else{
            	    printf("\nNo se han cargado datos en el sistema.\n\n");
                    getchar();
            	}
            	break;
            case 6:
            	if(bandera == 1){
            		controller_ListEmployee(listaEmpleados);
            		getchar();
               	}else{
               		printf("\nNo se han cargado datos en el sistema.\n\n");
                    getchar();
             	}
            	break;
            case 7:
            	if(bandera == 1){
            		if(!controller_sortEmployee(listaEmpleados)){
            			guardar = 1;
            		}
            	}else{
            		printf("\nNo se han cargado datos en el sistema.\n\n");
                    getchar();
            	}
            	break;
            case 8:
            	if(bandera == 1){
            		if(!controller_saveAsText("data.csv",listaEmpleados)){
            			guardar = 0;
            		}
            	}else{
            		printf("\nNo se han cargado datos en el sistema.\n\n");
                    getchar();
            	}
            	break;
            case 9:
            	if(bandera == 1){
            		if(!controller_saveAsBinary("data.bin", listaEmpleados)){
            			guardar = 0;
            		}
            	}else{
            		printf("\nNo se han cargado datos en el sistema.\n\n");
                    getchar();
            	}
            	break;
            case 10:
            	if(guardar == 1){
            		printf("\nSe han registrado cambios sin guardar, salir de todas formas? s/n :  ");
            		scanf("%c", &confirm);
            		if(confirm == 's' || confirm == 'S'){
            			break;
            		}else if(confirm == 'n' || confirm == 'N'){
            			opcion = 0;
            		}else{
            			printf("\nOpcion incorrecta.");
            			getchar();
            			opcion = 0;
            		}
            	}else{
            		printf("\nSeguro que desea salir? s/n : ");
            		scanf("%c", &confirm);
            		fflush(stdin);
            		if(confirm == 's' || confirm == 'S'){
            			break;
            		}else if(confirm == 'n' || confirm == 'N'){
            			opcion = 0;
            		}else{
            			printf("\nOpcion incorrecta.");
            			getchar();
            			opcion = 0;
            		}
            	}

        }
    }while(opcion != 10);
    return 0;

}

