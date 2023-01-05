#ifndef SIMU_YIELD_HPP
#define SIMU_YIELD_HPP

namespace simu {

class Yield {
public:
  virtual double discount_factor(double maturity) const = 0;
};

class SimpleYield : public Yield {
public:
  SimpleYield(const double rate);

  double discount_factor(double maturity) const override;

  double get_rate() const;
  void set_rate(double rate);

private:
  double m_rate;
};

class Dividend : public Yield {
public:
  Dividend(const double div);

  double discount_factor(double maturity) const override;

  double get_div() const;
  void set_div(double div);

private:
  double m_div;
};
}

#endif
