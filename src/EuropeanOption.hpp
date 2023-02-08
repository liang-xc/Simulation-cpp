#ifndef SIMU_EUROPEAN_OPTION_HPP
#define SIMU_EUROPEAN_OPTION_HPP

#include <memory>

#include "Date.hpp"
#include "Volatility.hpp"
#include "Yield.hpp"

namespace simu {

class EuropeanOption {
 public:
  enum class OptionType { call = 1, put = -1 };

  EuropeanOption(double current, double strike, double maturity, Date now_date,
                 std::shared_ptr<Volatility> vol,
                 std::shared_ptr<SimpleYield> risk_free_rate,
                 std::shared_ptr<Dividend> dividend_rate, OptionType type);

  EuropeanOption(double current, double strike, Date now_date, Date expire_date,
                 std::shared_ptr<Volatility> vol,
                 std::shared_ptr<SimpleYield> risk_free_rate,
                 std::shared_ptr<Dividend> dividend_rate, OptionType type);

  // Getters and Setters
  double get_spot() const;
  void set_spot(const double& current);
  double get_strike() const;
  void set_strike(const double& strike);
  double get_maturity() const;
  void set_maturity(const double& maturity);
  std::shared_ptr<Volatility> get_vol() const;
  void set_vol(std::shared_ptr<Volatility> vol);
  std::shared_ptr<SimpleYield> get_risk_free_rate() const;
  void set_risk_free_rate(std::shared_ptr<SimpleYield> risk_free_rate);
  std::shared_ptr<Dividend> get_dividend() const;
  void set_dividend(std::shared_ptr<Dividend> div);
  OptionType get_option_type() const;
  void set_option_type(OptionType type);

 private:
  double m_spot;
  double m_strike;
  double m_maturity;
  Date m_now_date;
  Date m_expire_date;
  std::shared_ptr<Volatility> m_vol;
  std::shared_ptr<SimpleYield> m_risk_free_rate;
  std::shared_ptr<Dividend> m_dividend_rate;
  OptionType m_type;
};

}  // namespace simu
#endif
