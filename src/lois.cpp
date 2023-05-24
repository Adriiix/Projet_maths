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

double bernoulliTheorique(double p, int k) {
  double q = 1 - p;
  return pow(p, k) * pow(q, 1 - k);
}

int papier() {
  int X;
  if (bernoulliTheorique(0.3, 1) == 1) {
    X = 2;
  } else {
    X = 1;
  }

  return X;
}

int feuille() {
  int X;
  if (bernoulliTheorique(1, 1) == 1) {
    X = 2;
  } else {
    X = 1;
  }

  return X;
}

int ciseaux() {
  int X = 0;
  return X;
}