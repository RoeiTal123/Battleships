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
    };

    //["Carrier", "Battleship", "Cruiser", "Submarine", "Destroyer"]
        class Carrier : public Ship
        {
        public:
             const char* getType() const override
             {
                 return "Carrier";
             }
    
            Carrier()
                : Ship("Carrier", 5, 0, 0, "horizontal") {} 
        };
    
        class BattleShip : public Ship
        {
        public:
             const char* getType() const override
             {
                 return "BattleShip";
             }
    
             BattleShip()
                : Ship("Battleship", 4, 0, 0, "horizontal") {} 
        };
    
        class Cruiser : public Ship
        {
        public:
             const char* getType() const override
             {
                 return "Cruiser";
             }
    
             Cruiser()
                : Ship("Cruiser", 3, 0, 0, "horizontal") {} 
        };

        class Submarine : public Ship
        {
        public:
             const char* getType() const override
             {
                 return "Submarine";
             }
    
             Submarine()
                : Ship("Submarine", 3, 0, 0, "horizontal") {} 
        };
    
        class Destroyer : public Ship
        {
        public:
             const char* getType() const override
             {
                 return "Destroyer";
             }
    
             Destroyer()
                : Ship("Destroyer", 2, 0, 0, "horizontal") {} 
        };
}
