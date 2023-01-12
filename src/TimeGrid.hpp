#ifndef SIMU_TIME_GRID_HPP
#define SIMU_TIME_GRID_HPP

#include <initializer_list>
#include <iterator>
#include <memory>
#include <vector>

namespace simu {
/*
 * TimeGrid class
 * Uses a std::vector<double> to store the time grid
 * Each entry within the vector defines the positive time difference
 * from the starting point in fraction of a year
 */
class TimeGrid {
 public:
  TimeGrid() = default;
  // evenly distributed, default first number is 0;
  TimeGrid(double end, std::size_t steps);
  TimeGrid(double first, double end,
                    std::size_t steps);  // (first, end]
  template<class Iterator>
  TimeGrid(Iterator begin, Iterator end) : m_grid(begin, end) {}
  TimeGrid(std::initializer_list<double> grid);

  double operator[](std::size_t i);
  double operator[](std::size_t i) const;

  std::size_t size() const;

 private:
  std::vector<double> m_grid;
};

}  // namespace simu

#endif
