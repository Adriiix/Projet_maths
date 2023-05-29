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

int pierre();
int feuille();
int ciseaux();

int demanderChoixUtilisateur(std::vector<int> &historiqueUtilisateur);
std::string getNomCoup(int coup);
void afficherResultat(int choixUtilisateur, int choixOrdinateur);