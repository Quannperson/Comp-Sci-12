    #ifndef U2PROJ_HPP
    #define U2PROJ_HPP

    #include <iostream>
    #include <vector>
    #include <algorithm>
    #include <cctype>
    #include <limits>

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
                    cout << " \033[31m*\033[0m"; //misses are red
                }
                else if (boards[a][b] == 3)
                {
                    cout << " \033[32m*\033[0m"; //hits are green
                }
                else
                {
                    cout << " *";
                }
            }
            cout << "\n";
        }
    }

    void chooseBoats(vector<vector<int>>& board, int boatNumber, int boatCounter, const string& playerName)
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
            if (!(cin >> row >> column))
            {
                cin.clear();
                cout << "Hmm.. not on the grid, try again!\n";
                continue;
            }

            row = static_cast<char>(toupper(static_cast<unsigned char>(row)));

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

    int adjBoats(const vector<vector<int>>& board, int rowMark, int columnMark, int index)
    {
        static const int rowOffsets[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
        static const int columnOffsets[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

        if (index == 8) //finish if all surrounding cells are checked
        {
            return 0;
        }

        int adjRow = rowMark + rowOffsets[index];
        int adjColumn = columnMark + columnOffsets[index];
        int count = 0;

        if (adjRow >= 0 && adjRow < 10 && adjColumn >= 0 && adjColumn < 10 && board[adjRow][adjColumn] == 1)
        {
            count = 1;
        }
    

        //check the next position, then add its count to current one
        return count + adjBoats(board, rowMark, columnMark, index + 1);
    }


    void hitOrmiss(vector<vector<int>>& board, const string& playerName)
    {
        char row;
        int column;
        char rowMark;
        int columnMark;

        cout << "\nLet's see, " << playerName << " choose a coordinate to shoot: ";

        while(true)
        {
            if (!(cin >> row >> column))
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Hmm.. not on the grid, try again!\n";
                continue;
            }

            row = static_cast<char>(toupper(static_cast<unsigned char>(row)));
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
                break;
            }
            else
            {
                cout << "Bangg hit! \n";
                board[rowMark][columnMark] = 3; //set to hit value
                break;
            }
        }

        int adjacent = adjBoats(board, rowMark, columnMark, 0);

        cout << "There are " << adjacent << " unhit boats around the cell you shot...\n";
    }

    int boatsLeft(const vector<vector<int>>& board) //counts how many boats are left
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

        int player1BoatsLeft = boatsLeft(boardOne);
        int player2BoatsLeft = boatsLeft(boardTwo);

        if(cellCount2 >= 100 || cellCount1 >= 100)
        {
            cout << "\nDang, didn't know that was possible... double loss!";
        }
        else if(player1BoatsLeft == 0 && player2BoatsLeft == 0)
        {
            cout << "\nWowie! Close, it's a draw! Let's choose more boats to keep playing!\n";

            cout << "\nFirst, " << player1 << " choose where you want to place 2 more boats\n";
            cout << "\033[2J\033[H";
            chooseBoats(boardOne, 2, 0, player1);

            cout << "Now, " << player2 << " two boats as well\n";
            chooseBoats(boardTwo, 2, 0, player2);
            cout << "\033[2J\033[H";

            cout << "Ok run it back\n";

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

    #endif
