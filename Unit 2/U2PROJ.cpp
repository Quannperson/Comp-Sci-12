#include <iostream>
#include <vector>

using namespace std;

    void battleshipBoard(const vector<vector<int>>& boards)
    {
        cout << "   1 2 3 4 5 6 7 8 9 10\n";

        for (int a = 0; a < 10; a++)
        {
            char letter = 'A' + a;
            cout << letter << " ";

            for (int b = 0; b < 10; b++)
            {
                cout << " " << boards[a][b];
            }
            cout << "\n";
        }
    }

    void playerBoards(vector<vector<int>>& boardOne, vector<vector<int>>& boardTwo, const string& player1, const string& player2)
    {

    }

    void chooseBoats(vector<vector<int>>& board, int boatNumber, int boatCounter, string& playerName)
    {
        char row;
        int column;

        if (boatCounter == boatNumber)
            return;

            cout << "Alright " << playerName << "type the coordinates of your ships one by one!\n";

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


    
int main()
{
    //variables
    int rows = 10;
    int columns = 10;
    int boatCounter;
    int boatNumber;
    string player1;
    string player2;

    vector <vector<int>> boardOne(rows, vector<int>(columns, 0));
    vector <vector<int>> boardTwo(rows, vector<int>(columns, 0));

    cout << "Time to play some Battleship!\n";

    cout << "Player 1, who are you?: ";
    cin >> player1;

    cout << "Player 2, who are you?: ";
    cin >> player2;

    cout << "Let's present our board!";
    battleshipBoard(boardOne); //calling either board to show blank board

    cout << "First, how many boats would you like to play with? (both players):";
    cin >> boatNumber;
    chooseBoats(boardOne, boatNumber, boatCounter, player1);
    chooseBoats(boardTwo, boatNumber, boatCounter, player2);


}