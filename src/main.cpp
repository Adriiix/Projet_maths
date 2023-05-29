#include <iostream>
#include <vector>
#include "lois.hpp"
#include "p6/p6.h"

int main(int argc, char* argv[])
{
    // Actual app
    auto ctx = p6::Context{{.title = "Pierre Feuille Ciseaux"}};

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

    ctx.maximize_window();
    ctx.imgui = [&]() {
        // Show a simple window
        // ImGui::Begin("Test");

        // ImGui::SliderFloat("distance Between Boids", &DISTANCE, 0.001, 10);
        // ImGui::SliderFloat("separation Strength", &(strengths.m_separationStrength), 0, 2);
        // ImGui::SliderInt("cohesion Strength", &(strengths.m_cohesionStrength), 0, 10);
        // ImGui::SliderInt("alignment Strength", &(strengths.m_alignmentStrength), 0, 10);
        // ImGui::SliderFloat("maximum speed", &(strengths.m_vitesseMax), 0.001, 0.02);

        // ImGui::End();
        // Show the official ImGui demo window
        // It is very useful to discover all the widgets available in ImGui
    };

    // Declare your infinite update loop.
    ctx.update = [&]() {
        ctx.background({0.151 * 3, 0.253 * 3, 0.135 * 3});
    };

    // Should be done last. It starts the infinite loop.
    ctx.start();
}
