#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
#include "timer.hpp"

using std::sin, std::vector, std::sort;

vector<double> generate_list(int N) {
  vector<double> list;
  for(int i=0; i<N; ++i) {
    list.push_back(sin(0.7*i*M_PI));
  }
  return list;
}

double slow_min() {
  auto list = generate_list(1'000'000);
  sort(list.begin(), list.end());
  return list[0];
}

double fast_min() {
  double min = 0.0;
  for(int i=0; i<1'000'000; ++i) {
    min = std::min(min, sin(0.7*i*M_PI));
  }
  return min;
}

int main() {
  const int N_ITERATIONS = 10;
  Timer timer;

  for(int i=0; i<N_ITERATIONS; ++i) {
    fast_min();
  }

  std::cout << "Fast: " << timer.elapsed()/N_ITERATIONS << '\n';

  timer.reset();

  for(int i=0; i<N_ITERATIONS; ++i) {
    slow_min();
  }

  std::cout << "Slow: " << timer.elapsed()/N_ITERATIONS << '\n';
}
