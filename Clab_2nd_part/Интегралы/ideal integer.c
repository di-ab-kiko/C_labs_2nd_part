#include <stdio.h>
#include <math.h>

#define  MAX_ITER 3 // максимальное число интервал
#define ideal_value 2.3333333
double f(double); // исходная функция
double rectIntegral(double x1,double start_x, int N); // метод прямоугольников

int main()
{
    const double Pi = 3.14159;
    printf("Рассчитываем значение интеграла для a=1 на отрезке [0;2Pi]\n");
    printf("Интегрирование методом прямоугольников = %f\n", rectIntegral( 1,2, MAX_ITER));
    getchar();
    return 0;
}

double f( double x) { // исходная функция
    return pow(x,2);
}
double rectIntegral( double x1,double start_x, int N)
{ // метод прямоугольников
    a = 0.0;
    double h = (x1 - start_x) / N, I = 0;
    x1 = a + h;
    for (I=1, I<= N-1, I++)
            I += f(a, x1 + h / 2)
    return h*I;
