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

int pierre() {
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

int feuille() {
  int X;
  if (simulerBernoulli(0.6)) {
    X = 2; // Ciseaux
  } else {
    X = 0; // Pierre
  }
  // Feuille ne pas être rejoué
  return X;
}

int ciseaux() {
  int X;
  double valeurAleatoire = exponentielle(0.6);
  if (valeurAleatoire <= 1) {
    X = 1; // Feuille
  } else if (valeurAleatoire <= 2) {
    X = 0; // Pierre
  } else {
    X = 2; // Ciseaux
  }
  return X;
}

// int choixSuivant(int choixUtilisateurPrecedent, int choixOrdinateurPrecedent)
// {
//   if (choixUtilisateurPrecedent == 0 && choixOrdinateurPrecedent == 0) {
//     // Les deux joueurs ont joué Pierre au tour précédent
//     // Définir ici la logique de choix suivant de l'ordinateur
//     // Par exemple, si l'ordinateur a 60% de chances de jouer Feuille et 40%
//     de chances de jouer Ciseaux : if (simulerBernoulli(0.6)) {
//       return 1; // Feuille
//     } else {
//       return 2; // Ciseaux
//     }
//   } else if (choixUtilisateurPrecedent == 0 && choixOrdinateurPrecedent == 1)
//   {
//     // Situation spécifique lorsque l'utilisateur a joué Pierre et
//     l'ordinateur a joué Feuille au tour précédent
//     // Définir ici la logique de choix suivant de l'ordinateur pour cette
//     situation
//     // Par exemple, si l'ordinateur a 70% de chances de jouer Pierre et 30%
//     de chances de jouer Ciseaux : if (simulerBernoulli(0.7)) {
//       return 0; // Pierre
//     } else {
//       return 2; // Ciseaux
//     }
//   } else {
//     // Situation par défaut pour les autres cas
//     // Utiliser la logique existante pour déterminer le choix suivant de
//     l'ordinateur return choixOrdinateurPrecedent; // Utiliser le choix
//     précédent de l'ordinateur
//   }
// }

int demanderChoixUtilisateur(std::vector<int> &historiqueUtilisateur) {
  std::cout << "Choisissez votre coup : p (Pierre), f (Feuille), c (Ciseaux)"
            << std::endl;
  char saisieUtilisateur;
  std::cin >> saisieUtilisateur;

  if (saisieUtilisateur == 'p' || saisieUtilisateur == 'P') {
    historiqueUtilisateur.push_back(0);
    return 0; // Pierre
  } else if (saisieUtilisateur == 'f' || saisieUtilisateur == 'F') {
    historiqueUtilisateur.push_back(1);
    return 1; // Feuille
  } else if (saisieUtilisateur == 'c' || saisieUtilisateur == 'C') {
    historiqueUtilisateur.push_back(2);
    return 2; // Ciseaux
  } else {
    std::cout << "Choix invalide. Veuillez réessayer." << std::endl;
    return demanderChoixUtilisateur(
        historiqueUtilisateur); // Appel récursif pour demander une
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

int definirChoixOrdinateur(int &choixOrdinateur) {
  if (choixOrdinateur == 0) { // si l'ordi a joué Pierre au tour précédent
    choixOrdinateur = pierre();
  } else if (choixOrdinateur ==
             1) { // si l'ordi a joué Feuille au tour précédent
    choixOrdinateur = feuille();
  } else { // si l'ordi a joué Ciseaux au tour précédent
    choixOrdinateur = ciseaux();
  }
}