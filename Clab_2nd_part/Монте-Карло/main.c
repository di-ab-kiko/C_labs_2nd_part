#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <locale.h>


#define MAX_ITER 100

int main() {
//    long long int i, n2 = 0;
//    long double a, b;
//    long double Pi;
//    time_t t;
//
//    setlocale(LC_NUMERIC, "");
//    struct lconv *ptrLocale = localeconv();
//    ptrLocale->decimal_point = ",";
//
//    srand((unsigned) time(&t));
//
//    for (i = 0; i < MAX_ITER; i++) {
//        a = (double)rand() / (double)RAND_MAX;
//        b = (double)rand() / (double)RAND_MAX;
//        n2 = (sqrt(pow(a, 2) + pow(b, 2)) <= 1.0f) ? ++n2 : n2;
//
//        if (i % 10000000 == 0) {
//            Pi = (double)n2 / i * 4;
//            printf("%1.20llf\n", Pi);
//        }
//    }

    double x, y;
    double PI = 0;
    double z = 1;
    int count = 0;
    char enter = 0;

    for (int i = 1; i < MAX_ITER; i += 2)
    {
        PI += z * 4 / i;
        z *= -1;

        printf("%f\n", PI);
    }
    printf("Для выхода из программы нажмите enter ");
    scanf("%c\n",enter);
    return 0;
}