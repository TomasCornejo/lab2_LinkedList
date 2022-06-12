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
        return punteroNuevoPaciente;
    } else {
        while(pivotPaciente->siguiente != NULL){
            pivotPaciente = pivotPaciente->siguiente;
        }
        pivotPaciente->siguiente = punteroNuevoPaciente;
    }
    return head;
};

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

listaVacunacion vacunar(listaVacunacion head, int Tiempo){
    if (!hayDesatendidos(head)){
        return head;
    }
    listaVacunacion pivotPaciente = head;
// Variable para acumular la unidad de tiempo por atenciones consecutivas
    int tiempoAcumuladoEnAtencion = 0; 
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

void imprimirInformacionLista(listaVacunacion head){
    listaVacunacion pivotPaciente = head;
    float TotalTiempoEsperaAtendidos = 0;
    float CantidadDePacientesAtendidos = 0;
    int Vacunados = 0;
    int NoVacunados = 0;

    if(esVacia(pivotPaciente)){
        printf("Esta lista esta vacia\n");
    }else{
        while(pivotPaciente != NULL){
            if(pivotPaciente->tiempoAtencion != -1){
                TotalTiempoEsperaAtendidos = TotalTiempoEsperaAtendidos + (pivotPaciente->tiempoAtencion - pivotPaciente->tiempoLlegada);
                CantidadDePacientesAtendidos = (float) pivotPaciente->numeroLlegada;
                Vacunados++;
            }else{
                NoVacunados++;
            }
            pivotPaciente = pivotPaciente->siguiente;
        }
        printf("Tiempo promedio de espera (Vacunados): %.1f unidades de tiempo\n", (TotalTiempoEsperaAtendidos/CantidadDePacientesAtendidos)); 
        printf("Pacientes vacunados: %d\n", Vacunados);     
        printf("Pacientes sin vacunar: %d\n", NoVacunados);     
    }
};

void imprimirlistaVacunacion(listaVacunacion head){
    listaVacunacion pivotPaciente = head;

   if(esVacia(pivotPaciente)){
        printf("Esta lista esta vacia\n");
    }else{
        while(pivotPaciente != NULL){
            printf("Paciente n%d: ||%d||%d||\n", pivotPaciente->numeroLlegada, pivotPaciente->tiempoLlegada, pivotPaciente->tiempoAtencion);
            pivotPaciente = pivotPaciente->siguiente;
        };
    }
     printf("\n");
};

void imprimirTiemposEspera(listaVacunacion head){
    listaVacunacion pivotPaciente = head;

    if(esVacia(pivotPaciente)){
        printf("Esta lista esta vacia\n");
    }else{
        int tiempoEspera = 0;
        printf("El tiempo de espera de cada paciente es :");
        while(pivotPaciente != NULL){
            if(pivotPaciente->tiempoAtencion == -1){
                printf("p%d:No Atendido, ", pivotPaciente->numeroLlegada);
            }else{
                printf("p%d:%d, ", pivotPaciente->numeroLlegada, ((pivotPaciente->tiempoAtencion) - (pivotPaciente->tiempoLlegada)));
            }
            pivotPaciente = pivotPaciente->siguiente;
        };
        printf("\n\n");
    }
};


