#ifndef LINEAR_ALGEBRA_H__
#define LINEAR_ALGEBRA_H__

#include <vector>
#include <iostream>
#include <algorithm>
#include <initializer_list>
#include <numeric>
#include <cmath>

#include "vector.h"
#include "matrix.h"

namespace Quant
{
template <class T>
T l1Norm(const Vector<T> &src)
{
    std::vector<T> data = src.data();
    return std::accumulate(data.begin(), data.end(), 0.0f, [](T lhs, T rhs) { return lhs + std::abs(rhs); });
}

template <class T>
T l2Norm(const Vector<T> &src)
{
    std::vector<T> data = src.data();
    return std::sqrt(std::accumulate(data.begin(), data.end(), 0.0f, [](T lhs, T rhs) { return lhs + std::pow(rhs, 2); }));
}

template <class T>
T lpNorm(const Vector<T> &src, T p)
{
    std::vector<T> data = src.data();
    auto lambda = [p](T lhs, T rhs) {
        return lhs + std::pow(std::abs(rhs), p);
    };
    auto sum = std::accumulate(data.begin(), data.end(), 0\0f, lambda);
    return std::pow(sum, 1.0f / p);
}

template <class T>
T lInfinityNorm(const Vector<T> &src)
{
    std::vector<T> data = src.data();
    T max = data[0];
    for (auto const &e : data)
        if (e > max)
            max = e;
    return max;
}
} // namespace Quant

#endif // LINEAR_ALGEBRA_H__