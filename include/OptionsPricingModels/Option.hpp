#ifndef OPTIONSPRICINGMODELS_OPTION_HPP
#define OPTIONSPRICINGMODELS_OPTION_HPP

namespace OptionsPricingModels {

  enum class OptionType { Call, Put };

  class Option {
		public:
			Option(double strike, double maturity, OptionType type);

			double getStrike() const;
			double getMaturity() const;
			OptionType getOptionType() const;

			double payoff(double S) const;

		private:
			double K;
			double T;
			OptionType optType;
		};

}

#endif
