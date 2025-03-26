//
// Created by niewiadomskan on 3/14/2025.
//

#include "Game.h"
#include "Player.h"
#include "Ghost.h"
#include <iostream>
#include <memory>

using namespace std;

Game::Game() : player("Luigi"), currentRoomIndex(0)  {
//    auto ghost1 = std::make_shared<Ghost>("Purple Puncher", 30);
//    auto ghost2 = std::make_shared<Ghost>("Sneaky Spook", 40);
//
//    Room entrance("Entrance", nullptr, false);
//    Room library("Library", ghost1, true);
//    Room ballroom("Ballroom", ghost2, false);

    mansion.emplace_back("Entrance", nullptr, false);
    mansion.emplace_back("Library", new Ghost("Purple Puncher", 30), true);
    mansion.emplace_back("Ballroom", new Ghost("Sneaky Spook", 40), false);
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

    if (allGhostsDefeated()) {
       std::cout << "Congratulations! You have defeated all the ghosts!\n";
       exit(0);
    }
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

  if (!ghost.getHealth()) {
    std::cout << "There's no ghost here!\n";
    return;
  }
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

bool Game::allGhostsDefeated() const {
  for (const Room& room : mansion) {
    if (room.hasGhost()) {
      return false;
    }
  }
  return true;
}
