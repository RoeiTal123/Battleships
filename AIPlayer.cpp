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
        

    AIPlayer::~AIPlayer()
    {

    }

}