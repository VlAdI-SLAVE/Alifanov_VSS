#include <iostream>
#include <string>
#include <random>

using namespace std;

/**
 * \brief Проверка ввода размера массива.
 * \return Размер массива.
 */
size_t GetSize();

/**
 * \brief Замена элементов массива с нечетными номерами на квадраты их номеров.
 * \param myArray массив.
 * \param size размер массива.
 * \return массив.
 */
int* ChangeElements( int* myArray, const size_t size);

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
 * \brief Функция определяет, есть ли положительные элементы, делящиеся на заданное число k с остатком 2.
 * \param myArray массив.
 * \param size размер массива.
 * \return true, если имеются, false если нет.
 */
bool PositiveEvenElements(const int* myArray, const size_t size);

/**
 * \brief Вычисление произведения четных элементов массива.
 * \param myArray массив.
 * \param size размер массива.
 * \return Произведение.
 */
int CompositionOfEvenElements(int* myArray, const size_t size);

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

    ArrayPrint(myArray, size);

    cout << "Произведение чётных элементов массива: " << CompositionOfEvenElements(myArray, size)<<endl;

    cout << "Массив с заменёнными элементами: ";
    myArray = ChangeElements(myArray, size);
    ArrayPrint(myArray, size);

    if (PositiveEvenElements(myArray, size)) {
        cout << "Есть положительные элементы, делящиеся на заданное число k с остатком 2.";
    }
    else {
        cout << "Нет положительных элементов, делящихся на заданное число k с остатком 2";
    }
    cout << endl;

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

int* ChangeElements( int* myArray, const size_t size) {
    for (size_t index = 0; index < size; index+=2) {
        myArray[index] = index * index;
    }
    return myArray;
}

bool PositiveEvenElements(const int* myArray, const size_t size) {
    int k = 0;
    int countelements = 0;
    cout << "Введите k "<< endl;
    cin >> k;
    if (k < 3) {
        cout << "k < 3: Остаток от деления не может быть равен 2. Введите k > 3 "<< endl;
        return false;
    }

    for (size_t index = 1; index < size; index = index + 2) {
        if (myArray[index] > 0 && myArray[index] % k == 2) {
            countelements++;
        }
    }
    return countelements > 0;

}

int CompositionOfEvenElements(int* myArray, const size_t size)
{
    int comp = 1;
    for (size_t index = 0; index < size; index++) {
        if (myArray[index] % 2 == 0)
            comp = comp * myArray[index];
    }
    return comp;
}

void ArrayPrint(const int* myArray, const size_t size)
{
    if (myArray == nullptr)
    {
        cout << "Массива не существует";
    }
    else {
        cout << "\nМассив:\n";
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