#include <iostream>
#include <string.h>
#pragma once

// ID: 327397105, name: Denis Beigel
// ID: 212692875, name: Roei Tal

namespace Battle
{
    class Grid
    {
    private:
        char cells[10][10];

    public:
        bool isTileOccupied(int row, int col) const;
        bool inBounds(int row, int col, int shipSize, bool horizontal) const;
        void placeShip(int row, int col, int shipSize, bool horizontal);
        void markHit(int row, int col);
        void markMiss(int row, int col);
        char getCell(int row, int col) const;

        void printGrid();

        Grid();
        ~Grid();
    };
}