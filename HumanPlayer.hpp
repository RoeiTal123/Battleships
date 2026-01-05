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
    private:
        /* data */
    public:
        HumanPlayer(const char* name) : Player() {}
        HumanPlayer();
        ~HumanPlayer();
    };

}