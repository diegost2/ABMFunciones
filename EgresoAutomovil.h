#include "Propietario.h"
#include "Automovil.h"

#ifndef EGRESOAUTOMOVIL_H_INCLUDED
#define EGRESOAUTOMOVIL_H_INCLUDED

typedef struct{
    int marca;
    int idPropietario;
    float importe;
}eEgresoAutomovil;

#endif // EGRESOAUTOMOVIL_H_INCLUDED

void Egreso_Hardcodeo(eEgresoAutomovil egresos[]);
void TablaDeValores(void);
void EgresoAutomovil(eAutomovil lista[],ePropietario listado[] , eEgresoAutomovil egresos[], int limiteAutos, int limitePRO);
