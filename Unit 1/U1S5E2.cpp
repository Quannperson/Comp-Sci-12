#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;
int main ()

{
    //Vectors
    vector <int> numbers1= {1, 2, 3, 4, 5};
    vector <int> numbers2 = {6, 7, 8, 9, 10};
    vector <int> combined;

    //Main
    cout << "The first group of magic numbers are: " << endl;
    for (int i = 0; i < numbers1.size(); i++)
    {
        cout << numbers1[i] << endl;
    }

    cout << "\nThe second group of magic numbers are: " << endl;
    for (int i = 0; i < numbers2.size(); i++)
    {
        cout << numbers2[i] << endl;
    }

    //reserve makes space for new vector, combine merges both vectors
    combined.reserve(numbers1.size() + numbers2.size());
    merge(numbers1.begin(), numbers1.end(), numbers2.begin(), numbers2.end(), back_inserter(combined));

    cout << "\nYour magic numbers combined are: " << endl;
    for (int i = 0; i < combined.size(); i++)
    {
        cout << combined[i] << endl;
    }
}