#include <iostream>
#include <vector>
#include "pfc.hpp"

int main(int argc, char* argv[])
{
    // Actual app
    auto ctx = p6::Context{{.title = "Pierre Feuille Ciseaux"}};

    ctx.maximize_window();

    // P = 0, F = 1, C = 2
    int choixOrdinateur  = 0; // Choix de l'ordinateur
    int scoreUtilisateur = 0; // Score de l'utilisateur
    int scoreOrdinateur  = 0; // Score de l'ordinateur

    std::u16string scoreJoueurTxt     = u"0";
    std::u16string scoreOrdinateurTxt = u"0";

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
        ctx.text(u"Ciseaux", p6::Center{0.f, -3.f * ctx.text_size});

        ctx.text(scoreJoueurTxt, p6::Center{-0.2f, 5.f * ctx.text_size});
        ctx.text(u"-", p6::Center{0.f, 5.f * ctx.text_size});
        ctx.text(scoreOrdinateurTxt, p6::Center{0.2f, 5.f * ctx.text_size});

        updateScore(scoreJoueurTxt, scoreOrdinateurTxt, scoreUtilisateur, scoreOrdinateur);

        ctx.key_pressed = [&](p6::Key const&) {
            std::cout << "Pressed\n";
        };
    };

    // Should be done last. It starts the infinite loop.
    ctx.start();
}
