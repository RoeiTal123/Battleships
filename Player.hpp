#include <iostream>
#include <fstream>
#include <string.h>
#include "Ship.hpp"
#include "Grid.hpp"
#pragma once

// ID: 327397105, name: Denis Beigel
// ID: 212692875, name: Roei Tal
namespace Battle
{
    class Player
    {
    private:
        char* playerName;
        Ship* ships[5]; // Pointers to ships the player has
        Grid grid; // 10 x 10

    public:
        virtual void placeAllShips(); // Places the 5 ship onto the grid: Each ship get a (row, col) (random || expecting input)
                                      // Two check follow: grid.inBounds(...) & grid.isTileOccupied(...)
                                      // If all good: grid.placeShip()

        virtual void makeMove(Player* opponent); // If opponent->grid.getCell(...) == A ship
                                                 // Find the matching ship type and run takeHit() and then opponent->grid.markHit(...) || opponent->grid.markMiss(...)
                                                 // After this is over, print the two grids of the two player to show the results of the move

        bool allShipsSunk() const; // If all 5 ships are Sunk, this retuns true

        void displayGrid(); // Print the grip (Somehow...)

        Player(const char* name); // Initializes playerName and constructs grid
        Player();
        virtual ~Player(); // Cleans up playerName and Ship pointers.
        Player& Player::operator=(const Player& other);

        void SetPlayerName(const char* shipName);
        void ClearShips();
    };
}