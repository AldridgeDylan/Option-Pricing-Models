#include "OptionsPricingModels/BlackScholesModel.hpp"

#include <cmath>
#include <stdexcept>

namespace OptionsPricingModels {

  double norm_cdf(double x) {
    return 0.5 * (1.0 + std::erf(x / std::sqrt(2.0)));
  }

	double BlackScholesModel::price(const Option& opt, double S0, double r, double sigma) {

    double T = opt.getTimeToMaturity();
    double K = opt.getStrikePrice();

    if (T < 0.0) {
      throw std::invalid_argument("Time to maturity cannot be negative.");
    }

    if (S0 <= 0.0 || K <= 0.0 || sigma <= 0.0) {
      throw std::invalid_argument("S0, K, and sigma must be positive.");
    }

    double d1 = (std::log(S0/K) + (r+0.5*sigma*sigma)*T)/(sigma*std::sqrt(T));
    double d2 = d1 - sigma*std::sqrt(T);

    double Nd1 =  norm_cdf(d1);
    double Nd2 =  norm_cdf(d2);
    double discount = (T > 0) ? std::exp(-r * T) : 1.0;

    return (opt.getOptionType() == OptionType::Call)
      ? (S0*Nd1 - K*discount*Nd2)
      : (K*discount*(1.0-Nd2) - S0*(1.0-Nd1));

	}
  
}