#ifndef LINEAR_ALGEBRA_H__
#define LINEAR_ALGEBRA_H__

#include <vector>
#include <iostream>
#include <algorithm>
#include <initializer_list>

#include "vector.h"
#include "matrix.h"

namespace Quant
{
    template <class T>
    Format l1Norm(const Vector<T>& src);

    template <class T>
    Format l2Norm(const Vector<T>& src);

    template <class T>
    Format lpNorm(const Vector<T>& src);

    template <class T>
    Format lInfinityNorm(const Vector<T>& src);
}

#endif // LINEAR_ALGEBRA_H__