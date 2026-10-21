#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

double gcf(vector <int> numbers)
{
    return gcd(gcd(numbers[0], numbers [1]), numbers [2]);
}

int main()
{
    int a;
    vector <int> numbers;

    cout << "Enter some numbers, the magic sorter will find their GCF!\n";
    while (cin >> a)
    {
        numbers.push_back(a);
    }

    cout << "\nThe greatest common factor : " << gcf(numbers);
}