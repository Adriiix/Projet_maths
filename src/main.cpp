#include "lois.hpp"
#include <iostream>
#include <iterator>
#include <vector>

int main() {

  // for (int i = 0; i < 20; i++) {
  //   std::cout << exponentielle(0.6) << std::endl;
  // }

  // P = 0, F = 1, C = 2
  int choixOrdinateur = 0;  // Choix de l'ordinateur
  int scoreUtilisateur = 0; // Score de l'utilisateur
  int scoreOrdinateur = 0;  // Score de l'ordinateur

  while (scoreUtilisateur < 3 && scoreOrdinateur < 3) {
    int choixUtilisateur = demanderChoixUtilisateur();

    if (choixOrdinateur == 0) {
      choixOrdinateur = pierre();
    } else if (choixOrdinateur == 1) {
      choixOrdinateur = feuille();
    } else {
      choixOrdinateur = ciseaux();
    }

    afficherResultat(choixUtilisateur, choixOrdinateur);

    if ((choixUtilisateur == 0 && choixOrdinateur == 2) ||
        (choixUtilisateur == 1 && choixOrdinateur == 0) ||
        (choixUtilisateur == 2 && choixOrdinateur == 1)) {
      // L'utilisateur a gagné
      scoreUtilisateur++;
    } else if ((choixUtilisateur == 2 && choixOrdinateur == 0) ||
               (choixUtilisateur == 0 && choixOrdinateur == 1) ||
               (choixUtilisateur == 1 && choixOrdinateur == 2)) {
      // L'ordinateur a gagné
      scoreOrdinateur++;
    }

    std::cout << "Score : Utilisateur " << scoreUtilisateur << " - "
              << scoreOrdinateur << " Ordinateur" << std::endl;
  }

  if (scoreUtilisateur == 3) {
    std::cout << "Vous avez gagné la partie !" << std::endl;
  } else {
    std::cout << "L'ordinateur a gagné la partie !" << std::endl;
  }

  return 0;
}
