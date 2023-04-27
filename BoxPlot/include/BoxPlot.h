#include <vector>
#include <algorithm>
#include <cmath>

class BoxPlot {
public:
  static double min(const std::vector<double>& data) {
    double q1 = lq(data);
    double q3 = uq(data);
    double iqr = q3 - q1;
    return std::max(q1 - 1.5 * iqr, data.front());
  }

  static double lq(const std::vector<double>& data) {
    return data[0.25*data.size()];
  }

  static double median(const std::vector<double>& data) {
    int n = data.size();
    if (n % 2 == 0) {
      return (data[n / 2 - 1] + data[n / 2]) / 2.0;
    } else {
      return data[n / 2];
    }
  }

  static double mean(const std::vector<double>& data) {
    double sum = 0.0;
    for (const auto& x : data) {
      sum += x;
    }
    return sum / data.size();
  }

  static double stddev(const std::vector<double>& data) {
    double m = mean(data);
    double sum = 0.0;
    for (const auto& x : data) {
      sum += (x - m) * (x - m);
    }
    return std::sqrt(sum / (data.size() - 1));
  }

  static double uq(const std::vector<double>& data) {
    return data[0.75*data.size()];
  }

  static double max(const std::vector<double>& data) {
    double q1 = lq(data);
    double q3 = uq(data);
    double iqr = q3 - q1;
    return std::min(q3 + 1.5 * iqr, data.back());
  }

  static std::vector<double> out(const std::vector<double>& data) {
    double q1 = lq(data);
    double q3 = uq(data);
    double iqr = q3 - q1;
    double lowerBound = q1 - 1.5 * iqr;
    double upperBound = q3 + 1.5 * iqr;

    std::vector<double> out;
    for (const auto& x : data) {
      if (x < lowerBound || x > upperBound) {
        out.push_back(x);
      }
    }
    return out;
  }
};
