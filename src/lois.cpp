#include "lois.hpp"

int fac(int n) {
  if (n == 0 || n == 1) {
    return 1;
  } else {
    return n * fac(n - 1);
  }
}

bool simulerBernoulli(double p) {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_real_distribution<double> dis(0.0, 1.0);

  double randomNum = dis(gen);
  return randomNum <= p;
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

double exponentielle(double lambda) {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::exponential_distribution<double> dis(lambda);
  return dis(gen);
}

int simulerPoisson(double lambda) {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::poisson_distribution<int> dis(lambda);

  return dis(gen);
}

double simulerLoiNormale(double moyenne, double ecartType) {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::normal_distribution<double> dis(moyenne, ecartType);

  return dis(gen);
}

int pierre(int choixUtilisateur) {
  int X;
  double valeurAleatoire = uniforme(); // Stocke la valeur générée
  if (valeurAleatoire < 0.33) {
    X = 0; // Pierre
  } else if (valeurAleatoire < 0.66) {
    X = 1; // Feuille
  } else {
    X = 2; // Ciseaux
  }
  return X;
}

int feuille(int choixUtilisateur) {
  int X;
  if (choixUtilisateur == 1) { // si le joueur a joué Feuille
    if (simulerBernoulli(0.8)) {
      X = 0; // Pierre
    } else {
      X = 1; // Feuille
    }
    // Ciseaux ne pas être rejoué dans ce cas là
  }

  else if (choixUtilisateur == 0) { // si le joueur a joué Pierre
    if (simulerBernoulli(0.6)) {
      X = 2; // Ciseaux
    } else {
      X = 0; // Pierre
    }
    // Feuille ne pas être rejoué dans ce cas là
  }

  else { // si le joueur a joué Ciseaux
    if (simulerBernoulli(0.2)) {
      X = 2; // Ciseaux
    } else {
      X = 1; // Feuille
    }
    // Pierre ne pas être rejoué dans ce cas là
  }

  return X;
}

int ciseaux(int choixUtilisateur) {
  int X;
  if (choixUtilisateur == 0) { // si le joueur a joué Pierre
    double valeurAleatoire = exponentielle(0.6);
    if (valeurAleatoire <= 1) {
      X = 1; // Feuille
    } else if (valeurAleatoire <= 2) {
      X = 0; // Pierre
    } else {
      X = 2; // Ciseaux
    }
  }

  if (choixUtilisateur == 1) { // si le joueur a joué Feuille
    double valeurAleatoire = simulerPoisson(1.5);
    if (valeurAleatoire <= 0) {
      X = 2; // Ciseaux
    } else if (valeurAleatoire <= 2.5) {
      X = 0; // Pierre
    } else {
      X = 1; // Feuille
    }
  }

  if (choixUtilisateur == 2) { // si le joueur a joué Feuille
    double valeurAleatoire = simulerLoiNormale(1, 2);
    if (valeurAleatoire <= 0.5) {
      X = 0; // Pierre
    } else if (valeurAleatoire <= 2.5) {
      X = 2; // Ciseaux
    } else {
      X = 1; // Feuille
    }
  }

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

int definirChoixOrdinateur(int &choixOrdinateur, int choixUtilisateur) {

  if (choixOrdinateur == 0) { // si l'ordi a joué Pierre au tour précédent
    choixOrdinateur = pierre(choixUtilisateur);
  } else if (choixOrdinateur ==
             1) { // si l'ordi a joué Feuille au tour précédent
    choixOrdinateur = feuille(choixUtilisateur);
  } else { // si l'ordi a joué Ciseaux au tour précédent
    choixOrdinateur = ciseaux(choixUtilisateur);
  }
}