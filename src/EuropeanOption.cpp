#include "EuropeanOption.hpp"

#include <memory>

#include "Volatility.hpp"
#include "Yield.hpp"

namespace simu {

EuropeanOption::EuropeanOption(double current, double strike, double maturity,
                               std::shared_ptr<Volatility> vol,
                               std::shared_ptr<SimpleYield> risk_free_rate,
                               std::shared_ptr<Dividend> dividend_rate,
                               OptionType type)
    : m_spot(current),
      m_strike(strike),
      m_maturity(maturity),
      m_vol(std::move(vol)),
      m_risk_free_rate(std::move(risk_free_rate)),
      m_dividend_rate(std::move(dividend_rate)),
      m_type(type) {}

// Getters and Setters
double EuropeanOption::get_spot() const { return m_spot; }
void EuropeanOption::set_spot(const double& current) { m_spot = current; }
double EuropeanOption::get_strike() const { return m_strike; }
void EuropeanOption::set_strike(const double& strike) { m_strike = strike; }
double EuropeanOption::get_maturity() const { return m_maturity; }
void EuropeanOption::set_maturity(const double& maturity) {
  m_maturity = maturity;
}
std::shared_ptr<Volatility> EuropeanOption::get_vol() const { return m_vol; }
void EuropeanOption::set_vol(std::shared_ptr<Volatility> vol) {
  m_vol = std::move(vol);
}
std::shared_ptr<SimpleYield> EuropeanOption::get_risk_free_rate() const {
  return m_risk_free_rate;
}
void EuropeanOption::set_risk_free_rate(
    std::shared_ptr<SimpleYield> risk_free_rate) {
  m_risk_free_rate = std::move(risk_free_rate);
}
std::shared_ptr<Dividend> EuropeanOption::get_dividend() const {
  return m_dividend_rate;
}
void EuropeanOption::set_dividend(std::shared_ptr<Dividend> div) {
  m_dividend_rate = std::move(div);
}
EuropeanOption::OptionType EuropeanOption::get_option_type() const {
  return m_type;
}
void EuropeanOption::set_option_type(EuropeanOption::OptionType type) {
  m_type = type;
}

}  // namespace simu
