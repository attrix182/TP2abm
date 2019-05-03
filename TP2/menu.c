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
