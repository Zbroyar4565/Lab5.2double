#include <iostream>
#include <math.h>
#include <iomanip>
#include <Windows.h>
using namespace std;

double Sum(const double x, const double eps, int& n, double s);
double A(const double x, const int n, double a);
const double PI_2 = 2.0 * atan(1.0);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);


    double x, xp, xk, dx, eps, S = 0;
    int n = 0;
    cout << "Введіть початковe значення x: ";
    cin >> xp;
    cout << "Введіть кінцеве значення x: ";
    cin >> xk;
    cout << "Введіть крок x: ";
    cin >> dx;
    cout << "Введіть точність eps: ";
    cin >> eps;

    cout << fixed;
    cout << "---------------------------------------------------------" << endl;
    cout << "|" << setw(7) << "x" << " |"
        << setw(12) << "acos(x)" << " |"
        << setw(12) << "Сума ряду" << " |"
        << setw(5) << "n" << " |"
        << endl;
    cout << "---------------------------------------------------------" << endl;
    x = xp;
    while (x <= xk)
    {
        S = Sum(x, eps, n, S);
        cout << "|" << setw(7) << setprecision(5) << x << " |"
            << setw(12) << setprecision(5) << acos(x) << " |"
            << setw(12) << setprecision(5) << S << " |"
            << setw(5) << n << " |" << endl;
        x += dx;
    }
}

double Sum(const double x, const double eps, int& n, double s)
{
    n = 0;
    double a = x;
    s = a;
    do
    {
        n++;
        a = A(x, n, a);
        s += a;
    } while (abs(a) >= eps);
    s = PI_2 - s;
    return s;
}

double A(const double x, const int n, double a)
{
    double r = (pow(x, 2.0) * pow(2.0 * n - 1, 2.0))
        / (2.0 * n * (2.0 * n + 1.0));
    a *= r;
    return a;
}