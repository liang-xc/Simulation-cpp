#include <iostream>
#include <memory>
#include <random>

#include "EuropeanOption.hpp"
#include "EuropeanOptionPricer.hpp"
#include "MCEuropeanOptionPricer.hpp"
#include "Path.hpp"
#include "StochasticProcesses.hpp"
#include "Yield.hpp"

using namespace simu;

int main() {
  Dividend d(0.0);
  std::shared_ptr<SimpleYield> yptr{std::make_shared<SimpleYield>(0.0)};
  EuropeanOption opt(1.0, 1.0, 1, 0.16, yptr, d,
                     EuropeanOption::OptionType::call);
  BSEuropeanOptionPricer pricer(std::make_shared<EuropeanOption>(opt));
  std::cout << "Black-Scholes price: " << pricer.price() << std::endl;

  TimeGrid test_grid(1.0, 366);

  MCEuropeanOptionPricer<std::mt19937> mcpricer(
      std::make_shared<EuropeanOption>(opt),
      std::make_unique<TimeGrid>(test_grid), 10000);
  std::cout << "Monte Carlo price: " << mcpricer.price() << std::endl;
  return 0;
}
