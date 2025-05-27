#pragma once
#include <iostream>
using namespace std;

template<typename T>
class Parallelepiped {
protected:
    T a, b, h;
public:
    Parallelepiped(T value_a = 2, T value_b = 1, T value_h = 1)
    {
        a = (value_a > 0) ? value_a : 2;
        b = (value_b > 0) ? value_b : 1;
        h = (value_h > 0) ? value_h : 1;
        if (a == b && b == h || a <= 0 || b <= 0 || h <= 0)
        {
            a = 2;
            b = 1;
            h = 1;
        }
    }
    ~Parallelepiped() {}

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
        if (value  > 0 && (b != value || h != value)) {
            setA(value);
            cout << "Ustanovleno novoe znachenie dlini\n";
        } else cout << "Nekorrectniy vvod, znachenie ne ustanovleno\n";
    }

    void changeB(T value) {
        if (value > 0 && (a != value || h != value)) {
            setB(value);
            cout << "Ustanovleno novoe znachenie shirini\n";
        } else cout << "Nekorrectniy vvod, znachenie ne ustanovleno\n";
    }

    void changeH(T value) {
        if (value > 0 && (a != value || b != value )) {
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