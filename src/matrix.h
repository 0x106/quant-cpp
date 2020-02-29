#include <vector>

namespace Quant {

    using Format = float;

    class Vector {
        private:
            std::vector<Format> m_data;

        public:
            Vector();
            virtual ~Vector();
            
            Vector(Format value, int N);
            Vector(std::vector<Format> data);
            Vector(const Vector& v);

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

    class Matrix {
        private:
            std::vector<Quant::Vector> m_data;

        public:
            Matrix();
            virtual ~Matrix();
            
            Matrix(Format value, int N);
            Matrix(const Quant::Vector& data, int N);
            Matrix(const std::vector<Quant::Vector> data);
            Matrix(const Matrix& m);

            void print() const;
            Matrix& 

    };


}