#include <iostream>
#include <fstream>
#include <string.h>
#include <random>
#include <chrono>
#include "Player.hpp"
#include "Grid.hpp"

// ID: 327397105, name: Denis Beigel
// ID: 212692875, name: Roei Tal

namespace Battle
{

    Player &Player::operator=(const Player &other)
    {
        if (this == &other)
            return *this;

        delete[] playerName; // Clean up
        for (int i = 0; i < 5; ++i)
        {
            delete ships[i];
        }

        if (other.playerName) // Deep Copy
        {
            playerName = new char[strlen(other.playerName) + 1];
            strcpy(playerName, other.playerName);
        }
        else
        {
            playerName = nullptr;
        }

        for (int i = 0; i < 5; ++i)
        { // Deep copy of player ships
            if (other.ships[i])
            {
                // ships[i] = other.ships[i]->clone(); // Need a virtuale clone
            }
            else
            {
                ships[i] = nullptr;
            }
        }

        grid = other.grid;
        shipCount = other.shipCount;

        return *this;
    }

    void Player::placeAllShips()
    {

    }

    void Player::makeMove(Player *opponent)
    {
        int row = getRandomCoordinate();
        int col = getRandomCoordinate();

        if (opponent->grid.getCell(row, col) == 'S')
        {
           
        }
        else
        {
            opponent->grid.markMiss(row, col);
        }
        std::cout << "Attack: (" << row << ", " << col << ")" << std::endl;
        this->grid.printGrid();
        opponent->grid.printGrid();
    }

    void Player::addShip(Ship* newShip)
    {
        ships[shipCount++] = newShip;
    }

    int Battle::Player::getRandomCoordinate()
    {
        return std::rand() % 10;
    }

    bool Player::allShipsSunk() const
    {
        int validShipsFound = 0;

        for (int i = 0; i < 5; i++)
        {
            // 1. Safety check: skip empty slots
            if (ships[i] != nullptr)
            {
                validShipsFound++;
                
                // 2. If we find even ONE ship that is NOT sunk, the player is still in the game
                if (ships[i]->isSunk() == false)
                {
                    return false; 
                }
            }
        }

        // 3. If we found 0 ships total, the player hasn't "lost" yet (handles setup errors)
        if (validShipsFound == 0) return false;

        // 4. If we found ships and NONE of them returned false (meaning they are all sunk)
        return true;
    }

    void Player::displayGrid()
    {
        grid.printGrid();
    }

    Player::Player(const char *name) : playerName(nullptr)
    {
        SetPlayerName(name);
        ClearShips();
        shipCount = 0;

    }

    Player::Player()
    { 
        SetPlayerName("default");
        ClearShips();
        shipCount = 0;
    }

    Player::~Player()
    {
        delete[] playerName;
        for(int i = 0; i < shipCount; i++)
        {
            delete ships[i];
        }
    }

    void Player::SetPlayerName(const char *n) // sets name
    {
        if (playerName)
            delete[] playerName;
        if (n)
        {
            playerName = new char[strlen(n) + 1];
            strcpy(playerName, n);
        }
        else
        {
            playerName = nullptr;
        }
    }
    
    int Player::getShipCount(){
        return shipCount;
    }
    
    void Player::ClearShips()
    {
        for (int i = 0; i < 5; i++)
        {
            ships[i] = nullptr;
        }
    }
}