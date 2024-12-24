#include "Utility.hpp"
#include <cmath>

double Utility::discountFactor(double r, double T) {
    return std::exp(-r * T);
}

// Approximate normal CDF using Abramowitz and Stegun approximation
static double cnd(double x) {
    const double A1 = 0.319381530;
    const double A2 = -0.356563782;
    const double A3 = 1.781477937;
    const double A4 = -1.821255978;
    const double A5 = 1.330274429;

    double L = std::fabs(x);
    double K = 1.0/(1.0+0.2316419*L);
    double w = 1.0 - 1.0/std::sqrt(2.0*M_PI)*std::exp(-L*L/2.0) *
        (A1*K + A2*K*K + A3*K*K*K + A4*K*K*K*K + A5*K*K*K*K*K);
    return (x < 0.0) ? 1.0-w : w;
}

double Utility::normalCDF(double x) {
    return cnd(x);
}
