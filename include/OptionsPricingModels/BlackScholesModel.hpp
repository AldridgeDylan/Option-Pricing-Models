#ifndef BLACKSCHOLESMODEL_HPP
#define BLACKSCHOLESMODEL_HPP

#include "PricingModel.hpp"

namespace OptionsPricingModels {

  class BlackScholesModel : public PricingModel {
  	public:
    	double price(const Option& option, double S0, double r, double sigma) override;
	};

}

#endif
