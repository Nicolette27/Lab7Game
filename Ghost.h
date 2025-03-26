//
// Created by niewiadomskan on 3/14/2025.
//

#ifndef GHOST_H
#define GHOST_H

#include <string>

class Ghost {
private:
    std::string name;
    int health;

public:
    Ghost(std::string name, int health);
    ~Ghost();
    std::string getName() const;
    int getHealth() const;
    void takeDamage(int damage);
};

#endif // GHOST_H


