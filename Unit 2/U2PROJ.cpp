#include "U2PROJ.hpp"

using namespace std;

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
    getline(cin, player1);

    cout << "Player 2, who are you?: ";
    getline(cin, player2);

    cout << "\nLet's present our board!\n";
    battleshipBoard(boardOne); //calling either board to show blank board
    cout << "\nWhen shooting, type the row letter and column number of the cell you'd like to shoot at together\n Red is a miss, green is a hit!\n";

    cout << "First, how many boats would you like to play with? (both players): ";
    cin >> boatNumber;

    cout << "Alright " << player1 << ", type the coordinates of your ships one by one!\n";
    chooseBoats(boardOne, boatNumber, boatCounter, player1);
    cout << "\033[2J\033[H"; //hide boats from other player

    cout << "\nAlright " << player2 << ", type the coordinates of your ships one by one!\n";
    chooseBoats(boardTwo, boatNumber, boatCounter, player2);
    cout << "\033[2J\033[H";

    cout << "Time to get started!";
    playerBoards(boardOne, boardTwo, player1, player2, boatNumber, boatCounter);
}