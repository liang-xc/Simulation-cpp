#include "TimeGrid.hpp"

#include <memory>
#include <stdexcept>
#include <vector>

namespace simu {

TimeGrid::TimeGrid(double end, std::size_t steps) {
  double a = end / steps;
  for (std::size_t n = 0; n < steps; ++n) {
    m_grid.push_back(a * (n + 1));
  }
}

TimeGrid::TimeGrid(double first, double end, std::size_t steps) {
  double a = (end - first) / steps;
  for (std::size_t n = 0; n < steps; ++n) {
    m_grid.push_back(first + a * (n + 1));
  }
}

TimeGrid::TimeGrid(std::initializer_list<double> grid)
    : m_grid(grid.begin(), grid.end()) {}

double TimeGrid::operator[](std::size_t i) {
  return i < m_grid.size() ? m_grid[i] : throw std::out_of_range("");
}

double TimeGrid::operator[](std::size_t i) const {
  return i < m_grid.size() ? m_grid[i] : throw std::out_of_range("");
}

std::size_t TimeGrid::size() const { return m_grid.size(); }

}  // namespace simu
