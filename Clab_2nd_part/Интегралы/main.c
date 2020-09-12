#include <math.h>
#include <stdio.h>


#define RECTANGLE 1 // метод прямоугольников
#define TRAPEZOIDAL 2 // метод трапеций
#define SIMPSON 3 // метод симпсона
#define  MAX_ITER 1000000 // максимальное число итераций

double f(double, double); // исходная функция
double getIntegralValue(int method, double a, double start_x, double stop_x, int n); // выбор метода интегрирования
double rectIntegral(double a, double start_x, double stop_x, int N); // метод прямоугольников
double trapIntegral(double a, double start_x, double stop_x, int N); // метод трапеций
double simpIntegral(double a, double start_x, double stop_x, int N);

int main(){
    const double Pi = 3.14159;
	printf("Рассчитываем значение интеграла для a=1 на отрезке [0;2Pi]\n");
	printf("Интегрирование методом прямоугольников = %f\n", getIntegralValue(RECTANGLE, 1, 0, 2*Pi, MAX_ITER));
	printf("Интегрирование методом трапеций: %f\n", getIntegralValue(TRAPEZOIDAL, 1, 0, 2*Pi, MAX_ITER));
	printf("Интегрирование методом Симпсона: %f\n", getIntegralValue(SIMPSON, 1, 0, 2*Pi, MAX_ITER));
	return 0;
}

double f(double a, double x) { // исходная функция
	return tan(18 * a * a + 29 * a * x + 10 * x * x);
}

double getIntegralValue(int method, double a, double start_x, double stop_x, int n){ // выбор метода интегрирования
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

double rectIntegral(double a, double start_x, double stop_x, int N){ // метод прямоугольников
	double h = (stop_x - start_x) / N, I = 0;
	for (double i = start_x; i < stop_x; i += h)
		I += f(a,i);
	return h * I;

}

double trapIntegral(double a, double start_x, double stop_x, int N)
{ // метод трапеций
	double h = (stop_x - start_x) / N, I = f(a,start_x) / 2 + f(a,stop_x) / 2;
	for (double i = start_x + h; i < stop_x; i += h)
		I += f(a, i);
	return h * I;

}

double simpIntegral(double a, double start_x, double stop_x, int N){ // метод симпсона
	double h = (stop_x - start_x) / N, I = f(a, start_x) + f(a, stop_x);
	for (int j = 1; j < N; j++)
		if (j % 2 == 1)
		    I += 4 * f(a, start_x + h * j);  
		else   
		    I += 2*f(a, start_x + h * j);
	return (h*I/3);
}

