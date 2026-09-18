#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main ()

{
    //State vector!
    vector<int> numbers = {1, 2, 3, 4, 5};

    //Main
    cout << "The magic numbers are: " << endl;
    for (int i = 0; i < numbers.size(); i++)
    {
        cout << numbers[i] << endl;
    }

    //Reverse numbers and determine max and min
    reverse(numbers.begin(), numbers.end());

    int max = *max_element(numbers.begin(), numbers.end());
    int min = *min_element(numbers.begin(), numbers.end());
    
    //Output reversed vector and max & min
    cout << "\n The magic numbers reversed: " << endl;
    for (int i = 0; i < numbers.size(); i++)
    {
        cout << numbers[i] << endl;
    }

    cout << "The max of the magic numbers is: " << max << endl;
    cout << "The min of the magic numbers is: " << min << endl;
}