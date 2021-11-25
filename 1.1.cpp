#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>

using namespace std;

/**
* \brief Расчёт значения а
* \param x Значение x
* \param y Значение y
* \param z Значение z
* \return Значение а
*/
double GetFoundA(const double x, const double y);

/**
* \brief Расчёт значения b
* \param x Значение x
* \param y Значение y
* \param z Значение z
* \return Значение b
*/
double GetFoundB(const double x, const double y, const double z);

int main()
{    
	// объявление и инициализация констант x, y, z
	const auto x = 1.825;
	const auto y = 18.225;
	const auto z = -3.298;

	// объявление констант a, b, которым присвается значения функций GetFoundA(x, y) и GetFoundB(x, y, z) соответственно.
	const auto a = GetFoundA(x, y);
	const auto b = GetFoundB(x, y, z);

	// вывод исходных данных, т.е. значения x, y, z
	cout << "x = " << x << ", y = " << y << ", z = " << z << "\n";
	// вывод результатов вычислений
	cout << "a = " << a << ", b = " << b;

	return 0;
}

// функция, которая принимает в качестве двух аргументов значения типа double и возвращает значение типа double.
double GetFoundA(const double x, const double y)
{
	// pow(...) - возведение числа в степень
	return pow(x, y / x) - pow(y / x, 1 / 3);
}

//  функция, которая принимает в качестве двух аргументов значения типа double и возвращает значение типа double.
double GetFoundB(const double x, const double y, const double z)
{
	return (y - x) + ((y - z) / (y - x)) / (3 + ((z * z) / 5));
}
