#include <memory>

#include "EuropeanOption.hpp"
#include "Yield.hpp"

namespace simu {

EuropeanOption::EuropeanOption(double current, double strike, double maturity, 
                               double vol, const SimpleYield& risk_free_rate, 
                               const Dividend& dividend_rate, OptionType type)
  : m_current(current), m_strike(strike), m_maturity(maturity), m_vol(vol),
    m_risk_free_rate(std::make_shared<SimpleYield>(risk_free_rate)), 
    m_dividend_rate(dividend_rate), m_type(type) {}

}
