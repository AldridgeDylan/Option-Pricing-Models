#include "OptionsPricingModels/analytical/BlackScholesModel.hpp"
#include "../util/Utility.hpp"

#include <cmath>

namespace OptionsPricingModels {

	double BlackScholesModel::price(const Option& opt, double S0, double r, double sigma) {

    double T = opt.getMaturity();
    double K = opt.getStrike();

    double d1 = (std::log(S0/K) + (r+0.5*sigma*sigma)*T)/(sigma*std::sqrt(T));
    double d2 = d1 - sigma*std::sqrt(T);

    double Nd1 = internal::Utility::normalCDF(d1);
    double Nd2 = internal::Utility::normalCDF(d2);
    double discount = internal::Utility::discountFactor(r, T);

    return (opt.getOptionType() == OptionType::Call)
      ? (S0*Nd1 - K*discount*Nd2)
      : (K*discount*(1.0-Nd2) - S0*(1.0-Nd1));

	}
}