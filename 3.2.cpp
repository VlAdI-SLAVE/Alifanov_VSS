#define USE_MATH_DEFINES
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

/*
*\brief Вычисление рекурентного выражения
*\param k Индекс члена ряда
*\return Значение рекурентного соотношения
*/
double Recurrent(const size_t k);

/*
*\brief Вычисление суммы ряда
*\param n Колличество членов ряда
*\return Значение суммы
*/
double Summa(const size_t n);

/*
*\brief Вычисление суммы ряда со значением большим е
*\param e Значение е
*\return Значение суммы
*/
double SummaE(const double e);

int main()
{
	cout << "Enter number of elements in sequence." << endl;
	size_t n;
	cin >> n;
	cout << Summa(n) << "\n";
	cout <<  "Enter e = ";
	double e;
	cin >> e;
	cout << SummaE(e);
	return 0;
}

double Recurrent(const size_t k)
{
	return (-1.0) / ((k + 1) * (k + 2));
}
double Summa(const size_t n)
{
	double pre = 1, sum = 1, cur;
	for (size_t k = 0; k < n; k++)
	{
		cur = Recurrent(k) * pre;
		pre = cur;
		sum += pre;
	}
	return sum;
}

double SummaE(const double e)
{
	double pre = 1, sum = 1, cur;
	for (size_t k = 0; abs(pre) > e; k++)
	{
		cur = Recurrent(k) * pre;
		pre = cur;
		sum += pre;
	}
	return sum;
}