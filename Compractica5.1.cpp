// Compractica5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include<cmath>

using namespace std;

double cosTaylor(double a);

int main()
{
    double x=-2;
    double finalx=2;
    double step=0.5;
    double y;
    double error;

    for (x = -2; x <= finalx; x = x + step)
    {
        if (x < -1)
        {
            cout<<"Undefined function" << endl;
        }
        else if (x <= 0)
        {
            y = cosTaylor(x / 2) / cosTaylor(pow(x, 2));

            error = fabs(cos(x / 2) / cos(pow(x, 2)) - y);

            cout << "x = " << x << " y = " << y << endl;
            cout << "error = " << error << endl;
        }
        else
        {
            y = pow(cosTaylor(x / 2), 2) * cosTaylor(2 * x);

            error = fabs(pow(cos(x / 2), 2) * cos(2 * x) - y);

            cout << "x = " << x << " y = " << y << endl;
            cout << "error = " << error << endl;
        }
      
    }
}
double cosTaylor(double a)
{
    double sum = 1;
    int i = 1;
    double member = 1;
    while (fabs(member) > 0.00001)
    {
        member = member * (-a * a) / (2 * i * (2 * i - 1));
        sum = sum + member;
        i++;
    }
    return sum;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
