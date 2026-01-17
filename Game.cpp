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
        int round = 1;
        bool gameLoop = true;
        while (gameLoop) {
            std::cout << "Round:" << round << std::endl;
            // Player 1 Turn
            std::cout << "\n--- Player 1's Turn ---" << std::endl;
            player1->makeMove(player2);
            if (player2->allShipsSunk()) { // Check immediately
                std::cout << "Player 1 wins! All enemy ships sunk." << std::endl;
                break; 
            }

            // Player 2 Turn
            std::cout << "\n--- Player 2's Turn ---" << std::endl;
            player2->makeMove(player1);
            if (player1->allShipsSunk()) {
                std::cout << "Player 2 wins! All enemy ships sunk." << std::endl;
                break;
            }
            round++;
        }
    }

    bool Game::isGameOver() const
    {
        return player1->allShipsSunk() || player2->allShipsSunk();
    }

    Game::Game(Player *p1, Player *p2)
    {
        player1 = p1;
        player2 = p2;
    }

    Game::Game()
    {

    }
    
    Game::~Game()
    {
        
    }
    void Game::test()
    {
        player1->getGrid().printGrid();
        player2->getGrid().printGrid();
    }
}
