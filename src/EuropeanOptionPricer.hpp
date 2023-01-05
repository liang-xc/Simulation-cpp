#ifndef EUROPEAN_OPTION_PRICER_HPP
#define EUROPEAN_OPTION_PRICER_HPP

#include <memory>

#include "EuropeanOption.hpp"

namespace simu{

class EuropeanOptionPricer {
public:
  virtual double price() = 0;
};

class BSEuropeanOptionPricer : public EuropeanOptionPricer {
public:
  BSEuropeanOptionPricer(std::shared_ptr<EuropeanOption> european_option_ptr);
  [[nodiscard]] double price() override;

private:
  std::shared_ptr<EuropeanOption> m_optionPtr;
  
  double d1();
  double d2();
};

class MCEuropeanOptionPricer : public EuropeanOptionPricer {
public:
  [[nodiscard]] double price() override;
private:
  std::shared_ptr<EuropeanOption> m_optionPtr;
};

}

#endif
