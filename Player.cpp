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

    void Player::placeAllShips(){}

    void Player::makeMove(Player *opponent){}

    void Player::addShip(Ship* newShip)
    {
        if (shipCount < 5) 
        {
            ships[shipCount] = newShip; // Ensure this is not a fixed index like [0]
            shipCount++;
        }
    }

    int Battle::Player::getRandomCoordinate()
    {
        return std::rand() % 10;
    }

    bool Player::allShipsSunk() const
    {
        for (int i = 0; i < 5; i++)
        {
            if (ships[i] == nullptr)
            {
                std::cout << "NULL SHIP index:" << i << std::endl;
            }
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
    void Player::printAllShips()
    {
        for (int i = 0; i < 5; i++)
        {
            ships[i]->printShip();
        }
    }
}