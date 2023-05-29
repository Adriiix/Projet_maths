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
int simulerPoisson(double lambda);
double simulerLoiNormale(double moyenne, double ecartType);

int pierre(int choixUtilisateur);
int feuille(int choixUtilisateur);
int ciseaux(int choixUtilisateur);

int demanderChoixUtilisateur();
std::string getNomCoup(int coup);
void afficherResultat(int choixUtilisateur, int choixOrdinateur);
int definirChoixOrdinateur(int &choixOrdinateur, int choixUtilisateur);