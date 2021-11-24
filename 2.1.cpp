#define _USE_MATH_DEFINES 
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

/**
 * \brief Расчет периметра прямоугольного треугольника
 * \param OneSide Длина первого катета
 * \param TwoSide Длина второго катета
 * \return Периметр прямоугольного треугольника
 */
double GetPerimeter(double OneSide, double TwoSide);

/**
 * \brief Расчет площади прямоугольного треугольника
 * \param CatheterOne Длина первого катета
 * \param CatheterTwo Длина второго катета
 * \return Площадь прямоугольного треугольника
 */
double GetArea(double OneSide, double TwoSide);

/**
 * \brief Пользовательский выбор расчета  периметра (0) или площади (1)
 */
enum class Choice { perimeter, area };

int main()
{
	double CatheterOne, CatheterTwo;
	cout << "Length of the first catheter: "; 
	cin >> CatheterOne;
	cout << "Length of the second catheter: ";
	cin >> CatheterTwo;

	cout << "Enter an action on the triangle (perimeter = 0, area = 1) ";
	int input;
	cin >> input;

	const auto choice = static_cast<Choice>(input);

	switch (choice)
	{
		case Choice::perimeter:
        {
           const double Perimeter = GetPerimeter(OneSide, TwoSide);
           cout << "Triangle perimeter = " << Perimeter;
           break;
        }
        case Choice::area:
        {
           const double Area = GetArea(OneSide, TwoSide);
           cout << "Area of the triangle = " << Area;
           break;
        }
	}
	return 0;
}

double GetPerimeter(double OneSide, double TwoSide)
{
	return OneSide + TwoSide + sqrt(OneSide * OneSide + TwoSide * TwoSide);
}

double GetArea(double OneSide, double TwoSide)
{
	return (OneSide * TwoSide) / 2;
}