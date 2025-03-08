#include <stdio.h>
#include <pthread.h>

#define NUM_HILOS 5
#define ITERACIONES 1000000

int variable_compartida = 0;  // Variable global compartida
pthread_mutex_t mutex;  // Declaración del mutex

// Función que ejecutan los hilos
void* incrementar(void* arg) {
    for (int i = 0; i < ITERACIONES; i++) {
        pthread_mutex_lock(&mutex);  // Bloquea el mutex antes de modificar la variable
        variable_compartida++;
        pthread_mutex_unlock(&mutex);  // Desbloquea el mutex después de la modificación
    }
    return NULL;
}

int main() {
    pthread_t hilos[NUM_HILOS];
    pthread_mutex_init(&mutex, NULL);  // Inicialización del mutex

    // Crear los hilos
    for (int i = 0; i < NUM_HILOS; i++) {
        pthread_create(&hilos[i], NULL, incrementar, NULL);
    }

    // Esperar a que todos los hilos terminen
    for (int i = 0; i < NUM_HILOS; i++) {
        pthread_join(hilos[i], NULL);
    }

    // Destruir el mutex
    pthread_mutex_destroy(&mutex);

    printf("Valor final de variable_compartida: %d\n", variable_compartida);
    return 0;
}
