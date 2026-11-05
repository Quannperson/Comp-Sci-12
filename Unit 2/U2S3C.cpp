#include <iostream>

using namespace std;

int fibonacci(int number)
{
    if(number < 1)
    {
        return number;
    }
    else
    {
        return fibonacci(number - 1) + fibonacci(number - 2);
    }
}

int main()
{
    int number;

    cout << "Input a term number and the magic sorter will find its value in the Fibonacci sequence\n";
    cin >> number;
    cout << "Your Fibonacci number is: " << fibonacci(number);
}