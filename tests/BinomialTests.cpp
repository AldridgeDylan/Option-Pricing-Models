#include "OptionsPricingModels/BinomialModel.hpp"
#include "gtest/gtest.h"
#include <cmath>

namespace OptionsPricingModelsTests {

    TEST(BinomialModelTests, PriceCallOption) {
        OptionsPricingModels::Option callOption(100.0, 1.0, OptionsPricingModels::OptionType::Call);
        OptionsPricingModels::BinomialModel binomialModel;
        double price = binomialModel.price(callOption, 100.0, 0.05, 0.2);
        double expectedPrice = 10.43;
        EXPECT_NEAR(price, expectedPrice, 0.01);
    }

    TEST(BinomialModelTests, PricePutOption) {
        OptionsPricingModels::Option putOption(100.0, 1.0, OptionsPricingModels::OptionType::Put);
        OptionsPricingModels::BinomialModel binomialModel;
        double price = binomialModel.price(putOption, 100.0, 0.05, 0.2);
        double expectedPrice = 5.55;
        EXPECT_NEAR(price, expectedPrice, 0.01);
    }

}
