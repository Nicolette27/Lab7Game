//
// Created by niewiadomskan on 3/14/2025.
//

#include "Game.h"
#include "Player.h"
#include "Ghost.h"
#include <iostream>

using namespace std;

Game::Game() : player("Luigi"), currentRoomIndex(0)  {
    Ghost ghost1("Purple Puncher", 30);
    Ghost ghost2("Sneaky Spook", 40);

    Room entrance("Entrance", nullptr, false);  // No ghost, no key
    Room library("Library", &ghost1, true);     // Ghost in Library, has a key
    Room ballroom("Ballroom", &ghost2, false);  // Ghost in Ballroom, no key

    mansion.push_back(entrance);
    mansion.push_back(library);
    mansion.push_back(ballroom);
}

void Game::play() {
    std::cout << "Welcome to Luigi’s Mansion!\n";
    while (player.getHealth() > 0) {
        playTurn();
    }
    std::cout << "Game Over! Luigi fainted.\n";
}

void Game::playTurn() {
    std::cout << "\nYou are in the " << mansion[currentRoomIndex].getName() << ".\n";

    while (true) {
        std::cout << "What would you like to do?\n";
        std::cout << "[1] Fight Ghost\n[2] Explore Room\n[3] Move to Another Room\nChoice: ";
        int choice;
        std::cin >> choice;

        if (choice == 1 && mansion[currentRoomIndex].hasGhost()) {
            fightGhost();
        } else if (choice == 2) {
            searchRoom();
        } else if (choice == 3) {
            chooseRoom();
            break;
        } else {
            std::cout << "Invalid choice!\n";
        }
    }
}

void Game::fightGhost() {
    Ghost& ghost = *mansion[currentRoomIndex].getGhost();

    while (ghost.getHealth() > 0 && player.getHealth() > 0) {
        player.attackGhost(ghost);
        if (ghost.getHealth() > 0) {
            player.takeDamage(10);
        }
    }

    if (player.getHealth() == 0) {
        std::cout << "Luigi has fainted!\n";
    } else {
        std::cout << "You defeated the ghost!\n";
        mansion[currentRoomIndex].removeGhost();
    }
}

void Game::searchRoom() {
    if (mansion[currentRoomIndex].hasKeyInRoom()) {
        std::cout << "You found a hidden key!\n";
        player.addKey("Key");
        mansion[currentRoomIndex].setKey(false);
    } else {
        std::cout << "Nothing here.\n";
    }
}

void Game::chooseRoom() {
    std::cout << "Available rooms:\n";
    for (int i = 0; i < mansion.size(); ++i) {
        if (i != currentRoomIndex) {
            std::cout << "- [" << i << "] " << mansion[i].getName() << "\n";
        }
    }

    int choice;
    std::cout << "Enter room number: ";
    std::cin >> choice;

    if (choice >= 0 && choice < mansion.size()) {
        currentRoomIndex = choice;
    } else {
        std::cout << "Invalid room choice!\n";
    }
}
