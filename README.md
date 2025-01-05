# Options Pricing Models

This library aims to simplify the process of pricing derivative options by providing multiple models under a single unified interface.

## Provided Models
---
Below are the main models and their typical usage:

1. **Black-Scholes**:
   - Best suited for European-style options on non-dividend-paying stocks.

     ```
     BlackScholesModel bs;
     double result = bs.price(option, S0, r, sigma);
     ```

2. **Monte Carlo**:
   - Simulates random price paths under the risk-neutral measure.
   - Flexible for path-dependent or exotic payoffs.

     ```
     MonteCarloModel mc(100000); // e.g. 100k paths
     double result = mc.price(option, S0, r, sigma);
     ```

## Example Workflow
---
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
---
- **Extensibility**: You can add new models by inheriting from `PricingModel` and overriding the `price(...)` function.
- **Performance**: Analytical methods are typically faster but handle fewer complexities. Monte Carlo and binomial approaches can model more scenarios but may be slower.

## Contact And Support
---
- Please see the repository issues page if you encounter problems or have feature requests.
- For bug fixes, improvements, or new models, feel free to submit a pull request.

## License
---
This project is licensed under the MIT License. See the `LICENSE` file for full terms.