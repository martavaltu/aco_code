/*****************************************************
 * CalculoPi_Parallel.cpp
 *
 * Cálculo de π paralelizado con OpenMP.
 * Compilar y ejecutar indicando cuántos threads
 * deseamos.
 *
 * Compilación:
 *   g++ -fopenmp CalculoPi_Parallel.cpp -o pi_parallel
 * Ejecución (ejemplo con 4 threads):
 *   OMP_NUM_THREADS=4 ./pi_parallel
 *****************************************************/

#include <iostream>
#include <cmath>
#include <omp.h>
using namespace std;

int main(){
    // Probamos con un N grande
    int N = 1000000;

    // Inicia la suma en 0
    double suma = 0.0;

    // Marcamos el tiempo de inicio
    double start = omp_get_wtime();

    // Usamos la directiva 'parallel for' para paralelizar el bucle
    // y la cláusula reduction(+:suma) para que cada thread lleve
    // su propia suma parcial y luego se combinen.
    #pragma omp parallel for reduction(+:suma)
    for(int k = 0; k <= N; k++){
        double termino = pow(-1.0/3.0, k) * (1.0 / (2*k + 1));
        suma += termino;
    }
    // Calculamos pi
    double pi_aprox = sqrt(12.0) * suma;

    // Tiempo final
    double end = omp_get_wtime();
    double tiempo = end - start;

    // Imprimimos resultados
    cout << "Aproximacion de pi (N=" << N << ") = " << pi_aprox << endl;
    cout << "Valor de M_PI                   = " << M_PI << endl;
    cout << "Error absoluto                 = " << fabs(pi_aprox - M_PI) << endl;
    cout << "Tiempo de ejecucion (segundos) = " << tiempo << endl;
   
     // También podemos saber cuántos threads se usaron:
    // (si no lo forzamos con OMP_NUM_THREADS, depende del sistema)
    int numTh = 0;
    #pragma omp parallel
    {
        // Solo un thread hace este print (usamos "single")
        #pragma omp single
        {
            numTh = omp_get_num_threads();
        }
    }
    cout << "Numero de threads utilizados   = " << numTh << endl;

    return 0;
}

