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

        for (int size : shipSizes) 
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
                std::cin >> col;                //user will enter 'row 1' which would be 0, so row n is actually n-1
                col--;
                std::cout << "Horizontal? ";
                std::cin >> input;
                if (input == "no" || input == "No" || input == "NO" || input == "nO"){
                    horizontal = false;
                } else {
                    horizontal = true;
                }
                if (grid.isTileOccupied(row, col))
                {
                    std::cout << "Tile is occupied";
                }
                if (!grid.inBounds(row, col, size, horizontal)) 
                {
                    std::cout << "Ship is off the grid";
                }
                else if (!grid.isTileOccupied(row, col) && grid.inBounds(row, col, size, horizontal))
                {
                    grid.placeShip(row, col, size, horizontal);
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
            opponent->getShip(1)->takeHit(); // Need to find the correct ship
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
