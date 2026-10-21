#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

double average(vector <int> numbers)
{
    float sum = accumulate(numbers.begin(), numbers.end(), 0.0);
    return sum / numbers.size();
}

int main()
{
    int a;
    vector <int> numbers;

    cout << "Enter some numbers, the magic sorter will average them!\n";
    while (cin >> a)
    {
        numbers.push_back(a);
    }
    
    cout << "\nYour magic numbers averaged are: " << average(numbers);
}