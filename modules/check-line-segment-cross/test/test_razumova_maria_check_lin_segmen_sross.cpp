// Copyright 2018 Razumova Maria

#include <gtest/gtest.h>


#include "include/lineSegment.h"


TEST(Razumova_Maria_LineCross, Can_create_LineSegment_without_parametrs)
{
    //AAA
    ASSERT_NO_THROW(LineSegment());
}

TEST(Razumova_Maria_LineCross,Can_create_LineSegment_with_parametrs)
{
    //Arrange
    double x1, y1, x2, y2;

    //Act
    x1 = 1;
    y1 = 2;
    x2 = 0;
    y2 = 0;

    //Assert
    ASSERT_NO_THROW(LineSegment(x1,y1,x2,y2));
}

TEST (Razumova_Maria_LineCross, Can_create_via_copyng)
{
    //Arrange
    LineSegment line(1,2,3,4);

    //Act
    LineSegment line2(line);
    //Assert
    EXPECT_EQ(line, line2);
}

TEST(Razumova_Maria_LineCross, Can_compare_equal_lines)
{
    //Arrange
    LineSegment line1(1,0,0,1);
    LineSegment line2(1,0,0,1);
    
    //Act && Assert
    EXPECT_TRUE(line1 == line2);
}

TEST(Razumova_Maria_LineCross, Can_compare_not_equal_lines)
{
    //Arrange
    LineSegment line1(1,0,0,1);
    LineSegment line2(1,0,1,1);
    
    //Act && Assert
    EXPECT_FALSE(line1 == line2);
}

 TEST (Razumova_Maria_LineCross, Can_assign_different_lines)
 {
     //Arrange
     LineSegment line1(1,1,3,4);
     LineSegment line2(2,2,2,2);
     //Act
     line2 = line1;
     //Assert
     EXPECT_EQ(line1, line2);
 }

 TEST (Razumova_Maria_LineCross, Can_assign_equal_lines)
 {
     //Arrange
     LineSegment line1(1,1,3,4);
     LineSegment line2(2,2,2,2);
     //Act
     line2 = line1;
     //Assert
     EXPECT_EQ(line1, line2);
 }

 TEST (Razumova_Maria_LineCross, Can_assign_line_to_itself)
 {
     //Arrange
     LineSegment line(1,1,1,1);

     //Act & Assert
     ASSERT_NO_THROW(line = line);
 }

 TEST(Razumova_Maria_LineCross, Can_calculate_vector_product)
 {
     //Arrange
     LineSegment line1(1,2,3,4);
     LineSegment line2(4,4,5,2);
     double prod;

     //Act
     prod = (3-1)*(2-4)-(5-4)*(4-2);

     //Assert
     EXPECT_EQ(prod, line1.vectorProduct(line2));
 }

TEST(Razumova_Maria_LineCross, check_cross_line_segments_crossed)
{
    //Arrange
    LineSegment line1(1, 1, 4, 1);
    LineSegment line2(2,-3, 2, 8);

    //Act & Assert
    EXPECT_TRUE(line1.isCross((line2)));
}

TEST(Razumova_Maria_LineCross, check_cross_line_segments_not_crossed)
{
    //Arrange
    LineSegment line1(1, 1, 4, 1);
    LineSegment line2(2,-3, 2, 0);

    //Act & Assert
    EXPECT_FALSE(line1.isCross(line2));
}
