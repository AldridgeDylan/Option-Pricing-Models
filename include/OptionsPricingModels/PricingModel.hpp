#ifndef PRICINGMODEL_HPP
#define PRICINGMODEL_HPP

#include "Option.hpp"

namespace OptionsPricingModels {

  class PricingModel {
    public:
      virtual ~PricingModel() = default;
      virtual double price(const Option& opt, double S0, double r, double sigma) = 0;
  };

}

#endif
