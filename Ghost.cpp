//
// Created by niewiadomskan on 3/14/2025.
//

#include "Ghost.h"
#include <iostream>

Ghost::Ghost(std::string name, int health)
    : name(name), health(health) {}

std::string Ghost::getName() const {
    return name;
}

int Ghost::getHealth() const {
    return health;
}

void Ghost::takeDamage(int damage) {
    health -= damage;
    if (health <= 0) {
        std::cout << name << " is defeated!\n";
    }
}



