#include <iostream>
#include <fstream>
#include <string.h>
#include "Ship.hpp"

// ID: 327397105, name: Denis Beigel
// ID: 212692875, name: Roei Tal

namespace Battle
{
    Ship::Ship(const char *name, int shipSize, int givenX, int givenY, const char *direction) : name(nullptr) // create constructor by details
    {
        SetName(name);
        SetSize(shipSize);
        startingX = givenX;
        startingY = givenY;
        this->direction = new char[strlen(direction) + 1];
        if (direction)
        {
            direction = direction;
        }
        else
        {
            direction = "horizontal";
        }
    }

    Ship::~Ship()
    {
        delete[] name;
    }

    void Ship::SetSize(int size) // sets size
    {
        this->size = size;
    }

    void Ship::SetName(const char *n) // sets name
    {
        if (name)
            delete[] name;
        if (n)
        {
            name = new char[strlen(n) + 1];
            strcpy(name, n);
        }
        else
        {
            name = nullptr;
        }
    }

    bool Ship::occupies(int row, int col) const
    {
        if (direction == nullptr)
            return false; // safety check

        // Check horizontal
        if (strcmp(direction, "horizontal") == 0)
        {
            return row == startingX && col >= startingY && col < startingY + size;
        }
        // Check vertical
        else if (strcmp(direction, "vertical") == 0)
        {
            return col == startingY && row >= startingX && row < startingX + size;
        }
        // Optional: handle invalid directions
        return false;
    }

    void Ship::takeHit()
    {
        if (this->hitsTaken >= this->size)
        {
            std::cout << "the ship is already gone \n";
        }
        else
        {
            this->hitsTaken++;
            if (this->hitsTaken < this->size)
            {
                std::cout << this->name << " got hit! \n";
            } else if (this->hitsTaken >= this->size)
            {
                std::cout << this->name << " got sunk! \n";
            }
        }
    }

    bool Ship::isSunk()
    {
        if (this->hitsTaken >= this->size)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}