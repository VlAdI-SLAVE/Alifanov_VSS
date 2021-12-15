#define _USE_MATH_DEFINES 
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

/**
 * \brief Расчет периметра прямоугольного треугольника
 * \param CatheterOne Длина первого катета
 * \param CatheterTwo Длина второго катета
 * \return Периметр прямоугольного треугольника
 */
double GetPerimeter(double CatheterOne, double CatheterTwo);

/**
 * \brief Расчет площади прямоугольного треугольника
 * \param CatheterOne Длина первого катета
 * \param CatheterTwo Длина второго катета
 * \return Площадь прямоугольного треугольника
 */
double GetArea(double CatheterOne, double CatheterTwo);

/**
 * \brief Пользовательский выбор расчета  периметра (0) или площади (1)
 */
enum class Choice { perimeter, area };

/**
* \brief Точка входа в программу
* \return Код ошибки (0) успех
*/
int main()
{
	// объявление переменных CatheterOne, CatheterTwo типа double
	double CatheterOne, CatheterTwo;
	// вывод вспомогательной строки в консоль
	cout << "Length of the first catheter: "; 
	// присваивание CatheterOne значение, введенного с консоли
	cin >> CatheterOne;
	// вывод вспомогательной строки в консоль
	cout << "Length of the second catheter: ";
	// присваивание CatheterTwo значение, введенного с консоли
	cin >> CatheterTwo;

	// вывод вспомогательной строки в консоль
	cout << "Enter an action on the triangle (perimeter = 0, area = 1) ";

	// объявление переменной input типа int
	int input;
	// присваивание input значение, введенного с консоли
	cin >> input;

	// объявление и инициализация константы choice
	const auto choice = static_cast<Choice>(input);

	// оператор switch
	switch (choice)
	{
		case Choice::perimeter:
        {
		   // объявление и инициализация константы Perimeter, которой присвается значение результата вычисления функции GetPerimeter
           const double Perimeter = GetPerimeter(CatheterOne, CatheterTwo);
		   // вывод значения Perimeter
           cout << "Triangle perimeter = " << Perimeter;
           break;
        }
        case Choice::area:
        {
		   // объявление и инициализация константы Area, которой присвается значение результата вычисления функции GetArea
           const double Area = GetArea(CatheterOne, CatheterTwo);
		   // вывод значения Area
           cout << "Area of the triangle = " << Area;
           break;
        }
	}
	return 0;
}

// функция, которая принимает в качестве двух аргументов значения типа double и возвращает значение типа double.
double GetPerimeter(double CatheterOne, double CatheterTwo)
{
	return CatheterOne + CatheterTwo + sqrt(CatheterOne * CatheterOne + CatheterTwo * CatheterTwo);
}

// функция, которая принимает в качестве двух аргументов значения типа double и возвращает значение типа double.
double GetArea(double CatheterOne, double CatheterTwo)
{
	return CatheterOne * CatheterTwo / 2;
}