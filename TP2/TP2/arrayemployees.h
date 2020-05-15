#ifndef EMPLOYEE_H_INCLUDED
#define EMPLOYEE_H_INCLUDED

typedef struct{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;

}eEmployee;

#endif // EMPLOYEE_H_INCLUDED

/**
* \brief inicializa la cadena de empleados colocando los isEmpty en 1
* \param employee cadena que se desea inicializar
* \param tamemp tamaño de dicha cadena
* \return retorna -1 si no se pudo inicializar con exito o 0 si se pudo
*/
int initEmployees(eEmployee employee[], int tamemp);

/**
* \brief agrega un nuevo empleado tomandole los datos
* \param idx id que se le va a asignar al empleado nuevo
* \param vector donde se almacenara el empleado
* \param tamemp tamaño del vector de empleados
* \return retorna 1 si se pudo dar el alta con exito o 0 si no se pudo
*/
int addEmployee(int idx, eEmployee employee[], int tamemp);

/**
* \brief busca la posicion de un empleado mediante el id
* \param id que se desea buscar
* \param employee cadena de empleados que se desea analizar
* \param tamemp tamaño de dicha cadena
* \return retorna -1 si no se encontro nada o retorna la ubicacion del empleado
*/
int findEmployeeById(int id, eEmployee employee[], int tamemp);

/**
* \brief imprime un empleado individualmente
* \param ubicacion del empleado a imprimir
*/
void printEmployee(eEmployee employee);

/**
* \brief elimina un empleado del sistema colocando isEmpty en 1
* \param employee vector del empleado que se desea dar de baja
* \param tamemp tamaño de dicho vector
* \return retorna 1 si se dio de baja con exito o 0 si no se pudo
*/
int removeEmployee(eEmployee employee[], int tamemp);

/**
* \brief imprime por pantalla la lista de empleados
* \param employee cadena que se desea imprimir
* \param tamemp tamaño de dicha cadena
* \return retorna -1 si no se pudo o 1 si se pudo con exito
*/
int printEmployees(eEmployee employee[], int tamemp);

/**
* \brief ordena los empleados segun el enunciado del tp
* \param employee cadena de empleados que se desea ordenar
* \param tamemp tamaño de dicha cadena
* \param order orden con que se desea ordenar apellido y sector
*        (1 es de menor a mayor y de la A a la Z)
* \return retorna -1 si no se pudo ordenar o 0 si se pudo satisfactoriamente
*/
int sortEmployee(eEmployee employee[], int tamemp, int order);

/**
* \brief busca un lugar libre en el vector y devuelve la posicion
* \param employee cadena donde se busca un lugar libre
* \param tamsec tamaño de la cadena employee
* \return retorna la ubicacion libre del vector encontrada
*/
int buscarLibre(eEmployee employee[], int tamemp);

/**
* \brief imprime el menu de opciones por pantalla
* \return retorna la opcion ingresada por el usuario
*/
int menuOpciones();

/**
* \brief imprime el menu de informes
* \return retorna la opcion ingresada por el usuario
*/
int menuInformar();

/**
* \brief modifica los campos del empleado pasado por referencia
* \param employee empleado que se desea modificar
* \param tamemp tamaño de cadena de empleados
*/
void modificarEmpleado(eEmployee employee[], int tamemp);

/**
* \brief funciones del menu de funciones
* \param employee vector de empleados
* \param tamemp tamaño de dicho vector
*/
void infoEmployees(eEmployee employee[], int tamemp);

/**
* \brief calcula el total de salarios, promedios y sueldos superiores a promedio
* \param employee vector de empleados
* \param tamemp tamaño de dicho vector
*/
void totalYPromSalary(eEmployee employee[], int tamemp);

/**
* \brief verifica si hay algun empleado cargado
* \param employee vector que se desea verificar
* \param tamemp tamaño de dicha cadena
* \return retorna 1 si hay empleados cargados o 0 si no los hay
*/
int buscarEmployee(eEmployee employee[], int tamemp);
