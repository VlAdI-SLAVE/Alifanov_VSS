#define USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

/*
*\brief Вычисляет значение функции
*\param x Значение x
*\param c Значение c=0.29
*\param k Значение k=1.2502
*\return Значение y
*/
double GetFunction(double x, double const c, double const k);

int main()
{
    double const c=0.29, k= 1.2502;
    double x, left, right, step;
    cout << "Enter left limit of interval" << endl;
    cin >> left;
    cout << "Enter right limit of interval" << endl;
    cin >> right;
    cout << "Enter value of step " << endl;
    cin >> step;

    x = left;
    while (x <= right)
    {
        cout << setprecision(5) << GetFunction(x,c,k) << endl;
        x += step;
    }
}

double GetFunction(double x, double const c, double const k)
{
    return c * pow(x, 3) + x - k;
}