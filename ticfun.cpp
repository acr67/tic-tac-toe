#include <vector>
#include <iostream>
#include <string>
#include <stdlib.h>
using std::cin;
using std::cout;
using std::endl;

void is_winning(std::string board, char p1, char p2)
{
    // Single index using the columns straight down, left to right
    cout << "Let's settle the score...\n";
    int flag = 0;
    std::string combo;
    /*for (int i = 0; i < combo.size(); i++)
    {

    }*/

    /*Case 1
    012
    345
    678
    */
    //cout << board[0] << board[1] << board[2] << endl;
    char check = 'Q';

    if ((board[0] == board[1] && board[1] == board[2]))
        check = board[0];
    else if ((board[3] == board[4] && board[4] == board[5]))
        check = board[3];
    else if ((board[6] == board[7] && board[7] == board[8]))
       check = board[6];
    else if ((board[0] == board[3] && board[3] == board[6]))
        check = board[0];
    else if ((board[1] == board[4] && board[4] == board[7]))
        check = board[1];
    else if ((board[2] == board[5] && board[5] == board[8]))
        check = board[2];
    else if ((board[0] == board[4] && board[4] == board[8]))
        check = board[0];
    else if ((board[2] == board[4] && board[4] == board[6]))
        check = board[2];

    if (check == 'X')
    {
        cout << "X has won!\n";
        exit(0);
    }
    else if (check == 'O')
    {
        cout << "O has won!\n";
        exit(0);
    }


/*Case 1
ZZZ
456
789
*/

/*Case 2
123
ZZZ
789
*/

/*Case 3
123
456
ZZZ
*/

/*Case 4
Z23
Z56
Z89
*/

/*Case 5
1Z3
4Z6
7Z9
*/

/*Case 6
12Z
45Z
78Z
*/

/*Case 7
12Z
4Z6
Z89
*/

/*Case 8
Z23
4Z6
Z8Z
*/
cout << "Nobody has won yet.\n";
return;
/*if (flag == 0){
    cout << "Nobody has won yet.\n";
    return;
}
else if (flag == 1){
    cout << "Looks like player 1 has won!\n";
    return;
}
else if (flag == 2){
    "Looks like player 2 has won!\n";
    return;
}*/
}

std::string choice_loop(std::string board, char first, char second)
{
    char playerMove; // changed from int to char
    std::vector<char> usedMoves;
    cout << first << " please pick a single digit NUMBER only, between 1 and 9. The moves will alternate, so " << second << " goes next.\n";
    for (int i = 0; i < board.size(); i++)
    {
        int tries = 0;
        while (tries < 3) // The user has 3 tries to give a new number position (don't repeat positions, don't use letters/non-numbers)
        {
            cin >> playerMove;
            int flag = 0;
            cout << "Previous moves:\n";
            for (int q = 0; q < usedMoves.size(); q++)
            {

                cout << usedMoves[q] << " ";
                if (playerMove == usedMoves[q])
                    flag++;
            }
            cout << endl;
            // usedMoves.push_back(playerMove); Moving this so that the invalid moves are not "collected"

            if (flag != 0)
            {
                cout << "This position is already played.\n";
                tries++;
                if (usedMoves.size() == 9)
                    break;
            }
            else
            {
                int playerVal;
                switch (playerMove)
                {
                case '1':
                    cout << "You picked position 1.\n";
                    cout << "This is an acceptable move.\n";
                    tries = 0;
                    playerVal = 1;
                    break;
                case '2':
                    cout << "You picked position 2.\n";
                    cout << "This is an acceptable move.\n";
                    tries = 0;
                    playerVal = 2;
                    break;
                case '3':
                    cout << "You picked position 3.\n";
                    cout << "This is an acceptable move.\n";
                    tries = 0;
                    playerVal = 3;
                    break;
                case '4':
                    cout << "You picked position 4.\n";
                    cout << "This is an acceptable move.\n";
                    tries = 0;
                    playerVal = 4;
                    break;
                case '5':
                    cout << "You picked position 5.\n";
                    cout << "This is an acceptable move.\n";
                    tries = 0;
                    playerVal = 5;
                    break;
                case '6':
                    cout << "You picked position 6.\n";
                    cout << "This is an acceptable move.\n";
                    tries = 0;
                    playerVal = 6;
                    break;
                case '7':
                    cout << "You picked position 7.\n";
                    cout << "This is an acceptable move.\n";
                    tries = 0;
                    playerVal = 7;
                    break;
                case '8':
                    cout << "You picked position 8.\n";
                    cout << "This is an acceptable move.\n";
                    tries = 0;
                    playerVal = 8;
                    break;
                case '9':
                    cout << "You picked position 9.\n";
                    cout << "This is an acceptable move.\n";
                    tries = 0;
                    playerVal = 9;
                    break;
                default:
                    cout << "This is not a valid move.\n";
                    tries++;
                } // This is the end of a case-switch that gives options if the right numbers are played, and notes invalid moves otherwise
                if (tries != 0)
                {
                    // cout << tries << endl;
                }

                else
                {
                    usedMoves.push_back(playerMove);
                    if (usedMoves.size() == 9)
                    {
                        tries = 3;
                        if (i % 2 == 0)
                        {
                            board[playerVal - 1] = first;
                            if (i != board.size() - 1)
                            {
                                cout << second << " go next.\n";
                                break;
                            }
                        }
                        else
                        {
                            board[playerVal - 1] = second;
                            if (i != board.size() - 1)
                            {
                                cout << first << " go again.\n";
                                break;
                            }
                            break;
                        }
                    }
                    else if (i % 2 == 0)
                    {
                        board[playerVal - 1] = first;
                        if (i != board.size() - 1)
                        {
                            cout << second << " go next.\n";
                            break;
                        }
                    }
                    else
                    {
                        board[playerVal - 1] = second;
                        if (i != board.size() - 1)
                        {
                            cout << first << " go again.\n";
                            break;
                        }
                    }
                }

            } // This is the end of a large else statement, when the number played is not a repeat
        }     // This is the end of the while loop for tries<3
        //cout << "Round " << i + 1 << " ends.\n";

        // Showing the board to the player before the next round
        for (int i = 0; i < board.size(); i++)
        {
            cout << board[i] << board[i + 1] << board[i + 2] << endl;
            i = i + 2;
        }

        is_winning(board, first, second);

        if (tries == 3)
        {
            return "Game Over.\n";
        }
    }

    return board;
}

std::string make_move(std::string board, char p1, char p2)
{
    //cout << "Looks like Player 1 has " << p1 << " and Player 2 has " << p2 << ".\n";
    cout << "Who will go first, Player 1 or 2?\n";
    char first;

    std::string boardReturn;
    // The turns happen here, in a turn loop
    char dice_Roll = 0;
    while (dice_Roll < 3)
    {
        cin >> first;
        if (first == '1')
        {
            boardReturn = choice_loop(board, p1, p2);
            break;
        }
        else if (first == '2')
        {
            boardReturn = choice_loop(board, p2, p1);
            break;
        }
        else
        {
            cout << "Invalid.\n";
            dice_Roll++;
        }
    }
    if (dice_Roll == 3)
    {
        return "Game Over.\n";
    }
    else
    {
        return boardReturn;
    }
}