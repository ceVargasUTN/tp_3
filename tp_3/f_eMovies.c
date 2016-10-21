
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers.h"
/** \brief Pide al usuario los datos y los guarda en la struct
 * \param struct S_Person* p puntero a struct donde se almacenan los datos ingresados
 * \return void
 */
void loadData(eMovie* p)
{
    getValidString("Ingrese el titulo: ", "error, solo  numeros...",p->titulo);
    getValidString("Ingrese el genero: ","error, solo  numeros...",p->genero);
    getValidString("Ingrese el link de imagen: ","error, solo  numeros...",p->linkImagen);
    p->puntaje=getValidInt("Ingrese el  puntaje: ", "Error,  solo  numeros...", 1, 10);
    p->duracion=getInt("Ingrese la duracion: ","Error,  solo  numeros...");
}



/** \brief Guarda una struct al final de un archivo binario bin.dat
 * \param struct S_Person* p puntero a struct a ser escrita
 * \return 0: error, 1:OK
 */
int saveMovie(eMovie* p)
{
    FILE* fp;
    fp=fopen("bin.dat","ab+"); // append binario, lo crea si no existe
    if(fp==NULL)
    {
        printf("No se puede abrir el  archivo");
        return 0;
    }
    fwrite(p,sizeof( eMovie),1,fp); // escribo una struct al final

    fclose(fp);
    return 1;
}




/** \brief Busca en el archivo la struct con el apellido pasado como argumento y la devuelve
 * \param char* surname apellido
 * \return Puntero a struct que se leyo del archivo o NULL si no existe el apellido
 */
eMovie* readMovie(char* title)
{
    FILE* fp;
    fp=fopen("bin.dat","rb"); // lectura binaria
    if(fp==NULL)
    {
        printf("Error opening file");
        return NULL;
    }

    eMovie* pRet = malloc(sizeof(eMovie));
    int flagFound=0;
    while(fread(pRet,sizeof(eMovie),1,fp)!=0)
    {
        //printf("Leo %s %s %d\r\n",pRet->name,pRet->surname,pRet->age);
        if(strcmp(title,pRet->titulo)==0)
        {
            flagFound=1;
            break;
        }
    }
    fclose(fp);
    if(flagFound)
        return pRet;
    free(pRet);
    return NULL;
};
