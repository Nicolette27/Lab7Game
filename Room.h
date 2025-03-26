//
// Created by niewiadomskan on 3/14/2025.
//
#ifndef ROOM_H
#define ROOM_H

#include <memory>
#include <string>
#include "Ghost.h"

class Room {
private:
    std::string name;
    Ghost* ghost;

public:
    Room(const std::string& name, Ghost* ghost, bool hasKey);
    ~Room();

    std::string getName() const;
    Ghost* getGhost() const;
    bool hasGhost() const;
    bool hasKeyInRoom() const;

    void removeGhost();
    void setKey(bool hasKey);
    bool hasKey;
};

#endif // ROOM_H

