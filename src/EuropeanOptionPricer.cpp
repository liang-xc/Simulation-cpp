#include "EuropeanOptionPricer.hpp"

#include <cmath>
#include <memory>

#include "EuropeanOption.hpp"
#include "utilities.hpp"

namespace simu {

BSEuropeanOptionPricer::BSEuropeanOptionPricer(
    std::shared_ptr<EuropeanOption> european_option_pricer)
    : m_optionPtr(std::move(european_option_pricer)) {}

double BSEuropeanOptionPricer::price() const {
  int call_flag =
      (m_optionPtr->get_option_type()) == EuropeanOption::OptionType::call ? 1
                                                                           : -1;
  return call_flag * m_optionPtr->get_spot() *
             m_optionPtr->get_dividend()->discount_factor(
                 m_optionPtr->get_maturity()) *
             norm_cdf(call_flag * d1()) -
         call_flag * m_optionPtr->get_strike() *
             m_optionPtr->get_risk_free_rate()->discount_factor(
                 m_optionPtr->get_maturity()) *
             norm_cdf(call_flag * d2());
}

double BSEuropeanOptionPricer::d1() const {
  return (std::log(m_optionPtr->get_spot() / m_optionPtr->get_strike()) +
          (m_optionPtr->get_risk_free_rate()->get_rate() -
           m_optionPtr->get_dividend()->get_div() +
           m_optionPtr->get_vol()->get_vol() *
               m_optionPtr->get_vol()->get_vol() / 2) *
              m_optionPtr->get_maturity()) /
         (m_optionPtr->get_vol()->get_vol() *
          std::sqrt(m_optionPtr->get_maturity()));
}

double BSEuropeanOptionPricer::d2() const {
  return d1() - m_optionPtr->get_vol()->get_vol() * m_optionPtr->get_maturity();
}

}  // namespace simu
