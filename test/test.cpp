#include <gtest/gtest.h>

#include <MyVector.hpp>

TEST(myvector, ctr)
{
    MyVector::vector<int> A(100);

    for(int i = 0; i < A.len(); ++i)
        A[i] = i;

    for(int i = 0; i < A.len(); ++i)
        EXPECT_EQ(A[i], i);
}

TEST(myvector, default_ctr)
{
    MyVector::vector<int> A(100, 5);

    for(int i = 0; i < A.len(); ++i)
        EXPECT_EQ(A[i], 5);
}

TEST(myvector, operator_eq1)
{
    MyVector::vector<int> A(100);
    MyVector::vector<int> B(100);

    for(int i = 0; i < A.len(); ++i)
    {
        A[i] = i;
        B[i] = i;
    }

    EXPECT_TRUE(A == B);
}

TEST(myvector, operator_eq2)
{
    MyVector::vector<int> A(100);
    MyVector::vector<int> B(200);

    EXPECT_FALSE(A == B);
}

TEST(myvector, copy_ctr)
{
    MyVector::vector<int> A(100, 5);
    MyVector::vector<int> B(A);

    for(int i = 0; i < A.len(); ++i)
        EXPECT_EQ(A[i], B[i]);
}

TEST(myvector, move_ctr)
{
    MyVector::vector<int> B(std::move(MyVector::vector<int>(10, 5)));

    for(int i = 0; i < B.len(); ++i)
        EXPECT_EQ(5, B[i]);
}

TEST(myvector, copy_assign)
{
    MyVector::vector<int> A(100, 5);
    MyVector::vector<int> B(5);
    B = A;

    for(int i = 0; i < A.len(); ++i)
        EXPECT_EQ(A[i], B[i]);
}

TEST(myvector, move_assign)
{
    MyVector::vector<int> B = std::move(MyVector::vector<int>(10, 5));

    for(int i = 0; i < B.len(); ++i)
        EXPECT_EQ(5, B[i]);
}
