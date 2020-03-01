#ifndef VECTOR_H__
#define VECTOR_H__

// https://codereview.stackexchange.com/questions/63970/custom-mathematical-vector-class

#include <vector>
#include <iostream>
#include <algorithm>
#include <initializer_list>

namespace Quant
{

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

    Vector<T> &operator=(const Vector<T> &v);
    Vector<T> operator+(const Vector<T> &v) const;
    Vector<T> operator-(const Vector<T> &v) const;
    Vector<T> operator*(T value) const;
    Vector<T> operator/(T value) const;

    Vector<T> &operator+=(const Vector<T> &v);
    Vector<T> &operator-=(const Vector<T> &v);
    Vector<T> &operator*=(T value);
    Vector<T> &operator/=(T value);

    const std::vector<T> data() const;
    // friend std::ostream& operator<<(std::ostream& out, const Vector& v);
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

template <class T>
const std::vector<T> Vector<T>::data() const
{
    return m_data;
}

template <class T>
std::ostream &operator<<(std::ostream &out, const Vector<T> &v)
{
    for (const auto &e : v.data())
    {
        out << e << " ";
    }
    return out;
}

template <class T>
Vector<T> &Vector<T>::operator=(const Vector<T> &v)
{
    m_data = v.data();
    return *this;
}

template <class T>
Vector<T> Vector<T>::operator+(const Vector<T> &v) const
{
    std::vector<T> resultData;
    std::vector<T> vData = v.data();
    if (!(m_data.size() == vData.size()))
        return Vector<T>();
    for (int i = 0; i < m_data.size(); ++i)
        resultData.push_back(m_data[i] + vData[i]);
    return Vector<T>(resultData);
}

template <class T>
Vector<T> &Vector<T>::operator+=(const Vector<T> &v)
{
    std::vector<T> vData = v.data();
    if (!(m_data.size() == vData.size()))
        return *this;
    for (int i = 0; i < m_data.size(); ++i)
        m_data[i] += vData[i];
    return *this;
}

template <class T>
Vector<T> Vector<T>::operator-(const Vector<T> &v) const
{
    std::vector<T> resultData;
    std::vector<T> vData = v.data();
    if (!(m_data.size() == vData.size()))
        return Vector<T>();
    for (int i = 0; i < m_data.size(); ++i)
        resultData.push_back(m_data[i] - vData[i]);
    return Vector<T>(resultData);
}

template <class T>
Vector<T> &Vector<T>::operator-=(const Vector<T> &v)
{
    std::vector<T> vData = v.data();
    if (!(m_data.size() == vData.size()))
        return *this;
    for (int i = 0; i < m_data.size(); ++i)
        m_data[i] -= vData[i];
    return *this;
}

template <class T>
Vector<T> Vector<T>::operator*(T value) const
{
    std::vector<T> resultData;
    for (int i = 0; i < m_data.size(); ++i)
        resultData.push_back(m_data[i] * value);
    return Vector<T>(resultData);
}

template <class T>
Vector<T> &Vector<T>::operator*=(T value)
{
    std::vector<T> resultData;
    for (int i = 0; i < m_data.size(); ++i)
        m_data[i] *= value;
    return *this;
}

template <class T>
Vector<T> Vector<T>::operator/(T value) const
{
    if (value == 0.0f)
        return *this;
    std::vector<T> resultData;
    for (int i = 0; i < m_data.size(); ++i)
    {
        if (m_data[i] != 0.f)
            resultData.push_back(m_data[i] / value);
    }
    return Vector<T>(resultData);
}

template <class T>
Vector<T> &Vector<T>::operator/=(T value)
{
    if (value == 0.0f)
        return *this;
    for (int i = 0; i < m_data.size(); ++i)
        if (m_data[i] != 0.f)
            m_data[i] /= value;
    return *this;
}

} // namespace Quant

#endif // VECTOR_H__