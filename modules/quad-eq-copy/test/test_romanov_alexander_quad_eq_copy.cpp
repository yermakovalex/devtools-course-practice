// Copyright 2018 Chvanov Leonid

#include <gtest/gtest.h>

#include <vector>

#include "include/quad_eq_copy.h"

TEST(Chvanov_Leonid_QuadraticEquationTest,
     Able_Create_Quadratic_Equation) {
    // AAA
    ASSERT_NO_THROW(quadraticEquation q(1, 1, 1));
}

TEST(Chvanov_Leonid_QuadraticEquationTest,
    Throw_Quadratic_Coefficient_Zero) {
    // AAA
    ASSERT_ANY_THROW(quadraticEquation q(0, 1, 1));
}

TEST(Chvanov_Leonid_QuadraticEquationTest,
    Able_Get_Roots) {
    // Arrange
    quadraticEquation q(1, -2, -3);
    std::vector<double> roots;

    // Act and assert
    ASSERT_NO_THROW(roots = q.getRoots());
}

TEST(Chvanov_Leonid_QuadraticEquationTest,
    Able_Get_Roots_Multiple_Times) {
    // Arrange
    quadraticEquation q(1, -2, -3);
    std::vector<double> roots;

    // Act
    q.getRoots();

    // Assert
    ASSERT_NO_THROW(q.getRoots());
}

TEST(Chvanov_Leonid_QuadraticEquationTest,
    Able_Get_Correct_Roots) {
    // Arrange
    quadraticEquation q(1, -2, -3);
    std::vector<double> roots;

    // Act
    roots.push_back(-1);
    roots.push_back(3);

    // Assert
    EXPECT_EQ(roots, q.getRoots());
}

TEST(Chvanov_Leonid_QuadraticEquationTest,
    Returns_One_Root_Discriminant_Zero) {
    // Arrange
    quadraticEquation q(1, -2, 1);
    std::vector<double> roots;

    // Act
    roots.push_back(1);

    // Assert
    EXPECT_EQ(roots, q.getRoots());
}

TEST(Chvanov_Leonid_QuadraticEquationTest,
    Throws_If_No_Real_Roots) {
    // Arrange
    quadraticEquation q(1, -2, 2);

    // Act and assert
    ASSERT_ANY_THROW(q.getRoots());
}

TEST(Chvanov_Leonid_QuadraticEquationTest,
    Able_Set_Corfficients) {
    // Arrange
    quadraticEquation q(1, -2, 2);

    // Act and assert
    ASSERT_NO_THROW(q.setCoefficients(1, -2, 2));
}

TEST(Chvanov_Leonid_QuadraticEquationTest,
    Setting_Coefficients_Changes_Roots) {
    // Arrange
    quadraticEquation q(1, -2, 1);
    std::vector<double> roots;

    // Act
    roots = q.getRoots();
    q.setCoefficients(1, -2, -3);

    // Assert
    EXPECT_NE(roots, q.getRoots());
}
