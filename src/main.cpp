#include <iostream>
#include <string>
#include "Option.hpp"
#include "Pricer.hpp"
#include "ModelFactory.hpp"

int main() {

    double S0, K, r, sigma, T;
    std::string modelName, optTypeStr, exerciseTypeStr;

    std::cout << "Enter current underlying price (S0): ";
    std::cin >> S0;

    std::cout << "Enter strike price (K): ";
    std::cin >> K;

    std::cout << "Enter risk-free interest rate (r): ";
    std::cin >> r;

    std::cout << "Enter volatility (sigma): ";
    std::cin >> sigma;

    std::cout << "Enter time to maturity in years (T): ";
    std::cin >> T;

    std::cout << "Enter option type (Call or Put): ";
    std::cin >> optTypeStr;

    OptionType optType;
    if (optTypeStr == "Call" || optTypeStr == "call") {
        optType = OptionType::Call;
    } else if (optTypeStr == "Put" || optTypeStr == "put") {
        optType = OptionType::Put;
    } else {
        std::cerr << "Invalid option type. Defaulting to Call." << std::endl;
        optType = OptionType::Call;
    }

    std::cout << "Enter exercise type (European or American): ";
    std::cin >> exerciseTypeStr;

    ExerciseType exType;
    if (exerciseTypeStr == "European" || exerciseTypeStr == "european") {
        exType = ExerciseType::European;
    } else if (exerciseTypeStr == "American" || exerciseTypeStr == "american") {
        exType = ExerciseType::American;
    } else {
        std::cerr << "Invalid exercise type. Defaulting to European." << std::endl;
        exType = ExerciseType::European;
    }

    Option userOption(K, T, optType, exType);

    std::cout << "Enter the model to use (e.g., BlackScholes, CRR, MonteCarlo): ";
    std::cin >> modelName;

    auto model = ModelFactory::createModel(modelName);
    if (!model) {
        std::cerr << "Failed to create model \"" << modelName << "\". Check the name or the factory setup." << std::endl;
        return 1;
    }

    double price = Pricer::price(userOption, *model, S0, r, sigma);
    std::cout << modelName << " Model Price: " << price << std::endl;

    return 0;

}
