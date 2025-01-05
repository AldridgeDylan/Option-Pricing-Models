#ifndef OPTIONSPRICINGMODELS_UTILITY_HPP
#define OPTIONSPRICINGMODELS_UTILITY_HPP

namespace OptionsPricingModels {
  namespace internal {

    class Utility {
    	public:
        static double discountFactor(double r, double T);
        static double normalCDF(double x);
    };

  }
}

#endif
