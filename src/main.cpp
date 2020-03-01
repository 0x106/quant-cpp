#include <iostream>
#include "./vector.h"
#include "./matrix.h"
#include "./linalg.h"
#include "./stats.h"

using Vector = Quant::Vector<Quant::Format>;

int main (int argc, char** argv) {
    std::cout << "Quant" << std::endl;

    Vector b;
    Vector c(1);
    Vector d({1.0f, 2.0f, 3.0f});

    Vector e = {1.0f, 2.0f};

    std::cout << b << std::endl;
    std::cout << c << std::endl;
    std::cout << d << std::endl;
    std::cout << e << std::endl;

    Vector f(e);
    Vector g;
    g = f;

    std::cout << f << std::endl;
    std::cout << g << std::endl;

    Vector h = f + g;
    std::cout << h << std::endl;

    return 0;
}