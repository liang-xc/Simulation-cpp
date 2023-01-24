#ifndef SIMU_MC_EUROPEAN_OPTION_PRICER_HPP
#define SIMU_MC_EUROPEAN_OPTION_PRICER_HPP

#include <algorithm>
#include <iostream>
#include <memory>
#include <numeric>

#include "EuropeanOptionPricer.hpp"
#include "StochasticProcesses.hpp"

namespace simu {

template <class RNG>
class MCEuropeanOptionPricer : EuropeanOptionPricer {
 public:
  MCEuropeanOptionPricer() = delete;
  MCEuropeanOptionPricer(std::shared_ptr<EuropeanOption> opt_ptr,
                         std::unique_ptr<TimeGrid> time_grid_ptr,
                         std::size_t path_num);
  ~MCEuropeanOptionPricer() override = default;
  MCEuropeanOptionPricer(const MCEuropeanOptionPricer&) = delete;
  MCEuropeanOptionPricer& operator=(const MCEuropeanOptionPricer&) = delete;
  MCEuropeanOptionPricer(MCEuropeanOptionPricer&&) = delete;
  MCEuropeanOptionPricer& operator=(MCEuropeanOptionPricer&&) = delete;
  [[nodiscard]] double price() const override;

 private:
  std::shared_ptr<EuropeanOption> m_opt_ptr;
  std::unique_ptr<TimeGrid> m_time_grid;
  std::size_t m_path_num{};
};

template <class RNG>
MCEuropeanOptionPricer<RNG>::MCEuropeanOptionPricer(
    std::shared_ptr<EuropeanOption> opt_ptr,
    std::unique_ptr<TimeGrid> time_grid_ptr, std::size_t path_num)
    : m_opt_ptr(std::move(opt_ptr)),
      m_time_grid(std::move(time_grid_ptr)),
      m_path_num(path_num) {}

template <class RNG>
double MCEuropeanOptionPricer<RNG>::price() const {
  TimeGrid t = *m_time_grid;
  GeometricBrownianMotion<RNG> gbm(std::make_unique<TimeGrid>(t),
                                   m_opt_ptr->get_spot(),
                                   m_opt_ptr->get_risk_free_rate()->get_rate(),
                                   m_opt_ptr->get_vol()->get_vol());
  Path path = gbm.generate_path(m_path_num);
  std::vector<double> payoff = path.at_t(m_time_grid->size() - 1);
  for (auto& v : payoff) {
    if (m_opt_ptr->get_option_type() == EuropeanOption::OptionType::call) {
      v -= m_opt_ptr->get_strike();
    } else {
      v = m_opt_ptr->get_strike() - v;
    }
    if (v < 0) v = 0;
  }
  double result = std::accumulate(payoff.begin(), payoff.end(), 0.0) /
                  double(payoff.size());
  return result;
}

}  // namespace simu

#endif
