#include "Utility.hpp"
#include <cmath>

double Utility::discountFactor(double r, double T) {
    return (T > 0) ? std::exp(-r * T) : 1.0;
}

double Utility::normalCDF(double x) {
    return 0.5 * (1.0 + std::erf(x / std::sqrt(2.0)));
}
