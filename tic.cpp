#include <iostream>
#include <vector>
#include "tic.hpp"
using std::cin;
using std::cout;
using std::endl;

int main()
{
    cout << "Welcome to Tic Tac Toe Game!\n";
    cout << "Player 1, are you X or O?\n";
    char p1;
    char p2;
    int tries=0;
    while (tries<3)
    {
        cin >> p1;
        if (p1 == 'X')
        {
            cout << "Excellent! Player 1 is X. Player 2 is O.\n";
            p2 = 'O';
            break;
        }
        else if (p1 == 'O')
        {
            cout << "Excellent! Player 1 is O. Player 2 is X.\n";
            p2 = 'X';
            break;
        }
        else
        {
            cout << "Invalid choice.\n";
            tries++;
        }
    }
    if (tries==3)
    {
        return 0;
    }
    cout << "The game board looks like this. You can pick your positions, 1-9, as we play.\n";
    //Sample of what the game board should look like, with single indexing
    std::string myBoardString = "123456789";
    for (int i = 0; i < myBoardString.size(); i++)
    {
        cout << myBoardString[i] << myBoardString[i + 1] << myBoardString[i + 2] << endl;
        i = i + 2;
    }
    cout << "Let's start playing!\n";
    std::string newBoard;
    newBoard = make_move(myBoardString, p1, p2);

}