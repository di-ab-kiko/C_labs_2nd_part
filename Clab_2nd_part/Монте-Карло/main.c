#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <locale.h>


#define N 100
#define M_PI 3.14159265358979323846

int main() {
    

    double x, y;
    double PI = 0;
    double z = 1;
    int count = 0;
    char enter = 0;

    for (int i = 1; i < N; i += 2)
    {
        PI += z * 4 / i;
        z *= -1;

        printf("%f\n", M_PI-PI);
    }
    printf("Для выхода из программы нажмите enter ");
    scanf("%c\n",enter);
    return 0;
}
