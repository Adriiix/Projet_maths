#include "lois.hpp"
#include <iostream>
#include <vector>

int main() {

  // P = 0, F = 1, C = 2
  // X -> ce que joue l'ordi, inialisé à 0
  int X = 0;

  // jeu permet de savoir quand on arrête la partie
  // Tant que jeu = "o" ou "O", ça continue
  std::string jeu = "O";

  double p;

  while (jeu == "O" || jeu == "o") {

    if (X == 0) { // si au tour d'avant on a joué papier X=0

      X = papier();

    }

    else if (X == 1) { // si au tour d'avant on a joué feuille X=1

      X = feuille();

    }

    else { // si au tour d'avant on a joué ciseaux X=2

      X = ciseaux();
    }

    std::cout << "X= " << X << std::endl;
    std::cout << "Rejouer? O/N" << std::endl;
    std::cin >> jeu;
  }

  return 0;
}
