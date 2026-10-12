// Lab 5_1
#include <iostream>
#include <cmath>
using namespace std;

double g(const double a, const double b);

int main()
{
    double s, t;
    cout << "s = ";
    cin >> s;
    cout << "t = ";
    cin >> t;

    double c = (g(2, s) + pow(1 + pow(g(t, 1), 2), 3)) / sqrt(1 + pow(g(s, t), 2));

    cout << "c = " << c << endl;
    return 0;
}

double g(const double a, const double b)
{
    return (a * b) / (a * a + b * b);
}