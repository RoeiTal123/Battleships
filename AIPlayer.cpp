#include <iostream>
#include <fstream>
#include <string.h>
#include "AIPlayer.hpp"

// ID: 327397105, name: Denis Beigel
// ID: 212692875, name: Roei Tal

namespace Battle
{

    void AIPlayer::placeAllShips()
    {
        int shipSizes[] = {5, 4, 3, 3, 2};
    // Names aren't needed for AI logic, but helpful if you add debug prints later
    
    for (int i = 0; i < 5; i++)
    {
        int size = shipSizes[i];
        bool placed = false;

        while (!placed)
        {
            int row = getRandomCoordinate();
            int col = getRandomCoordinate();
            bool horizontal = std::rand() % 2; // 0 for vertical, 1 for horizontal
            const char* direction = (horizontal) ? "horizontal" : "vertical";

            if (!grid.inBounds(row, col, size, horizontal)) {
                continue; 
            }
            
            if (grid.isTileOccupied(row, col)) { 
                continue;
            }

            // 3. Create the specific ship subclass (Fixes the Null Pointer/Segfault)
            Ship* newShip = nullptr;
            if (i == 0)      newShip = new Carrier(row, col, direction);
            else if (i == 1) newShip = new BattleShip(row, col, direction);
            else if (i == 2) newShip = new Cruiser(row, col, direction);
            else if (i == 3) newShip = new Submarine(row, col, direction);
            else if (i == 4) newShip = new Destroyer(row, col, direction);

            // 4. Register the ship to the Player's array and the Grid
            if (newShip)
            {
                addShip(newShip); // This fills the ships[i] array used in allShipsSunk()
                grid.placeShip(row, col, size, horizontal);
                placed = true;
            }
        }
    }
    }

    void AIPlayer::makeMove(Player *opponent)
    {
        int row, col;
        char targetCell;

        do {
            row = getRandomCoordinate();
            col = getRandomCoordinate();
            targetCell = opponent->getGrid().getCell(row, col);
        } while (targetCell == 'X' || targetCell == 'M');

        if (targetCell == 'S')
        {
            bool shipFound = false;
            for (int i = 0; i < opponent->getShipCount(); i++)
            {
                Ship* currentShip = opponent->getShip(i);
                if (currentShip != nullptr && currentShip->occupies(row, col))
                {
                    currentShip->takeHit();
                    std::cout << "Target damaged: " << currentShip->getType() << std::endl;
                    shipFound = true;
                    break; // Ship is found
                }
            }

            opponent->getGrid().markHit(row, col);
        }
        else
        {
            std::cout << "Miss at (" << row << ", " << col << ")" << std::endl;
            opponent->getGrid().markMiss(row, col);
        }

        std::cout << "--- " << playerName << "'s View ---" << std::endl;
        opponent->displayGrid();
    }

    AIPlayer::~AIPlayer()
    {

    }

}