# Options Pricing Models

Options are financial derivatives that grant the holder the right, but not the obligation, to buy or sell an underlying asset at a predetermined price within a specified time frame. Accurately pricing these options is crucial for traders, investors, and financial analysts.

The **Options Pricing Models** library provides a collection of models to simplify the process of pricing derivative options. By offering multiple models under a unified interface, users can select the most appropriate model based on their specific needs and scenarios.

## Features

- **Multiple Pricing Models:** Black-Scholes, Monte Carlo, Binomial Tree, and more.
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

### 2. Monte Carlo ###
Simulates random price paths under the risk-neutral measure. 

**Usage Example:**

```
MonteCarloModel mc(100000); // e.g. 100k paths
double result = mc.price(option, S0, r, sigma);
```

### 2. Monte Carlo ###
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

## Additional Notes
- **Extensibility**: You can add new models by inheriting from `PricingModel` and overriding the `price(...)` function.
- **Performance**: Analytical methods are typically faster but handle fewer complexities. Monte Carlo and binomial approaches can model more scenarios but may be slower.

## Contact And Support
- Issues: Report bugs or request features via the Issues Page.
- Contributions: For bug fixes, improvements, or new models, please submit a Pull Request.

## License
This project is licensed under the MIT License. See the `LICENSE` file for full terms.