#ifndef YIELD_HPP
#define YIELD_HPP

namespace simu {

class Yield {
public:
  double discount_factor(double maturity) const;

private:
  double m_rate;
};

class Dividend : public Yield {
private:
  double m_div;
};
}

#endif
