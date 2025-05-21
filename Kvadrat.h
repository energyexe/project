#pragma once
#include "Kub.h"
#include <cmath>
#include <iostream>
using namespace std;

template<typename T>
class Square : public Kub<T> {
public:
    Square(T side) : Kub<T>(side) {}

    void changet(T value) {
        if (value > 0) {
            this->a = value;
            cout << "Установлено новое значение стороны квадрата\n";
        }
        else {
            cout << "Некорректное значение. Сторона должна быть положительной\n";
        }
    }

    void findRadius() {
        cout << "Радиус описанной окружности: " << this->a * sqrt(2) / 2 << endl;
    }

    void findSquare() override {
        cout << "Площадь квадрата: " << this->a * this->a << endl;
    }

    void show() {
        cout << "Сторона квадрата: " << this->a << endl;
    }
};