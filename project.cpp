#include <iostream>
#include <string>
#include <sstream>
#include <type_traits> 
#include "Parallelepiped.h"
#include "Kub.h"
#include "Kvadrat.h"
#include "Rectangle.h"
using namespace std;

//ввод чисел
int Get_number()
{
    int input;
    while (true) {
        cin >> input;
        if (cin.fail()) {
            cout << "Некорректный ввод. Пожалуйста, введите целое число: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else {
            return input;
        }
    }
}
double Get_double() {
    double input;
    while (true) {
        cin >> input;
        if (cin.fail() || input <= 0) {
            system("cls");
            cout << "Некорректный ввод. Пожалуйста, введите положительное число: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else {
            return input;
        }
    }
}

//менюшки
void parMenu() {
    cout << "\n--- МЕНЮ ПАРАЛЛЕЛЕПИПЕДА ---";
    cout << "\n1 - показать текущие размеры";
    cout << "\n2 - изменить длину";
    cout << "\n3 - изменить ширину";
    cout << "\n4 - изменить высоту";
    cout << "\n5 - найти площадь поверхности";
    cout << "\n6 - найти объём";
    cout << "\n0 - выход\n";
}
void cubeMenu() {
    cout << "\n--- МЕНЮ КУБА ---";
    cout << "\n1 - показать сторону";
    cout << "\n2 - изменить сторону";
    cout << "\n3 - найти площадь поверхности";
    cout << "\n4 - найти объём";
    cout << "\n5 - найти радиус описанной окружности";
    cout << "\n0 - выход\n";
}
void squareMenu() {
    cout << "\n--- МЕНЮ КВАДРАТА ---";
    cout << "\n1 - показать сторону";
    cout << "\n2 - изменить сторону";
    cout << "\n3 - найти площадь";
    cout << "\n4 - найти радиус описанной окружности";
    cout << "\n0 - выход\n";
}
void rectangleMenu() {
    cout << "\n--- МЕНЮ ПРЯМОУГОЛЬНИКА ---";
    cout << "\n1 - показать размеры";
    cout << "\n2 - изменить длину";
    cout << "\n3 - изменить ширину";
    cout << "\n4 - найти площадь";
    cout << "\n5 - найти периметр";
    cout << "\n6 - найти радиус описанной окружности";
    cout << "\n0 - выход\n";
}

