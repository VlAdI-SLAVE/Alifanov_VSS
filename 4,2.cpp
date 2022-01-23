#include <iostream>
#include <string>
#include <ctime>
#include <random>
using namespace std;

/**
 * \brief Проверка ввода размера массива.
 * \return Размер массива.
 */
size_t GetSize();

/**
 *\brief Вычисление нового размера массива.
 *\param size размер массива.
 *\param k переменная вводимая пользователем.
 *\return Размер нового массива.
*/
size_t NewSize(const int* myArray, size_t size, const int k);

/**
 * \brief Заполнение массива случайными числами.
 * \param size размер массива.
 * \param minValue минимальное значение элементов массива.
 * \param maxValue максимальное значение элементов массива.
 * \return заполненный массив.
 */
int* FillRandomArray(size_t size, int minValue, int maxValue);

/**
 * \brief Вывод массива на консоль.
 * \param myArray массив.
 * \param size размер массива.
 */
void ArrayPrint(const int* myArray, size_t size);

/**
 * \brief Добавление элементoв со значением К до и после всех элементов, заканчивающихся на цифру К.
 * \param myArray массив.
 * \param size размер массива.
 * \return изменённый массив.
 */
int* Add(int* myArray, size_t size);

/**
 * \brief Создание нового массива по заданным формулам.
 * \param myArray массив.
 * \param size размер массива.
 * \param k переменная вводимая пользователем.
 * \return изменённый массив.
 */
int* ArrayChange(int* myArray, size_t size, const int k );

/**
 * \brief Замена предпоследнего элемента массива на максимальный по модулю.
 * \param myArray массив.
 * \param size размер массива.
 * \param maxValue максимальное значение, которое может принимать элемент массива.
 */
int* LastToMaxChange(const size_t size, const int minValue);

/**
 * \brief Метод, возвращающий заполненный пользователем массив.
 * \param size размер массива.
 * \param minValue минимальное значение элементов массива.
 * \param maxValue максимальное значение элементов массива.
 * \return заполненный массив.
 */
int* FillUserArray(size_t size);

/**
 * \brief Варианы ввода массива.
 */
enum class ArrayInputWay
{
    random,
    keyboard
};

/**
 * \brief Точка входа в программу.
 * \return 0, в случае успеха.
 */
int main()
{
    setlocale(LC_ALL, "Russian");
    size_t size = GetSize();

    if (size == 0)
        return 1;

    cout << "Как вы хотите заполнить массив?\n";
    cout << static_cast<int>(ArrayInputWay::random) << " - random,\n";
    cout << static_cast<int>(ArrayInputWay::keyboard) << " - keyboard.\n";
    cout << "Ваш выбор: ";
    int choice;
    cin >> choice;

    const auto chosen = static_cast<ArrayInputWay>(choice);
    int* myArray = nullptr;

    auto minValue = 0;
    auto maxValue = 0;
    cout << "Введите диапазон чисел массива (сначала минимум, потом максимум) " << endl;
    cin >> minValue >> maxValue;
    if (maxValue <= minValue)
    {
        cout << "Введен неправильный диапазон!" << endl;
    }

    switch (chosen)
    {
    case ArrayInputWay::random:
    {
        myArray = FillRandomArray(size, minValue, maxValue);
        break;
    }
    case ArrayInputWay::keyboard:
    {
        myArray = FillUserArray(size);
        break;
    }
    }

    cout << "Массив с заменённым минимальным элементом: " << endl;

    myArray = LastToMaxChange(size, minValue);
    ArrayPrint(myArray, size);

    cout << "Введите К";
    int k = 0;
    cin >> k;

    int* newArray2 = new int[NewSize(myArray, size,k)];
    cout << "Массив с добавленными к" << endl;
    newArray2 = AddK(myArray, size, k);
    ArrayPrint(newArray2, size);

    if (newArray2 != nullptr) {

        delete[] newArray2;
        newArray2 = nullptr;

    }

    cout << "Заменённый массив по формулам" << endl;
    newArray2 = ArrayChange(myArray, size);
    ArrayPrint(newArray2, size);

    if (myArray != nullptr) {

        delete[] myArray;
        myArray = nullptr;

    }
    return 0;

}

size_t GetSize() {
    int size = 0;
    cout << "Введите размер массива" << endl;
    cin >> size;
    if (size <= 0)
    {
        cout << "Введён неверный размер";
        return 0;
    }
    else
        return size;
};

size_t NewSize(const int* myArray, size_t size, const int k) {
    size_t count = 0;
    for (size_t index = 0; index < size; index++) {
        if (myArray[index] % 10 == k) {
            count += 2;
        }
    }
    size = size + count;
    return size;
}

int* LastToMaxChange(const size_t size, const int minValue)
{
    auto maxArrayValue = minValue;
    size_t maxElementIndex = 0;

    int* newArray = new int[size];
    for (size_t index = 0; index < size; index++) {
        if (abs(newArray[index]) > maxArrayValue) {
            maxArrayValue = abs(newArray[index]);
            maxElementIndex = index;
        }
    }

    newArray[size - 2] = newArray[maxElementIndex];

    return newArray;
}

int* ArrayChange(int* myArray, size_t size)
{
    int temprary = 0;
    if (myArray == nullptr) {
        cout << "Массив пуст";
        return nullptr;
    }

    int* newArray = new int[size];
    for (size_t index = 0, newindex = 0; index < size; index++) {
        if (index % 2 == 0) {
            newArray[newindex] = myArray[index]* myArray[index] * index;
        }
        if(index % 2!=0 and index != 1 ) {
            newArray[newindex] = myArray[index] / (index - 1);
        }
    }

    return newArray;
}

int* AddK(int* myArray, size_t size, const int k)
{
    if (myArray == nullptr) {
        cout << "Массив пуст";
        return nullptr;
    }

    size_t count = 0;
    for (size_t index = 0; index < size; index++) {
        if (myArray[index] % 10 == k ) {
            count += 2; 
        }
    }

    int* newArray = new int[size + count];

    if (myArray[index + 1] % 10 == k || index >= 1 && myArray[index - 1] == k) {
        if (myArray[index + 1] % 10 == k) {
            newArray[newindex] = k;
            newindex++;
        }
        if (index >= 1 && myArray[index - 1] % 10 == k) {
            newArray[newindex] = k;
        }

    }
    else {
        newArray[newindex] = myArray[index];
    }

    return newArray;
}

void ArrayPrint(const int* myArray, const size_t size)
{
    if (myArray == nullptr)
    {
        cout << "Массива не существует";
    }
    else {
        cout << "Массив:\n";
        for (size_t index = 0; index < size; index++) {
            cout << myArray[index] << " ";
        }
        cout << "\n";

    }
}

int* FillRandomArray(const size_t size, const int minValue, const int maxValue)
{
    random_device rd;

    mt19937 gen(rd());

    const std::uniform_int_distribution<> uniformIntDistribution(minValue, maxValue);

    auto* myArray = new int[size];

    for (size_t index = 0; index < size; index++)
    {
        myArray[index] = uniformIntDistribution(gen);
    }
    return myArray;
}

int* FillUserArray(const size_t size)
{
    auto* array = new int[size];
    cout << "Введите элементы массива" << "\n";
    for (size_t index = 0; index < size; index++)
    {
        cin >> array[index];
    }
    return array;
}