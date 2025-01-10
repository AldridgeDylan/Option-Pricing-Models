#include "OptionsPricingModels/Option.hpp"

#include <algorithm>

namespace OptionsPricingModels {

    double Option::payoff(double S) const {
        if (optionType == OptionType::Call) {
            return std::max(S - strikePrice, 0.0);
        } else {
            return std::max(strikePrice - S, 0.0);
        }
    }

}
