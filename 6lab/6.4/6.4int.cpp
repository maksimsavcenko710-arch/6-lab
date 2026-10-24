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

// 3. Функція обчислення добутку елементів з парними номерами
int ProductEvenIndex(const int *a, const int size)
{
    int dob = 1;
    for (int i = 0; i < size; i += 2)
        dob *= a[i];
    return dob;
}

// 4. Функція обчислення суми елементів між першим і останнім нулями
int SumBetweenZeros(const int *a, const int size)
{
    int first = -1, last = -1;

    for (int i = 0; i < size; i++) // перший нуль
        if (a[i] == 0)
        {
            first = i;
            break;
        }

    for (int i = size - 1; i >= 0; i--) // останній нуль
        if (a[i] == 0)
        {
            last = i;
            break;
        }

    int sum = 0;
    if (first != -1 && first < last) // є щонайменше два нулі
        for (int i = first + 1; i < last; i++)
            sum += a[i];
    return sum;
}

// 5. Функція переставляння: спочатку додатні (і нулі), потім від'ємні,
//    відносний порядок елементів зберігається
void MovePositivesFirst(int *a, const int size)
{
    int *b = new int[size]; // допоміжний масив
    int k = 0;

    for (int i = 0; i < size; i++) // спочатку елементи >= 0
        if (a[i] >= 0)
            b[k++] = a[i];

    for (int i = 0; i < size; i++) // потім елементи < 0
        if (a[i] < 0)
            b[k++] = a[i];

    for (int i = 0; i < size; i++) // копіюємо назад
        a[i] = b[i];

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
    int Low = -5;
    int High = 5;

    Create(a, n, Low, High);

    cout << "Початковий масив:" << endl;
    Print(a, n);

    cout << "Добуток елементів з парними номерами: "
         << ProductEvenIndex(a, n) << endl;
    cout << "Сума між першим і останнім нулем: "
         << SumBetweenZeros(a, n) << endl;

    MovePositivesFirst(a, n); // змінює масив

    cout << "Масив після переставляння (спочатку додатні, потім від'ємні):" << endl;
    Print(a, n);

    delete[] a; // звільнення пам'яті
    return 0;
}