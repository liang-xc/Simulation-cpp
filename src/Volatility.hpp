#ifndef SIMU_VOLATILITY_HPP
#define SIMU_VOLATILITY_HPP

namespace simu {

class Volatility {
 public:
  Volatility() = default;
  Volatility(double vol);
  virtual ~Volatility() = default;

  double get_vol() const;
  void set_vol(const double& vol);

 private:
  double m_vol = 0;
};
}  // namespace simu

#endif
