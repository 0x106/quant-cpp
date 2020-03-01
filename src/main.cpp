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

    b.print();
    c.print();
    d.print();
    e.print();

    Vector f(e);
    Vector g;
    g = f;

    f.print();
    g.print();

    Vector h = f + g;
    h.print();

    return 0;
}