#include <iostream>
#include <string.h>
#pragma once

// ID: 327397105, name: Denis Beigel
// ID: 212692875, name: Roei Tal

namespace Battle 
{

    class Ship{
        private : 
        char* name;
        int size;
        int hitsTaken;
        int startingX;
        int startingY;
        char* direction;

        public :

        void SetName(const char* shipName);
        void SetSize(int shipSize);

        virtual const char* getType() const
        {
            return "default";
        }

        Ship(const char* shipName, int shipSize = 0, int givenX = 0, int givenY = 0, const char* direction = "horizontal");
        virtual ~Ship();
        virtual void takeHit();
        bool occupies(int row, int col) const;
        bool isSunk();
        void printShip();
    };

    //["Carrier", "Battleship", "Cruiser", "Submarine", "Destroyer"]
    class Carrier : public Ship
    {
    public:
         const char* getType() const override { return "Carrier"; }
         Carrier(int row, int col, const char* dir) 
            : Ship("Carrier", 4, row, col, dir) {}
    };

   class BattleShip : public Ship
    {
    public:
         const char* getType() const override { return "BattleShip"; }
         BattleShip(int row, int col, const char* dir) 
            : Ship("BattleShip", 4, row, col, dir) {}
    };

    class Cruiser : public Ship
    {
    public:
         const char* getType() const override { return "Cruiser"; }
         Cruiser(int row, int col, const char* dir) 
            : Ship("Cruiser", 3, row, col, dir) {}
    };

    class Submarine : public Ship
    {
    public:
         const char* getType() const override { return "Submarine"; }
         Submarine(int row, int col, const char* dir) 
            : Ship("Submarine", 3, row, col, dir) {}
    };

    class Destroyer : public Ship
    {
    public:
         const char* getType() const override { return "Destroyer"; }
         Destroyer(int row, int col, const char* dir) 
            : Ship("Destroyer", 2, row, col, dir) {}
    };
}
