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
        std::cout << "Manuel Ship Placement!" << std::endl; 
        int shipSizes[] = {5, 4, 3, 3, 2};
        const char *shipNames[] = {"Carrier", "Battleship", "Cruiser", "Submarine", "Destroyer"};

        for (int i = 0; i < 5; i++)
        {
            int row, col;
            std::string input;
            bool horizontal;
            bool placed = false;

            while (!placed)
            {
                std::cout << "\nPlacing " << shipNames[i] << " (Size " << shipSizes[i] << ")" << std::endl;
                std::cout << "Enter row (0-9): "; 
                std::cin >> row;
                std::cout << "Enter col (0-9): "; 
                std::cin >> col;
                
                std::cout << "Horizontal? (yes/no): ";
                std::cin >> input;
                horizontal = !(input == "no" || input == "No" || input == "NO" || input == "nO");
                
                const char *direction = (horizontal) ? "horizontal" : "vertical";

                // Validation logic
                if (!grid.inBounds(row, col, shipSizes[i], horizontal)) {
                    std::cout << "Error: Ship is off the grid!" << std::endl;
                    continue;
                }
                if (grid.isTileOccupied(row, col)) { // Note: You should ideally check all tiles the ship covers
                    std::cout << "Error: Tile is occupied!" << std::endl;
                    continue;
                }

                // Create the specific subclass based on the index 'i'
                Ship *newShip = nullptr;
                if (i == 0)      newShip = new Carrier(row, col, direction);
                else if (i == 1) newShip = new BattleShip(row, col, direction);
                else if (i == 2) newShip = new Cruiser(row, col, direction);
                else if (i == 3) newShip = new Submarine(row, col, direction);
                else if (i == 4) newShip = new Destroyer(row, col, direction);

                if (newShip)
                {
                    addShip(newShip);
                    grid.placeShip(row, col, shipSizes[i], horizontal);
                    placed = true;
                    std::cout << shipNames[i] << " placed successfully!" << std::endl;
                }
            }
        }
    }

    void HumanPlayer::makeMove(Player *opponent)
    {
        int row, col;
        std::cout << "Select row for attack: ";
        std::cin >> row;
        std::cout << "Select col for attack: ";
        std::cin >> col;
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

        std::cout << "\n--- Player's Grid ---" << std::endl;
        this->displayGrid();
        // std::cout << "\n--- Opponent's Grid ---" << std::endl;
        // opponent->displayGrid();
    }
}
