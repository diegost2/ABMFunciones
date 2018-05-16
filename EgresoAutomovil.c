#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "Automovil.h"
#include "EgresoAutomovil.h"
#include "Propietario.h"

#define ALPHA_ROMEO 11
#define FERRARI 22
#define AUDI 33
#define OTROS 44

void PrecioPorEstadia(eEgresoAutomovil egresos[],int limite,int valor)
{
    int resultado;
    int i;
    for(i=0;i<limite;i++)
    {
        if(egresos[i].marca==11)
        {
            resultado=valor*150;
            egresos[i].importe=resultado;

        }
        else if(egresos[i].marca==22)
        {
            resultado=valor*175;
            egresos[i].importe=resultado;
        }
        else if(egresos[i].marca==33)
        {
            resultado=valor*200;
            egresos[i].importe=resultado;

        }
        else if(egresos[i].marca==44)
        {
            resultado=valor*250;
            egresos[i].importe=resultado;
        }
    }

}

int devolverHorasEstadia()
{
    int horas;

    srand(time(NULL));

    horas = (rand()%24)+1;

    return horas;

}

void EgresoAutomovil(eAutomovil lista[],ePropietario listado[] , eEgresoAutomovil egresos[], int limiteAutos, int limitePRO)
{
    system("cls");
    int i,j,k;
    int valor;
    valor=devolverHorasEstadia();
    PrecioPorEstadia(egresos,limiteAutos,valor);
    TablaDeValores();
    printf("\n");
    printf("\n\t\t\t\tTicket De Estadia\n");
    printf("\nPropietario  Patente  Marca  Importe\n");
    for(i=0;i<limitePRO;i++)
    {
        if(listado[i].estado!=-1)
        {
            printf("\n %s ",listado[i].NombreApellido);

                for(j=0;j<limiteAutos;j++)
                {
                    if(listado[i].idPropietario==lista[j].idPropietario)
                    {
                        if(lista[j].estado!=-1)
                        {
                            printf("\t     %s    %d",lista[j].patente, lista[j].marca);

                            for(k=0;k<limiteAutos;k++)
                                    {
                                    //if(lista[j].id==egresos[k].idPropietario)
                                    //{
                                        if(lista[j].marca==egresos[k].marca)
                                        {
                                            printf("    $%.2f \n",egresos[k].importe);
                                            break;
                                      }
                                    //}
                                }
                        }
                    }
                }
        }
    }
}

void Egreso_Hardcodeo(eEgresoAutomovil egresos[])
{
    int i;
    int id[]={1,2,3,4,5,6,7,8,9,10};
    int marca[]= {ALPHA_ROMEO,ALPHA_ROMEO,FERRARI,AUDI,FERRARI,FERRARI,AUDI,OTROS,ALPHA_ROMEO,ALPHA_ROMEO};
    float importe[]= {100,200,100,300,100,100,200,200,100,100};

    for(i=0;i<10;i++)
    {
        egresos[i].idPropietario=id[i];
        egresos[i].marca=marca[i];
        egresos[i].importe=importe[i];
    }
}

void TablaDeValores(void){
    printf("\nMarca\t\t\tPrecio Por Hora\n");
    printf("-------------------------------------------\n");
    printf("ALPHA_ROMEO\t\t     $150\n");
    printf("FERRARI\t\t\t     $175\n");
    printf("AUDI\t\t\t     $200\n");
    printf("OTROS\t\t\t     $250\n");
}
