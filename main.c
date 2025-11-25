#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ITERACIONES 100000000.0

int rand5() {
    return (rand() % 5) + 1;
}

int rand7() {
    int numA, numB, x;

    while(1) {
        numA = rand5();
        numB = rand5();

        // Para aumentar el tamaño de la muestra hasta 25
        x = 5*(numA - 1) + numB;
        // Eliminamos los que son mayores que 21, el mayor múltiplo de 7 menos que 25
        // Para evitar que haya número con mayor tasa de aparición, necesitamos ciclos enteros al hacer mod 7.
         if(x <= 21) { 
            return x%7 + 1;
        }
    }
}

int main() {
    srand(time(NULL));
    int frecuencia[8] = {0};

    for(int i = 0; i < iteraciones; i++) {
        int numRand = rand7();
        frecuencia[numRand]++;
    }
    
    // Comprobación de la distribución
    for(int i=1; i <= 7; i++) {
        printf("Num %d: frecuncia relativa %.2f\n", i, (frecuencia[i]/ITERACIONES)*100);
    }

    return 0;
}