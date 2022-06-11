
typedef struct paciente* listaVacunacion;

struct paciente{
    int numeroLlegada;
    int tiempoLlegada;
    int tiempoAtencion;
    listaVacunacion siguiente;
};

listaVacunacion inicializaListaVacunacion(void);

int esVacia(listaVacunacion);

listaVacunacion agregaPaciente(listaVacunacion , int);

int obtenerNumeroUltimoPaciente(listaVacunacion);

void imprimirInformacionLista(listaVacunacion);

void imprimirlistaVacunacion(listaVacunacion);

void imprimirTiemposEspera(listaVacunacion);

listaVacunacion vacunar(listaVacunacion , int);
