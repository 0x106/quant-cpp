// 1. https://www.quantstart.com/articles/European-vanilla-option-pricing-with-C-and-analytic-formulae/
// https://github.com/PlamenStilyianov/FinMathematics

#include <cmath>
#include <iostream>

struct Option {
    double S; // Option price
    double K; // Strike price
    double r; // Risk-free rate (5%)
    double v; // Volatility of the underlying (20%)
    double T; // One year until expiry
};

void consolelog(const Option& option) {
    std::cout << "{ // option" << std::endl;
    std::cout << " S: " << option.S << std::endl;
    std::cout << " K: " << option.K << std::endl;
    std::cout << " r: " << option.r << std::endl;
    std::cout << " v: " << option.v << std::endl;
    std::cout << " T: " << option.T << std::endl;
    std::cout << "}" << std::endl;
}

int main () {

    Option option( { 100.0f, 100.0f, 0.05f, 0.2f, 1.0f } );
    consolelog(option);
    

    return 0;
}