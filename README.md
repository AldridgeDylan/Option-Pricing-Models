# Options Pricing Models

Options are financial derivatives that grant the holder the right, but not the obligation, to buy or sell an underlying asset at a predetermined price within a specified time frame. Accurately pricing these options is crucial for traders, investors, and financial analysts.

The **Options Pricing Models** library provides a collection of models to simplify the process of pricing derivative options. By offering multiple models under a unified interface, users can select the most appropriate model based on their specific needs and scenarios.

This library can be built using [conan](https://conan.io).

## Features

- **Multiple Pricing Models:** Black-Scholes, Monte Carlo and Binomial Tree.
- **Unified Interface:** Consistent method signatures across different models.
- **Extensibility:** Easily add new pricing models by inheriting from the base `PricingModel` class.
- **Performance Optimization:** Analytical models for speed and simulation-based models for flexibility.

## Provided Models

### 1. **Black-Scholes Model**
Best suited for European-style options on non-dividend-paying stocks.

**Usage Example:**
```
BlackScholesModel bs;
double result = bs.price(option, S0, r, sigma);
```

### 2. Binomial Model ###
Provides a discrete-time framework for modeling the evolution of asset prices, allowing for the evaluation of option prices by considering multiple possible paths the underlying asset's price might take until the option's expiration.

**Usage Example:**

```
BinomialModel bm;
double result = mb.price(option, S0, r, sigma);
```

### 3. Monte Carlo ###
Simulates random price paths under the risk-neutral measure. 

**Usage Example:**

```
MonteCarloModel mc(100000); // e.g. 100k paths
double result = mc.price(option, S0, r, sigma);
```
## Example Workflow
1. Define your option:
   
   ```
   Option myOption(
       100.0,       // Strike
       1.0,         // Time to maturity in years
       OptionType::Call  // or Put
   );
   ```

2. Instantiate a model (e.g. Black-Scholes):

   ```
   BlackScholesModel bs;
   double optionPrice = bs.price(myOption, 100.0, 0.05, 0.2);
   // S0 = 100, r = 5%, sigma = 0.2
   ```

## Contact And Support
- Issues: Report bugs or request features via the Issues Page.
- Contributions: For bug fixes, improvements, or new models, please submit a Pull Request.

## License
This project is licensed under the MIT License. See the `LICENSE` file for full terms.
