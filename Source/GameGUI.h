#pragma once
#include "SFML/Graphics.hpp"
#include<iostream>
using namespace std;


class GameGUI
{
   public:
        GameGUI(int size, int wincondition); // Constructor
        void run(); // Process events and draw
        ~GameGUI(); // Destructor
    private:
        typedef pair<int, int> bestMove;
        bool AItoMove = false;
        bool firstMove = true;
        bool running = true;
        sf::RenderWindow window; // Window from SFML
        size_t size; // Size of the board
        size_t wincondition; // Number of signs in a row,column or diagnolas to win
        size_t maxDepth; // Maximum depth for the minimax algorithm
        char** board; // Board of the game
        void EventHandler(); // Process events
        void Draw(); // Draw the board
        bool isValidMove(int x, int y); // Check if the move is valid
        bool isWin(char sign); // Check if the player with the sign has won
        bool isDraw(); // Check if the game is a draw
        void AITurn(char AIsign, char playerSign); // AI turn
        int minimax(char AIsign, char playerSign, size_t depth, bool isMaximizingPlayer, int alpha, int beta); // Minimax algorithm with alpha-beta pruning
};