# Enable testing
enable_testing()

# Find Conan dependencies
find_package(GTest REQUIRED)

# Add test executable
add_executable(OptionsPricingModelsTests
    BlackScholesTests.cpp
    BinomialTests.cpp
    MonteCarloTests.cpp
)

# Link libraries
target_link_libraries(OptionsPricingModelsTests PRIVATE OptionsPricingModels GTest::gtest_main)

# Discover and add tests
include(GoogleTest)
gtest_discover_tests(OptionsPricingModelsTests)
