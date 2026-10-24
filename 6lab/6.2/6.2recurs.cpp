#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void Create(int *a, const int size, const int Low, const int High, int i)
{
    a[i] = Low + rand() % (High - Low + 1);
    if (i < size - 1)
        Create(a, size, Low, High, i + 1);
}
void Print(int *a, const int size, int i)
{
    cout << setw(4) << a[i];
    if (i < size - 1)
        Print(a, size, i + 1);
    else
        cout << endl;
}
void SwapHalves(int *a, const int n, int i)
{
    int tmp = a[i];
    a[i] = a[n / 2 + i];
    a[n / 2 + i] = tmp;
    if (i < n / 2 - 1)
        SwapHalves(a, n, i + 1);
}
int main()
{
    srand((unsigned)time(NULL)); // ініціалізація генератора випадкових чисел
    const int n = 10;
    int a[n];
    int Low = -10;
    int High = 10;
    Create(a, n, Low, High, 0);
    Print(a, n, 0);
    SwapHalves(a, n, 0);
    Print(a, n, 0);
    return 0;
}