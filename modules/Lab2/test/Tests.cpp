// Copyright 2018 Matyasov Mixail
#include <gtest/gtest.h>
#include <string>
#include "Student.h"

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


TEST(Student, can_create_student_with_negative_amount_marks) {
    int marks[] = { 2, 4, 5, 2, 5, 5 };
    Student st(1, -1, marks, "Matyasov", "381608-2");

    EXPECT_EQ(st.GetAmountMarks(), 0);
}

TEST(Student, can_create_student_with_large_amount_marks) {
    int marks[] = { 2, 4, 5, 2, 5, 5 };
    Student st(1, MAX + 1, marks, "Matyasov", "381608-2");

    EXPECT_EQ(st.GetAmountMarks(), MAX);
}

TEST(Student, can_create_default_student) {
    Student s;

    EXPECT_EQ(s.GetId(), 0);
}

TEST(Student, can_calculate_medium_mark) {
    int marks[] = { 2, 4, 5 };
    Student st(1, 3, marks, "Volickov", "123");

    float mark = st.CalculateMediumMark();

    EXPECT_EQ(mark, (2 + 4 + 5) / (float)3);
}

TEST(Student, can_print_statistic) {
    int marks[] = { 2, 4, 5, 2, 5, 5 };
    Student st(1, 6, marks, "Matyasov", "381608-2");

    st.PrintStatistic();

    EXPECT_EQ(st.code, 0);
}

TEST(Student, can_copy_student) {
    int marks[] = { 2, 4, 5, 2, 5, 5 };
    Student st(1, 6, marks, "Matyasov", "381608-2");
    Student stud = st;

    EXPECT_EQ(stud.GetId(), 1);
}
