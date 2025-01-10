#include "OptionsPricingModels/MonteCarloModel.hpp"

#include <random>
#include <cmath>

namespace OptionsPricingModels {

	MonteCarloModel::MonteCarloModel(int paths) : numPaths(paths) {}

	double MonteCarloModel::price(const Option& opt, double S0, double r, double sigma) {

    double T = opt.getTimeToMaturity();
		
    std::random_device rd;
		std::mt19937 gen(rd());
    std::normal_distribution<> nd(0.0,1.0);

    double sumPayoffs = 0.0;
    for(int i=0; i < numPaths; i++){
      double Z = nd(gen);
      double ST = S0 * std::exp((r - 0.5*sigma*sigma)*T + sigma*std::sqrt(T)*Z);
      sumPayoffs += opt.payoff(ST);
    }
    double meanPayoff = sumPayoffs / numPaths;
    double discount = (T > 0) ? std::exp(-r * T) : 1.0;
    return meanPayoff * discount;
	}

}
