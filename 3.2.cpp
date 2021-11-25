#define USE_MATH_DEFINES
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

/*
*\brief Расчёт рекурентного выражения
*\param k Индекс члена ряда
*\return Значение рекурентного соотношения
*/
double Recurrent(const size_t k);

/*
*\brief Расчёт суммы ряда
*\param n Колличество членов ряда
*\return Значение суммы
*/
double Sum(const size_t n);

/*
*\brief Расчёт суммы ряда со значением большим е
*\param e Значение е
*\return Значение суммы
*/
double SumE(const double e);

int main()
{
	// вывод вспомогательной строки в консоль
	cout << "Enter number of elements in sequence." << endl;
	// объявление n базового беззнакового целочисленного типа, применяемый как правило для счетчиков циклов и т.д.
	size_t n;
	// присваивание n значение, введеного с консоли
	cin >> n;
	// вывод значения функции Sum(n), "\n" - тоже самое, что endl - перевод на новую строку
	cout << Sum(n) << "\n";
	// вывод вспомогательной строки в консоль
	cout <<  "Enter e = ";
	
	// объявление константы e типа double
	double e;
	// присваивание e значение, введенного с консоли
	cin >> e;
	// вывод значения функции SumE(e)
	cout << SumE(e);
	return 0;
}

// функция, которая принимает в качестве аргумента значение типа size_t и возвращает значение типа double.
double Recurrent(const size_t k)
{
	return (-1.0) / ((k + 1) * (k + 2));
}
// функция, которая принимает в качестве аргумента значение типа size_t и возвращает значение типа double.
double Sum(const size_t n)
{
	// объявление и инициализация переменных pre, sum, cur типа double
	double pre = 1, sum = 1, cur;
	// цикл for
	for (size_t k = 0; k < n; k++)
	{
		cur = Recurrent(k) * pre;
		pre = cur;
		sum += pre;
	}
	return sum;
}

// функция, которая принимает в качестве аргумента значение типа double и возвращает значение типа double.
double SumE(const double e)
{
	// объявление и инициализация переменных pre, sum, cur типа double
	double pre = 1, sum = 1, cur;
	// цикл for, abs(...) - модуль числа
	for (size_t k = 0; abs(pre) > e; k++)
	{
		cur = Recurrent(k) * pre;
		pre = cur;
		sum += pre;
	}
	return sum;
}