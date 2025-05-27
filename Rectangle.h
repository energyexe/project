#pragma once
#include <iostream>
using namespace std;

template<typename T>
class Rectangle : public Parallelepiped<T> {
public:

    Rectangle (T value_a=2, T value_b=1) : Parallelepiped<T>(value_a, value_b, 0) {}

    void setA(T value) { this->a = value; }
    void setB(T value) { this->b = value; }

    T getA() { return this->a; }
    T getB() { return this->b; }

    void show() {
        cout << "\nдлина - " << this->a;
        cout << "\nширина - " << this->b << '\n';
    }

    void changeSides(T value_a, T value_b) {
        if (value_a > 0 && value_b > 0) {
            setA(value_a);
            setB(value_b);
            cout << "Установлены новые значения длины и ширины.";
        }
        else {
            cout << "Значения должны быть положительными.";
        }
    }

    void changeA(T value) {
        if ((value > 0) && (this->b != value)) {
            setA(value);
            cout << "Установлено новое значение длины. \n";
        }
        else {
            cout << "Некорректный ввод, значение не установлено";
        }
    }

    void changeB(T value) {
        if ((value > 0) && (this->a != value)) {
            setB(value);
            cout << "Установлено новое значение ширины. \n";
        }
        else {
            cout << "Некорректный ввод, значение не установлено";
        }
    }

    void findSquare() {
        cout << "Площадь прямоугольника равна " << (this->a * this->b);
    }
    
    T findPerimeter() {
        return 2 * (this->a + this->b);
    }

    void printPerimeter() {
        cout << "Периметр прямоугольника равен " << findPerimeter() << "\n";
    }
    
    double findCircumcircleRadius() {
        return sqrt((double)(this->a * this->a + this->b * this->b)) / 2;
    }

    void printCircumcircleRadius() {
        cout << "Радиус описанной окружности равен " << findCircumcircleRadius() << "\n";
    }
};