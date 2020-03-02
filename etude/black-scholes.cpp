// https://www.quantstart.com/articles/European-vanilla-option-pricing-with-C-and-analytic-formulae/

#include <cmath>
#include <iostream>

using Format = float;

struct Option {
    Format S; // Option price
    Format K; // Strike price
    Format r; // Risk-free rate (5%)
    Format v; // Volatility of the underlying (20%)
    Format T; // One year until expiry
};

Format norm_pdf(Format x) {
    return (1.0 / std::pow(2.0 * M_PI, 0.5)) * std::exp(-0.5 * std::pow(x, 2));
}

Format norm_cdf(Format x) {
    Format k = 1.0 / (1.0 + 0.2316419 * x);
    Format k_sum = k*(0.319381530 + k*(-0.356563782 + k*(1.781477937 + k*(-1.821255978 + 1.330274429*k))));

    if (x > 0.0 ) {
        return (1.0 - (1.0/(std::pow(2*M_PI,0.5)))*std::exp(-0.5*x*x) * k_sum);
    } else {
        return 1.0 - norm_cdf(-x);
    }
}

Format d_j(const int j, const Option& option) {
    return (std::log(option.S/option.K) + (option.r + (std::pow(-1,j-1))*0.5*option.v*option.v)*option.T)/(option.v*(pow(option.T,0.5)));
}

Format call_price (const Option& option ) {
    return option.S * norm_cdf(d_j(1, option)) - option.K * std::exp(-option.r*option.T) * norm_cdf(d_j(2, option));
}

Format put_price (const Option& option ) {
    return -option.S * norm_cdf(-d_j(1, option)) + option.K * std::exp(-option.r * option.T) * norm_cdf(-d_j(2, option));
}

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
    
    std::cout << "Call price: " << call_price(option) << std::endl;
    std::cout << "Put price: " << put_price(option) << std::endl;

    return 0;
}