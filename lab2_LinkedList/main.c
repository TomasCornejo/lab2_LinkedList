#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "listaVacunacion.h"

//Declaracion previa de funciones
listaVacunacion simular(int TiempoSimulacion, int IntervaloLlegada, float ProbabilidadAtender);
int atender(float umbralACheckear,  int tiempo);


//Funcion Principal
int main(){
    printf("Comienza Ejecucion\n");
    // TODO Hacer INPUT de argumentos por consola
    //
    // Declaracion de Variables de Entrada
    int TIEMPO_SIMULACION = 50;
    int INTERVALO_LLEGADA = 7;
    float PROB_ATENDER = 0.1;
    
    printf("Atenciones en :\n");
    listaVacunacion listaSimulada = simular(TIEMPO_SIMULACION, INTERVALO_LLEGADA, PROB_ATENDER);

    printf("\n\n");

    //Impresión de lista final
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
        //Vacunar a los que esperan
        if(atender(ProbabilidadAtender, tiempo) == 1){
            listaSimulada = vacunar(listaSimulada, tiempo);
        }
    }
    return listaSimulada;
}

int atender(float umbralACheckear, int tiempo){

    // Establecemos semilla aleatoria
     srand(time(0) + tiempo); 

    // Genera Aleatorio entre 0 y 1
    float randNumber = (float) rand() / RAND_MAX;
    if (randNumber <= umbralACheckear){
        //TODO Quitar
        printf("||%d", tiempo );
        return 1;
    }else{
        return 0;
    }
}
