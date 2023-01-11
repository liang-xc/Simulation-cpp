#include <memory>
#include <vector>

#include "TimeGrid.hpp"
namespace simu{
TimeGrid::TimeGrid(double end, std::size_t steps)
{
  double a = end/steps;
  for(auto n=0;n<steps;++n)
  {
    m_grid.push_back(a * (n + 1));
  }
}
TimeGrid::TimeGrid(double first, double end, std::size_t steps)
{
  double a = (end-first)/steps;
  for(auto n=0;n<steps;++n)
  {
    m_grid.push_back(first+a*(n+1));
  }
}

double TimeGrid::operator[](std::size_t i)
{
  return m_grid[i];
}

double TimeGrid::operator[](std::size_t i) const {return m_grid[i];}

}
