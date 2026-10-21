#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int factorial(int number)
{
    if (number <= 1)
    {
        return 1;
    }
    else
    {
        return number * factorial(number - 1);
    }
}

int main()
{
    int number;

    cout << "Input a number and the magic sorter will find its factorial!\n";
    cin >> number;
    cout << "Your factorial is: " << factorial(number);
}