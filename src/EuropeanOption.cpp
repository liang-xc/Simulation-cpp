#include <memory>

#include "EuropeanOption.hpp"
#include "Yield.hpp"

namespace simu {

EuropeanOption::EuropeanOption(double current, double strike, double maturity, 
                               double vol, std::shared_ptr<SimpleYield> risk_free_rate, 
                               const Dividend& dividend_rate, OptionType type)
  : m_spot(current), m_strike(strike), m_maturity(maturity), m_vol(vol),
    m_risk_free_rate(std::move(risk_free_rate)), 
    m_dividend_rate(dividend_rate), m_type(type) {}

// Getters and Setters
double EuropeanOption::get_spot() const { return m_spot; }
void EuropeanOption::set_spot(const double& current) { m_spot = current; }
double EuropeanOption::get_strike() const { return m_strike; }
void EuropeanOption::set_strike(const double& strike) { m_strike = strike; }
double EuropeanOption::get_maturity() const { return m_maturity; }
void EuropeanOption::set_maturity(const double& maturity) { m_maturity = maturity; }
double EuropeanOption::get_vol() const { return m_vol; }
void EuropeanOption::set_vol(const double& vol) { m_vol = vol; }
std::shared_ptr<SimpleYield> EuropeanOption::get_risk_free_rate() const {
  return m_risk_free_rate; 
}
void EuropeanOption::set_risk_free_rate(std::shared_ptr<SimpleYield> risk_free_rate) {
  m_risk_free_rate = std::move(risk_free_rate);
}
Dividend EuropeanOption::get_dividend() const { return m_dividend_rate; }
void EuropeanOption::set_dividend(Dividend div) { m_dividend_rate = div; }
EuropeanOption::OptionType EuropeanOption::get_option_type() const { return m_type; }
void EuropeanOption::set_option_type(EuropeanOption::OptionType type) {
  m_type = type;
}

}
