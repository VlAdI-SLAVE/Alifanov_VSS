#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>

using namespace std;

/**
* \brief Вычисление значения а
* \param x Значение x
* \param y Значение y
* \param z Значение z
* \return Значение а
*/
double GetA(const double x, const double y);

/**
* \brief Вычисление начение b
* \param x Значение x
* \param y Значение y
* \param z Значение z
* \return Значение b
*/
double GetB(const double x, const double y, const double z);

int main()
{    
	const double x = 1.825;
	const double y = 18.225;
	const double z = -3.298;

	const double a = GetA(x, y);
	const double b = GetB(x, y, z);

	cout << "x = " << x << ", y = " << y << ", z = " << z << "\n";
	cout << "a = " << a << ", b = " << b;

	return 0;
}

double GetA(const double x, const double y)
{
	return pow(x, y / x) - pow(y / x, 1 / 3);
}

double GetB(const double x, const double y, const double z)
{
	return (y - x) + ((y - z) / (y - x)) / (3 + ((z * z) / 5));
}