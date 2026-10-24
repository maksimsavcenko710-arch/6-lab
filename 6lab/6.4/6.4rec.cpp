#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

// 1. Рекурсивна функція формування масиву
void Create(int *a, const int size, const int Low, const int High, int i)
{
    a[i] = Low + rand() % (High - Low + 1);
    if (i < size - 1)
        Create(a, size, Low, High, i + 1);
}

// 2. Рекурсивна функція форматного виведення масиву у рядок
void Print(const int *a, const int size, int i)
{
    cout << setw(5) << a[i];
    if (i < size - 1)
        Print(a, size, i + 1);
    else
        cout << endl;
}

// 3. Рекурсивна функція обчислення добутку елементів з парними номерами
int ProductEvenIndex(const int *a, const int size, int i)
{
    if (i < size)
        return a[i] * ProductEvenIndex(a, size, i + 2);
    else
        return 1;
}

// 4. Допоміжні рекурсивні функції для суми між першим і останнім нулями
int FindFirstZero(const int *a, const int size, int i) // індекс першого нуля або -1
{
    if (i >= size)
        return -1;
    if (a[i] == 0)
        return i;
    return FindFirstZero(a, size, i + 1);
}

int FindLastZero(const int *a, int i) // індекс останнього нуля або -1
{
    if (i < 0)
        return -1;
    if (a[i] == 0)
        return i;
    return FindLastZero(a, i - 1);
}

int SumRange(const int *a, int from, int to) // сума елементів з індексами from..to-1
{
    if (from >= to)
        return 0;
    return a[from] + SumRange(a, from + 1, to);
}

int SumBetweenZeros(const int *a, const int size)
{
    int first = FindFirstZero(a, size, 0);
    int last = FindLastZero(a, size - 1);
    if (first != -1 && first < last) // є щонайменше два нулі
        return SumRange(a, first + 1, last);
    return 0;
}

// 5. Допоміжні рекурсивні функції для переставляння
int CopyNonNegative(const int *a, int *b, const int size, int i, int k) // копіює елементи >= 0, повертає нове k
{
    if (i >= size)
        return k;
    if (a[i] >= 0)
        b[k++] = a[i];
    return CopyNonNegative(a, b, size, i + 1, k);
}

int CopyNegative(const int *a, int *b, const int size, int i, int k) // копіює елементи < 0, повертає нове k
{
    if (i >= size)
        return k;
    if (a[i] < 0)
        b[k++] = a[i];
    return CopyNegative(a, b, size, i + 1, k);
}

void CopyArray(const int *from, int *to, const int size, int i) // копіювання масиву
{
    to[i] = from[i];
    if (i < size - 1)
        CopyArray(from, to, size, i + 1);
}

// спочатку додатні (і нулі), потім від'ємні, відносний порядок зберігається
void MovePositivesFirst(int *a, const int size)
{
    int *b = new int[size]; // допоміжний масив
    int k = CopyNonNegative(a, b, size, 0, 0);
    CopyNegative(a, b, size, 0, k);
    CopyArray(b, a, size, 0);
    delete[] b;
}

int main()
{
    srand((unsigned)time(NULL));

    int n;
    cout << "Введіть розмір масиву: ";
    cin >> n;
    if (n <= 0)
    {
        cout << "Розмір має бути додатним." << endl;
        return 1;
    }

    int *a = new int[n]; // динамічний масив
    int Low = -14;
    int High = 7;

    Create(a, n, Low, High, 0);

    cout << "Початковий масив:" << endl;
    Print(a, n, 0);

    cout << "Добуток елементів з парними номерами: "
         << ProductEvenIndex(a, n, 0) << endl;
    cout << "Сума між першим і останнім нулем: "
         << SumBetweenZeros(a, n) << endl;

    MovePositivesFirst(a, n); // змінює масив

    cout << "Масив після переставляння (спочатку додатні, потім від'ємні):" << endl;
    Print(a, n, 0);

    delete[] a; // звільнення пам'яті
    return 0;
}