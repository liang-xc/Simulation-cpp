#ifndef SIMU_STOCHASTIC_PROCESSES_HPP
#define SIMU_STOCHASTIC_PROCESSES_HPP

#include <memory>
#include <random>
#include <vector>

#include "Path.hpp"
#include "TimeGrid.hpp"

namespace simu {

template<class RNG>
class StochasticProcess1d {
 public:
  virtual ~StochasticProcess1d() = default;
  virtual Path generate_path() = 0;
};

template<class RNG>
class GeometricBrownianMotion : StochasticProcess1d<RNG> {
 public:
  GeometricBrownianMotion() = delete;
  GeometricBrownianMotion(std::unique_ptr<TimeGrid> grid, double x0,
                          double drift, double sigma);
  ~GeometricBrownianMotion() override = default;
  Path generate_path(std::size_t path_num) override;

 private:
  std::unique_ptr<TimeGrid> m_grid;
  double m_x0;
  double m_drift;
  double m_sigma;
};

template<class RNG>
GeometricBrownianMotion<RNG>::GeometricBrownianMotion(
    std::unique_ptr<TimeGrid> grid, double x0, double drift, double sigma)
    : m_grid(std::move(grid)), m_x0(x0), m_drift(drift), m_sigma(sigma) {}

template<class RNG>
Path GeometricBrownianMotion<RNG>::generate_path(std::size_t path_num) {
  Path result(*m_grid, path_num);
  RNG rng;
  std::normal_distribution<double> distribution{};
  for (std::size_t i = 1; i < path_num; ++i) {
    for (std::size_t j = 1; j < m_grid->size(); ++j) {
      double rnum = distribution(rng);

    }
  }
  return result;
}

}  // namespace simu

#endif
