#include "OptionsPricingModels/BinomialModel.hpp"

#include <cmath>
#include <stdexcept>
#include <vector>

namespace OptionsPricingModels {

double BinomialModel::price(const Option& option, double S0, double r, double sigma) {
    
    double T = option.getTimeToMaturity();
    double K = option.getStrikePrice();
    int N = 100;
    
    if (T <= 0.0) {
        return (option.getOptionType() == OptionType::Call) ? std::max(S0 - K, 0.0) : std::max(K - S0, 0.0);
    }
    
    if (S0 <= 0.0 || K <= 0.0 || sigma <= 0.0) {
        throw std::invalid_argument("S0, K, and sigma must be positive.");
    }
    
    double dt = T / N;
    double u = std::exp(sigma * std::sqrt(dt));
    double d = 1.0 / u;
    double a = std::exp(-r * dt);
    double p = (std::exp(r * dt) - d) / (u - d);
    
    std::vector<double> prices(N + 1);
    for (int i = 0; i <= N; ++i) {
        prices[i] = S0 * std::pow(u, N - i) * std::pow(d, i);
    }
    
    std::vector<double> optionValues(N + 1);
    for (int i = 0; i <= N; ++i) {
        optionValues[i] = option.payoff(prices[i]);
    }
    
    for (int step = N - 1; step >= 0; --step) {
        for (int i = 0; i <= step; ++i) {
            optionValues[i] = a * (p * optionValues[i] + (1.0 - p) * optionValues[i + 1]);
        }
    }
    
    return optionValues[0];
}

}
