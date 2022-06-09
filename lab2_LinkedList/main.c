#include <stdio.h>
#include <stdlib.h>
#include "lista_vacunacion.h"

int main(){
    printf("Comienza Ejecucion\n");

    listaVacunacion listaSimulada = inicializaListaVacunacion();

    listaSimulada = agregaPaciente(listaSimulada , 4);
    listaSimulada = agregaPaciente(listaSimulada , 4);
    listaSimulada = agregaPaciente(listaSimulada , 4);
    listaSimulada = agregaPaciente(listaSimulada , 4);
    listaSimulada = agregaPaciente(listaSimulada , 4);
    
    imprimirlistaVacunacion(listaSimulada);
    
    printf("Fin Ejecucion\n");

    return 0;
}
