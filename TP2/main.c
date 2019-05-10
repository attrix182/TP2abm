#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include <string.h>
#include <ctype.h>
#include "ArrayEmployees.h"
#include "funcionesGet.h"
#define TAM 2

int main()
{

    char name[51];
    char lastName[51];
    int salary;
    int sector;
    int id;
    int idCheck;
    int sumSal;
    int average;
    int salarySup;
    int numberOfEmployees;
    int opcion;
    int optionModify;
    int optionShow;
    int addFull;
    int flagCreate = 0;
    char seguir = 's';

    sEmployee list[TAM];
    initEmployees(list, TAM);
    //harcode(list, TAM);

    do
    {
        opcion = pedirOpcionMenu();

        switch(opcion)
        {
        case 1:
            id = generateID(list, TAM);
            getString("Ingrese nombre del empleado \n", name);
            getString("Ingrese apellido del empleado \n", lastName);
            salary = getInt("Ingrese salario\n");
            sector = getInt("Ingrese sector\n");
            addFull = addEmployee(list, TAM, id, name, lastName, salary, sector);
            if(addFull == -1)
            {
                printf("No hay lugar para guardar a ese Empleado\n");
            }
            flagCreate = 1;
            break;
        case 2:
            if(flagCreate == 1)
            {
                id = getInt("Ingrese ID de empleado a modificar \n");
                idCheck = findEmployeeById(list, TAM, id);
                while(idCheck == -1)
                {
                    id = getInt("Reingrese una ID valida\n");
                    idCheck = findEmployeeById(list, TAM, id);

                }
                optionModify = getOptionModify();
                modifyEmployee(list, TAM, id, name, lastName, salary, sector, optionModify);
            }
            else
            {
                printf("Aun no hay empleados cargados...\n");
            }
            break;
        case 3:
            if(flagCreate == 1)
            {
                id = getInt("Ingrese ID de empleado a remover \n");
                idCheck = findEmployeeById(list, TAM, id);
                while(idCheck == -1)
                {
                    id = getInt("Reingrese una ID valida\n");
                    idCheck = findEmployeeById(list, TAM, id);
                }

                removeEmployee(list, TAM, id);

            }
            else
            {
                printf("Aun no hay empleados cargados...\n");
            }
            break;

        case 4:
            if(flagCreate == 1)
            {
                optionShow = getOptionShow();
                switch(optionShow)
                {
                case 1:
                    printEmployees(list, TAM);
                    break;
                case 2:
                    sumSal = showSalary(list, TAM);
                    numberOfEmployees = searchFull(list, TAM);
                    average = sumSal/numberOfEmployees;
                    salarySup = searchSalarySup(list, TAM);
                    printf("\n %s %d\n", "El total de los salarios es: ", sumSal);
                    printf("\n %s %d\n", "El promedio de los salarios es: ", average);
                    printf("\n %s %d\n\n", "La cantidad de empleados que superan el salario promedio es: ", salarySup);
                    break;
                }
            }
            else
            {
                printf("Aun no hay empleados cargados...\n");

            }
            break;
        case 5:
            seguir = 'n';
            break;

        default:
            printf("Opcion invalida\n");
            break;
        }

        system("pause");
        system("cls");

    }
    while(seguir == 's');

    return 0;
}


