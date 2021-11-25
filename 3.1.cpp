#define USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

/*
*\brief Находит значение функции
*\param x Значение x
*\param a Значение a=0.29
*\param b Значение b=1.2502
*\return Значение y
*/
double GetY(double x, double const a, double const b);

int main()
{
	// объявление и инициализация констант a, b
    double const a=0.29, b= 1.2502;
	// объявление переменных x, left, right, step типа double
    double x, left, right, step;
	// вывод вспомогательной строки в консоль
    cout << "Enter left limit of interval" << endl;
	// присвоить left значение, введенного с консоли
    cin >> left;
	// вывод вспомогательной строки в консоль
    cout << "Enter right limit of interval" << endl;
	// присвоить right значение, введенного с консоли
    cin >> right;
	// вывод вспомогательной строки в консоль
    cout << "Enter value of step " << endl;
	// присвоить step значение, введенного с консоли
    cin >> step;

	// присвоить x значение left
    x = left;
	// цикл, пока x <= right, выполняется:
    while (x <= right)
    {
		// вывод значения функции GetY(x,a,b), setprecision(...) - задает точность значений с плавающей запятой
        cout << setprecision(5) << GetY(x,a,b) << endl;
		// прибавление к x значение step
        x += step;
    }
}

// функция, которая принимает в качестве трех аргументов значения типа double и возвращает значение типа double.
double GetY(double x, double const a, double const b)
{
	// pow(...) - возведение числа в степень
    return a * pow(x, 3) + x - b;
}