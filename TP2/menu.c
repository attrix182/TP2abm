#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
int pedirOpcionMenu()
{
    int opcion;
    printf("                          A B M                  \n\n");
    printf(" 1. ALTAS  \n 2. MODIFICAR  \n 3. BAJA\n 4. INFORMAR\n 5. Salir\n");
    scanf("%d", &opcion);

    return opcion;

}
int getOptionModify()
{
    int optionModify;
    printf("%10s - %10s - %10s - %10s \n", "1.NAME", "2.LAST NAME","3.SALARY","4.SECTOR");
    scanf("%d", &optionModify);

    return optionModify;
}
