#include <cmath>

#include "Yield.hpp"

namespace simu {

SimpleYield::SimpleYield(const double rate) : m_rate(rate) {}

double SimpleYield::discount_factor(double maturity) const {
  return std::exp(-m_rate * maturity);
}

Dividend::Dividend(const double div) : m_div(div) {}

double Dividend::discount_factor(double maturity) const {
  return std::exp(-m_div * maturity);
}

}
