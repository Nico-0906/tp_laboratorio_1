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

int initEmployees(eEmployee employee[], int tamemp);

int addEmployee(int idx, eEmployee employee[], int tamemp);

int findEmployeeById(int id, eEmployee employee[], int tamemp);

int removeEmployee(eEmployee employee[], int tamemp);

int printEmployees(eEmployee employee[], int tamemp);

int sortEmployee(eEmployee employee[], int tamemp, int order);

int buscarLibre(eEmployee employee[], int tamemp);

int menuOpciones();

int menuInformar();

void modificarEmpleado(eEmployee employee[], int tamemp);

void infoEmployees(eEmployee employee[], int tamemp);

void totalYPromSalary(eEmployee employee[], int tamemp);
