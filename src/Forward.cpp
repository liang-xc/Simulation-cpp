

#include "Forward.h"
Discount::Discount(Date valuation_date,
                   const std::vector<Date> &dates,
                   const std::vector<double> &rates):m_valuation_date(valuation_date),m_Ts(dates.size()),m_rate(rates)
{
  for (int i1=0;i1<dates.size();i1++) {
    m_Ts[i1]=(dates[i1]-m_valuation_date)/365;
  }
}
double interpolate_lb(double x, size_t lb,
                      const std::vector<double> &xs, const std::vector<double> &ys) {
  if (lb==0) {
    return ys.front();
  }
  if (lb==ys.size()) {
    return ys.back();
  }
  else {
    double x0=xs[lb-1];
    double x1=xs[lb];
    double y0=ys[lb-1];
    double y1=ys[lb];
    return y0 + (x-x0)*(y1-y0)/(x1-x0);
  }

}
double interpolate(double x,
                   const std::vector<double> &xs,
                   const std::vector<double> &ys) {
  auto it=std::lower_bound(xs.begin(),xs.end(),x);
  auto lb=it-xs.begin();
  return interpolate_lb(x,lb,xs,ys);
}
