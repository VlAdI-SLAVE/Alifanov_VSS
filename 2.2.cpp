#define _USE_MATH_DEFINES 
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

/**
 * \brief Функция вычисления для случая, x >= 1 и x <= 2
 * \param x Значение x
 * \param a Значение a
 * \return Значение функции
 */
double GetFunctionOne(const double x, const double a);

/**
 * \brief Функция вычисления для случая, когда x > 2
 * \param x Значение x
 * \param a Значение a
 * \return Значение функции
 */
double GetFunctionTwo(const double x, const double a);

int main()
{
    const double a = 2;
    const double top = 2;
    const double bot = 1;
    double x;
    cout << "Enter x = "; 
    cin >> x;
    double result;

    if (x > top)
    {
        result = GetFunctionTwo(x, a);
    }

    else if (x < bot)
    {
        result = 1;
    }
    else
    {
        result = GetFunctionOne(x, a);
    }

    cout << "y = " << setprecision(15) << result;
    return 0;
}

double GetFunctionOne(const double x, const double a)
{
    return a * pow(x, 2 * log(x));
}

double GetFunctionTwo(const double x, const double a)
{
    return exp(a * x) * cos(x);
}