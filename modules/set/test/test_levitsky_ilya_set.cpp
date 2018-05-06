// Copyright 2018 Levitsky Ilya

#include <gtest/gtest.h>

#include "include/set.h"

TEST(Levitsky_Ilya_setTest, Can_Create_Set) {
  // Arrange
  set A;
  int x;

  // Act
  A.Insert(x);

  // Assert
  EXPECT_EQ(x, A.Get(1));
}

TEST(Levitsky_Ilya_setTest, Disjunctio_Sets) {
  // Arrange
  set A;
  set B;
  set C;

  A.insert(4);
  B.insert(7);

  // Act
  C = A + B;

  // Assert
  EXPECT_EQ(4, C.Get(4));
  EXPECT_EQ(7, C.Get(7));
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
  EXPECT_EQ(4, C.Get(4));
  EXPECT_EQ(6, C.Get(6));
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
  EXPECT_EQ(1, C.Get(1));
  EXPECT_EQ(7, C.Get(7));
  EXPECT_EQ(8, C.Get(8));
  EXPECT_EQ(9, C.Get(9));
  EXPECT_EQ(10, C.Get(10));
}

TEST(Levitsky_Ilya_setTest, Delete_Element) {
  // Arrange
  set A;

  A.Insert(5);
  A.Insert(8);

  // Act
  A.Del(5);

  // Assert
  ASSERT_FALSE(5, A.Get(5));
  EXPECT_EQ(8, C.Get(8));
}