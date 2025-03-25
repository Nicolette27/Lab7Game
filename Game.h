//
// Created by niewiadomskan on 3/14/2025.
//

#ifndef GAME_H
#define GAME_H

#include <vector>
#include <string>
#include "Room.h"
#include "Player.h"

class Game {
private:
    std::vector<Room> mansion;
    int currentRoomIndex;
    Player player;

public:
    Game();
    void play();
    void playTurn();
    void fightGhost();
    void searchRoom();
    void chooseRoom();
};

#endif // GAME_H

