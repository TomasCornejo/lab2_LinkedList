#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "listaVacunacion.h"

//Declaracion previa de funciones
listaVacunacion simular(int TiempoSimulacion, int IntervaloLlegada, float ProbabilidadAtender);
int atender(float umbralACheckear,  int tiempo);


//Funcion Principal
int main(int argc, char *argv[]){
    // Declaracion de Variables de Entrada
    int TIEMPO_SIMULACION = atoi(argv[1]);
    int INTERVALO_LLEGADA = atoi(argv[2]);
    float PROB_ATENDER = atof(argv[3]);

    printf("Comenzando simulacion para: Tiempo Simulacion %d || Intervalo Llegada %d || Probabilidad de Atender %.2f \n\n", TIEMPO_SIMULACION, INTERVALO_LLEGADA, PROB_ATENDER);
        
    printf("Las atenciones fueron en:\n");
    listaVacunacion listaSimulada = simular(TIEMPO_SIMULACION, INTERVALO_LLEGADA, PROB_ATENDER);

    printf("\n\n");

    //Impresión de lista final
    imprimirlistaVacunacion(listaSimulada);

    printf("\n");

    
    
    printf("Fin Ejecucion");
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
