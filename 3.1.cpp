#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

/*
*\brief Находит значение функции.
*\param x Значение x.
*\param a Значение a=0.29.
*\param b Значение b=1.2502.
*\return Значение y.
*/
double GetY(double x, double const a, double const b);

/**
* \brief Точка входа в программу
* \return Код ошибки (0) успех
*/
int main()
{
    double const a=0.29, b= 1.2502;
    double left, right, step;
    cout << "Enter left limit of interval" << endl;
    cin >> left;
    cout << "Enter right limit of interval" << endl;
    cin >> right;
    cout << "Enter value of step " << endl;
    cin >> step;

    double x = left;
    while (x <= right)
    {
        cout << setprecision(5) << GetY(x,a,b) << endl;
	x += step;
    }
    return 0;
}

double GetY(double x, double const a, double const b)
{
    return a * pow(x, 3) + x - b;
}