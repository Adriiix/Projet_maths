#include "lois.hpp"
#include <iostream>
#include <vector>

int main() {
  // P = 0, F = 1, C = 2
  int choixOrdinateur = 0; // Choix de l'ordinateur
  std::string jeu = "O";

  while (jeu == "o" || jeu == "O") {

    int choixUtilisateur = demanderChoixUtilisateur();
    choixOrdinateur = (choixOrdinateur + 1) % 3;

    afficherResultat(choixUtilisateur, choixOrdinateur);

    std::cout << "Rejouer ? O/N" << std::endl;
    std::cin >> jeu;
  }

  return 0;
}
