#ifndef MODELFACTORY_HPP
#define MODELFACTORY_HPP

#include <memory>
#include <string>
#include "PricingModel.hpp"

class ModelFactory {
public:
    static std::unique_ptr<PricingModel> createModel(const std::string& name);
};

#endif
