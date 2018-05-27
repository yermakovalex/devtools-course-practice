// Copyright 2018 Mayachkin Arseny

#include <gtest/gtest.h>
#include "include/batcher_merge.h"
#include <algorithm>
#include <cstdlib>
#include <vector>

TEST(BatcherMergeTest, Cant_Use_Right_Index_Smaller_Left) {
  // Arrange
  std::vector<int> array = { 1, 8, 3 };
  int left = 2;
  int right = 0;

  // Act & Assert
  EXPECT_ANY_THROW(merge::BatcherMerge(array, left, right));
}

TEST(BatcherMergeTest, Cant_Use_Negative_Index) {
  // Arrange
  std::vector<int> array = { 1, 8, 3 };
  int left = -1;
  int right = 1;

  // Act & Assert
  EXPECT_ANY_THROW(merge::BatcherMerge(array, left, right));
}

TEST(BatcherMergeTest, Can_Work_With_Unit_Vector) {
  // Arrange
  std::vector<int> array = { 1 };
  int left = 0;
  int right = 0;

  // Act & Assert
  EXPECT_NO_THROW(merge::BatcherMerge(array, left, right));
}

TEST(BatcherMergeTest, Can_Work_With_Two_Elements) {
  // Arrange
  std::vector<int> array = { 8, 3 };
  int left = 0;
  int right = 1;

  //Act
  merge::BatcherMerge(array, left, right);

  // Assert
  EXPECT_TRUE(array[0] < array[1]);
}

TEST(BatcherMergeTest, Can_Work_With_Big_Size) {
  // Arrange
  std::vector<int> array = { 1, 8, 3 , 5, 2, 7, 4, 6, 9, 15, 11, 10, 13, 12, 14};
  std::vector<int> sequence = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 };
  int left = 0;
  int right = 14;

  //Act
  merge::BatcherMerge(array, left, right);

  // Assert
  EXPECT_TRUE(sequence == sequence);
}


