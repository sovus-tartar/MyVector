#include <algorithm>
#include <stdexcept>
#include <iostream>

namespace MyVector
{
    template <typename T>
    class vector
    {
        T * data;
        unsigned size;

        public:

        explicit vector(unsigned size_): size(size_), data(new T[size_]) 
        {
        }

        vector(unsigned size_, T default_value): vector(size_) 
        {
            for(unsigned i = 0; i < size; ++i)
                access(i) = default_value;
        }

        ~vector()
        {
            delete[] data;
        }

        vector(const vector<T> & src): size(src.size), data(new T[src.size]) //copy ctr
        {
            std::cout << "Copy ctr called" << std::endl;
            std::copy(src.data, src.data + size, data);
        }

        vector(vector<T> && src) noexcept//move ctr
        {
            std::cout << "Move ctr called" << std::endl;

            std::swap(data, src.data);
            std::swap(size, src.size);
        }

        vector<T> & operator=(const vector<T> & src) //copy assign
        {
            std::cout << "Copy assign called" << std::endl;
            size = src.size;
            data = new T[size];
            std::copy(src.data, src.data + size, data);
        } 

        vector<T> & operator=(const vector<T> && src) noexcept //move assign
        { 
            std::cout << "Move assign called" << std::endl;
            std::swap(data, src.data);
            std::swap(size, src.size);
        }

        T& access(unsigned i)
        {
            if (i >= size)
                throw std::out_of_range("Index i is out of range of this vector\n");

            return data[i];
        }

        T& operator[](unsigned i)
        {
            return data[i];
        }

        void print()
        {
            std::cout << "[ ";

            for(unsigned i = 0; i < size; ++i)
                std::cout << access(i) << " ";

            std::cout << "]" << std::endl;
        }

        const unsigned len()
        {
            return size;
        }

    };
}