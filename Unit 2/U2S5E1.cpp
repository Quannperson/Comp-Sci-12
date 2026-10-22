#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int rows = 5;
    int columns = 5;
    int coolNumber = 1;

    vector <vector<int>> magicArray;

    for (int i = 0; i < rows; i++)
    {
        vector<int> magicRow;

        for (int j = 0; j < columns; j++)
        {
            magicRow.push_back(coolNumber);
            coolNumber += 2;
        }
    }
    
    for (const auto& rows : magicArray)
    {
        for (int number : rows)
        {
            cout << number << " ";
        }
        cout << endl;
    }
    
}