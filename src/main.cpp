#include <iostream>
#include <MyVector.hpp>

int main()
{
    MyVector::vector<int> A(10);

    for(int i = 0; i < A.len(); ++i)
        A[i] = i;
    A.print();

    MyVector::vector<int> B(A);
    B.print();

    MyVector::vector<int> C = B;
    C.print();
    
}