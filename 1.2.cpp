#include <iostream>
#include <cmath>

using namespace std;

/*
* \brief Вычисляет площадь грани куба.
* \param edge Длина ребра куба.
* \return Площадь грани куба.
*/
double GetArea(double edge);

/*
* \brief Вычисляет площадь полной поверхности куба.
* \param edge Длина ребра куба.
* \return Площадь полной поверхности куба.
*/
double GetSurfaceArea(double edge);

/*
* \brief Вычисляет объем куба.
* \param edge Длина ребра куба.
* \return Объем куба.
*/
double GetVolume(double edge);

/**
* \brief Точка входа в программу
* \return Код ошибки (0) успех
*/
int main()
{
	// объявление переменной edge типа double.
	double edge;
	// вывод вспомогательной строки в консоль.
	cout << "Cube edge length: ";
	// присваивание edge значение, введенного с консоли.
	cin >> edge;

	// объявление констант area, surfaceArea, volume, которым присвается значения функций  GetArea(edge), GetSurfaceArea(edge), GetVolume(edge) соответственно.
	const double area = GetArea(edge);
	const double surfaceArea = GetSurfaceArea(edge);
	const double volume = GetVolume(edge);

	// вывод результатов.
	cout << "Area of the cube face: " << area << ", The total surface area of the cube: " << SurfaceArea << ", Cube volume: " << volume;

	return 0;
}

double GetArea(const double edge)
{
	return edge * edge;
}

double GetSurfaceArea(const double edge)
{
	return edge * edge * 6;
}

double GetVolume(const double edge)
{
	return edge * edge * edge;
}
