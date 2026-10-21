#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int fibonacci(int number)
{
    if (number <= 1)
    {
        return number;
    }
    else
    {
        
        return fibonacci;
    }
}

int main()
{
    int number;

    cout << "Input a term number and the magic sorter will find its value in the Fibonacci sequence\n";
    cin >> number;
    cout << "Your Fibonacci number is: " << fibonacci(number);
}