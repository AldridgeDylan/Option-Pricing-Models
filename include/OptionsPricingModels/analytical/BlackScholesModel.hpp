#ifndef BLACKSCHOLESMODEL_HPP
#define BLACKSCHOLESMODEL_HPP

#include "OptionsPricingModels/PricingModel.hpp"

namespace OptionsPricingModels {

  class BlackScholesModel : public PricingModel {
  	public:
    	double price(const Option& opt, double S0, double r, double sigma) override;
	};

}

#endif
