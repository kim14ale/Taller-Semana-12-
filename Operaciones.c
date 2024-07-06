#include <stdio.h>
#include "Lecturas.h"
#include "Operaciones.h"

int mostrarMenu() {
    int opcion;
    printf("*\n");
    printf("Menu de Inventario de Equipos Tecnologicos\n");
    printf("1. Agregar equipo\n");
    printf("2. Mostrar inventario\n");
    printf("3. Calcular inversion total\n");
    printf("4. Buscar equipo\n");
    printf("5. Salir\n");
    opcion = leerEnteroEntre("Seleccione una opcion: ", 1, 5);
    printf("*\n");
    return opcion; 
}


void agregarEquipo(char nombres[MAX_EQUIPOS][MAX_NOMBRE], int cantidades[MAX_EQUIPOS], int cantidadesBueno[MAX_EQUIPOS], int cantidadesMalo[MAX_EQUIPOS], int cantidadesNecesarias[MAX_EQUIPOS], float precios[MAX_EQUIPOS], int* numEquipos) {
    if (*numEquipos < MAX_EQUIPOS) {
        printf("Ingrese el nombre del equipo: ");
        scanf("%s", nombres[*numEquipos]);

        printf("Ingrese la cantidad en buen estado: ");
        cantidadesBueno[*numEquipos] = leerEnteroPositivo("");

        printf("Ingrese la cantidad en mal estado: ");
        cantidadesMalo[*numEquipos] = leerEnteroPositivo("");

        printf("Ingrese la cantidad adicional necesaria: ");
        cantidadesNecesarias[*numEquipos] = leerEnteroPositivo("");

        precios[*numEquipos] = leerFlotantePositivo("Ingrese el precio del equipo: ");

        cantidades[*numEquipos] = cantidadesBueno[*numEquipos] + cantidadesMalo[*numEquipos];
        (*numEquipos)++;
    } else {
        printf("Inventario lleno. No se puede agregar mas equipos.\n");
    }
}


void mostrarInventario(char nombres[MAX_EQUIPOS][MAX_NOMBRE], int cantidades[MAX_EQUIPOS], int cantidadesBueno[MAX_EQUIPOS], int cantidadesMalo[MAX_EQUIPOS], int cantidadesNecesarias[MAX_EQUIPOS], float precios[MAX_EQUIPOS], int numEquipos) {
    if (numEquipos > 0) {
        printf("-------------------------------------------------\n");
        printf("    Inventario de Equipos Tecnologicos      \n");
        for (int i = 0; i < numEquipos; i++) {
            printf("Equipo %d:\n", i + 1);
            printf("Nombre: %s\n", nombres[i]);
            printf("Cantidad existente: %d\n", cantidades[i]);
            printf("Cantidad en buen estado: %d\n", cantidadesBueno[i]);
            printf("Cantidad en mal estado: %d\n", cantidadesMalo[i]);
            printf("Cantidad adicional necesaria: %d\n", cantidadesNecesarias[i]);
            printf("Precio por unidad: %.2f\n", precios[i]);
            printf("-----------------------------------------------\n");
        }
    } else {
        printf("El inventario esta vacio.\n");
    }
}


void calcularInversionTotal(char nombres[MAX_EQUIPOS][MAX_NOMBRE], int cantidadesMalo[MAX_EQUIPOS], int cantidadesNecesarias[MAX_EQUIPOS], float precios[MAX_EQUIPOS], int numEquipos) {
    float inversionTotal = 0.0;

    for (int i = 0; i < numEquipos; i++) {
        int totalAReemplazar = cantidadesMalo[i] + cantidadesNecesarias[i];
        float costoTotal = totalAReemplazar * precios[i];
        inversionTotal += costoTotal;

        printf("_____________________________________________\n");
        printf("Equipo: %s\n", nombres[i]);
        printf("Cantidad a reemplazar: %d\n", cantidadesMalo[i]);
        printf("Cantidad adicional necesaria: %d\n", cantidadesNecesarias[i]);
        printf("Costo de la inversion de los equipos: %.2f\n", costoTotal);
        printf("_____________________________________________\n");
    }

    printf("Inversion total: %.2f\n", inversionTotal);
}


void buscarEquipo(char nombres[MAX_EQUIPOS][MAX_NOMBRE], int cantidades[MAX_EQUIPOS], int cantidadesBueno[MAX_EQUIPOS], int cantidadesMalo[MAX_EQUIPOS], int cantidadesNecesarias[MAX_EQUIPOS], float precios[MAX_EQUIPOS], int numEquipos) {
    char nombreBuscar[MAX_NOMBRE];
    printf("Ingrese el nombre del equipo que desea buscar: ");
    scanf("%s", nombreBuscar);

    for (int i = 0; i < numEquipos; i++) {
        if (strcmp(nombres[i], nombreBuscar) == 0) {
            printf("Equipo encontrado:\n");
            printf("Nombre: %s\n", nombres[i]);
            printf("Cantidad existente: %d\n", cantidades[i]);
            printf("Cantidad en buen estado: %d\n", cantidadesBueno[i]);
            printf("Cantidad en mal estado: %d\n", cantidadesMalo[i]);
            printf("Cantidad adicional necesaria: %d\n", cantidadesNecesarias[i]);
            printf("Precio por unidad: %.2f\n", precios[i]);
            return;
        }
    }

    printf("El equipo %s no fue encontrado en el inventario.\n", nombreBuscar);
}