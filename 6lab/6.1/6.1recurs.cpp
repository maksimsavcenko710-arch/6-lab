#include <iostream>
#include <time.h>
#include <iomanip>
using namespace std;
void Create(int *a, const int size, const int Low, const int High, int i) // рекурсивна функція формування масиву
{
    a[i] = Low + rand() % (High - Low + 1);
    if (i < size - 1)
        Create(a, size, Low, High, i + 1);
}
void Print(int *a, const int size, int i) // рекурсивна функція форматного виведення масиву у рядок
{
    cout << setw(4) << a[i];
    if (i < size - 1)
        Print(a, size, i + 1);
    else
        cout << endl;
}
int sum(int *a, const int size, int i)
{
    int M = 0;
    if (a[i] > 0 && i % 4 != 0)
        M += a[i];
    if (i < size - 1)
        return M + sum(a, size, i + 1);
    return M;
}

int count(int *a, const int size, int i) // рекурсивна функція обчислення кількості додатніх елементів, індекс яких не кратний 4
{
    int S = 0;
    if (a[i] > 0 && i % 4 != 0)
    {
        S = 1;
    }
    if (i < size - 1)
        return S + count(a, size, i + 1);

    return S;
}
void zero(int *a, const int size, int i) // заміна нулями додатніх елементів, індекс яких не кратний 4
{
    if (a[i] > 0 && i % 4 != 0)
    {
        a[i] = 0;
    } // заміна нулем
    if (i < size - 1)
        zero(a, size, i + 1);
}

int main()
{
    srand((unsigned)time(NULL));
    const int t = 20;
    int a[t];
    int Low = -14;
    int High = 7;
    Create(a, t, Low, High, 0);
    Print(a, t, 0);

    int M = sum(a, t, 0);   // сума
    int k = count(a, t, 0); // кількість індекс яких не кратний 4
    zero(a, t, 0);          // заміна нулями додатніх елементів, індекс яких не кратний 4

    cout << "Кількість додатніх елементів, індекс яких не кратний 4: " << k << endl;
    cout << "Сума додатніх елементів, індекс яких не кратний 4: " << M << endl;
    cout << "Масив після заміни нулями додатніх елементів, індекс яких не кратний 4: " << endl;
    Print(a, t, 0);
    return 0;
}