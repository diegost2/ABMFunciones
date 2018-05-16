#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "Propietario.h"
#include "Automovil.h"
#include "EgresoAutomovil.h"
#define CANTIDADAUTO 20
#define CANTIDADPROPI 20



int main()
{
    ePropietario propietario[CANTIDADPROPI];
    ePropietario_init(propietario,CANTIDADPROPI,-1);

    eAutomovil automovil[CANTIDADAUTO];
    eAutomovil_init(automovil,CANTIDADAUTO,-1);

    eEgresoAutomovil egresoAutomovil[CANTIDADAUTO];

    Hardcodeo(propietario);
    eAutomovil_HardCodeo(automovil);
    Egreso_Hardcodeo(egresoAutomovil);

    char respuesta='s';
    int opcion;

    while(respuesta=='s')
    {
        printf("\n1)ALTA ");
        printf("\n2)MODIFICAR");
        printf("\n3)BAJA ");
        printf("\n4)INGRESO AUTOMOVIL.");
        printf("\n5)EGRESO AUTOMOVIL. ");
        //printf("\n6)CANCELAR PUBLICACION ");

        printf("\n\nOpcion: ");
        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            {
                Aux_ALTA(propietario,CANTIDADPROPI);
                break;
            }
        case 2:
            {
                ModificarAux(propietario,CANTIDADPROPI);
                break;
            }
        case 3:
            {
                BajaAux(propietario,CANTIDADPROPI);
                getch();
                break;
            }
        case 4:
            {
                Aux_ALTAAUTO(automovil,CANTIDADAUTO);
                break;
            }
        case 5:
            {
                EgresoAutomovil(automovil,propietario,egresoAutomovil,CANTIDADAUTO,CANTIDADPROPI);
               getch();
               break;
            }
        case 6:
            {
                //BajaAuxPRO(Productos,Usuarios,CANTIDADPRO,CANTIDADUSU);
                getch();
                break;
            }
        //case 7:
        default:
            {
                printf("Opcion Incorrecta.");
            }

        }
        system("cls");
    }
    return 0;
}
