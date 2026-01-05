#include <iostream>
#include <fstream>
#include <string.h>
#include "Player.hpp"

// ID: 327397105, name: Denis Beigel
// ID: 212692875, name: Roei Tal
namespace Battle
{
    class Game
    {
    private:
        Player* player1;
        Player* player2;

    public:
        void setup(); // Calls player1->placeAllShips();, then player2->placeAllShips();

        void start(); // 

        Game(Player* p1, Player* p2); // Assigns two player objects (e.g., HumanPlayer vs. AiPlayer).
        Game(/* args */);
        ~Game();
    };
    

}