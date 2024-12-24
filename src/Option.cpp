#include "Option.hpp"
#include <algorithm>

Option::Option(double strike, double maturity, OptionType type, ExerciseType exercise)
    : K(strike), T(maturity), optType(type), exType(exercise) {}

double Option::getStrike() const { return K; }
double Option::getMaturity() const { return T; }
OptionType Option::getOptionType() const { return optType; }
ExerciseType Option::getExerciseType() const { return exType; }
