
#include <iostream>
#include "Functions.h"
#include <string>


int main()
{
    //TicTacToe Grid
    char TTTArray[][3] = {
                            {'1','2','3'},
                            {'4','5','6'},
                            {'7','8','9'}
                          };
    //Print which character is for which player
    std::cout << "Player 1: 'X' \nPlayer 2: 'O' " << std::endl << std::endl;
    //Print grid
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            std::cout << TTTArray[i][j] << ' ';
        }
        std::cout << std::endl;
    }
    //false if no winner; true if winner   
    bool winner = false;
    //9 spaces on grid
    int spaces = 9;
    while (winner == false)
    {   
        int player = 1;
        //if no more spaces, end program.
        if (spaces == 0)
        {
            std::cout << "\nDraw. \n";
            return 0;
        }
        std::string replace;
        //check if its player 1 or 2
        if (spaces % 2 == 1)
        {
            player = 1;
        }
        else
        {
            player = 2;
        }

        //prompt player to choose a space
        std::cout << "\nPlayer " << player << ": choose what space to replace.";
        do
        {
          std::getline(std::cin, replace);
        } while (sizeof((char)replace[0]) != sizeof(char));
        //checks to see if the space is taken or not, if not replaces it
        Replacer(TTTArray, player, replace);
        //when returns, space available subtracts one
        spaces--;    
    }  
}