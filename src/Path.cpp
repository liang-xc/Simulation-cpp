#include "Path.hpp"

#include <iostream>
#include <vector>

namespace simu {

Path::Path(const TimeGrid& time_grid, std::size_t path_num)
    : m_grid(time_grid),
      m_paths(path_num, std::vector<double>(time_grid.size(), 0.0)) {}

std::vector<double> Path::at_t(std::size_t i) const {
  std::vector<double> result;
  for (const auto& path : m_paths) {
    result.push_back(path[i]);
  }
  return result;
}

std::vector<double> Path::path(std::size_t path_i) const {
  return m_paths[path_i];
}

double Path::at(std::size_t path_i, std::size_t t_i) const {
  return m_paths[path_i][t_i];
}

void Path::assign(std::size_t path_i, std::size_t t_i, double value) {
  m_paths[path_i][t_i] = value;
}

void Path::show() const {
  for (const auto& path : m_paths) {
    for (const auto& v : path) {
      std::cout << v << '\t';
    }
    std::cout << '\n';
  }
}

}  // namespace simu
