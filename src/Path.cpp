#include "Path.hpp"

#include <vector>

namespace simu {

Path::Path(TimeGrid time_grid, std::size_t path_num)
    : m_grid(std::move(time_grid)),
      m_paths(path_num, std::vector<double>(time_grid.size(), 0.0)) {}

std::vector<double> Path::at(std::size_t i) {
  std::vector<double> result;
  for (auto& path : m_paths) {
    result.push_back(path[i]);
  }
  return result;
}

}  // namespace simu
