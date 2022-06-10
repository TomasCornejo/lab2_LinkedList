#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lista_vacunacion.h"

//Declaracion previa de funciones
listaVacunacion simular(int TiempoSimulacion, int IntervaloLlegada, float ProbabilidadAtender);
int atender(float umbralACheckear);


//Funcion Principal
int main(){
    printf("Comienza Ejecucion\n");
    // TODO Hacer INPUT de argumentos por consola
    //
    // Declaracion de Variables de Entrada
    int TIEMPO_SIMULACION = 50;
    int INTERVALO_LLEGADA = 7;
    float PROB_ATENDER = 0.25;
    
    listaVacunacion listaSimulada = simular(TIEMPO_SIMULACION, INTERVALO_LLEGADA, PROB_ATENDER);
    
    imprimirlistaVacunacion(listaSimulada);
    
    
    printf("Fin Ejecucion\n");

    return 0;
}

//Crear la lista con los pacientes
listaVacunacion simular(int TiempoSimulacion, int IntervaloLlegada, float ProbabilidadAtender){
    listaVacunacion listaSimulada = inicializaListaVacunacion();
    
    
    for (int tiempo = 0; tiempo < TiempoSimulacion; tiempo++) {
        // Agregando un Pacientes
        if( (tiempo % IntervaloLlegada) == 0){
            listaSimulada = agregaPaciente(listaSimulada, IntervaloLlegada);
        }
        //Vacunando
        if(atender(ProbabilidadAtender)){
            listaSimulada = vacunar(listaSimulada, tiempo);
        }
    }
    return listaSimulada;
}

int atender(float umbralACheckear){
    // Establecemos la seed para la generacion aleatoria
    time_t t1;
    srand(time (t1));
    
    //Genera Aleatorio entre 0 y 1
//    float randNumber = (float) rand() / RAND_MAX;
    
    printf("&&ATENDER&&=>> %d &&", (rand()));
    
    if (rand() <= umbralACheckear){
        return 1;
    }else{
        return 0;
    }
}
