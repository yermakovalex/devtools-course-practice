// Copyright 2018 Mayachkin Arseny

#include <gtest/gtest.h>
#include <algorithm>
#include <vector>

#include "include/batcher_merge.h"

TEST(BatcherMergeTest, Cant_Use_Right_Index_Smaller_Left) {
  // Arrange
  std::vector<int> array = { 1, 8, 3 };
  int left = 2;
  int right = 0;
  BatcherMerge bat = BatcherMerge(array);

  // Act & Assert
  EXPECT_ANY_THROW(bat.merge(left, right););
}

TEST(BatcherMergeTest, Cant_Use_Negative_Index) {
  // Arrange
  std::vector<int> array = { 1, 8, 3 };
  int left = -1;
  int right = 1;
  BatcherMerge bat = BatcherMerge(array);

  // Act & Assert
  EXPECT_ANY_THROW(bat.merge(left, right););
}

TEST(BatcherMergeTest, Can_Work_With_Unit_Vector) {
  // Arrange
  std::vector<int> array = { 1 };
  int left = 0;
  int right = 0;
  BatcherMerge bat = BatcherMerge(array);

  // Act & Assert
  EXPECT_NO_THROW(bat.merge(left, right););
}

TEST(BatcherMergeTest, Can_Work_With_Two_Elements) {
  // Arrange
  std::vector<int> array = { 8, 3 };
  int left = 0;
  int right = 1;
  BatcherMerge bat = BatcherMerge(array);

  // Act
  bat.merge(left, right);
  array  = bat.getArray();

  // Assert
  EXPECT_TRUE(array[1] > array[0]);
}

TEST(BatcherMergeTest, Can_Work_With_Big_Size) {
  // Arrange
  std::vector<int> array = { 1, 7, 4 , 5, 2, 3, 6, 8};
  std::vector<int> sequence = { 1, 2, 3, 4, 5, 6, 7, 8};
  int left = 0;
  int right = 7;
  BatcherMerge bat = BatcherMerge(array);

  // Act
  bat.merge(left, right);
  array  = bat.getArray();

  // Assert
  EXPECT_TRUE(std::is_sorted(array.begin(), array.end()));
}

TEST(BatcherMergeTest, Right_Index_Out_Of_Range) {
  // Arrange
  std::vector<int> array = { 1, 8, 3 };
  int left = 0;
  int right = 5;
  BatcherMerge bat = BatcherMerge(array);

  // Act & Assert
  EXPECT_ANY_THROW(bat.merge(left, right););
}


