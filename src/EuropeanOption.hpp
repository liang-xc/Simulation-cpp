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
                 std::shared_ptr<SimpleYield> risk_free_rate, 
                 const Dividend& dividend_rate,
                 OptionType type);

  // Getters and Setters
  double get_current() const;
  void set_current(const double& current);
  double get_strike() const;
  void set_strike(const double& strike);
  double get_maturity() const;
  void set_maturity(const double& maturity);
  double get_vol() const;
  void set_vol(const double& vol);
  std::shared_ptr<SimpleYield> get_risk_free_rate() const;
  void set_risk_free_rate(std::shared_ptr<SimpleYield> risk_free_rate);
  Dividend get_dividend() const;
  void set_dividend(Dividend div);
  OptionType get_option_type() const;
  void set_option_type(OptionType type);

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
