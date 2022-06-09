
typedef struct paciente* listaVacunacion;

struct paciente{
    int numeroLlegada;
    int tiempoLlegada;
    int tiempoAtencion;
    listaVacunacion siguiente;
};

listaVacunacion inicializaListaVacunacion(void);

int esVacia(listaVacunacion );

listaVacunacion agregaPaciente(listaVacunacion , int);

int obtenerPacientesVacunados(listaVacunacion );

int obtenerPacientesNoVacunados(listaVacunacion );

int obtenerNumeroUltimoPaciente(listaVacunacion );

float obtenerPromedioDeTiempoEspera(listaVacunacion );

void imprimirlistaVacunacion(listaVacunacion);

void imprimirTiemposEsperalistaVacunacion(listaVacunacion);

listaVacunacion vacunar(listaVacunacion , int );
