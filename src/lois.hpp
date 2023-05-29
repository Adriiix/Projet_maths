#include <stdlib.h>
#include <cmath>
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <ostream>
#include <random>
#include <string>
#include "p6/p6.h"

int    de();
int    fac(int n);
void   binomialTheorique(int n, double p, int k);
double bernoulliTheorique(double p, int k);

double uniforme();
int    multinomiale(double proba1, double proba2, double proba3);

int papier();
int feuille();
int ciseaux();

int demanderChoixUtilisateur();

std::string getNomCoup(int coup);

void afficherResultat(int choixUtilisateur, int choixOrdinateur);

void updateScore(std::u16string& scoreJoueurTxt, std::u16string& scoreOrdinateurTxt, int scoreUtilisateur, int scoreOrdinateur);