#define _USE_MATH_DEFINES 
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

/**
 * \brief Функция расчета для случая, x >= 1 и x <= 2.
 * \param x Значение x.
 * \param a Значение a.
 * \return Значение функции.
 */
double GetF1(const double x, const double a);

/**
 * \brief Функция расчета для случая, когда x > 2.
 * \param x Значение x.
 * \param a Значение a.
 * \return Значение функции.
 */
double GetF2(const double x, const double a);

int main()
{
	// объявление и инициализация констант a, top, bot типа double
    const double a = 2;
    const double top = 2;
    const double bot = 1;
	// объявление переменной x
    double x;
	// вывод вспомогательной строки в консоль
    cout << "Enter x = "; 
	// присваивание x значение, введенной с консоли
    cin >> x;
	// объявление переменной result типа double
    double result;

	// условный оператор, где условие x > top, если верно, то result присвоит значение функции GetF2(x, a)
    if (x > top)
    {
        result = GetF2(x, a);
    }

	// условный оператор, где условие x < bot, если верно, то result присвоит значение 1, иначе присвоит result значение функции GetF1(x, a)
    else if (x < bot)
    {
        result = 1;
    }
    else
    {
        result = GetF1(x, a);
    }

	// вывод result, setprecision(...) - задает точность значений с плавающей запятой.
    cout << "y = " << setprecision(15) << result;
    return 0;
}

// функция, которая принимает в качестве двух аргументов значения типа double и возвращает значение типа double.
double GetF1(const double x, const double a)
{
	// pow(...) - возведение числа в степень, log(...) - возвращает натуральный логарифм числа
    return a * pow(x, 2 * log(x)); 
}

// функция, которая принимает в качестве двух аргументов значения типа double и возвращает значение типа double.
double GetF2(const double x, const double a)
{
	// exp(...) - возведение экспоненты в степень, cos(...) - возвращает косинус числа
    return exp(a * x) * cos(x);
}