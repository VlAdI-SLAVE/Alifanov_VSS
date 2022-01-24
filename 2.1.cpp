#include <iostream>

using namespace std;

/**
 * \brief Расчет периметра прямоугольного треугольника.
 * \param firstCatheterLength Длина первого катета.
 * \param secondCatheterLength Длина второго катета.
 * \return Периметр прямоугольного треугольника.
 */
double GetPerimeter(double firstCatheterLength, double secondCatheterLength);

/**
 * \brief Расчет площади прямоугольного треугольника.
 * \param firstCatheterLength Длина первого катета.
 * \param secondCatheterLength Длина второго катета.
 * \return Площадь прямоугольного треугольника.
 */
double GetArea(double firstCatheterLength, double secondCatheterLength);

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
    double firstCatheterLength, secondCatheterLength;
    cout << "Length of the first catheter: ";
    cin >> firstCatheterLength;
    cout << "Length of the second catheter: ";
    cin >> secondCatheterLength;

    cout << "Enter an action on the triangle (perimeter = 0, area = 1) ";

    int input;
    cin >> input;

    const auto choice = static_cast<Choice>(input);

    switch (choice)
    {
    case Choice::perimeter:
    {
        const double perimeter = GetPerimeter(firstCatheterLength, secondCatheterLength);
        cout << "Triangle perimeter = " << perimeter;
        break;
    }
    case Choice::area:
    {
        const double area = GetArea(firstCatheterLength, secondCatheterLength);
        cout << "Area of the triangle = " << area;
        break;
    }
    }
    return 0;
}

double GetPerimeter(double firstCatheterLength, double secondCatheterLength)
{
    return firstCatheterLength + secondCatheterLength + sqrt(firstCatheterLength * firstCatheterLength + secondCatheterLength * secondCatheterLength);
}

double GetArea(double firstCatheterLength, double secondCatheterLength)
{
    const double a = 2.0;
    return firstCatheterLength * secondCatheterLength / a;
}