#include <iostream>
#include <time.h>
#include <iomanip>
using namespace std;

void Create(int *a, const int size, const int Low, const int High);
void Print(int *a, const int size);
int sumofsquares(int *a, const int size);

template <typename T>
void Create(T *a, const int size, const int Low, const int High);
template <typename T>
void Print(T *a, const int size);
template <typename T>
T sumofsquares(T *a, const int size);

int main()
{
    srand((unsigned)time(NULL));
    const int t = 20;
    int Low = -14;
    int High = 7;

    int a[t];
    Create(a, t, Low, High);
    Print(a, t);

    int s1 = sumofsquares(a, t);
    cout << "sumofsquares(a, t) = " << s1 << endl;

    int s2 = sumofsquares<int>(a, t);
    cout << "sumofsquares<int>(a, t) = " << s2 << endl;

    double b[t];
    Create<double>(b, t, Low, High);
    Print<double>(b, t);

    double s3 = sumofsquares<double>(b, t);
    cout << "sumofsquares<double>(b, t) = " << s3 << endl;

    return 0;
}

void Create(int *a, const int size, const int Low, const int High) // функція формування масиву
{
    for (int i = 0; i < size; i++)
        a[i] = Low + rand() % (High - Low + 1);
}

void Print(int *a, const int size) // функція форматного виведення масиву у рядок
{
    for (int i = 0; i < size; i++)
        cout << setw(4) << a[i];
    cout << endl;
}

int sumofsquares(int *a, const int size) // функція обчислення суми квадратів
{
    int s = 0;
    for (int i = 0; i < size; i++)
        s += a[i] * a[i];
    return s;
}

template <typename T>
void Create(T *a, const int size, const int Low, const int High)
{
    for (int i = 0; i < size; i++)
        a[i] = Low + rand() % (High - Low + 1);
}

template <typename T>
void Print(T *a, const int size)
{
    for (int i = 0; i < size; i++)
        cout << setw(4) << a[i];
    cout << endl;
}

template <typename T>
T sumofsquares(T *a, const int size)
{
    T s = T(); // присвоїли нульове значення
    for (int i = 0; i < size; i++)
        s += a[i] * a[i];
    return s;
}