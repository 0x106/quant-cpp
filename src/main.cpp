#include <iostream>
#include "./matrix.h"

using Vector = Quant::Vector<Quant::Format>;

int main (int argc, char** argv) {
    std::cout << "Quant" << std::endl;

    // Quant::Vector<Quant::Format> a({1, 2, 3});
    Vector b;
    Vector c(1);
    Vector d({1.0f, 2.0f, 3.0f});

    return 0;
}