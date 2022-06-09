#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lista_vacunacion.h"

//Declaracion previa de funciones
listaVacunacion simular(int TiempoSimulacion, int IntervaloLlegada);
int atender(float umbralACheckear);


//Funcion Principal
int main(){
    printf("Comienza Ejecucion\n");
    // TODO Hacer INPUT de argumentos por consola
    //
    // Declaracion de Variables de Entrada
    int TIEMPO_SIMULACION = 50;
    int INTERVALO_LLEGADA = 7;
    float PROB_ATENDER = 0.1;
    
    listaVacunacion listaSimulada = simular(TIEMPO_SIMULACION, INTERVALO_LLEGADA);
    
    imprimirlistaVacunacion(listaSimulada);
    
    printf("Fin Ejecucion\n");

    return 0;
}

//Crear la lista con los pacientes
listaVacunacion simular(int TiempoSimulacion, int IntervaloLlegada){
    listaVacunacion listaSimulada = inicializaListaVacunacion();
    
    
    for (int i = 0; i < TiempoSimulacion; i++) {
        if( (i % IntervaloLlegada) == 0){
            listaSimulada = agregaPaciente(listaSimulada, IntervaloLlegada);
        }
    }
    return listaSimulada;
}

int atender(float umbralACheckear){
    // Establecemos la seed para la generacion aleatoria
    time_t t1;
    srand((unsigned) time (&t1));
    
    //Genera Aleatorio entre 0 y 1
    float randNumber = (float) rand() / RAND_MAX;
    
    if (randNumber <= umbralACheckear){
        return 1;
    }else{
        return 0;
    }
}
