#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int rows = 10;
    int columns = 10;
    char letter = 'A';
    int number = 1;
    
    vector <vector<string>> battleShip;

    for (int i = 0; i < 10; i++)
    {
        vector<string> magicColumn;
        letter++;

        for (int j = 0; j < 10; j++)
        {
            magicColumn.push_back(string(1, letter) + to_string(number));
            number++;
        }
    }

    for (const auto& rows : battleShip)
    {
        for (const string& cell : rows)
        {
            cout << cell << " ";
        }
        cout << endl;
    }
}