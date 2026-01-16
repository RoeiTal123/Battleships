#include <iostream>
#include <fstream>
#include <string.h>
#include "HumanPlayer.hpp"
#include "Grid.hpp"

// ID: 327397105, name: Denis Beigel
// ID: 212692875, name: Roei Tal

namespace Battle
{
    HumanPlayer::~HumanPlayer()
    {
    }

    void HumanPlayer::placeAllShips()
    {
        int shipSizes[] = {5, 4, 3, 3, 2}; // Standard Fleet
        char *shipNames[] = {"Carrier", "Battleship", "Cruiser", "Submarine", "Destroyer"};

        for (int i = 0; i < 5; i++)
        {
            int row, col;
            std::string input;
            bool horizontal;
            bool placed = false;

            while (!placed)
            {
                std::cout << "Enter row: ";
                std::cin >> row;
                row--;
                std::cout << "Enter col: ";
                std::cin >> col; // user will enter 'row 1' which would be 0, so row n is actually n-1
                col--;
                std::cout << "Horizontal? ";
                std::cin >> input;
                if (input == "no" || input == "No" || input == "NO" || input == "nO")
                {
                    horizontal = false;
                }
                else
                {
                    horizontal = true;
                }
                const char *direction = (horizontal) ? "horizontal" : "vertical";

                if (grid.isTileOccupied(row, col))
                {
                    std::cout << "Tile is occupied";
                }
                if (!grid.inBounds(row, col, shipSizes[i], horizontal))
                {
                    std::cout << "Ship is off the grid";
                }
                else if (!grid.isTileOccupied(row, col) && grid.inBounds(row, col, shipSizes[i], horizontal))
                {
                    Ship *newShip = new Ship(shipNames[i], shipSizes[i], row, col, direction);
                    addShip(newShip);
                    grid.placeShip(row, col, shipSizes[i], horizontal);
                    placed = true;
                }
            }
        }
    }

    void HumanPlayer::makeMove(Player *opponent)
    {
        int row, col;
        std::cout << "Select row for attack: ";
        std::cin >> row;
        row--;
        std::cout << "Select col for attack: ";
        std::cin >> col;
        col--;
        if (opponent->getGrid().getCell(row, col) == 'S')
        {
            for (int i = 0; i < opponent->getShipCount(); i++)
            {
                Ship *ship = opponent->getShip(i);
                if (ship->occupies(row, col)) // checks if ship covers this cell
                {
                    ship->takeHit(); // increment hitsTaken
                    break;           // stop after finding the correct ship
                }
            }
            opponent->getGrid().markHit(row, col);
        }
        else
        {
            opponent->getGrid().markMiss(row, col);
        }

        this->grid.printGrid();
        opponent->getGrid().printGrid();
    }
}
