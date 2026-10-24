#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

// 1. Функція формування масиву
void Create(int *a, const int size, const int Low, const int High)
{
    for (int i = 0; i < size; i++)
        a[i] = Low + rand() % (High - Low + 1);
}

// 2. Функція форматного виведення масиву у рядок
void Print(const int *a, const int size)
{
    for (int i = 0; i < size; i++)
        cout << setw(5) << a[i];
    cout << endl;
}

// 3. Функція перевірки критерію: додатний елемент з індексом, не кратним 4
bool MeetsCriterion(const int value, const int index)
{
    return value > 0 && index % 4 != 0;
}

// 4. Функція обчислення кількості елементів, що задовольняють критерій
int CountByCriterion(const int *a, const int size)
{
    int count = 0;
    for (int i = 0; i < size; i++)
        if (MeetsCriterion(a[i], i))
            count++;
    return count;
}

// 5. Функція обчислення суми елементів, що задовольняють критерій
int SumByCriterion(const int *a, const int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
        if (MeetsCriterion(a[i], i))
            sum += a[i];
    return sum;
}

// 6. Функція заміни нулями елементів, що задовольняють критерій
void ReplaceByCriterionWithZeros(int *a, const int size)
{
    for (int i = 0; i < size; i++)
        if (MeetsCriterion(a[i], i))
            a[i] = 0;
}

int main()
{
    srand((unsigned)time(NULL));

    const int t = 20; // за варіантом 23 — 20 елементів
    int a[t];
    int Low = -14; // за варіантом 23
    int High = 7;  // за варіантом 23

    // 1. Формування масиву
    Create(a, t, Low, High);

    // 2. Виведення початкового масиву
    cout << "Початковий масив:" << endl;
    Print(a, t);

    // 3. Обчислення кількості та суми (до заміни нулями)
    int count = CountByCriterion(a, t);
    int sum = SumByCriterion(a, t);

    // 4. Заміна нулями
    ReplaceByCriterionWithZeros(a, t);

    // 5. Виведення результатів
    cout << "\nКількість додатних елементів, індекс яких не кратний 4: " << count << endl;
    cout << "Сума додатних елементів, індекс яких не кратний 4: " << sum << endl;

    // 6. Виведення модифікованого масиву
    cout << "\nМодифікований масив (після заміни нулями):" << endl;
    Print(a, t);

    return 0;
}