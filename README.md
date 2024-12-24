# Option Pricing Models in C++

This project demonstrates various option pricing methods, including both classical and modern approaches, all implemented in C++. Users can interactively input option parameters and choose a model to price the option.

## Features

- **Interactive Input:**  
  Input parameters (S0, K, r, sigma, T) and option/model selections at runtime.
  
- **Multiple Models:**
  - **Analytical:** Black-Scholes, Barone-Adesi-Whaley, Bjerksund-Stensland, Heston (stochastic volatility)
  - **Binomial:** CRR, Jarrow-Rudd, Leisen-Reimer
  - **Simulation:** Monte Carlo

- **Extensible Architecture:**  
  Easily add new models by implementing the `PricingModel` interface and registering them in `ModelFactory`.

## Building

**Requirements:**

- A C++17-compatible compiler (g++, clang++, or MSVC)
- CMake (version 3.10+ recommended)

**Build steps:**

```
mkdir build
cd build
cmake ..
make
``````

After building, run the executable:

```
./option_pricer
```

