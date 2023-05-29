#include <cmath>
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <ostream>
#include <random>
#include <stdlib.h>

int fac(int n);
bool simulerBernoulli(double p);
double exponentielle(double lambda);

double uniforme();
int multinomiale(double proba1, double proba2, double proba3);

int pierre();
int feuille();
int ciseaux();

int demanderChoixUtilisateur();

std::string getNomCoup(int coup);

void afficherResultat(int choixUtilisateur, int choixOrdinateur);