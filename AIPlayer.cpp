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

        for (int size : shipSizes)
        {
            bool placed = false;
            while (!placed)
            {
                // Use the global rand() seeded in main
                int row = getRandomCoordinate();
                int col = getRandomCoordinate();
                bool horizontal = std::rand() % 2; // 0 or 1

                if (grid.inBounds(row, col, size, horizontal) && !grid.isTileOccupied(row, col))
                {
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
            std::cout << "HIT at (" << row << ", " << col << ")!" << std::endl;
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