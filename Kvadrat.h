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
            cout << "����������� ����� �������� ������� ��������\n";
        }
        else {
            cout << "������������ ��������. ������� ������ ���� �������������\n";
        }
    }

    void findRadius() {
        cout << "������ ��������� ����������: " << this->a * sqrt(2) / 2 << endl;
    }

    void findSquare() override {
        cout << "������� ��������: " << this->a * this->a << endl;
    }

    void show() {
        cout << "������� ��������: " << this->a << endl;
    }
};