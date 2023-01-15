#ifndef SIMU_STOCHASTIC_PROCESSES_HPP
#define SIMU_STOCHASTIC_PROCESSES_HPP

#include <cmath>
#include <memory>
#include <random>
#include <vector>

#include "Path.hpp"
#include "TimeGrid.hpp"

namespace simu {

template <class RNG>
class StochasticProcess1d {
 public:
  virtual ~StochasticProcess1d() = default;
  virtual Path generate_path(std::size_t path_num) = 0;
};

template <class RNG>
class GeometricBrownianMotion : StochasticProcess1d<RNG> {
 public:
  GeometricBrownianMotion() = delete;
  GeometricBrownianMotion(std::unique_ptr<TimeGrid> grid, double x0,
                          double drift, double sigma);
  ~GeometricBrownianMotion() override = default;
  [[nodiscard]] Path generate_path(std::size_t path_num) override;

 private:
  std::unique_ptr<TimeGrid> m_grid;
  double m_x0;
  double m_drift;
  double m_sigma;
};

template <class RNG>
GeometricBrownianMotion<RNG>::GeometricBrownianMotion(
    std::unique_ptr<TimeGrid> grid, double x0, double drift, double sigma)
    : m_grid(std::move(grid)), m_x0(x0), m_drift(drift), m_sigma(sigma) {}

template <class RNG>
Path GeometricBrownianMotion<RNG>::generate_path(std::size_t path_num) {
  Path result(*m_grid, path_num);
  RNG rng;
  std::normal_distribution<double> distribution(0, 1);
  for (std::size_t i = 0; i < path_num; ++i) {
    result.assign(i, 0, m_x0);
    for (std::size_t j = 1; j < m_grid->size(); ++j) {
      double dW = distribution(rng);
      double dt = (*m_grid)[j] - (*m_grid)[j - 1];
      double s_plus = result.at(i, j - 1) *
                      std::exp((m_drift - 0.5 * m_sigma * m_sigma) * dt +
                               m_sigma * std::sqrt(dt) * dW);
      result.assign(i, j, s_plus);
    }
  }
  return result;
}

}  // namespace simu

#endif
