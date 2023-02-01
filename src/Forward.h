
//This file includes the basic Discount class: term structure, basic interpolate and Rate term structure -> Forward
#ifndef EUROPEANOPTIONPRICER_CPP_FORWARD_H
#define EUROPEANOPTIONPRICER_CPP_FORWARD_H
#include<Date.h>
#include"algorithm"
class Discount {
 public:
  Discount()=default;
  Discount (Date valuation_date,
           const std::vector<Date> &dates,
           const std::vector<double> &rates);
  double discount(Date expiry) const;
  Date valuation_date() const {
    return m_valuation_date;
  }
 private:
  Date m_valuation_date;
  std::vector<double> m_Ts;
  std::vector<double> m_rate;
  inline double get_T(Date expiry) const
  {
    return  (expiry-m_valuation_date)/365.0;
  }
};
//interpolate
double interpolate_lb(double x, size_t lb,
                      const std::vector<double> &xs, const std::vector<double> &ys);
double interpolate(double x,
                   const std::vector<double> &xs,
                   const std::vector<double> &ys);
//Forward


#endif  // EUROPEANOPTIONPRICER_CPP_FORWARD_H
