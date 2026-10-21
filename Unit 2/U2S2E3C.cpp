#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

double gcf(vector <int> numbers)
{
    return accumulate(numbers.begin(), numbers.end(), numbers[0], [](int a, int b){ 
        return gcd(a, b); });
}

int main()
{
    int a;
    vector <int> numbers;

    cout << "Enter some numbers, the magic sorter will find their GCF";
    while (cin >> a)
    {
        numbers.push_back(a);
    }

    cout << "\nThe greatest common factor : " << gcf(numbers);
}