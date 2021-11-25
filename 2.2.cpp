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
    const double a = 2;
    const double top = 2;
    const double b = 1;
    double x;
    cout << "Enter x = "; 
    cin >> x;
    double result;

     if (x > top)
    {
        result = GetF2(x, a);
    }
    else if (x < b)
    {
        result = 1;
    }
    else
    {
        result = GetF1(x, a);
    }
    cout << "y = " << setprecision(15) << result;
    return 0;
}

double GetF1(const double x, const double a)
{
	return a * pow(x, 2 * log(x)); 
}

double GetF2(const double x, const double a)
{
	 return exp(a * x) * cos(x);
}