#ifndef SIMU_EUROPEAN_OPTION_PRICER_HPP
#define SIMU_EUROPEAN_OPTION_PRICER_HPP

#include <memory>

#include "EuropeanOption.hpp"

namespace simu {

class EuropeanOptionPricer {
 public:
  EuropeanOptionPricer() = default;
  virtual double price() const = 0;
  virtual ~EuropeanOptionPricer() = default;
  EuropeanOptionPricer(const EuropeanOptionPricer&) = delete;
  EuropeanOptionPricer& operator=(const EuropeanOptionPricer&) = delete;
  EuropeanOptionPricer(EuropeanOptionPricer&&) = delete;
  EuropeanOptionPricer& operator=(EuropeanOptionPricer&&) = delete;
};

class BSEuropeanOptionPricer : public EuropeanOptionPricer {
 public:
  BSEuropeanOptionPricer(std::shared_ptr<EuropeanOption> european_option_ptr);

  [[nodiscard]] double price() const override;

  ~BSEuropeanOptionPricer() override = default;
  BSEuropeanOptionPricer(const BSEuropeanOptionPricer& other) = delete;
  BSEuropeanOptionPricer& operator=(const BSEuropeanOptionPricer& rhs) = delete;
  BSEuropeanOptionPricer(const BSEuropeanOptionPricer&& other) noexcept =
      delete;
  BSEuropeanOptionPricer& operator=(BSEuropeanOptionPricer&& rhs) = delete;

 private:
  std::shared_ptr<EuropeanOption> m_optionPtr;

  double d1() const;
  double d2() const;
};
}  // namespace simu

#endif
