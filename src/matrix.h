#include <iostream>
#include <algorithm>
#include <initializer_list>

namespace Quant {

    using Format = float;

    class Vector {
        private:
            Format* m_data;
            int m_N;

        public:
            Vector() : m_data(nullptr), m_N(0) {}
            virtual ~Vector() {
                delete m_data;
                m_data = nullptr;
                m_N = 0;
            }

            Vector(int N) {
                m_N = N;
                m_data = new Format[m_N];
            }
            
            Vector(int N, Format value) {
                m_N = N;
                m_data = new Format[m_N];
                for (int i = 0; i < m_N; ++i)
                    m_data[i] = value;
            }

            Vector(std::initializer_list<Format> data) {
                m_N = data.size();
                m_data = new Format[m_N];
                m_data = data;
                // for( int i = 0; i < m_N; ++i ) { m_data[i] = data[i]; }
            }

            Vector(const Vector& v) : m_data(v.m_data), m_N(v.m_N) {}

            // Vector(Vector&& v) : m_data(nullptr), m_N(0) {
            //     *this = std::move(v);
            // }

            void print() const;

            // element-wise addition and subtraction
            Vector& operator+(const Vector& rhs) const;
            Vector& operator-(const Vector& rhs) const;
            
            // dot product
            Format operator*(const Vector& rhs) const;

            Format l1Norm() const;
            Format l2Norm() const;
            Format lpNorm(const int p) const;
            Format lInfinityNorm() const;
    };

    // class Matrix {
    //     private:
    //         std::vector<Quant::Vector> m_data;

    //     public:
    //         Matrix();
    //         virtual ~Matrix();
            
    //         Matrix(Format value, int N);
    //         Matrix(const Quant::Vector& data, int N);
    //         Matrix(const std::vector<Quant::Vector> data);
    //         Matrix(const Matrix& m);

    //         void print() const;
    //         Matrix& operator* (const Matrix& rhs);
    // };


}