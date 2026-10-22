#include <iostream>
#include <vector>
#include <numeric>
#include <U2S4E1.hpp>
#include <U2S4E2.hpp>

using namespace std;

int main()
{
    cout << "Look at these cool magic numbers: ";
    for (int i = 0; i < magicNumbers.size(); i++)
    {
        cout << magicNumbers[i] << " ";
    }
    cout << "\nThe sum of these magic numbers is: " << add(magicNumbers) << endl;
    return 0;
}

