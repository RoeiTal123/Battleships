#include <iostream>
#include <fstream>
#include <string.h>
#include "Player.hpp"
#include "Grid.hpp"

// ID: 327397105, name: Denis Beigel
// ID: 212692875, name: Roei Tal

namespace Battle
{

    void Player::placeAllShips()
    {
    }

    void Player::makeMove(Player *opponent)
    {
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
        // Print grid stooge
    }

    Player::Player(const char *name) : playerName(nullptr)
    {
        SetPlayerName(name);
        ClearShips();
    }

    Player::Player()
    {
        SetPlayerName("defualt");
        ClearShips();
    }

    Player::~Player()
    {
        
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
    void Player::ClearShips()
    {
        for (int i = 0; i < 5; i++)
        {
            ships[i] == nullptr;
        } 
    }
}