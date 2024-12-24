#include "models/analytical/BlackScholesModel.hpp"
#include "Utility.hpp"
#include "Option.hpp"
#include <cmath>

double BlackScholesModel::price(const Option& opt, double S0, double r, double sigma) {

    double T = opt.getMaturity();
    double K = opt.getStrike();
    // d1 = [ln(S0/K) + (r + 0.5 * sigma^2) * T] / (sigma * sqrt(T))
    double d1 = (std::log(S0/K) + (r+0.5*sigma*sigma)*T)/(sigma*std::sqrt(T));
    // d2 = d1 - sigma * sqrt(T)
    double d2 = d1 - sigma*std::sqrt(T);

    double Nd1 = Utility::normalCDF(d1);
    double Nd2 = Utility::normalCDF(d2);
    double discount = Utility::discountFactor(r, T);

    if (opt.getOptionType() == OptionType::Call) {
        // C = S0 * N(d1) - K * e^(-rT) * N(d2)
        return S0*Nd1 - K*discount*Nd2;
    } else {
        // Using the identity N(-x) = 1 - N(x)
        return K*discount*(1.0-Nd2) - S0*(1.0-Nd1);
    }

}
