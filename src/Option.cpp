#include "OptionsPricingModels/Option.hpp"

#include <algorithm>

namespace OptionsPricingModels {

	Option::Option(double strike, double maturity, OptionType optType) : K(strike), T(maturity), optType(optType) {}

	double Option::getStrike() const { return K; }
	double Option::getMaturity() const { return T; }
	OptionType Option::getOptionType() const { return optType; }

	double Option::payoff(double S) const {
    return (optType == OptionType::Call) 
      ? std::max(S - K, 0.0)
			: std::max(K - S, 0.0);
	}

}
