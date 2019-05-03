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
    printf("%s\t - %s\t - %s\t - %s - %s \n", "ID", "NAME", "LAST NAME","SALARY"," SECTOR");
    for(i = 0; i < len; i++)
    {

        if(list[i].isEmpty == 0)
        {
            printf("%d\t - %s\t - %s\t - %.2f - %d \n", list[i].id, list[i].name, list[i].lastName, list[i].salary, list[i].sector);

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

int modifyEmployee(Employee list[], int len, int id, char name[],char lastName[],float salary,int sector)
{
    int idAeditar = findEmployeeById(list, len, id);
    if(idAeditar == -1)
    {
        return -1;
    }
    strcpy(list[idAeditar].name, name);
    strcpy(list[idAeditar].lastName, lastName);
    list[idAeditar].salary = salary;
    list[idAeditar].sector = sector;
    list[idAeditar].isEmpty = 0;
    return 0;

}

int harcode(Employee list[], int len)
{
    int i;

    int id[4]= {42, 43, 44, 45};
    char name[4][50]= {"Fernado", "Juan", "Pablo", "Roberto"};
    char lastName[4][13]= {"Perez", "Lopez", "Suarez", "Garcia"};
    float salary[4]= {100, 200, 300, 400};
    int sector[4]= { 1, 2, 3, 4};
    int isEmpty[4]= { 0, 0, 0, 0};

    for(i=0; i<3; i++)
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


