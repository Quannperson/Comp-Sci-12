#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
int main ()

{
    //Variables
    string words;

    //Main
    cout << "Please enter a phrase/word for the palindrome checker!\n";
    getline(cin, words);

    //Make a copy and update it to input then reverse later
    string backwards = words;

    words.erase(remove_if(words.begin(), words.end(), ::isspace), words.end());
    backwards.erase(remove_if(backwards.begin(), backwards.end(), ::isspace), backwards.end());

    reverse(backwards.begin(), backwards.end());

    //Check for palindrome
    if (words == backwards)
    {
        cout << "The input is a palindrome.\n";
    }
    else 
    {
        cout << "The input is not a palindrome.\n";
    }
}