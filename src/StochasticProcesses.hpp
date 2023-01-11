#ifndef SIMU_STOCHASTIC_PROCESSES_HPP
#define SIMU_STOCHASTIC_PROCESSES_HPP

#include <memory>
#include <vector>

#include "TimeGrid.hpp"

namespace simu {

class StochasticProcess1d {
 public:
};

class GeometricBrownianMotion : StochasticProcess1d {
 public:
  GeometricBrownianMotion() = default;

 private:
  std::unique_ptr<TimeGrid> grid;
  double x0;
  double drift;
  double sigma;
};

}  // namespace simu

#endif
