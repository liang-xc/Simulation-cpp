#ifndef YIELD_HPP
#define YIELD_HPP

namespace simu {

class Yield {
public:
  virtual double discount_factor(double maturity) const = 0;
};

class SimpleYield : public Yield {
public:
  SimpleYield(const double rate);
  double discount_factor(double maturity) const override;

private:
  double m_rate;
};

class Dividend : public Yield {
public:
  Dividend(const double div);
  double discount_factor(double maturity) const override;
private:
  double m_div;
};
}

#endif
