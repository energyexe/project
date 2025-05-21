#pragma once
#include <iostream>
using namespace std;

template<typename T>
class Rectangle {
protected:
    T a, b; 
public:
    Rectangle(T value_a = 1, T value_b = 1) {
        a = value_a;
        b = value_b;
    }
    ~Rectangle() {}

    void setA(T value) { a = value; }
    void setB(T value) { b = value; }

    T getA() { return a; }
    T getB() { return b; }

    void show() {
        cout << "\n����� - " << a;
        cout << "\n������ - " << b << '\n';
    }

    void changeSides(T value_a, T value_b) {
        if (value_a > 0 && value_b > 0) {
            setA(value_a);
            setB(value_b);
            cout << "����������� ����� �������� ����� � ������.";
        }
        else {
            cout << "�������� ������ ���� ��������������.";
        }
    }

    void changeA(T value) {
        if (value > 0) {
            setA(value);
            cout << "����������� ����� �������� �����. \n";
        }
        else {
            cout << "����� ������ ���� �������������, �������� �� �����������";
        }
    }

    void changeB(T value) {
        if (value > 0) {
            setB(value);
            cout << "����������� ����� �������� ������. \n";
        }
        else {
            cout << "������ ������ ���� �������������, �������� �� �����������";
        }
    }

    T findSquare() {
        return a * b;
    }

    void printSquare() {
        cout << "������� �������������� ����� " << findSquare() << "\n";
    }

    
    T findPerimeter() {
        return 2 * (a + b);
    }

    void printPerimeter() {
        cout << "�������� �������������� ����� " << findPerimeter() << "\n";
    }

    
    double findCircumcircleRadius() {
        return sqrt((double)(a * a + b * b)) / 2;
    }

    void printCircumcircleRadius() {
        cout << "������ ��������� ���������� ����� " << findCircumcircleRadius() << "\n";
    }
};