#ifndef EUROPEANOPTION_HPP
#define EUROPEANOPTION_HPP

#include <memory>

#include "Yield.hpp"

namespace simu {

class EuropeanOption {
public:
  enum class OptionType { call = 1, put=-1 };

  EuropeanOption(double current,
                 double strike, 
                 double maturity, 
                 double vol, 
                 const SimpleYield& risk_free_rate, 
                 const Dividend& dividend_rate,
                 OptionType type);

  // Getters and Setters

private:
  double m_current;
  double m_strike;
  double m_maturity;
  double m_vol;
  std::shared_ptr<SimpleYield> m_risk_free_rate;
  Dividend m_dividend_rate;
  OptionType m_type;
};

}
#endif
