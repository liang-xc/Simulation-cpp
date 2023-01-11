#include "Yield.hpp"

#include <cmath>

namespace simu {

SimpleYield::SimpleYield(const double rate) : m_rate(rate) {}

double SimpleYield::discount_factor(double maturity) const {
  return std::exp(-m_rate * maturity);
}

void SimpleYield::set_rate(double rate) { m_rate = rate; }
double SimpleYield::get_rate() const { return m_rate; }

Dividend::Dividend(const double div) : m_div(div) {}

double Dividend::discount_factor(double maturity) const {
  return std::exp(-m_div * maturity);
}

double Dividend::get_div() const { return m_div; }
void Dividend::set_div(double div) { m_div = div; }
}  // namespace simu
