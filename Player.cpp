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
        { 
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
       int row, col;
        char targetCell;

        do {
            row = getRandomCoordinate();
            col = getRandomCoordinate();
            targetCell = opponent->grid.getCell(row, col);
        } while (targetCell == 'X' || targetCell == 'M');

        if (targetCell == 'S')
        {
            std::cout << "HIT at (" << row << ", " << col << ")!" << std::endl;
            bool shipFound = false;
            for (int i = 0; i < opponent->getShipCount(); i++)
            {
                Ship* currentShip = opponent->getShip(i);
                if (currentShip != nullptr && currentShip->occupies(row, col))
                {
                    currentShip->takeHit();
                    std::cout << "Target damaged: " << currentShip->getType() << std::endl;
                    shipFound = true;
                    break; // Ship is found
                }
            }

            opponent->grid.markHit(row, col);
        }
        else
        {
            std::cout << "Miss at (" << row << ", " << col << ")" << std::endl;
            opponent->grid.markMiss(row, col);
        }

        std::cout << "--- " << playerName << "'s View ---" << std::endl;
        opponent->displayGrid();
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
        for (int i = 0; i < 5; i++)
        {
            if (ships[i]->isSunk() == false)
            {
               return false;
            }
        }
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