#include <stdio.h>
#include <string.h>
#include "Lecturas.h"
#include "Operaciones.h"


void cargarInventario(char nombres[MAX_EQUIPOS][MAX_NOMBRE], int *cantidades, int *cantidadesBueno, int *cantidadesMalo, int *cantidadesNecesarias, float *precios, int *numEquipos) {
    FILE *archivo = fopen("inventario.txt", "w+");
    if (archivo != NULL) {
        fscanf(archivo, "%d", numEquipos);
        for (int i = 0; i < *numEquipos; i++) {
            fscanf(archivo, "%s %d %d %d %d %f", nombres[i], &cantidadesBueno[i], &cantidadesMalo[i], &cantidadesNecesarias[i], &cantidades[i], &precios[i]);
            cantidades[i] = cantidadesBueno[i] + cantidadesMalo[i];
        }
        fclose(archivo);
    }
}


void guardarInventario(char nombres[MAX_EQUIPOS][MAX_NOMBRE], int *cantidades, int *cantidadesBueno, int *cantidadesMalo, int *cantidadesNecesarias, float *precios, int numEquipos) {
    FILE *archivo = fopen("inventario.txt", "w+");
    if (archivo != NULL) {
        fprintf(archivo, "%d\n", numEquipos);
        for (int i = 0; i < numEquipos; i++) {
            fprintf(archivo, "%s %d %d %d %d %.2f\n", nombres[i], cantidadesBueno[i], cantidadesMalo[i], cantidadesNecesarias[i], cantidades[i], precios[i]);
        }
        fclose(archivo);
    }
}

int main() {
    char nombres[MAX_EQUIPOS][MAX_NOMBRE];
    int cantidades[MAX_EQUIPOS], cantidadesBueno[MAX_EQUIPOS], cantidadesMalo[MAX_EQUIPOS], cantidadesNecesarias[MAX_EQUIPOS];
    float precios[MAX_EQUIPOS];
    int numEquipos = 0;
    int opcion;

    cargarInventario(nombres, cantidades, cantidadesBueno, cantidadesMalo, cantidadesNecesarias, precios, &numEquipos);

    do {
        opcion = mostrarMenu();
        switch (opcion) {
            case 1:
                agregarEquipo(nombres, cantidades, cantidadesBueno, cantidadesMalo, cantidadesNecesarias, precios, &numEquipos);
                guardarInventario(nombres, cantidades, cantidadesBueno, cantidadesMalo, cantidadesNecesarias, precios, numEquipos);
                break;
            case 2:
                mostrarInventario(nombres, cantidades, cantidadesBueno, cantidadesMalo, cantidadesNecesarias, precios, numEquipos);
                break;
            case 3:
                calcularInversionTotal(nombres, cantidadesMalo, cantidadesNecesarias, precios, numEquipos);
                break;
            case 4:
                buscarEquipo(nombres, cantidades, cantidadesBueno, cantidadesMalo, cantidadesNecesarias, precios, numEquipos);
                break;
        }
    } while (opcion != 5);

    return 0;
}
