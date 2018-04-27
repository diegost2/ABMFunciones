#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "funciones.h"
#define CANT 5

int main()
{
    eUsuario Usuarios[CANT];
    InicializarEstadoEnCero(Usuarios,CANT,-1);

    char respuesta='s';
    int opcion;

    while(respuesta=='s')
    {
        printf("\n1)ALTA ");
        printf("\n2)BAJA");
        printf("\n3)LISTADO ");
        printf("\n4)MODIFICAR ");
        printf("\n5)ORDENAMIENTO");

        printf("\n\nOpcion: ");
        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            {
                ingresarUsuario(Usuarios,CANT);
                break;
            }
        case 2:
            {
                DarDeBaja(Usuarios,CANT);
                break;
            }
        case 3:
            {
                MostrarVariosUsuarios(Usuarios,CANT);
                getch();
                break;
            }
        case 4:
            {
                ModificarUsuario(Usuarios,CANT);
                break;
            }
        case 5:
            {
               //OrdenamientoUsuariosPorNombre(Usuarios,CANT);

               getch();
               break;
            }
        default:
            {
                printf("Opcion Incorrecta.");
            }

        }
        system("cls");
    }

    return 0;
}
