#include "OptionsPricingModels/BlackScholesModel.hpp"
#include "gtest/gtest.h"
#include <cmath>

namespace OptionsPricingModelsTests {

    TEST(BlackScholesModelTests, PriceCallOption) {
        OptionsPricingModels::Option callOption(100.0, 1.0, OptionsPricingModels::OptionType::Call);
        OptionsPricingModels::BlackScholesModel bsModel;
        double price = bsModel.price(callOption, 100.0, 0.05, 0.2);
        double expectedPrice = 10.4506;
        EXPECT_NEAR(price, expectedPrice, 1e-4);
    }

    TEST(BlackScholesModelTests, PricePutOption) {
        OptionsPricingModels::Option putOption(100.0, 1.0, OptionsPricingModels::OptionType::Put);
        OptionsPricingModels::BlackScholesModel bsModel;
        double price = bsModel.price(putOption, 100.0, 0.05, 0.2);
        double expectedPrice = 5.5735;
        EXPECT_NEAR(price, expectedPrice, 1e-4);
    }

}
