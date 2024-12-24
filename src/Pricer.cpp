#include "Pricer.hpp"

double Pricer::price(const Option& opt, PricingModel& model, double S0, double r, double sigma) {
    return model.price(opt, S0, r, sigma);
}
