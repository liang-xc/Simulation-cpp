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
  Path(const TimeGrid& time_grid, std::size_t path_num);

  // return a vector of the values at the i-th time on the grid
  std::vector<double> at_t(std::size_t i) const;

  std::vector<double> path(std::size_t path_i) const;

  double at(std::size_t path_i, std::size_t t_i) const;

  void assign(std::size_t path_i, std::size_t t_i, double value);

  void show() const;

 private:
  TimeGrid m_grid;
  std::vector<std::vector<double>> m_paths;
};

}  // namespace simu

#endif
