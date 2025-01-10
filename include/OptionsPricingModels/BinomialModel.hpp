#ifndef BINOMIALMODEL_HPP
#define BINOMIALMODEL_HPP

#include "PricingModel.hpp"

namespace OptionsPricingModels {

    class BinomialModel : public PricingModel {
        public:
            double price(const Option& option, double S0, double r, double sigma) override;
    };

}

#endif
