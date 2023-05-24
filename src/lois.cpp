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

int demanderChoixUtilisateur() {
  std::cout << "Choisissez votre coup : p (Pierre), f (Feuille), c (Ciseaux)"
            << std::endl;
  char saisieUtilisateur;
  std::cin >> saisieUtilisateur;

  if (saisieUtilisateur == 'p' || saisieUtilisateur == 'P') {
    return 0; // Pierre
  } else if (saisieUtilisateur == 'f' || saisieUtilisateur == 'F') {
    return 1; // Feuille
  } else if (saisieUtilisateur == 'c' || saisieUtilisateur == 'C') {
    return 2; // Ciseaux
  } else {
    std::cout << "Choix invalide. Veuillez réessayer." << std::endl;
    return demanderChoixUtilisateur(); // Appel récursif pour demander une
                                       // nouvelle saisie
  }
}

std::string getNomCoup(int coup) {
  if (coup == 0) {
    return "Pierre";
  } else if (coup == 1) {
    return "Feuille";
  } else {
    return "Ciseaux";
  }
}

void afficherResultat(int choixUtilisateur, int choixOrdinateur) {
  std::cout << "L'ordinateur joue : " << getNomCoup(choixOrdinateur)
            << std::endl;

  if (choixUtilisateur == choixOrdinateur) {
    std::cout << "Egalité !" << std::endl;
  } else if ((choixUtilisateur == 0 && choixOrdinateur == 2) ||
             (choixUtilisateur == 1 && choixOrdinateur == 0) ||
             (choixUtilisateur == 2 && choixOrdinateur == 1)) {
    std::cout << "Vous avez gagné !" << std::endl;
  } else {
    std::cout << "L'ordinateur a gagné !" << std::endl;
  }
}