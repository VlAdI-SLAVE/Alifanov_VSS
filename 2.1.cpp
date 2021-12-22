#define _USE_MATH_DEFINES 
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

/**
 * \brief Расчет периметра прямоугольного треугольника.
 * \param CatheterOne Длина первого катета.
 * \param CatheterTwo Длина второго катета.
 * \return Периметр прямоугольного треугольника.
 */
double GetPerimeter(double CatheterOne, double CatheterTwo);

/**
 * \brief Расчет площади прямоугольного треугольника.
 * \param CatheterOne Длина первого катета.
 * \param CatheterTwo Длина второго катета.
 * \return Площадь прямоугольного треугольника.
 */
double GetArea(double CatheterOne, double CatheterTwo);

/**
 * \brief Пользовательский выбор расчета  периметра или площади.
 */
enum class Choice {
    /**
     *brief Периметр. 
    */
    perimeter,
    
    /**
     * \brief Площадь. 
    */
    area 
    
};

/**
* \brief Точка входа в программу.
* \return Код ошибки (0) - успех.
*/
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
           const double Perimeter = GetPerimeter(CatheterOne, CatheterTwo);
           cout << "Triangle perimeter = " << Perimeter;
           break;
        }
        case Choice::area:
        {
           const double Area = GetArea(CatheterOne, CatheterTwo);
           cout << "Area of the triangle = " << Area;
           break;
        }
	}
	return 0;
}

double GetPerimeter(double CatheterOne, double CatheterTwo)
{
	return CatheterOne + CatheterTwo + sqrt(CatheterOne * CatheterOne + CatheterTwo * CatheterTwo);
}

double GetArea(double CatheterOne, double CatheterTwo)
{
        const double a = 2.0;
	return CatheterOne * CatheterTwo / a;
}