#include "OptionsPricingModels/MonteCarloModel.hpp"
#include "gtest/gtest.h"
#include <cmath>

TEST(MonteCarloTests, PriceCallOption) {
    OptionsPricingModels::Option callOption(100.0, 1.0, OptionsPricingModels::OptionType::Call);
    OptionsPricingModels::MonteCarloModel mcModel(100000);
    double price = mcModel.price(callOption, 100.0, 0.05, 0.2);
    double expectedPrice = 10.45;
    EXPECT_NEAR(price, expectedPrice, 0.5);
}

TEST(MonteCarloTests, PricePutOption) {
    OptionsPricingModels::Option putOption(100.0, 1.0, OptionsPricingModels::OptionType::Put);
    OptionsPricingModels::MonteCarloModel mcModel(100000);
    double price = mcModel.price(putOption, 100.0, 0.05, 0.2);
    double expectedPrice = 5.57;
    EXPECT_NEAR(price, expectedPrice, 0.5);
}
