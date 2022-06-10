#include <stdlib.h>
#include <stdio.h>
#include "listaVacunacion.h"


listaVacunacion inicializaListaVacunacion(void){
    listaVacunacion head = NULL;
    return head;
};

int esVacia(listaVacunacion head){
    return head == NULL;
};

int hayDesatendidos(listaVacunacion head){
    listaVacunacion pivotPaciente = head;
    while(pivotPaciente != NULL)
    {
        if (pivotPaciente->tiempoAtencion == -1){
            return 1;
        }
        pivotPaciente = pivotPaciente->siguiente ;
    };
    return 0;    
}

listaVacunacion agregaPaciente(listaVacunacion head , int intervaloLlegada){

    listaVacunacion pivotPaciente = head;
    listaVacunacion punteroNuevoPaciente = malloc(sizeof(listaVacunacion));

    if(esVacia(head)){
        punteroNuevoPaciente->numeroLlegada = 1;
        punteroNuevoPaciente->tiempoLlegada = 0;
        punteroNuevoPaciente->tiempoAtencion= -1;
        punteroNuevoPaciente->siguiente = NULL;
    }else{
        int ultimoPaciente = obtenerNumeroUltimoPaciente(head);
        punteroNuevoPaciente->numeroLlegada = ultimoPaciente + 1;
        punteroNuevoPaciente->tiempoLlegada =  ultimoPaciente*intervaloLlegada;
        punteroNuevoPaciente->tiempoAtencion= -1;
        punteroNuevoPaciente->siguiente = NULL;
    }

    if(esVacia(head)){
        return head = punteroNuevoPaciente;
    } else {
        while(pivotPaciente->siguiente != NULL){
            pivotPaciente = pivotPaciente->siguiente;
        }
        pivotPaciente->siguiente = punteroNuevoPaciente;
    }
    return head;
};
//
//TODO
//
//int obtenerPacientesVacunados(listaVacunacion head){
//    int pacientesVacunados = 0;
//    if (!esVacia(head)){
//        while(head->siguiente != NULL){
//            pacientesVacunados++;
//            head = head->siguiente;
//        }
//    }
//    return pacientesVacunados;
//};
//
//int obtenerPacientesNoVacunados(listaVacunacion);

int obtenerNumeroUltimoPaciente(listaVacunacion head){
    listaVacunacion pivotPaciente = head;

    if(esVacia(pivotPaciente)){
        return 0;
    }else{
        while(pivotPaciente->siguiente != NULL){
            pivotPaciente = pivotPaciente->siguiente;
        }
        return pivotPaciente->numeroLlegada;
    }
};

//TODO
//float obtenerPromedioDeTiempoEspera(listaVacunacion);

void imprimirlistaVacunacion(listaVacunacion head){
    listaVacunacion pivotPaciente = head;

   if(esVacia(pivotPaciente)){
        printf("Esta lista esta vacia\n");
    }else{
        while(pivotPaciente != NULL){
            printf("Paciente N%d: ||%d||%d||\n", pivotPaciente->numeroLlegada, pivotPaciente->tiempoLlegada, pivotPaciente->tiempoAtencion);
            pivotPaciente = pivotPaciente->siguiente;
        };
    }
     printf("\n");
};

//void imprimirTiemposEsperalistaVacunacion(listaVacunacion head){
//
//   if(esVacia(head)){
//
//        println("Esta lista esta vacia\n");
//
//    }else{
//        int tiempoEspera;
//        println("El tiempo de espera de cada paciente es :");
//        do{
//            if(head->tiempoAtencion == -1){
//                tiempoEspera = -1;
//            }else{
//                tiempoEspera = head->tiempoAtencion - head->tiempoLlegada;
//            }
//            println("p%d: %d, ", head->numeroLlegada, tiempoEspera);
//        }while(head->siguiente != NULL);
//        println("\n");
//    }
//};


listaVacunacion vacunar(listaVacunacion head, int Tiempo){
    if (!hayDesatendidos(head)){
        return head;
    }

    listaVacunacion pivotPaciente = head;

    int tiempoAcumuladoEnAtencion = 0; // Variable para acumular la unidad de tiempo por atenciones consecutivas
//    Avanzamos hasta encontrar la atención vacia
    while (pivotPaciente->tiempoAtencion != -1){
        pivotPaciente = pivotPaciente->siguiente;
    }
//    Agregamos el tiempo de atención
    while (pivotPaciente != NULL) {
        pivotPaciente->tiempoAtencion = Tiempo  + tiempoAcumuladoEnAtencion;
        tiempoAcumuladoEnAtencion++;
        pivotPaciente = pivotPaciente->siguiente;
    };

    return head;
};
