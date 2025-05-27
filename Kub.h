#pragma once
#include "Parallelepiped.h"
#include <cmath>

template<typename T>
class Kub : public Parallelepiped<T> {
public:
    
    Kub(T side=2) : Parallelepiped<T>(side, 0, 0) {}

    void changeSide(T value) {
        if (value > 0) {
            this->a = value;
            cout << "Ustanovleno novoe znachenie storoni kuba\n";
        }
        else {
            cout << "Nekorrectnoe znachenie. Storona dolshna bit' poloshitel'noy\n";
        }
    }

    void findRadius() {
        cout << "Radius opisannoy okruzhnosti: " << (sqrt(2)* this->a) / 2 << endl;
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