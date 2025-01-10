#ifndef OPTION_HPP
#define OPTION_HPP

namespace OptionsPricingModels {

    enum class OptionType {
        Call,
        Put
    };

    class Option {
    public:
        Option(double strike, double maturity, OptionType type)
            : strikePrice(strike), timeToMaturity(maturity), optionType(type) {}

        double getStrikePrice() const { return strikePrice; }
        double getTimeToMaturity() const { return timeToMaturity; }
        OptionType getOptionType() const { return optionType; }

		double payoff(double S) const;

    private:
        double strikePrice;
        double timeToMaturity;
        OptionType optionType;
    };

}

#endif
