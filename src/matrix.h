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
    std::vector<Vector<T>> m_data;

public:
    Matrix();
    virtual ~Matrix();

    Matrix(size_t n, size_t m);
    Matrix(const std::vector<Vector<T> > &m);
    Matrix(const Matrix<T> &m);

    std::vector<Vector<T> > data() const;
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
Matrix<T>::Matrix(size_t n, size_t m) : m_data(n) {
    for (int i = 0; i < n; ++i)
        m_data.push_back( Vector<T>(m) );
}

template <class T>
Matrix<T>::Matrix(const std::vector<Vector<T> > &m) : m_data(m) {}

template <class T>
Matrix<T>::Matrix(const Matrix<T> &m) : m_data(m.data()) {}

template <class T>
std::vector<Vector<T> > Matrix<T>::data() const
{
    return m_data;
}

template <class T>
void Matrix<T>::print() const
{
    // for (const auto &e : m_data)
    // {
    //     std::cout << e << " ";
    // }
    // std::cout << std::endl;
}
} // namespace Quant

#endif // MATRIX_H__