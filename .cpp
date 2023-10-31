#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void Create(int* a, const int n, const int Low, const int High)
{
    for (int i = 0; i < n; i++)
        a[i] = Low + rand() % (High - Low + 1);
}

void Print(int* a, const int n)
{
    for (int i = 0; i < n; i++)
        cout << "a[" << setw(2) << i << " ] = " << setw(4) << a[i] << endl;
    cout << endl;
}

int Sum(int* a, const int n)
{
    int S = 0;
    for (int i = 0; i < n; i++)
        if (a[i] % 2 != 0) // Перевірка на непарність
            S += a[i];
    return S;
}
double AverageOfOddElements(int* a, const int n)
{
    int sum = 0;
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2 != 0)
        {
            sum += a[i];
            count++;
        }
    }

    if (count == 0)
    {
        cerr << "У векторі немає непарних елементів." << endl;
        return 0.0;
    }

    return static_cast<double>(sum) / count;
}

int main()
{
    srand((unsigned)time(NULL)); // ініціалізація генератора випадкових чисел
    const int n = 5;
    int a[n];
    int Low = -20;
    int High = 30;
    Create(a, n, Low, High);
    Print(a, n);
    cout << "Sum of odd elements = " << Sum(a, n) << endl;
    cout << "mid" << AverageOfOddElements(a, n) << endl;
    return 0;
}
