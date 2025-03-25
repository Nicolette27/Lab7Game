//
// Created by niewiadomskan on 3/14/2025.
//

#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <set>
#include "Ghost.h"

class Player {
private:
    std::string name;
    int health;
    std::set<std::string> keys;

public:
    Player(std::string name);
    std::string getName() const;
    int getHealth() const;
    void takeDamage(int amount);
    void attackGhost(Ghost& ghost);
    void addKey(std::string key);
    bool hasKey(std::string key) const;
};

#endif // PLAYER_H


