#ifndef SIMU_TIME_GRID_HPP
#define SIMU_TIME_GRID_HPP

#include <initializer_list>
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
  TimeGrid(double end, std::size_t steps); // evenly distributed
  TimeGrid(std::initializer_list<double> grid);
  TimeGrid(std::initializer_list<double> grid, std::size_t steps);

  double operator[](std::size_t i);
  double operator[](std::size_t i) const;

private:
  std::unique_ptr<std::vector<double>> grid;
};

}

#endif