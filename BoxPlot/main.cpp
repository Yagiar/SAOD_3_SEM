#include <iostream>
#include "BoxPlot.h"
int main() {
  const std::vector<double> x = {0.0855298042e+00,1.4513241053e+00,1.3237277269e+00,1.0128350258e+00,1.4122089148e+00,6.5826654434e-01,2.0795986652e+00,1.0230206251e+00,1.4231411219e+00,1.1091691256e+00,1.7714337111e+00,1.3986129761e+00,1.0640757084e+00,1.4216910601e+00,1.2402026653e+00};
  std::cout.precision(2);
  std::cout << std::scientific << "min:    " <<  BoxPlot::min(x) << std::endl;
  std::cout << std::scientific << "lq:     " <<  BoxPlot::lq(x) << std::endl;
  std::cout << std::scientific << "median: " <<  BoxPlot::median(x) << std::endl;
  std::cout << std::scientific << "mean:   " <<  BoxPlot::mean(x) << std::endl;
  std::cout << std::scientific << "stddev: " <<  BoxPlot::stddev(x) << std::endl;
  std::cout << std::scientific << "uq:     " <<  BoxPlot::uq(x) << std::endl;
  std::cout << std::scientific << "max:    " <<  BoxPlot::max(x) << std::endl;
  auto out = BoxPlot::out(x);
  std::cout << "out: ";
  for(const auto & it : out)
    std::cout << std::scientific << it << " ";
  std::cout << std::endl;
}
