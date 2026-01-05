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

        public :

        void SetName(const char* shipName);
        void SetSize(int shipSize);

        virtual const char* getType() const
        {
            return "default";
        }

        Ship(const char* shipName, int shipSize);
        virtual ~Ship();
        virtual void takeHit();
        bool isSunk();
    };


    class Carrier : public Ship
        {
        public:
             const char* getType() const override
             {
                 return "Carrier";
             }
    
            Carrier()
                : Ship("Carrier", 5) {} 
        };
    
        class BattleShip : public Ship
        {
        public:
             const char* getType() const override
             {
                 return "BattleShip";
             }
    
             BattleShip()
                : Ship("Battleship", 4) {} 
        };
    
        class Cruiser : public Ship
        {
        public:
             const char* getType() const override
             {
                 return "Cruiser";
             }
    
             Cruiser()
                : Ship("Cruiser", 3) {} 
        };

        class Submarine : public Ship
        {
        public:
             const char* getType() const override
             {
                 return "Submarine";
             }
    
             Submarine()
                : Ship("Submarine", 3) {} 
        };
    
        class Destroyer : public Ship
        {
        public:
             const char* getType() const override
             {
                 return "Destroyer";
             }
    
             Destroyer()
                : Ship("Destroyer", 2) {} 
        };
}
