#include <iostream>
#include <cmath>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

double devide(int, int);
long mult(int, int);

int main()
{
    cout << "Здравствуйте, как вас зовут?" << endl;
    string fullName;
    cin >> fullName;

    cout << "Приятно познакомиться, " + fullName + ". Начнём нашу первую тренировку.\n"
         << "Это азы, основы основ - делай всё неспеша и вдумчиво." << endl;
    int a = 0, b = 0;
    cout << "\nВведи 2 целых числа a и b, которые будут диапазоном [a,b] "
            <<"(предельные значения: [-10, 10], a не должно равняться b): " << endl;
    cin >> a >> b;
    while (a < -10 || a > 10 || b < -10 ||  b > 10 || a >= b) {

        if (a < -10)
            cout << "Ты невнимательный: a меньше, чем -10. Попробуй снова: \n";
        else if (a > 10)
            cout << "Ты невнимательный: a больше, чем 10. Попробуй снова: \n";
        else if (b < -10)
            cout << "Ты невнимательный: b меньше, чем -10. Попробуй снова: \n";
        else if (b > 10)
            cout << "Ты невнимательный: b больше, чем 10. Попробуй снова: \n";
        else if (a > b)
            cout << "Ты невнимательный: a больше, чем b. Попробуй снова: \n";
        else
            cout << "Ты невнимательный: a совпадает со значением b. Попробуй снова: \n";
        cin >> a >> b;
    }

    cout << "===================" << "Молодец" <<"============================" << endl;
    cout << "Теперь выбери одну из операций:\n"
         << "1. Посчитать сумму чисел в диапазоне [" << a << "," << b << "]" << endl
         << "2. Посчитать произведение чисел в диапазоне [" << a << "," << b << "]" << endl
         << "3. Посчитать частное чисел " << a << " и " << b << endl
         << "4. Узнать чему равен квадратный корень из 888" << endl;

    int choice = 0;
    cin >> choice;
    cout << "===================" << "Результат" <<"============================" << endl;
    switch (choice)
    {
    case 1 :
    {
        int sum = 0;
        for (int i = a; i < b + 1; ++i)
            sum += i;
        cout << "sum([a, b]) = " << sum << endl;
        break;
    }
    case 2 :
    {
        cout << "mult([a, b]) = " << mult(a, b) << endl;
        break;
    }
    case 3 :
    {
        cout << "a / b = " << devide(a, b) << endl;
        break;
    }
    case 4 :
    {
        cout << "Квадратный корень из 888 равен " << sqrt(888) << endl;
        break;
    }
    default :
        cout << "Нет такой операции." << endl;
        break;

    }

    cout << "Пока!" << endl;

    cin.get();
    cin.get();

    return 0;
}


long mult(int a, int b)
{
    if (a + b <= b)
        return 0;
    long m = a;
    for (int i = a + 1; i < b + 1; ++i)
        m *= i;
    return m;
}


double devide(int a, int b)
{
    return (double)a / b;
}
