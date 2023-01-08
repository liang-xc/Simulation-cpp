#include <iostream>
#include <memory>

#include "Yield.hpp"
#include "EuropeanOption.hpp"
#include "EuropeanOptionPricer.hpp"

using namespace simu;

int main() {
  SimpleYield y(0.0);  
  Dividend d(0.0);
  std::shared_ptr<SimpleYield> yptr = std::make_shared<SimpleYield>(y);  
  EuropeanOption opt(100.0, 100.0, 1, 0.3, yptr, d, EuropeanOption::OptionType::call);
  BSEuropeanOptionPricer pricer(std::make_shared<EuropeanOption>(opt));
  std::cout << "Black-Scholes price: " << pricer.price() << std::endl;
  return 0;
}
