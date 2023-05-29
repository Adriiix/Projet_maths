#include <cmath>
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <ostream>
#include <random>
#include <stdlib.h>

int de();
int fac(int n);
void binomialTheorique(int n, double p, int k);
double bernoulli(double p, int k);
bool simulerBernoulli(double p);

double uniforme();
int multinomiale(double proba1, double proba2, double proba3);

int papier();
int feuille();
int ciseaux();

int demanderChoixUtilisateur();

std::string getNomCoup(int coup);

void afficherResultat(int choixUtilisateur, int choixOrdinateur);