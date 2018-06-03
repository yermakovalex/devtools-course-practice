// Copyright 2018 Chvanov Leonid

#ifndef MODULES_QUAD_EQ_COPY_INCLUDE_QUAD_EQ_COPY_H_
#define MODULES_QUAD_EQ_COPY_INCLUDE_QUAD_EQ_COPY_H_

#include <vector>

class quadraticEquation {
 public:
     quadraticEquation(const double& _a,
                       const double& _b,
                       const double& _c);
     ~quadraticEquation();

     std::vector<double> getRoots();
     void setCoefficients(const double& _a,
                          const double& _b,
                          const double& _c);
     void solve();
     std::vector<double> roots;
     double discriminant;

 private:
     double a, b, c;  // coefficients of equation

     bool isSolved;

     bool hasRealRoots() const;
};

#endif  // MODULES_QUAD_EQ_COPY_INCLUDE_QUAD_EQ_COPY_H_
