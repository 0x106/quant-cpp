#ifndef VECTOR_H__
#define VECTOR_H__

// https://codereview.stackexchange.com/questions/63970/custom-mathematical-vector-class

#include <vector>
#include <iostream>
#include <algorithm>
#include <initializer_list>

namespace Quant
{

using Format = float;

template <class T>
class Vector
{
private:
    std::vector<T> m_data;

public:
    Vector();
    virtual ~Vector();

    Vector(size_t n);
    Vector(const std::vector<T> &v);
    Vector(std::initializer_list<T> data);
    Vector(const Vector<T> &v);

    // todo: figure out how to get the move constructors to work
    // Vector(Vector<T>&& v);
    // Vector<T>& operator=(Vector<T>&& v);

    std::vector<T> data() const;
    void print() const;
};

template <class T>
Vector<T>::Vector()
{
}

template <class T>
Vector<T>::~Vector()
{
    m_data.clear();
}

template <class T>
Vector<T>::Vector(size_t n) : m_data(n) {}

template <class T>
Vector<T>::Vector(const std::vector<T> &v) : m_data(v) {}

template <class T>
Vector<T>::Vector(std::initializer_list<T> data) : m_data(data) {}

template <class T>
Vector<T>::Vector(const Vector<T> &v) : m_data(v.data()) {}

// template <class T>
// Vector<T>::Vector(Vector<T>&& v) {
//     *this = std::move(v);
// }

// template <class T>
// Vector<T>& operator=(Vector<T>&& v) {
//     v.swap(*this);
//     return *this;
// }

template <class T>
std::vector<T> Vector<T>::data() const
{
    return m_data;
}

template <class T>
void Vector<T>::print() const
{
    for (const auto &e : m_data)
    {
        std::cout << e << " ";
    }
    std::cout << std::endl;
}
} // namespace Quant

#endif // VECTOR_H__