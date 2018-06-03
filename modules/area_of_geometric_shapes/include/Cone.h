// Copyright 2018 Generalov Aleksandr

#ifndef MODULES_AREA_OF_GEOMETRIC_SHAPES_INCLUDE_CONE_H_
#define MODULES_AREA_OF_GEOMETRIC_SHAPES_INCLUDE_CONE_H_

class Cone {
 public:
    Cone();
    Cone(const double& _rad, const double& _h);
    Cone(const Cone& _c);

    Cone& operator=(const Cone& _c);

    double getRad() const;
    double getH() const;
    void setRad(const double _rad);
    void setH(const double _h);

    bool operator==(const Cone& _c) const;
    bool operator!=(const Cone& _c) const;

    double areaCone() const;
 private:
    bool negativeNumbers(const double _rad, const double _h);
    double radius;
    double h;
};

#endif  // MODULES_AREA_OF_GEOMETRIC_SHAPES_INCLUDE_CONE_H_
