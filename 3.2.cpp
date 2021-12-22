#include <iostream>
#include <cmath>

using namespace std;

/*
*\brief Расчёт рекурентного выражения.
*\param k Индекс члена ряда.
*\return Значение рекурентного соотношения.
*/
double Recurrent(const size_t k);

/*
*\brief Расчёт суммы ряда.
*\param n Колличество членов ряда.
*\return Значение суммы.
*/
double Sum(const size_t n);

/*
*\brief Расчёт суммы ряда со значением большим е.
*\param e Погрешность вычисления.
*\return Значение суммы.
*/
double SumE(const double e);

/*
*\brief Точка входа в программу.
*\return 0 в случае успеха.
*/
int main()
{
	cout << "Enter number of elements in sequence." << endl;
	size_t n = 0;
	cin >> n;

	cout << "Sum of elements = " << Sum(n) << "\n";

	cout <<  "Enter e = ";
	double e;
	cin >> e;
	cout << "Sum of elements less than e = " <<SumE(e);
	return 0;
}

double Recurrent(const size_t k)
{
	return pow((-1.0),k) / ((k + 1.0) * (k + 2.0));
}

double Sum(const size_t n)
{
	double sum = 1.0;
	for (size_t k = 0; k < n; k++)
	{
		sum += Recurrent(k);
		k++;
	}
	return sum;
}

double SumE(const double e)
{
    size_t k = 0;
	double current, sum;
    current = Recurrent(k);
    while (current > e){
        sum = sum + current;
        k++;
        current = Recurrent(k);
    }
    return sum;
}