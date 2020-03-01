#ifndef STATS_H__
#define STATS_H__

#include <vector>
#include <iostream>
#include <algorithm>
#include <initializer_list>

#include "vector.h"
#include "matrix.h"

namespace Quant
{

template <class T>
T sum(const Vector<T> &v)
{
    std::vector<T> data = v.data();
    return std::accumulate(data.begin(), data.end(), 0.0);
}

template <class T>
T mean(const Vector<T> &v)
{
    if (v.size() == 0)
        return 0.0f;
    return sum(v) / v.size();
}

template <class T>
T median(const Vector<T> &v)
{
    if (v.size() == 0)
        return 0.0f;
    std::vector<T> data = v.data();
    std::sort(data.begin(), data.end());
    return data[data.size() / 2];
}

template <class T>
T variance(const Vector<T> &v)
{
    std::vector<T> data = v.data();
    auto m = mean(v);
    auto lambda = [m](T lhs, T rhs) {
        return lhs + std::pow(m - rhs, 2);
    };
    return (1.0f / data.size()) *
           std::accumulate(data.begin(), data.end(), 0.0f, lambda);
}
} // namespace Quant

#endif // STATS_H__