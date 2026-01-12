#include <iostream>
#include <fstream>
#include <string.h>
#include "Player.hpp"
#pragma once

// ID: 327397105, name: Denis Beigel
// ID: 212692875, name: Roei Tal

namespace Battle
{
    class HumanPlayer : public Player
    {
    public:
        HumanPlayer(const char* name) : Player(name) {}

        void placeAllShips() override;
        void makeMove(Player* opponent) override;
        
        virtual ~HumanPlayer() = default;
    };
}