#include "ModelFactory.hpp"
#include "models/analytical/BlackScholesModel.hpp"
#include <unordered_map>
#include <functional>

std::unique_ptr<PricingModel> ModelFactory::createModel(const std::string& name) {
    static std::unordered_map<std::string, std::function<std::unique_ptr<PricingModel>()>> modelMap = {
        {"BlackScholes", [](){ return std::make_unique<BlackScholesModel>(); }},
    };

    auto model = modelMap.find(name);
    if (model != modelMap.end()) {
        return model->second();
    } else {
        return nullptr;
    }
}
