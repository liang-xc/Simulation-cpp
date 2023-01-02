#ifndef EUROPEAN_OPTION_PRICER_HPP
#define EUROPEAN_OPTION_PRICER_HPP

#include <memory>

#include "EuropeanOption.hpp"

namespace simu{

class EuropeanOptionPricer {
public:
  virtual ~EuropeanOptionPricer() = default;
  virtual double price() = 0;
};

class BSPricer : public EuropeanOptionPricer {
public:
  ~BSPricer() override;
  [[nodiscard]] double price() override;
private:
  std::shared_ptr<EuropeanOption> m_optionPtr;
};

class MCPricer : public EuropeanOptionPricer {
public:
  ~MCPricer() override;
  [[nodiscard]] double price() override;
private:
  std::shared_ptr<EuropeanOption> m_optionPtr;
};

}

#endif
