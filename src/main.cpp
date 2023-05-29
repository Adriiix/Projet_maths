#include <iostream>
#include <vector>
#include "lois.hpp"
#include "p6/p6.h"

int main(int argc, char* argv[])
{
    // Actual app
    auto ctx = p6::Context{{.title = "Pierre Feuille Ciseaux"}};

    ctx.maximize_window();

    // Declare your infinite update loop.
    ctx.update = [&]() {
        ctx.background(p6::NamedColor::PinkPearl);
        ctx.fill = p6::NamedColor::OrangePeel;
        ctx.circle(p6::Center{ctx.mouse()}, p6::Radius{0.1f});
        ctx.text_size = 0.1f;
        ctx.fill      = {1.f, 0.f, 0.f, 1.f};
        ctx.text(u"Pierre", p6::Center{0.f, 2.f * ctx.text_size});
        ctx.fill = {1.f, 0.f, 0.f, 1.f};
        ctx.text(u"Feuille", p6::Center{0.f, 0.f * ctx.text_size});
        ctx.text(u"Ciseaux", p6::Center{0.f, -2.f * ctx.text_size});
    };

    // Should be done last. It starts the infinite loop.
    ctx.start();
}

// P = 0, F = 1, C = 2
// int choixOrdinateur  = 0; // Choix de l'ordinateur
// int scoreUtilisateur = 0; // Score de l'utilisateur
// int scoreOrdinateur  = 0; // Score de l'ordinateur

// while (scoreUtilisateur < 3 && scoreOrdinateur < 3)
// {
//     int choixUtilisateur = demanderChoixUtilisateur();
//     choixOrdinateur      = (choixOrdinateur + 1) % 3;

//     afficherResultat(choixUtilisateur, choixOrdinateur);

//     if ((choixUtilisateur == 0 && choixOrdinateur == 2) || (choixUtilisateur == 1 && choixOrdinateur == 0) || (choixUtilisateur == 2 && choixOrdinateur == 1))
//     {
//         // L'utilisateur a gagné
//         scoreUtilisateur++;
//     }
//     else if ((choixUtilisateur == 2 && choixOrdinateur == 0) || (choixUtilisateur == 0 && choixOrdinateur == 1) || (choixUtilisateur == 1 && choixOrdinateur == 2))
//     {
//         // L'ordinateur a gagné
//         scoreOrdinateur++;
//     }

//     std::cout << "Score : Utilisateur " << scoreUtilisateur << " - "
//               << scoreOrdinateur << " Ordinateur" << std::endl;
// }

// if (scoreUtilisateur == 3)
// {
//     std::cout << "Vous avez gagné la partie !" << std::endl;
// }
// else
// {
//     std::cout << "L'ordinateur a gagné la partie !" << std::endl;
// }