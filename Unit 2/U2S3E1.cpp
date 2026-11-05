#include <iostream>

using namespace std;

int fiftyNumbers(int number)
{
    if(number > 50)
    {
        return number;
    }
    else
    {
    cout << number << " ";
    fiftyNumbers(number + 1);
    }
}

int main()
{
    int numbers = 1;
    cout << "The first 50 numbers are: " << fiftyNumbers(numbers);
}