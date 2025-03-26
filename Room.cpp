//
// Created by niewiadomskan on 3/14/2025.
//

#include "Room.h"
#include <memory>

Room::Room(const std::string& name, Ghost* ghost, bool hasKey)
    : name(name), ghost(ghost), hasKey(hasKey) {}

Room::~Room() {
    delete ghost;
}

std::string Room::getName() const {
    return name;
}

Ghost* Room::getGhost() const {
    return ghost;
}

bool Room::hasGhost() const {
    return ghost != nullptr;
}

bool Room::hasKeyInRoom() const {
    return hasKey;
}

void Room::removeGhost() {
    delete ghost;
    ghost = nullptr;
}

void Room::setKey(bool hasKey) {
    this->hasKey = hasKey;
}


