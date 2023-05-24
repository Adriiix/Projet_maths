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

double uniforme() {
  // Initialisation du générateur de nombres aléatoires
  std::random_device rd;
  std::mt19937 gen(rd());

  // Définition de la distribution uniforme sur [0, 1)
  std::uniform_real_distribution<double> dis(0.0, 1.0);

  // Génération d'un nombre aléatoire selon la distribution uniforme
  double r = dis(gen);
  return r;
}

int multinomiale(double proba1, double proba2, double proba3) {
  // Probabilités de chaque choix
  std::vector<double> probabilites = {proba1, proba2, proba3};

  // Initialisation du générateur de nombres aléatoires
  std::random_device rd;
  std::mt19937 gen(rd());

  // Création de la distribution multinomiale avec les probabilités données
  std::discrete_distribution<int> dis(probabilites.begin(), probabilites.end());

  // Génération d'un nombre aléatoire selon la distribution multinomiale
  int r = dis(gen);

  return r;
}

int papier() {
  int X;
  double valeurAleatoire = uniforme(); // Stocke la valeur générée
  if (valeurAleatoire < 0.33) {
    X = 0;
  } else if (valeurAleatoire < 0.66) {
    X = 1;
  } else {
    X = 2;
  }

  return X;
}

int feuille() {
  int X;
  double valeurAleatoire = uniforme(); // Stocke la valeur générée
  if (valeurAleatoire < 0.33) {
    X = 0;
  } else if (valeurAleatoire < 0.66) {
    X = 1;
  } else {
    X = 2;
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