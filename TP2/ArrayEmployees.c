#include "ArrayEmployees.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int initEmployees(Employee list[], int len)
{
    int i;

    for(i = 0; i<len; i++ )
    {
        list[i].isEmpty = 1;

    }

    return 0;

}

int addEmployee(Employee list[], int len, int id, char name[],char lastName[],float salary,int sector)
{
    int i;
    for(i = 0; i<len; i++)
    {
        if(list[i].isEmpty == 1)
        {
            list[i].id = id;
            strcpy(list[i].name, name);
            strcpy(list[i].lastName, lastName);
            list[i].salary = salary;
            list[i].sector = sector;
            list[i].isEmpty = 0;
            return 0;
        }
    }
    return -1;
}

int printEmployees(Employee list[], int len)
{
    int i;
    printf("%10s - %10s - %10s - %10s - %10s \n", "ID", "NAME", "LAST NAME","SALARY"," SECTOR");
    sortEmployees(list, len, 1);

    for(i = 0; i < len; i++)
    {
        if(list[i].isEmpty == 0)
        {
            printf("%10d  %10s  %10s  %10.2f  %10d \n", list[i].id, list[i].name, list[i].lastName, list[i].salary, list[i].sector);

        }


    }
    return 0;
}

int findEmployeeById(Employee list[], int len,int id)
{
    int i;
    for(i = 0; i<len; i++)
    {
        if(list[i].id == id)
        {
            return i;
        }
    }

    return -1;

}

int removeEmployee(Employee list[], int len, int id)
{

    int idAborrar = findEmployeeById(list, len, id);
    if(idAborrar == -1)
    {
        return -1;
    }
    list[idAborrar].isEmpty = 1;
    return 0;
}

int modifyEmployee(Employee list[], int len, int id, char name[],char lastName[],float salary,int sector, int option)
{
    int posToEdit = findEmployeeById(list, len, id);
    if(posToEdit == -1)
    {
        return -1;
    }
    switch(option)
    {
    case 1:
        printf(" new name \n");
        scanf("%s", name);
        fflush(stdin);
        strcpy(list[posToEdit].name, name);
        list[posToEdit].isEmpty = 0;
        break;
    case 2:
        printf(" new lastName \n");
        scanf("%s", lastName);
        fflush(stdin);
        strcpy(list[posToEdit].lastName, lastName);
        list[posToEdit].isEmpty = 0;
        break;
    case 3:
        printf(" new salary \n");
        scanf("%f", &salary);
        fflush(stdin);
        list[posToEdit].salary = salary;
        list[posToEdit].isEmpty = 0;
        break;
    case 4:
        printf(" new sector \n");
        scanf("%d", &sector);
        fflush(stdin);
        list[posToEdit].sector = sector;
        list[posToEdit].isEmpty = 0;
        break;
    }


    return 0;

}

int harcode(Employee list[], int len)
{
    int i;

    int id[4]= {1, 2, 20, 21};
    char name[4][50]= {"Fernado", "Juan", "Pablo", "Roberto"};
    char lastName[4][13]= {"Andes", "Caceres", "Borges", "Echeverria"};
    float salary[4]= {100, 200, 300, 400};
    int sector[4]= { 8, 2,2,9};
    int isEmpty[4]= { 0, 0, 0, 0};

    for(i=0; i<4; i++)
    {
        list[i].id=id[i];
        strcpy(list[i].name,name[i]);
        strcpy(list[i].lastName,lastName[i]);
        list[i].salary = salary[i];
        list[i].sector = sector[i];
        list[i].isEmpty = isEmpty[i];

    }
    return -1;
}

int sortEmployees(Employee list[], int len, int order)
{
    int i;
    int j;
    Employee aux;
    for(i=0; i<len; i++)
    {
        for(j=i+1; j<len; j++)
        {
            if( strcmp(list[i].lastName, list[j].lastName) > 0)
            {
                aux=list[i];
                list[i] = list[j];
                list[j] = aux;
            }
        }

    }

    return 0;
}

int searchEmpty(Employee list[], int len)
{
    int i;
    int id;

    for(i=0; i<len; i++)
    {
        if(list[i].isEmpty ==1)
        {
            id = i+1;
            break;
        }
    }
    return id;
}
