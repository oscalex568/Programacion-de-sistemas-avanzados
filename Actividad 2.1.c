#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;

    // Pedir al usuario el tama�o del array
    printf("Ingrese el numero de elementos: ");
    scanf("%d", &n);

    // Asignar memoria din�micamente para 'n' enteros
    int *arr = (int *)malloc(n * sizeof(int));

    // Verificar si la asignaci�n fue exitosa
    if (arr == NULL) {
        printf("Error: No se pudo asignar memoria.\n");
        return 1; // Salir con error
    }

    // Llenar el array con valores
    for (int i = 0; i < n; i++) {
        arr[i] = i * 10; // Asigna m�ltiplos de 10
    }

    // Mostrar el contenido del array
    printf("Valores almacenados en memoria dinamica:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Liberar la memoria asignada
    free(arr);
    //arr = NULL;

    // ERROR: Intento de acceso a memoria despu�s de liberarla (use-after-free)
    printf("Valor despu�s de free: %d\n", arr[0]); // Acceso ilegal

    return 0;
}
