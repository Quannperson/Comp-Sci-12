#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;
int main ()

{
    //Vectors
    vector <int> numbers;
    int variable;
    unordered_map<int, int> frequency;

    //Main
    cout << "Enter 5 magic numbers!\n";
    
    for (int i = 0; i < 5; i++)
    {
        cin >> variable;
        numbers.push_back(variable);
    }

    //count number frequency in vector
    for (int numbers : numbers)
    {
        frequency [numbers]++;
    }

    cout << "The duplicate magic numbers are: " << endl;
    for (const auto& pair : frequency)
    {
        if (pair.second > 1)
        {
            cout << " " << pair.second << " " << pair.first << "s" << endl;
        }
    }
}