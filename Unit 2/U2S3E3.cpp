#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>

using namespace std;

int fibonacci(int number)
{
    int i = 1;

    if (number <= 1)
    {
        return number;
    }
    else if (i < number)
    {
        return (pow(numbers::phi, number) - pow(1 - numbers::phi, number)) / sqrt(5);
        i++;
    }
}

int main()
{
    int number;

    cout << "Input a term number and the magic sorter will find its Fibonacci Sequence value!\n";
    cin >> number;
    cout << "Your Fibonacci value is: " << fibonacci(number);
}