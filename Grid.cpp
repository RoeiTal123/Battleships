#include <iostream>
#include <fstream>
#include <string.h>
#include "Grid.hpp"

// ID: 327397105, name: Denis Beigel
// ID: 212692875, name: Roei Tal

namespace Battle
{
    Grid::Grid()
    {
        for (int i = 0; i < 10; ++i)
        {
            for (int j = 0; j < 10; ++j)
            {
                this->cells[i][j] = '~';
            }
        }
    }

    Grid::~Grid()
    {
    }

    bool Grid::isTileOccupied(int row, int col) const
    {
        if (row >= 10 || row < 0 || col >= 10 || col < 0)
        {
            std::cout << "this tile is out of range \n";
        }
        if ((this->cells[row][col] == 'S') || (this->cells[row][col] == 'X'))
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool Grid::inBounds(int row, int col, int shipSize, bool horizontal) const
    {
        if (row >= 10 || row < 0 || col >= 10 || col < 0)
        {
            std::cout << "Starting tile is out of range\n";
            return false;
        }
        int startRow = 0, endRow = 0, startCol = 0, endCol = 0;
        if (horizontal == true)
        {
            startRow = endRow = row;
            startCol = col;
            endCol = startCol + shipSize - 1;
            for (int i = col; i <= endCol; i++)
            {
                if (cells[row][i] != '~')
                { 
                    std::cout << "The ship reaches out of bounds\n";
                    return false;
                }
            }
        }
        else
        {
            startCol = endCol = col;
            startRow = row;
            endRow = startRow + shipSize - 1;
            for (int i = row; i <= endRow; i++)
            {
                if (cells[i][col] != '~')
                { 
                    std::cout << "The ship reaches out of bounds\n";
                    return false;
                }
            }
        }

        if (endRow >= 10 || endCol >= 10)
        {
            std::cout << "the ship reaches out of bounds \n";
            return false;
        }
        else
        {
            return true;
        }
    }

    void Grid::placeShip(int row, int col, int shipSize, bool horizontal)
    {
        if (this->inBounds(row, col, shipSize, horizontal))
        {
            if (horizontal)
            {
                for (int i = col; i < col + shipSize; i++)
                {
                    this->cells[row][i] = 'S';
                }
            }
            else
            {
                for (int i = row; i < row + shipSize; i++)
                {
                    this->cells[i][col] = 'S';
                }
            }
        }
        else
        {
            std::cout << "the ship reaches out of bounds or on occupied space\n";
        }
    }

    void Grid::markHit(int row, int col)
    {
        if (row < 0 || row >= 10 || col < 0 || col >= 10)
        {
            std::cout << "This tile is out of range\n";
            return;
        }

        char &cell = cells[row][col];

        if (cell == 'S')
        {
            cell = 'X';
            std::cout << "Hit at [" << row << "][" << col << "]!\n";
        }
        else if (cell == 'X' || cell == 'M')
        {
            std::cout << "Tile [" << row << "][" << col << "] has already been attacked\n";
        }
    }

    void Grid::markMiss(int row, int col)
    {
        if (row < 0 || row >= 10 || col < 0 || col >= 10)
        {
            std::cout << "This tile is out of range\n";
            return;
        }

        char &cell = cells[row][col];

        if (cell == '~')
        {
            cell = 'M';
            std::cout << "Miss at [" << row << "][" << col << "]\n";
        }
        else if (cell == 'X' || cell == 'M')
        {
            std::cout << "Tile [" << row << "][" << col << "] has already been attacked\n";
        }
    }

    char Grid::getCell(int row, int col) const
    {
        if (row < 0 || row >= 10 || col < 0 || col >= 10)
        {
            std::cout << "This tile is out of range\n";
            return 'E';
        }
        else
        {
            return this->cells[row][col];
        }
    }
    void Grid::printGrid()
    {
        // for (int row = 0; row < 10; ++row)
        // {
        //     std::cout << "-----------------------------\n";

        //     std::cout << "|";
        //     for (int col = 0; col < 10; ++col)
        //     {
        //         std::cout << " " << this->cells[row][col] << " |";
        //     }
        //     std::cout << "\n";
        // }
        // std::cout << "-----------------------------\n";
        // Print Column Numbers at the top
        // 1. Column Numbers: Start from 0 to 9
        std::cout << "     0   1   2   3   4   5   6   7   8   9\n";
        
        // 2. Loop from index 9 down to 0
        // This ensures index 0 is visually at the bottom
        for (int row = 9; row >= 0; --row)
        {
            std::cout << "   -----------------------------------------\n";

            // 3. Row Number: Print the raw index 'row' (0-9)
            // Space padding for single digits to keep the grid aligned
            std::cout << " " << row << " |";

            for (int col = 0; col < 10; ++col)
            {
                // Internal array access: cells[row][col]
                std::cout << " " << this->cells[row][col] << " |";
            }
            std::cout << "\n";
        }
        std::cout << "   -----------------------------------------\n";
    }
}