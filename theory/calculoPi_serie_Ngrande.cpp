/*****************************************************
 * CalculoPi_Serie_Ngrande.cpp
 *
 * Cálculo de π en serie con N grande (ej. 1e6),
 * midiendo el tiempo de ejecución con OpenMP 
 * (aunque no usemos la parte paralela aún, solo
 * el reloj).
 *
 * Compilación:
 *   g++ -fopenmp CalculoPi_Serie_Ngrande.cpp -o pi_serie_grande
 * Ejecución:
 *   ./pi_serie_grande
 *****************************************************/

#include <iostream>
#include <cmath>     // sqrt, pow, M_PI
#include <omp.h>     // para medir tiempo con omp_get_wtime()
using namespace std;

int main(){
    int N = 1000000;           // Un millón
    double suma = 0.0;

    // 1. Marcamos el inicio de tiempo usando OMP
    double start = omp_get_wtime();
    
    // 2. Bucle en serie
    for(int k = 0; k <= N; k++){
        double termino = pow(-1.0/3.0, k) * (1.0 / (2*k + 1));
        suma += termino;
    }
        
    double pi_aprox = sqrt(12.0) * suma;
    
    // 3. Marcamos el final del tiempo
    double end = omp_get_wtime();
    double tiempo = end - start;
    
    // 4. Imprimimos resultados
    cout << "Aproximacion de pi (N=" << N << ") = " << pi_aprox << endl;
    cout << "Valor de M_PI                   = " << M_PI << endl;
    cout << "Error absoluto                 = " << fabs(pi_aprox - M_PI) << endl;
    cout << "Tiempo de ejecucion (segundos) = " << tiempo << endl;

    return 0;
}
