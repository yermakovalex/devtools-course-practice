// Copyright 2018 Levitsky Ilya

#include <gtest/gtest.h>

#include "include/set.h"

TEST(Levitsky_Ilya_setTest, Can_Create_Set) {
  // Arrange
  set A;

  // Act
  A.Insert(5);

  // Assert
  EXPECT_EQ(5, A.GetN(5));
}

TEST(Levitsky_Ilya_setTest, Disjunctio_Sets) {
  // Arrange
  set A;
  set B;
  set C;

  A.Insert(4);
  B.Insert(7);

  // Act
  C = A + B;

  // Assert
  EXPECT_EQ(4, C.GetN(4));
  EXPECT_EQ(7, C.GetN(7));
}

TEST(Levitsky_Ilya_setTest, Conjuctio_Sets) {
  // Arrange
  set A;
  set B;
  set C;

  A.Insert(2);
  A.Insert(4);
  A.Insert(6);

  B.Insert(3);
  B.Insert(4);
  B.Insert(9);
  B.Insert(6);

  // Act
  C = A*B;

  // Assert
  EXPECT_EQ(4, C.GetN(4));
  EXPECT_EQ(6, C.GetN(6));
}

TEST(Levitsky_Ilya_setTest, Addition_Set) {
  // Arrange
  set A;
  set C;

  A.Insert(5);
  A.Insert(4);
  A.Insert(6);
  A.Insert(3);
  A.Insert(2);

  // Act
  C = ~A;

  // Assert
  EXPECT_EQ(1, C.GetN(1));
  EXPECT_EQ(7, C.GetN(7));
  EXPECT_EQ(8, C.GetN(8));
  EXPECT_EQ(9, C.GetN(9));
  EXPECT_EQ(10, C.GetN(10));
}
