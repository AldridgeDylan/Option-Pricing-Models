#ifndef PRICER_HPP
#define PRICER_HPP

#include "PricingModel.hpp"

class Pricer {
public:
    static double price(const Option& opt, PricingModel& model, double S0, double r, double sigma);
};

#endif
