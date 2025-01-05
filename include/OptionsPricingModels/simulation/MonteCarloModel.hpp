#ifndef OPTIONSPRICINGMODELS_MONTECARLOMODEL_HPP
#define OPTIONSPRICINGMODELS_MONTECARLOMODEL_HPP

#include "OptionsPricingModels/PricingModel.hpp"

namespace OptionsPricingModels {

	class MonteCarloModel : public PricingModel {
		public:
    	MonteCarloModel(int paths = 10000);
	  	double price(const Option& opt, double S0, double r, double sigma) override;

		private:
    	int numPaths;
		};

}

#endif
