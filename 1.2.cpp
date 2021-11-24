#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>

using namespace std;
/*
* \brief Высчитывает площадь грани куба
* \param x Длина ребра куба
* \return Площадь грани куба
*/

double GetArea(double x);

/*
* \brief Высчитывает площадь полной поверхности куба
* \param x Длина ребра куба
* \return Площадь полной поверхности куба
*/

double GetSurfaceArea(double x);

/*
* \brief Высчитывает объем куба
* \param x Длина ребра куба
* \return Объем куба
*/

double GetVolume(double x);

int main()
{
	double x;
	cout << "Cube edge length: ";
	cin >> x;

	const double area = GetArea(x);
	const double SurfaceArea = GetSurfaceArea(x);
	const double volume = GetVolume(x);

	cout << "Area of the cube face: " << area << ", The total surface area of the cube: " << SurfaceArea << ", Cube volume: " << volume;

	return 0;
}

double GetArea(double x)
{
	return x * x;
}

double GetSurfaceArea(double x)
{
	return x * x * 6;
}

double GetVolume(double edge)
{
	return x * x * x;
}