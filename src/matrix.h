#ifndef MATRIX_H__
#define MATRIX_H__

// https://codereview.stackexchange.com/questions/63970/custom-mathematical-Matrix-class

#include <vector>
#include <iostream>
#include <algorithm>
#include <initializer_list>

#include "vector.h"

namespace Quant
{

using Format = float;

template <class T>
class Matrix
{
private:
    std::vector<T> m_data;

public:
    Matrix();
    virtual ~Matrix();

    Matrix(size_t n);
    Matrix(const std::vector<T> &v);
    Matrix(std::initializer_list<T> data);
    Matrix(const Matrix<T> &v);

    // todo: figure out how to get the move constructors to work
    // Matrix(Matrix<T>&& v);
    // Matrix<T>& operator=(Matrix<T>&& v);

    std::vector<T> data() const;
    void print() const;
};

template <class T>
Matrix<T>::Matrix()
{
}

template <class T>
Matrix<T>::~Matrix()
{
    m_data.clear();
}

template <class T>
Matrix<T>::Matrix(size_t n) : m_data(n) {}

template <class T>
Matrix<T>::Matrix(const std::vector<T> &v) : m_data(v) {}

template <class T>
Matrix<T>::Matrix(std::initializer_list<T> data) : m_data(data) {}

template <class T>
Matrix<T>::Matrix(const Matrix<T> &v) : m_data(v.data()) {}

// template <class T>
// Matrix<T>::Matrix(Matrix<T>&& v) {
//     *this = std::move(v);
// }

// template <class T>
// Matrix<T>& operator=(Matrix<T>&& v) {
//     v.swap(*this);
//     return *this;
// }

template <class T>
std::vector<T> Matrix<T>::data() const
{
    return m_data;
}

template <class T>
void Matrix<T>::print() const
{
    for (const auto &e : m_data)
    {
        std::cout << e << " ";
    }
    std::cout << std::endl;
}
} // namespace Quant

#endif // MATRIX_H__