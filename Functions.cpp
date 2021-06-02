#include <iostream>
#include <string>

void PrintArray(char myArray[][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			std::cout << myArray[i][j] << ' ';
		}
		std::cout << std::endl;
	}
}

bool WinnerChecker(char TTTarray[][3])
{
    char player1 = 'X';
    char player2 = 'O';
    //if a win condition is met, winner is true
    bool winner = false;
    //win conditions
    if (TTTarray[0][0] == player1 && TTTarray[0][1] == player1 && TTTarray[0][2] == player1 || TTTarray[0][0] == player2 && TTTarray[0][1] == player2 && TTTarray[0][2] == player2)
    {
        winner = true;
    }
    else if (TTTarray[1][0] == player1 && TTTarray[1][1] == player1 && TTTarray[1][2] == player1 || TTTarray[1][0] == player2 && TTTarray[1][1] == player2 && TTTarray[1][2] == player2)
    {
        winner = true;

    }
    else if (TTTarray[2][0] == player1 && TTTarray[2][1] == player1 && TTTarray[2][2] == player1 || TTTarray[2][0] == player2 && TTTarray[2][1] == player2 && TTTarray[2][2] == player2)
    {
        winner = true;

    }
    else if (TTTarray[0][0] == player1 && TTTarray[1][0] == player1 && TTTarray[2][0] == player1 || TTTarray[0][0] == player2 && TTTarray[1][0] == player2 && TTTarray[2][0] == player2)
    {
        winner = true;

    }
    else if (TTTarray[0][1] == player1 && TTTarray[1][1] == player1 && TTTarray[2][1] == player1 || TTTarray[0][1] == player2 && TTTarray[1][1] == player2 && TTTarray[2][1] == player2)
    {
        winner = true;

    }
    else if (TTTarray[0][2] == player1 && TTTarray[1][2] == player1 && TTTarray[2][2] == player1 || TTTarray[0][2] == player2 && TTTarray[1][2] == player2 && TTTarray[2][2] == player2)
    {
        winner = true;

    }
    else if (TTTarray[0][2] == player1 && TTTarray[1][1] == player1 && TTTarray[2][0] == player1 || TTTarray[0][2] == player2 && TTTarray[1][1] == player2 && TTTarray[2][0] == player2)
    {
        winner = true;

    }
    else if (TTTarray[0][0] == player1 && TTTarray[1][1] == player1 && TTTarray[2][2] == player1 || TTTarray[0][0] == player2 && TTTarray[1][1] == player2 && TTTarray[2][2] == player2)
    {
        winner = true;

    }
    else
    {
        //if no win condition is met, will return false (no winner)
        winner = false;
    }

    return winner;
}

void Replacer(char myArray[][3], int playerNumber, std::string replace)
{	
    while (replace[0] < (int)'1')
    {
        std::cout << "Number too small, try again: ";
        std::getline(std::cin, replace);
    }
    while (replace[1] != '\0')
    {
        std::cout << "Number too large, try again: ";
        std::getline(std::cin, replace);
    }
    //the variable that determines what to replace the number space with
	char replaceWith;
    //player 1 is 'X', player 2 is 'O'
	if (playerNumber == 1)
	{
		replaceWith = 'X';
	}
	else
	{
		replaceWith = 'O';
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
            //if the space mathches your chosen value
			if (myArray[i][j] == replace[0])
			{
                //replace the space with your chosen value
				myArray[i][j] = replaceWith;
				PrintArray(myArray);
                //check for winner
                bool winner = WinnerChecker(myArray);
                if (winner == true)
                {
                    {
                        //exit the program if there is a winner
                        std::cout << "\nCongratulation Player "<< playerNumber <<" you win!\n";
                        exit(0);
                    }
                }
				return;
			}
		}
	}
    //if the space chosen is taken or not on the grid
	std::cout << "Space unavailable, choose another.";
    std::getline(std::cin, replace);
	Replacer(myArray, playerNumber, replace);
}
