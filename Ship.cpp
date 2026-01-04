#include <iostream>
#include <fstream>
#include <string.h>
#include "Ship.hpp"

// ID: 327397105, name: Denis Beigel
// ID: 212692875, name: Roei Tal

namespace Battle
{
    Ship::Ship(const char *name, int shipSize) : name(nullptr) // create constructor by details
    {
        SetName(name);
        SetSize(shipSize);
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

    void Ship::takeHit()
    {
        if (this->hitsTaken >= this->size)
        {
            std::cout << "the ship is already gone \n";
        }
        else
        {
            this->hitsTaken++;
            if (this->hitsTaken >= this->size)
            {
                std::cout << this->name << " got hit! \n";
            }
        }
    }

    bool Ship::isSunk()
    {
        if (this->hitsTaken >= this->size)
        {
            return true;
        } else {
            return false;
        }
    }
}