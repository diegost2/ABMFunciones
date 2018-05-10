#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "Automovil.h"
#include "Propietario.h"
#define OCUPADO 1
#define LIBRE -1

#define ALPHA_ROMEO 11
#define FERRARI 22
#define AUDI 33
#define OTRO 44

void Aux_ALTAAUTO(eAutomovil lista[],int limiteAutomovil)
{
    eAutomovil automovilAux;
    int opcion;
    int indice;
    int id;
    id=eAutomovil_siguienteId(lista,limiteAutomovil);
        indice = eAutomovil_buscarLugarLibre(lista,limiteAutomovil);
        if(indice == -1)
        {
            printf("No hay mas espacio para ingresar.");
            getch();
        }
        else{

            printf("\nIngrese pantente: ");
            fflush(stdin);
            gets(automovilAux.patente);

            printf("\n");
            printf("\n11)ALPHA_ROMEO.");
            printf("\n22)FERRARI.");
            printf("\n33)AUDI.");
            printf("\n44)OTROS.");
            printf("\nIngrese Marca: ");
            scanf("%d",&opcion);
            switch(opcion)
            {
            case 11:
                {
                    strcpy(lista[indice].marca,"ALPHA_ROMEO.");
                    break;
                }
            case 22:
                {
                    strcpy(lista[indice].marca,"FERRARI");
                    break;
                }
            case 33:
                {
                    strcpy(lista[indice].marca,"AUDI");
                    break;
                }
            case 44:
                {
                    strcpy(lista[indice].marca,"OTROS.");
                    break;
                }


            strcpy(lista[indice].patente,automovilAux.patente);
            lista[indice].idPropietario=id;
            //lista[indice].marca=automovilAux.marca;
            lista[indice].estado=1;
}


void eAutomovil_mostrarListado(eAutomovil lista[],ePropietario listado[],int limite, int limiteAutomovil)
{

    int i;
    int j;
    printf(" Propietario     Marca      ID      Patente \n");
    for(i=0; i<limite; i++)
        {
            if(listado[i].estado!=-1)
            {
                printf("  %s ", listado[i].NombreApellido);

                for(j=0;j<limiteAutomovil;j++)
                {
                    if(listado[i].idPropietario==lista[j].idPropietario)
                    {
                        //if(listado[j].estado!=-1){
                            eAutomovil_mostrarUno(lista[j]);
                            break;


                    }

                }

            }
        }
}


void eAutomovil_mostrarUno(eAutomovil lista)
{
     printf("        %s      %d      %s ",lista.marca,lista.idPropietario,lista.patente);

}

int eAutomovil_siguienteId(eAutomovil lista[],int limite)
{
    int retorno = 0;
    int i;
    if(limite > 0 && lista != NULL)
    {
        for(i=0; i<limite; i++)
        {
            if(lista[i].estado == OCUPADO)
            {
                    if(lista[i].idPropietario>retorno)
                    {
                         retorno=lista[i].idPropietario;

                    }

            }
        }
    }

    return retorno+1;
}

int eAutomovil_buscarLugarLibre(eAutomovil lista[],int limite)
{
    int retorno = OCUPADO;
    int i;

        for(i=0;i<limite;i++)
        {
            if(lista[i].estado == OCUPADO)
            {
                retorno = i;
                break;
            }
        }

    return retorno;
}

void eAutomovil_init(eAutomovil lista[],int limite,int valor)
{
    int i;
        for(i=0; i<limite; i++)
        {
            lista[i].estado= valor;
            //listado[i].idProducto=0;
        }

}
