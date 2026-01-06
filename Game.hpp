#include <iostream>
#include <fstream>
#include <string.h>
#include "Player.hpp"

// ID: 327397105, name: Denis Beigel
// ID: 212692875, name: Roei Tal

enum Winner { Player1, Player2, None};

namespace Battle
{
    class Game
    {
    private:
        Player* player1;
        Player* player2;
        Winner w = None;
    public:
        void setup(); // Calls player1->placeAllShips();, then player2->placeAllShips();

        void start(); // The main game loop: a.player1->makeMove(player2);

                                        //   b.Check player2->allShipsSunk().

                                        //   c.player2->makeMove(player1);

                                        //   d.Check player2->allShipsSunk().
                                        
        bool isGameOver() const;

        Game(Player* p1, Player* p2); // Assigns two player objects (e.g., HumanPlayer vs. AiPlayer).
        Game();
        ~Game();
    };
    

}