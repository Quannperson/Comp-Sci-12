#include <iostream>
#include <algorithm>

using namespace std;

int main() 
{
    //Variables
    string word;
    
    cout << "Hello! Enter a word or number.";
    cin >> word;

    //word.begin and word.end point to first and last digit of number sets a range, isdigit checks if the characters in range are numbers
    if (!all_of(word.begin(), word.end(), ::isdigit))
    {
        if (word.find('.') != string::npos)
        {
            if (word.length() >= 7)
            {
                if (word.length() <=15)
                {
                    double wordDouble = stod(word);
                    cout << sizeof(wordDouble);
                }
                else
                {
                    long double wordLdouble = stold(word);
                    cout << sizeof(wordLdouble);
                }
            }
            else
            {
                float wordFloat = stof(word);
                cout << sizeof(wordFloat);
            }
        }
        else 
        {
            
        }
    }
        
    
}
