#include <iostream>

#include "OptionsPricingModels/Option.hpp"
#include "OptionsPricingModels/analytical/BlackScholesModel.hpp"
#include "OptionsPricingModels/simulation/MonteCarloModel.hpp"

int main() {

    using namespace OptionsPricingModels;

    Option callOption(100.0, 1.0, OptionType::Call);

    BlackScholesModel bsModel;
    double bsPrice = bsModel.price(callOption, 100.0, 0.05, 0.2);

    std::cout << "Black-Scholes Price for call option: " << bsPrice << std::endl;

    MonteCarloModel mcModel(50000);
    double mcPrice = mcModel.price(callOption, 100.0, 0.05, 0.2);

    std::cout << "Monte Carlo Price for call option: " << mcPrice << std::endl;

    return 0;
    
}
