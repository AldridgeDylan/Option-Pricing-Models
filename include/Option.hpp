#ifndef OPTION_HPP
#define OPTION_HPP

enum class OptionType { Call, Put };
enum class ExerciseType { European, American };

class Option {
public:
    Option(double strike, double maturity, OptionType type, ExerciseType exercise);

    double getStrike() const;
    double getMaturity() const;
    OptionType getOptionType() const;
    ExerciseType getExerciseType() const;

private:
    double K;
    double T;
    OptionType optType;
    ExerciseType exType;
};

#endif
