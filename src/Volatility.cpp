#include "Volatility.hpp"

#include <utility>

namespace simu {

Volatility::Volatility(double vol) : m_vol(vol) {}

double Volatility::get_vol() const { return m_vol; }

void Volatility::set_vol(const double& vol) { m_vol = vol; }

}  // namespace simu
