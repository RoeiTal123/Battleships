#include <iostream>
#include <fstream>
#include <string.h>
#include "Game.hpp"

// ID: 327397105, name: Denis Beigel
// ID: 212692875, name: Roei Tal

namespace Battle
{
    void Game::setup()
    {
        player1->placeAllShips();
        player2->placeAllShips();
    }

    void Game::start()
    {
    }

    bool Game::isGameOver() const
    {
        if (player1->allShipsSunk() || player2->allShipsSunk())
            return true;
    }

    Game::Game(Player *p1, Player *p2)
    {
        
    }

    Game::Game()
    {
    }
    
    Game::~Game()
    {
    }
}
