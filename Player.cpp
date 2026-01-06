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

Player& Player::operator=(const Player& other) 
{
    if (this == &other) return *this;

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

    for (int i = 0; i < 5; ++i) { // Deep copy of player ships
        if (other.ships[i]) {
            // ships[i] = other.ships[i]->clone(); // Need a virtuale clone
        } else {
            ships[i] = nullptr;
        }
    }

    grid = other.grid;

    return *this;
}

    void Player::placeAllShips() // AIPlayer will used this funtion, Overide will be made for HumanPlayer
    {
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count(); // Create a random seed based on the system_clock
        std::default_random_engine engine(seed); // Feed that seed into a random number engine
        std::uniform_int_distribution<int> RandomAxisPoint(0, 9);  
        std::uniform_int_distribution<int> RandomBool(0, 1);

        int shipSizes[] = {5, 4, 3, 3, 2}; // Standard Fleet

        for (int size : shipSizes) {
        bool placed = false;
        
        while (!placed) {
            int row = RandomAxisPoint(engine);
            int col = RandomAxisPoint(engine);
            bool horizontal = RandomBool(engine);

            if (grid.inBounds(row, col, size, horizontal)) {
                grid.placeShip(row, col, size, horizontal);
                placed = true; // Exit
            }
        }
    }
}

    void Player::makeMove(Player *opponent)
    {
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count(); // Create a random seed based on the system_clock
        std::default_random_engine engine(seed); // Feed that seed into a random number engine
        std::uniform_int_distribution<int> RandomAxisPoint(0, 9);

        int row = RandomAxisPoint(engine), col = RandomAxisPoint(engine);

        if (opponent->grid.getCell(row, col) == 'S')
        {
            opponent->ships[1]->takeHit(); // Need to find the correct ship
            opponent->grid.markHit(row, col);
        }
        else
        {
            opponent->grid.markMiss(row, col);
        }
        
        this->grid.printGrid();
        opponent->grid.printGrid();
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
    }

    Player::Player()
    {
        SetPlayerName("defualt");
        ClearShips();
    }

    Player::~Player()
    {
        delete[] playerName;
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