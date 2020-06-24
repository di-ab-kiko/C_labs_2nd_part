#include <math.h>
#include <stdio.h>
#define IDEAL_INTEGRAL_VALUE

#define RECTANGLE 1
#define TRAPEZOIDAL 2
#define SIMPSON 3

#define  MAX_ITER 500

double f1(double,double );
double freq(double);
double getIntegralValue(int method, double a, double start_x, double stop_x, int n);
double rectIntegral(double a, double start_x, double stop_x, int N);
double trapIntegral(double a, double start_x, double stop_x, int N);
double simpIntegral(double a, double start_x, double stop_x, int N);

void absDifferenceCompare(int, int, int, double, double );

int main()
{

    printf("Значение интеграла: 45\n");
    printf("Интегрирование методом треугольника: %lf\n", getIntegralValue(RECTANGLE, 1, 0, 2 * M_PI, MAX_ITER));
    printf("Интегрирование методом трапеций: %lf\n", getIntegralValue(TRAPEZOIDAL, 1, 0, 3 * M_PI, MAX_ITER));
    printf("Интегрирование методом Симпсона: %lf\n", getIntegralValue(SIMPSON, 1, 0, 4 * M_PI, MAX_ITER));
    printf("Нажмите x чтобы закрыть: ");
    char *var;
    scanf("%c", var);

    if (*var = 'x')
    {
        return 0;
    }
}

double function_integral(double a, double x)
{
    tan(18 * pow(a, 2) + 29 * a * x + 10 * pow(x, 2));
}

double getIntegralValue(int method, double a, double start_x, double stop_x, int n)
{
    double result = 0.0;

    switch (method) {
        case RECTANGLE:
            result = rectIntegral(a, start_x, stop_x, n);
            break;
        case TRAPEZOIDAL:
            result = trapIntegral(a, start_x, stop_x, n);
            break;
        case SIMPSON:
            result = simpIntegral(a, start_x, stop_x, n);
            break;
        default:
            break;
    }

    return result;
}

double rectIntegral(double a, double start_x, double stop_x, int N)
{
    return ((stop_x - start_x) * ((start_x + stop_x)/2));
}
double trapIntegral(double a, double start_x, double stop_x, int N)
{
    return 0.5*(stop_x - start_x)*(start_x + stop_x);
}
double simpIntegral(double a, double start_x, double stop_x, int N)
{
    return (stop_x - start_x) / 6.0 * (start_x + 4.0 * 0.5 * (start_x + stop_x) + stop_x);
}