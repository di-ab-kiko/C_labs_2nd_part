#include <stdio.h>
#include <math.h>
#include <conio.h>

#define N 1000000

double F (double x)
{
    double f;
    f = tan(10*pow(x,2) + 29*x + 18);
    return f;
}

int main ()
{
    double S = 0, x, a, b, h;
    const double Pi = 3.14159;
    a = 0;
    b = 2*Pi;
    //отрезок [a, b] разобьем на N частей
    h = (b - a)/N;
    x = a + h;
    while (x < b)
    {
        S = S + 4*F(x);
        x = x + h;
        //проверяем не вышло ли значение x за пределы полуинтервала [a, b)
        if (x >= b) break;
        S = S + 2*F(x);
        x = x + h;
    }
    S = (h/3)*(S + F(a) + F(b));
    printf ("%f", S);
    return 0;
}
