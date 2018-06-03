// Copyright 2018 Generalov Aleksandr

#include "include/Cone.h"

#include <string>
#include <sstream>


const double pi = 3.14;

Cone::Cone() : radius(0), h(0) {}

Cone::Cone(const double& _rad, const double& _h) {
    if (!negativeNumbers(_rad, _h)) {
        radius = _rad;
        h = _h;
    } else {
        throw std::string("Number can't be less then zero");
    }
}

Cone::Cone(const Cone & _c)
           : radius(_c.getRad()), h(_c.getH()) {}

Cone & Cone::operator=(const Cone & _c) {
    radius = _c.radius;
    h = _c.h;

    return *this;
}

double Cone::getRad() const {
    return radius;
}

double Cone::getH() const {
    return h;
}

void Cone::setRad(const double _rad) {
    radius = _rad;
}

void Cone::setH(const double _h) {
    h = _h;
}

bool Cone::operator==(const Cone & _c) const {
    return radius == _c.getRad() && h == _c.getH();
}

bool Cone::operator!=(const Cone & _c) const {
    return !(*this == _c);
}

double Cone::areaCone() const {
    return pi * radius * (radius + h);
}

bool Cone::negativeNumbers(const double _rad, const double _h) {
    return _rad < 0 || _h < 0;
}
