#include <iostream>
#include <time.h>
#include <iomanip>
using namespace std;

void Create(int *a, const int size, const int Low, const int High, int i);
void Print(int *a, const int size, int i);
int sumofsquares(int *a, const int size, int i);

template <typename T>
void Create(T *a, const int size, const int Low, const int High, int i);
template <typename T>
void Print(T *a, const int size, int i);
template <typename T>
T sumofsquares(T *a, const int size, int i);

int main()
{
    srand((unsigned)time(NULL));
    const int t = 20;
    int Low = -14;
    int High = 7;

    int a[t];
    Create(a, t, Low, High, 0);
    Print(a, t, 0);

    int s1 = sumofsquares(a, t, 0);
    cout << "sumofsquares(a, t) = " << s1 << endl;

    int s2 = sumofsquares<int>(a, t, 0);
    cout << "sumofsquares<int>(a, t) = " << s2 << endl;

    double b[t];
    Create<double>(b, t, Low, High, 0);
    Print<double>(b, t, 0);

    double s3 = sumofsquares<double>(b, t, 0);
    cout << "sumofsquares<double>(b, t) = " << s3 << endl;

    return 0;
}

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

int sumofsquares(int *a, const int size, int i) // рекурсивна функція обчислення суми квадратів
{
    if (i < size)
        return a[i] * a[i] + sumofsquares(a, size, i + 1);
    else
        return 0;
}

template <typename T>
void Create(T *a, const int size, const int Low, const int High, int i)
{
    a[i] = Low + rand() % (High - Low + 1);
    if (i < size - 1)
        Create<T>(a, size, Low, High, i + 1);
}

template <typename T>
void Print(T *a, const int size, int i)
{
    cout << setw(4) << a[i];
    if (i < size - 1)
        Print<T>(a, size, i + 1);
    else
        cout << endl;
}

template <typename T>
T sumofsquares(T *a, const int size, int i)
{
    if (i < size)
        return a[i] * a[i] + sumofsquares<T>(a, size, i + 1);
    else
        return T();
}