//функции
template<typename T>
Parallelepiped<T> createParallelepiped() {
    while (true) {
        cout << "Вы хотите использовать значения по умолчанию? \n1 - да \n2 - нет\n> ";
        int defchoice = Get_number();

        if (defchoice == 1) {
            return Parallelepiped<T>();
        }
        else if (defchoice == 2) {
            T a, b, h;
            cout << "Введите длины сторон (a b h): ";
            if constexpr (is_same<T, int>::value) {
                a = Get_number(); b = Get_number(); h = Get_number();
            }
            else {
                a = Get_double(); b = Get_double(); h = Get_double();
            }
            return Parallelepiped<T>(a, b, h);
        }
        else {
            system("cls");
            cout << "Неверный ввод. Повторите попытку.\n";
        }
    }
}
template<typename T>
Kub<T> createKub() {
    while (true) {
        cout << "Вы хотите использовать значения по умолчанию? \n1 - да \n2 - нет\n> ";
        int defchoice = Get_number();

        if (defchoice == 1) {
            return Kub<T>();
        }
        else if (defchoice == 2) {
            T a;
            cout << "Введите длину стороны: ";
            if constexpr (is_same<T, int>::value) {
                a = Get_number();
            }
            else {
                a = Get_double();
            }
            return Kub<T>(a);
        }
        else {
            system("cls");
            cout << "Неверный ввод. Повторите попытку.\n";
        }
    }
}
template<typename T>
Square<T> createSquare() {
    while (true) {
        cout << "Вы хотите использовать значения по умолчанию? \n1 - да \n2 - нет\n> ";
        int defchoice = Get_number();

        if (defchoice == 1) {
            return Square<T>();
        }
        else if (defchoice == 2) {
            T a;
            cout << "Введите длину стороны: ";
            if constexpr (is_same<T, int>::value) {
                a = Get_number();
            }
            else {
                a = Get_double();
            }
            return Square<T>(a);
        }
        else {
            system("cls");
            cout << "Неверный ввод. Повторите попытку.\n";
        }
    }
}
template<typename T>
Rectangle<T> createRectangle() {
    while (true) {
        cout << "Вы хотите использовать значения по умолчанию? \n1 - да \n2 - нет\n> ";
        int defchoice = Get_number();

        if (defchoice == 1) {
            return Rectangle<T>();
        }
        else if (defchoice == 2) {
            T a, b;
            cout << "Введите длину стороны: ";
            if constexpr (is_same<T, int>::value) {
                a = Get_number(); b = Get_number();
            }
            else {
                a = Get_double(); b = Get_double();
            }
            return Rectangle<T>(a, b);
        }
        else {
            system("cls");
            cout << "Неверный ввод. Повторите попытку.\n";
        }
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Привет!Представляем Вам наш проект!!!\n";
    while (true)
    {
        
        cout << "Выберите фигуру:\n1 - Параллелепипед\n2 - Куб\n3 - Квадрат\n4 - Прямоугольник\n0 - Выход\n> ";
        int choice = Get_number();
        if (choice < 0 || choice > 4) { system("cls"); cout << "Неверный ввод. Повторите: \n"; continue; }
        if (choice == 0) break;
        cout << "Выберите тип данных:\n1 - int\n2 - double\n> ";
        int typeChoice = Get_number();
        if (typeChoice != 1 && typeChoice != 2)
        {
            system("cls");
            cout << "Неправильный ввод. Возвращение в меню..\n";
            continue;
        }

        // Параллелепипед
        if (choice == 1) {
            if (typeChoice == 1) {
                Parallelepiped<int> p = createParallelepiped<int>();
                int act;
                do {
                    parMenu();
                    act = Get_number();
                    switch (act) {
                    case 1: system("cls"); p.show(); break;
                    case 2: system("cls"); cout << "Новая длина: "; p.changeA(Get_number()); break;
                    case 3: system("cls"); cout << "Новая ширина: "; p.changeB(Get_number()); break;
                    case 4: system("cls"); cout << "Новая высота: "; p.changeH(Get_number()); break;
                    case 5: system("cls"); p.findSquare(); break;
                    case 6: system("cls"); p.findVolume(); break;
                    case 0: system("cls"); break;
                    default: system("cls"); cout << "Неверный номер.\n"; break;
                    }
                } while (act != 0);
            }
            else {
                Parallelepiped<double> p = createParallelepiped<double>();
                int act;
                do {
                    parMenu();
                    act = Get_number();
                    switch (act) {
                    case 1: system("cls"); p.show(); break;
                    case 2: system("cls"); cout << "Новая длина: "; p.changeA(Get_double()); break;
                    case 3: system("cls"); cout << "Новая ширина: "; p.changeB(Get_double()); break;
                    case 4: system("cls"); cout << "Новая высота: "; p.changeH(Get_double()); break;
                    case 5: system("cls"); p.findSquare(); break;
                    case 6: system("cls"); p.findVolume(); break;
                    case 0: system("cls"); break;
                    default: system("cls"); cout << "Неверный номер.\n"; break;
                    }
                } while (act != 0);
            }
        }

        // Куб
        else if (choice == 2) {
            if (typeChoice == 1) {
                Kub<int> k = createKub<int>();
                int act;
                do {
                    cubeMenu();
                    act = Get_number();
                    switch (act) {
                    case 1: system("cls"); k.show(); break;
                    case 2: system("cls"); cout << "Введите новую сторону: "; k.changeSide(Get_number()); break;
                    case 3: system("cls"); k.findSquare(); break;
                    case 4: system("cls"); k.findVolume(); break;
                    case 5: system("cls"); k.findRadius(); break;
                    case 0: system("cls"); break;
                    default: system("cls"); cout << "Неверный номер.\n"; break;
                    }
                } while (act != 0);
            }
            else {
                Kub<double> k = createKub<double>();
                int act;
                do {
                    cubeMenu();
                    act = Get_number();
                    switch (act) {
                    case 1: system("cls"); k.show(); break;
                    case 2: system("cls"); cout << "Введите новую сторону: "; k.changeSide(Get_double()); break;
                    case 3: system("cls"); k.findSquare(); break;
                    case 4: system("cls"); k.findVolume(); break;
                    case 5: system("cls"); k.findRadius(); break;
                    case 0: system("cls"); break;
                    default: system("cls"); cout << "Неверный номер.\n"; break;
                    }
                } while (act != 0);
            }
        }

        // Квадрат
        else if (choice == 3) {
            if (typeChoice == 1) {
                Square<int> square = createSquare<int>();
                int act;
                do {
                    squareMenu();
                    act = Get_number();
                    switch (act) {
                    case 1: system("cls"); square.show(); break;
                    case 2: system("cls"); cout << "Введите новую сторону: "; square.changet(Get_number()); break;
                    case 3: system("cls"); square.findSquare(); break;
                    case 4: system("cls"); square.findRadius(); break;
                    case 0: system("cls"); break;
                    default: system("cls"); cout << "Неверный номер.\n"; break;
                    }
                } while (act != 0);
            }
            else {
                Square<double> square = createSquare<double>();
                int act;
                do {
                    squareMenu();
                    act = Get_number();
                    switch (act) {
                    case 1: system("cls"); square.show(); break;
                    case 2: system("cls"); cout << "Введите новую сторону: "; square.changet(Get_double()); break;
                    case 3: system("cls"); square.findSquare(); break;
                    case 4: system("cls"); square.findRadius(); break;
                    case 0: system("cls"); break;
                    default: system("cls"); cout << "Неверный номер.\n"; break;
                    }
                } while (act != 0);
            }
        }

        // Прямоугольник
        else if (choice == 4) {
            if (typeChoice == 1) {
                Rectangle<int> r = createRectangle<int>();
                int act;
                do {
                    rectangleMenu();
                    act = Get_number();
                    switch (act) {
                    case 1: system("cls"); r.show(); break;
                    case 2: system("cls"); cout << "Новая длина: "; r.changeA(Get_number()); break;
                    case 3: system("cls"); cout << "Новая ширина: "; r.changeB(Get_number()); break;
                    case 4: system("cls"); r.findSquare(); break;
                    case 5: system("cls"); r.printPerimeter(); break;
                    case 6: system("cls"); r.printCircumcircleRadius(); break;
                    case 0: system("cls"); break;
                    default: system("cls"); cout << "Неверный номер.\n"; break;
                    }
                } while (act != 0);
            }
            else {
                Rectangle<double> r = createRectangle<double>();
                int act;
                do {
                    rectangleMenu();
                    act = Get_number();
                    switch (act) {
                    case 1: system("cls"); r.show(); break;
                    case 2: system("cls"); cout << "Новая длина: "; r.changeA(Get_double()); break;
                    case 3: system("cls"); cout << "Новая ширина: "; r.changeB(Get_double()); break;
                    case 4: system("cls"); r.findSquare(); break;
                    case 5: system("cls"); r.printPerimeter(); break;
                    case 6: system("cls"); r.printCircumcircleRadius(); break;
                    case 0: system("cls"); break;
                    default: system("cls"); cout << "Неверный номер.\n"; break;
                    }
                } while (act != 0);
            }
        }

        cout << "\n";
    }

    cout << "До свидания!\n";
    return 0;
}