/*****************************************************
 * CalculoPi_Serie_Npeque.cpp
 *
 * Cálculo de π con la fórmula de la diapositiva 40,
 * usando una aproximación con N=20 en serie.
 *
 * Compilación:
 *   g++ calculoPi_serie_Npeque.cpp -o pi_serie_peque
 * Ejecución:
 *   ./pi_serie_peque
 *****************************************************/
 
#include <iostream>
#include <cmath>     // sqrt, pow, M_PI
using namespace std;

int main(){
    // 1. Definimos el número de términos
    int N = 20;  

    // 2. Definimos la variable para la suma
    double suma = 0.0;

    // 3. Bucle para ir sumando cada término
    for(int k = 0; k <= N; k++){
        // término = ((-1/3)^k) / (2k+1)
        // Ojo con el -1/3, conviene usar -1.0/3.0 para evitar truncamiento
        double termino = pow(-1.0/3.0, k) * (1.0 / (2*k + 1));
        suma += termino;
    }

    // 4. Multiplicamos la suma por sqrt(12)
    double pi_aprox = sqrt(12.0) * suma;
    
     // 5. Mostramos resultados
    cout << "Aproximacion de pi (N=20) = " << pi_aprox << endl;
    cout << "Valor de M_PI            = " << M_PI << endl;
    cout << "Error absoluto          = " << fabs(pi_aprox - M_PI) << endl;

    return 0;
}
