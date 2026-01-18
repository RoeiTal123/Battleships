#include <iostream>
#include <fstream>
#include <string.h>
#include "Game.hpp"

// ID: 327397105, name: Denis Beigel
// ID: 212692875, name: Roei Tal

namespace Battle
{
    void Game::setup() // Place all ships
    {
        player1->placeAllShips();
        player2->placeAllShips();
    }

    void Game::start() // Main game loop
    {
        int round = 1;
        bool gameLoop = true;
        std::cout << "\n------------Game Started!------------" << std::endl;
        while (gameLoop) {

            std::cout << "\nRound:" << round << std::endl;
            // Player 1 Turn
            std::cout << "\n--- Player 1's Turn ---" << std::endl;
            player1->makeMove(player2);
            if (isGameOver() == true) { 
                std::cout << "Player 1 wins! All enemy ships sunk." << std::endl;
                break; 
            }
            // Player 2 Turn
            std::cout << "\n--- Player 2's Turn ---" << std::endl;
            player2->makeMove(player1);
            if (isGameOver() == true) {
                std::cout << "Player 2 wins! All enemy ships sunk." << std::endl;
                break;
            }
            round++;
        }
    }

    bool Game::isGameOver() const // Game summery
    {
        if (player1->allShipsSunk() || player2->allShipsSunk() == true)
        {
            std::cout << "\n--- Player 1's Ships and Grid ---" << std::endl;
            player1->printAllShips();
            player1->displayGrid();
            std::cout << "\n--- Player 2's Ships and Grid ---" << std::endl;
            player2->printAllShips();
            player2->displayGrid();
            return true;
        }
        
        return false;
    }

    Game::Game(Player *p1, Player *p2) // create a game object
    {
        player1 = p1;
        player2 = p2;
    }

    Game::Game(){}
    
    Game::~Game(){}
    
    void Game::test() // May be printed after ships are placed to see the setup of each player
    {
        player1->getGrid().printGrid();
        player2->getGrid().printGrid();
    }
}
