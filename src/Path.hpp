#ifndef SIMU_PATH_HPP
#define SIMU_PATH_HPP

#include <Eigen/Core>
#include <vector>

#include "TimeGrid.hpp"

namespace simu {
/*
 * Path class
 * used to store generated paths from Monte Carlo Simulation
 */
class Path {
 public:
  // Path is initialized to be all zeros
  Path(TimeGrid time_grid, std::size_t path_num);

  // return a vector of the values at the i-th time on the grid
  std::vector<double> at(std::size_t i);

 private:
  TimeGrid m_grid;
  std::vector<std::vector<double>> m_paths;
};

}  // namespace simu

#endif
