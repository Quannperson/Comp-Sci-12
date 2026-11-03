#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

    void battleshipBoard(const vector<vector<int>>& boards) //printing main board
    {
        cout << "   1 2 3 4 5 6 7 8 9 10\n";

        for (int a = 0; a < 10; a++)
        {
            char letter = 'A' + a;
            cout << letter << " ";

            for (int b = 0; b < 10; b++)
            {
                if (boards[a][b] == 2)
                {
                    cout << " \033[31m*\033[0m"; // misses are red
                }
                else if (boards[a][b] == 3)
                {
                    cout << " \033[32m*\033[0m"; // hits are green
                }
                else
                {
                    cout << " *";
                }
            }
            cout << "\n";
        }
    }

    void chooseBoats(vector<vector<int>>& board, int boatNumber, int boatCounter, string& playerName)
    //choosing boats for players
    {
        char row;
        int column;

        if (boatCounter == boatNumber)
        {
            return;
        }

        while (true)
        {
            cin >> row >> column;

            if (row < 'A' || row > 'J' || column < 1 || column > 10)
            {
                cout << "Hmm.. not on the grid, try again!\n";
            }
            else if (board[row - 'A'][column - 1] != 0)
            {
                cout << "Hmm.. can't stack boats, try again!\n";
            }
            else
            {
                board[row - 'A'][column - 1] = 1;
                break;
            }
        }

        chooseBoats(board, boatNumber, boatCounter + 1, playerName);
    }

    void hitOrmiss(vector<vector<int>>& board, const string& playerName)
    {
        int cellCount = 0;
        char row;
        int column;
        int surrounding = 0;
        char rowMark;
        int columnMark;

        cout << "Let's see, " << playerName << " choose a coordinate to shoot: ";

        while(true)
        {
            cin >> row >> column;
            rowMark = row - 'A';
            columnMark = column - 1;

            if (row < 'A' || row > 'J' || column < 1 || column > 10)
            {
                cout << "Hmm.. not on the grid, try again!\n";
                continue;
            }
            else if (board[rowMark][columnMark] == 2 || board[rowMark][columnMark] == 3) 
            //2 if shot and missed earlier, 3 if shot and hit earlier
            {
                cout << "Shot there already, try again!\n";
                continue;
            }
            else if (board[rowMark][columnMark] == 0)
            {
                cout << "Oof.. big miss\n";
                board[rowMark][columnMark] = 2; //set to missed value
                cellCount++;
                break;
            }
            else
            {
                cout << "Bangg hit! \n";
                board[rowMark][columnMark] = 3; //set to hit value
                cellCount++;
                break;
            }
        }

        for (int r = -1; r <= 1; r++) //r is the row offset
        {
            for (int c = -1; c <= 1; c++) //c is the column offset
            {
                if (r == 0 && c == 0) //skips the shot cell
                    continue;

                int adjRow = rowMark + r;
                int adjColumn = columnMark + c;

                if (adjRow >= 0 && adjRow < 10 && adjColumn >= 0 && adjColumn < 10 && board[adjRow][adjColumn] == 1)
                {
                    surrounding++;
                }
            }
        }

        cout << "There are " << surrounding << " boats around the cell you shot...\n";
    }

    int boatsLeft(const vector<vector<int>>& board)
    {
        int count = 0;

        for (int r = 0; r < 10; r++)
        {
            for (int c = 0; c < 10; c++)
            {
                if (board[r][c] == 1)
                {
                    count++;
                }
            }
        }

        return count;
    }

    void playerBoards(vector<vector<int>>& boardOne, vector<vector<int>>& boardTwo, const string& player1, const string& player2, int boatNumber, int boatCounter)
    {
        bool player1Turn = true;
        int player1BoatsLeft = boatsLeft(boardOne);
        int player2BoatsLeft = boatsLeft(boardTwo);
        int cellCount1 = 0;
        int cellCount2 = 0;

        while (boatsLeft(boardOne) > 0 && boatsLeft(boardTwo) > 0)
        {
            hitOrmiss(boardTwo, player1); // Player 1 shoots
            cellCount1++;
            hitOrmiss(boardOne, player2); // Player 2 shoots
            cellCount2++;

            cout << player1 << "'s board:\n";
            battleshipBoard(boardOne);

            cout << player2 << "'s board:\n";
            battleshipBoard(boardTwo);
        }

        if(cellCount2 >= 100 || cellCount1 >= 100)
        {
            cout << "\nDang, didn't know that was possible... double loss!";
        }
        else if(player1BoatsLeft == 0 && player2BoatsLeft == 0)
        {
            cout << "\nWowie! Close, it's a draw! Let's choose more boats to keep playing!\n";
            chooseBoats(boardTwo, boatNumber, 0, player1);
        }
        else if(player2BoatsLeft == 0)
        {
            cout << "\nYippee! " << player1 << " wins!\n";
        }
        else
        {
            cout << "\nYippee! " << player2 << " wins!\n";
        }
    }


int main()
{
    //variables
    int rows = 10;
    int columns = 10;
    int boatCounter = 0;
    int boatNumber;
    string player1;
    string player2;

    vector <vector<int>> boardOne(rows, vector<int>(columns, 0));
    vector <vector<int>> boardTwo(rows, vector<int>(columns, 0));

    cout << "Time to play some Battleship!\n";

    cout << "\nPlayer 1, who are you?: ";
    cin >> player1;

    cout << "Player 2, who are you?: ";
    cin >> player2;

    cout << "\nLet's present our board!\n";
    battleshipBoard(boardOne); //calling either board to show blank board
    cout << "\nWhen shooting, type the row letter and column number of the cell you'd like to shoot at together\n Red is a miss, green is a hit!\n";

    cout << "First, how many boats would you like to play with? (both players): ";
    cin >> boatNumber;

    cout << "Alright " << player1 << ", type the coordinates of your ships one by one!\n";
    chooseBoats(boardOne, boatNumber, boatCounter, player1);
    cout << "\033[2J\033[H"; //hide boats from other player

    cout << "Alright " << player2 << ", type the coordinates of your ships one by one!\n";
    chooseBoats(boardTwo, boatNumber, boatCounter, player2);

    cout << "Time to get started! ";
    playerBoards(boardOne, boardTwo, player1, player2, boatNumber, boatCounter);
}