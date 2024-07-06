#define MAX_EQUIPOS 100
#define MAX_NOMBRE 50

int mostrarMenu();
void agregarEquipo(char nombres[MAX_EQUIPOS][MAX_NOMBRE], int *cantidades, int *cantidadesBueno, int *cantidadesMalo, int *cantidadesNecesarias, float *precios, int *numEquipos);
void mostrarInventario(char nombres[MAX_EQUIPOS][MAX_NOMBRE], int *cantidades, int *cantidadesBueno, int *cantidadesMalo, int *cantidadesNecesarias, float *precios, int numEquipos);
void calcularInversionTotal(char nombres[MAX_EQUIPOS][MAX_NOMBRE], int *cantidadesMalo, int *cantidadesNecesarias, float *precios, int numEquipos);
void cargarInventario(char nombres[MAX_EQUIPOS][MAX_NOMBRE], int *cantidades, int *cantidadesBueno, int *cantidadesMalo, int *cantidadesNecesarias, float *precios, int *numEquipos);
void guardarInventario(char nombres[MAX_EQUIPOS][MAX_NOMBRE], int *cantidades, int *cantidadesBueno, int *cantidadesMalo, int *cantidadesNecesarias, float *precios, int numEquipos);

