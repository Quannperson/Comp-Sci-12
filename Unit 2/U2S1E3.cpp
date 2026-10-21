#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int gcf(vector <int> numbers)
{
    return gcd(numbers[0], numbers[1]);
}

int main()
{
    int a;
    vector <int> numbers;

    cout << "Enter two numbers, the magic sorter will find their GCF!\n";
    for (int i = 0; i < 2; i++)
    {
        cin >> a;
        numbers.push_back(a);
    }

    cout << "\nThe greatest common factor : " << gcf(numbers);
}