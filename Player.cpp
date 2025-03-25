//
// Created by niewiadomskan on 3/14/2025.
//
#include <stdio.h>
#include "Player.h"

Player::Player(std::string name) : name(name), health(100) {}

std::string Player::getName() const {
    return name;
}

int Player::getHealth() const {
    return health;
}

void Player::takeDamage(int amount) {
    health -= amount;
    if (health < 0) health = 0;
}

void Player::attackGhost(Ghost& ghost) {
    ghost.takeDamage(20);
}

void Player::addKey(std::string key) {
    keys.insert(key);
}

bool Player::hasKey(std::string key) const {
    return keys.find(key) != keys.end();
}

