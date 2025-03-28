//
// Created by niewiadomskan on 3/23/2025.
//

#include "Game.h"
#include <iostream>
#include "Player.h"
#include "Ghost.h"

int main() {
    int debugInput;
    bool debug = false;
    std::cout << "Enable debug mode? (1 = Yes, 0 = No): ";
    std::cin >> debug;

    while (!(std::cin >> debugInput) || (debugInput != 0 && debugInput != 1)) {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << "Invalid input! Please enter 1 for Yes or 0 for No: ";
    }

    debug = (debugInput == 1);

    std::cout << "[DEBUG] Debug flag set to: " << (debug ? "true" : "false") << "\n";

    Game game(debug);
    game.play();
    return 0;
}