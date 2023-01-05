#include <cmath>
#include <numbers>

#include "utilities.hpp"

namespace simu {

double norm_pdf(const double& x) {
  return 1.0 / std::sqrt(2 * std::numbers::pi) * std::exp(-0.5 * x * x);
}

// standard normal cumulative distribution function
// Reference: https://en.cppreference.com/w/cpp/numeric/math/erfc
double norm_cdf(const double& x) {
  return std::erfc(-x / std::sqrt(2)) / 2;
}


}
