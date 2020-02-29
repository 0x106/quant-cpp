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
    Format sum(const Vector<T>& src);

    template <class T>
    Format mean(const Vector<T>& src);

    template <class T>
    Format median(const Vector<T>& src);

    template <class T>
    Format variance(const Vector<T>& src);
}

#endif // STATS_H__