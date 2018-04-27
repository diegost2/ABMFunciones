#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct{
    int id;
    int estado;
    char nombre[50];
    long int dni;
}eUsuario;

#endif // FUNCIONES_H_INCLUDED


void MostrarUsuario(eUsuario lista);
void MostrarVariosUsuarios(eUsuario lista[], int tam);
void InicializarEstadoEnCero(eUsuario lista[], int tam, int numero);
int BuscarLugarLibre(eUsuario lista[], int tam, int numero);
void ingresarUsuario(eUsuario lista[], int tam);
void DarDeBaja(eUsuario lista[], int tam);
int BuscarID(eUsuario lista[], int tam, int numero);
void ModificarUsuario(eUsuario lista[], int tam);
void OrdenamientoUsuariosPorNombre(eUsuario lista[], int tam);
