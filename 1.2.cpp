#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>

using namespace std;
/*
* \brief Вычисляет площадь грани куба
* \param edge Длина ребра куба
* \return Площадь грани куба
*/

double GetArea(double edge);

/*
* \brief Вычисляет площадь полной поверхности куба
* \param edge Длина ребра куба
* \return Площадь полной поверхности куба
*/

double GetSurfaceArea(double edge);

/*
* \brief Вычисляет объем куба
* \param edge Длина ребра куба
* \return Объем куба
*/

double GetVolume(double edge);

int main()
{
	// объявление переменной edge типа double
	double edge;
	// вывод вспомогательной строки в консоль
	cout << "Cube edge length: ";
	// присваивание edge значение, введенного с консоли
	cin >> edge;

	// объявление констант area, SurfaceArea, volume, которым присвается значения функций  GetArea(edge), GetSurfaceArea(edge), GetVolume(edge) соответственно.
	const double area = GetArea(edge);
	const double SurfaceArea = GetSurfaceArea(edge);
	const double volume = GetVolume(edge);

	// вывод результатов
	cout << "Area of the cube face: " << area << ", The total surface area of the cube: " << SurfaceArea << ", Cube volume: " << volume;

	return 0;
}

// функция, которая принимает в качестве аргумента значение типа double и возвращает значение типа double.
double GetArea(double edge)
{
	return edge * edge;
}

// функция, которая принимает в качестве аргумента значение типа double и возвращает значение типа double.
double GetSurfaceArea(double edge)
{
	return edge * edge * 6;
}

// функция, которая принимает в качестве аргумента значение типа double и возвращает значение типа double.
double GetVolume(double edge)
{
	return edge * edge * edge;
}