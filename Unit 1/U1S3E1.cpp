#include <iostream>
#include <string>

using namespace std;
int main ()

{
    string word;

    cout << "Please input a word!\n";
    cin >> word;

    if (word.length() == 5)
    {
        cout << "Your word is 5 letters long!" << endl;
    }
    else
    {
        cout << "Your word is not 5 letters long!" << endl;

    }

}