// https://codereview.stackexchange.com/questions/63970/custom-mathematical-vector-class

#include <vector>
#include <iostream>
#include <algorithm>
#include <initializer_list>

namespace Quant {

    using Format = float;

    template<class T>
    class Vector {
        private:
            std::vector<T> m_data;

        public:
            Vector() {};
            Vector(size_t n) : m_data(n) {}
            Vector(const std::vector<T>& v) : m_data(v) {}
            Vector(std::initializer_list<T> data) {
                m_data = data;
            }

            Vector(const Vector<T>& v) : m_data(v.data()) {}

            std::vector<T> data() const { 
                return m_data; 
            }
    };
}