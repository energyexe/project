#pragma once
#include <iostream>
using namespace std;

template<typename T>
class Parallelepiped {
protected:
    T a, b, h;
public:
    Parallelepiped(T value_a, T value_b, T value_h) {
        a = value_a;
        b = value_b;
        h = value_h;
    }

    void setA(T value) { a = value; }
    void setB(T value) { b = value; }
    void setH(T value) { h = value; }

    T getA() { return a; }
    T getB() { return b; }
    T getH() { return h; }

    virtual void show() {
        cout << "\nDlina - " << a;
        cout << "\nShirina - " << b;
        cout << "\nVisota - " << h << "\n";
    }

    void changeA(T value) {
        if (value >= b) {
            setA(value);
            cout << "Ustanovleno novoe znachenie dlini\n";
        } else cout << "Nekorrectniy vvod, znachenie ne ustanovleno\n";
    }

    void changeB(T value) {
        if (value <= a) {
            setB(value);
            cout << "Ustanovleno novoe znachenie shirini\n";
        } else cout << "Nekorrectniy vvod, znachenie ne ustanovleno\n";
    }

    void changeH(T value) {
        if (value > 0) {
            setH(value);
            cout << "Ustanovleno novoe znachenie visoti\n";
        } else cout << "Nekorrectniy vvod, znachenie ne ustanovleno\n";
    }

    virtual void findSquare() {
        cout << "Ploshad' poverhnosti parallelepipeda: " << 2 * (a * b + a * h + b * h) <<"\n";
    }

    virtual void findVolume() {
        cout << "Ob'em parallelepipeda: " << a * b * h << "\n";
    }
};