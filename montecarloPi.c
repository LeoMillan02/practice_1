//Librer�as 
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void monteCarlo(int N, int K){
    
    double x, y;
    
    double d;
 
    int pCircle = 0;
 
    int pSquare = 0;
 
    int i = 0;
 

#pragma omp parallel firstprivate(x, y, d, i) reduction(+ : pCircle, pSquare) num_threads(K)
    {
        // Iniciando puntos random
        // con temporizador
        srand48((int)time(NULL));
 
        for (i = 0; i < N; i++) {
            // Valor X random
            x = (double)drand48();
 
            // Valor Y random
            y = (double)drand48();
 
            // Encontrando el cuadrado de la distancia
            // del punto (x, y) hacia el origen
            d = ((x * x) + (y * y));
 
           
            if (d <= 1) {
                // Incremento de pCircle en 1
                pCircle++;
            }
            // Incremento de pSquare en 1
            pSquare++;
        }
    }
    // Formula para calcular Pi
    double pi = 4.0 * ((double)pCircle / (double)(pSquare));
 
    // Mostrar el valor de Pi
    printf("Valor de Pi = %f\n", pi);
}
 
// Funcion principal
int main()
{
    //Entradas
    int N;
    int K;
    printf("Ingrese numero de iteraciones: ");
    scanf("%d",&N);
	printf("Ingrese numero de hilos: ");
    scanf("%d",&K);
    //lLamanado a la funcion
    monteCarlo(N, K);
}
