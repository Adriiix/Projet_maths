#include "lois.hpp"

int de() { return rand() % 6 + 1; }

int fac(int n) {
  if (n == 0 || n == 1) {
    return 1;
  } else {
    return n * fac(n - 1);
  }
}

void binomialTheorique(int n, double p, int k) {
  double q, binomial;
  // Calcul des coefficients binomiaux
  q = 1 - p;
  binomial = static_cast<double>(fac(n)) / (fac(k) * fac(n - k)) * pow(p, k) *
             pow(q, n - k);
  std::cout << "La probabilité de X=" << k
            << " dans une distribution binomiale avec n=" << n << " et p=" << p
            << " est " << binomial << std::endl;
}
