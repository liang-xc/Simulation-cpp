#ifndef EUROPEANOPTION_HPP
#define EUROPEANOPTION_HPP

#include "Yield.hpp"

namespace simu {

class EuropeanOption {
public:
  enum class OptionType { call = 1, put=-1 };

  EuropeanOption() = default;
  EuropeanOption(double current,
                 double strike, 
                 double maturity, 
                 double vol, 
                 Yield risk_free_rate, 
                 Yield dividend_rate,
                 OptionType type);
  virtual ~EuropeanOption();
  EuropeanOption(const EuropeanOption& other) noexcept;
  EuropeanOption& operator=(const EuropeanOption& other) noexcept;
  EuropeanOption(const EuropeanOption&& other) noexcept;
  EuropeanOption& operator=(const EuropeanOption&& other) noexcept;

  // Getters and Setters

private:
  double m_current;
  double m_strike;
  double m_maturity;
  double m_vol;
  Yield m_risk_free_rate;
  Dividend m_dividend_rate;
  OptionType m_type;
};

}
#endif
