#pragma once
#include "Parallelepiped.h"
#include <cmath>

template<typename T>
class Kub : public Parallelepiped<T> {
public:
    
    Kub(T side) : Parallelepiped<T>(side, side, side) {}

    void changeSide(T value) {
        if (value > 0) {
            this->a = this->b = this->h = value;
            cout << "Ustanovleno novoe znachenie storoni kuba\n";
        }
        else {
            cout << "Nekorrectnoe znachenie. Storona dolshna bit' poloshitel'noy\n";
        }
    }

    void findRadius() {
        cout << "Radius opisannoy okruzhnosti: " << sqrt(3 * this->a * this->a) / 2 << endl;
    }

    void findSquare() override {
        cout << "Ploshad' poverhnosti kuba: " << 6 * this->a * this->a << endl;
    }

    void findVolume() override {
        cout << "Ob'em kuba: " << this->a * this->a * this->a << endl;
    }

    void show() {
        cout << "\nStorona kuba: " << this->a << endl;
    }
};