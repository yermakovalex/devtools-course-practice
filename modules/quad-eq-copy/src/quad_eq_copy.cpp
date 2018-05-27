// Copyright 2018 Chvanov Leonid

#include "include/quad_eq_copy.h"

#include <math.h>
#include <stdexcept>
#include <vector>

quadraticEquation::quadraticEquation(const double& _a,
                                     const double& _b,
                                     const double& _c) {
    this->setCoefficients(_a, _b, _c);
}

quadraticEquation::~quadraticEquation() { }

std::vector<double> quadraticEquation::getRoots() {
    if (isSolved) {
        if (this->hasRealRoots())
            return roots;
        else
            throw std::runtime_error(
                  "Quadratic equation has no real roots");
    } else {
        this->solve();
        return this->getRoots();
    }
}

void quadraticEquation::setCoefficients(const double& _a,
                                        const double& _b,
                                        const double& _c) {
    if (_a == 0.f)
        throw std::invalid_argument(
            "Quadratic coefficient can't be null");
    a = _a; b = _b; c = _c;
    discriminant = b*b - 4 * a*c;
    isSolved = false;
    roots.clear();
}

void quadraticEquation::solve() {
    if (!isSolved) {
        if (discriminant > 0) {
            roots.push_back((-b - sqrt(discriminant)) / (2 * a));
            roots.push_back((-b + sqrt(discriminant)) / (2 * a));
        } else if (discriminant == 0) {
            roots.push_back((-b - sqrt(discriminant)) / (2 * a));
        }
    }
    isSolved = true;
}

bool quadraticEquation::hasRealRoots() const {
    return (discriminant >= 0);
}
