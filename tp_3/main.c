#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers.h"

int main()
{
    eMovie* p;
    int opcion = 0;
    char out='s';


    while(out=='s')
    {

        loadData(&p);
        saveMovie(&p);
        out = getChar("Ingresar uno nuevo? s/n:");
    }

    char titleToFind[64];
    getString("Ingrese titulo a buscar en archivo:",titleToFind);

    eMovie* pFound = readMovie(titleToFind);

    if(pFound!=NULL)
    {
        printf("Se encontro: titulo:%s genero:%s link imagen:%s duracion:%d puntaje:%d\r\n",pFound->titulo,pFound->genero,pFound->linkImagen, pFound->duracion, pFound->puntaje);
        free(pFound);
    }
    else
        printf("el titulo ingresado no esta en el archivo");

    return 0;
}
