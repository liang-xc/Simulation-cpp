#include <iostream>
#include <memory>

#include "EuropeanOption.hpp"
#include "EuropeanOptionPricer.hpp"
#include "StochasticProcesses.hpp"
#include "Path.hpp"
#include "Yield.hpp"

using namespace simu;

int main() {
  Dividend d(0.0);
  std::shared_ptr<SimpleYield> yptr{std::make_shared<SimpleYield>(0.0)};
  EuropeanOption opt(100.0, 100.0, 1, 0.3, yptr, d,
                     EuropeanOption::OptionType::call);
  BSEuropeanOptionPricer pricer(std::make_shared<EuropeanOption>(opt));
  std::cout << "Black-Scholes price: " << pricer.price() << std::endl;

  TimeGrid test_grid(1, 30);
  Path p(test_grid, 10'000);
  return 0;
}
