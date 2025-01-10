#ifndef MONTECARLOMODEL_HPP
#define MONTECARLOMODEL_HPP

#include "PricingModel.hpp"

namespace OptionsPricingModels {

	class MonteCarloModel : public PricingModel {
		public:
    	MonteCarloModel(int paths = 10000);
	  	double price(const Option& option, double S0, double r, double sigma) override;

		private:
    	int numPaths;
	};

}

#endif
