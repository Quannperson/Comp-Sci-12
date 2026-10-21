#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

double add(vector <int> numbers)
{
    return accumulate(numbers.begin(), numbers.end(), 0.0);
}

int main()
{
    int a;
    vector <int> numbers;

    cout << "Enter some numbers, the magic sorter will add them!\n";
    while (cin >> a)
    {
        numbers.push_back(a);
    }
    
    cout << "\nYour magic numbers added are: " << add(numbers);
}