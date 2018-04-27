#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "funciones.h"

void OrdenamientoUsuariosPorNombre(eUsuario lista[], int tam)
{

    char auxNombre[50];
    int aux;

    for(int i=1;i<tam;i++)
    {
        for(int j=i+1;j<tam;j++)
        {
           if(strcmp(lista[i].nombre,lista[j].nombre)>0)
           {
               strcpy(auxNombre,lista[i].nombre);
               strcpy(lista[i].nombre,lista[j].nombre);
               strcpy(lista[j].nombre,auxNombre);

               aux=lista[i].id;
               lista[i].id=lista[j].id;
               lista[j].id=aux;

               aux=lista[i].dni;
               lista[i].dni=lista[j].dni;
               lista[j].dni=aux;
           }

        }
    }

}

void ModificarUsuario(eUsuario lista[], int tam)
{

    int IdEncontrado;
    int numero;
    int Opciones;
    eUsuario AuxModificar;

    printf("\nIngresar ID a modificar: ");
    scanf("%d",&numero);
    IdEncontrado=BuscarID(lista,tam,numero);
    if(numero==-1)
    {
        printf("\n\nID no encontrado.");
        getch();
    }
    else{
        printf("\nEsta seguro de querer modificar al usuario : %s ?: ",lista[IdEncontrado].nombre);
        printf("\n\n1)YES.");
        printf("\n\n2)NO.\n");
        scanf("%d",&Opciones);
            switch(Opciones)
            {
            case 1:
                {
                    printf("Ingrese nuevo ID: ");
                    scanf("%d",&AuxModificar.id);

                    printf("Ingrese nuevo Nombre: ");
                    fflush(stdin);
                    gets(AuxModificar.nombre);

                    printf("Ingrese nuevo DNI: ");
                    scanf("%ld",&AuxModificar.dni);

                    lista[IdEncontrado]=AuxModificar;
                    system("cls");
                    printf("\nUsuario Modificado con Exito.");
                    getch();
                    break;
                }
            case 2:
                {
                    system("cls");
                    printf("\nModificacion cancelada.");
                    break;
                }
            default:
                {
                    printf("Opcion Incorrecta.");
                    getch();
                    break;
                }

            }


    }


}

void DarDeBaja(eUsuario lista[], int tam)
{
    int Numero=0;
    int IdEncontrado;
    int Opciones;

    printf("\nIngrese ID a dar de baja: ");
    scanf("%d",&Numero);

    IdEncontrado=BuscarID(lista,tam,Numero);
    if(IdEncontrado==-1)
    {
        printf("Usuario Inexistente.");
        getch();
    }
    else{
        printf("\nEsta seguro de querer hacer la baja del usuario : %s ?: ",lista[IdEncontrado].nombre);
        printf("\n\n1)YES.");
        printf("\n\n2)NO.\n");
        scanf("%d",&Opciones);
            switch(Opciones)
            {
            case 1:
                {
                    lista[IdEncontrado].estado=-1;
                    system("cls");
                    printf("\nUsuario eliminado con Exito.");
                    getch();
                    break;
                }
            case 2:
                {
                    system("cls");
                    printf("\nBaja cancelada.");
                    break;
                }
            default:
                {
                    printf("Opcion Incorrecta.");
                    getch();
                    break;
                }

            }
        }

}

void InicializarEstadoEnCero(eUsuario lista[], int tam, int numero)
{
    int i;
    for(i=0;i<tam;i++)
    {
        lista[i].estado=numero;
    }
}

void MostrarUsuario(eUsuario lista){
    printf("\n\n Id: %d  Nombre: %s  DNI: %d",lista.id,lista.nombre,lista.dni);
}

void MostrarVariosUsuarios(eUsuario lista[], int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
        if(lista[i].estado!=-1){
            MostrarUsuario(lista[i]);
        }
    }
}

int BuscarLugarLibre(eUsuario lista[], int tam, int numero)
{
    int i;
    int retorno=-1;
    for(i=0;i<tam;i++)
    {
        if(lista[i].estado==numero)
        {
            retorno=i;
            break;
        }
    }
    return retorno;
}

int BuscarID(eUsuario lista[], int tam, int numero)
{
    int i;
    int retorno=-1;
    for(i=0;i<tam;i++)
    {
        if(lista[i].id==numero)
        {
            retorno=i;
            break;
        }
    }
    return retorno;
}

void ingresarUsuario(eUsuario lista[], int tam)
{
    eUsuario UsuarioAux;
    int LugarLibre;
    LugarLibre=BuscarLugarLibre(lista,tam,-1);
    if(LugarLibre==-1)
    {
        printf("No se puede ingresar mas usuarios.");
        getch();
    }
    else
    {
        printf("Ingrese su Id: ");
        scanf("%d",&UsuarioAux.id);

        printf("Ingrese su nombre: ");
        fflush(stdin);
        gets(UsuarioAux.nombre);

        printf("Ingrese su DNI: ");
        scanf("%ld",&UsuarioAux.dni);

        UsuarioAux.estado=1;
        lista[LugarLibre]=UsuarioAux;
        printf("Usuario Ingresado con Exito.!");
        getch();
    }

}
