#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include <string.h>
#include <ctype.h>
#include "ArrayEmployees.h"
#define TAM 1000

int main()
{
    int opcion;
    char seguir = 's';
    int id;
    char name[51];
    char lastName[51];
    int salary;
    int sector;
    Employee list[TAM];
    initEmployees(list, TAM);
    harcode(list, TAM);


    do
    {
        opcion = pedirOpcionMenu();

        switch(opcion)
        {
        case 1:
            printf(" id \n");
            scanf("%d", &id);
            fflush(stdin);
            printf(" name \n");
            scanf("%s", name);
            fflush(stdin);
            printf(" lastName \n");
            scanf("%s", lastName);
            fflush(stdin);
            printf(" salary \n");
            scanf("%d", &salary);
            fflush(stdin);
            printf(" sector \n");
            scanf("%d", &sector);

            addEmployee(list, TAM, id, name, lastName, salary, sector);

            break;
        case 2:
            printf(" ingrese id de empleado a modificar \n");
            scanf("%d", &id);
            fflush(stdin);
            printf(" new name \n");
            scanf("%s", name);
            fflush(stdin);
            printf(" new lastName \n");
            scanf("%s", lastName);
            fflush(stdin);
            printf(" new salary \n");
            scanf("%d", &salary);
            fflush(stdin);
            printf(" new sector \n");
            scanf("%d", &sector);
            modifyEmployee(list, TAM, id, name, lastName, salary, sector);
            break;
        case 3:
            printf(" ingrese id de empleado a remover \n");
            scanf("%d", &id);
            fflush(stdin);
            removeEmployee(list, TAM, id);
            break;
        case 4:
            printEmployees(list, TAM);
            break;
        case 5:
            seguir = 'n';
            break;

        default:
            printf("Opcion incorrecta\n");
            break;
        }

        system("pause");
        system("cls");

    }
    while(seguir == 's');


    return 0;
}


