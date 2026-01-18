#include <iostream>
#include <fstream>
#include <string.h>
#include "Grid.hpp"

// ID: 327397105, name: Denis Beigel
// ID: 212692875, name: Roei Tal

namespace Battle
{
    Grid::Grid() // default and only constructor
    {
        for (int i = 0; i < 10; ++i)
        {
            for (int j = 0; j < 10; ++j)
            {
                this->cells[i][j] = '~';
            }
        }
    }

    Grid::~Grid() // no pointers are used so it deletes it by default
    {
    }

    bool Grid::isTileOccupied(int row, int col) const // checks if the tile is occupied if input is correct
    {
        if (row >= 10 || row < 0 || col >= 10 || col < 0)
        {
            std::cout << "Starting tile is out of range\n";
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

    bool Grid::inBounds(int row, int col, int shipSize, bool horizontal) const // checks if the ship can be placed
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

    void Grid::placeShip(int row, int col, int shipSize, bool horizontal) // places the ship on the grid if it can be placed
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

    void Grid::markHit(int row, int col) // marks a hit on the map depending on the what at that cell
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

    void Grid::markHitSimple(int row, int col) // second version of the prior function
    {
        if (row < 0 || row >= 10 || col < 0 || col >= 10)
        {
            std::cout << "This tile is out of range\n";
            return;
        }

        char &cell = cells[row][col];

        if (cell == '~')
        {
            cell = 'X';
        }

    }

    void Grid::markMiss(int row, int col) // marks a miss by a M on the grid
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

    void Grid::markMissSimple(int row, int col) // second version of the prior function
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
        }
    }

    char Grid::getCell(int row, int col) const  // gives the value at the given cell if it's in range
    {
        if (row < 0 || row >= 10 || col < 0 || col >= 10)
        {
            std::cout << "This tile is out of range\n";
            return 'E'; // E for Error
        }
        else
        {
            return this->cells[row][col];
        }
    }
    void Grid::printGrid() // prints the grid with a row and column count
    {
        std::cout << "     0   1   2   3   4   5   6   7   8   9\n";
        for (int row = 0; row < 10; ++row) {
            std::cout << "   -----------------------------------------\n";
            std::cout << " " << row << " |"; 
            for (int col = 0; col < 10; ++col) {
                std::cout << " " << cells[row][col] << " |";
            }
            std::cout << "\n";
        }
        std::cout << "   -----------------------------------------\n";
    }
}