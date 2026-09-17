#include <iostream>
#include <algorithm>

using namespace std;

int main() 
{
    //Variables
    string word;
    
    cout << "Hello! Enter a word or number.";
    cin >> word;

    //word.begin and word.end point to first and last digit of number sets a range
    //isdigit checks if range characters are numbers

    //statement sorts what variable to convert given string to, then counts length
    if (!all_of(word.begin(), word.end(), ::isdigit))
    {
        if (word.find('.') != string::npos)
        {
            if (word.length() >= 7)
            {
                if (word.length() <=15)
                {
                    double wordDouble = stod(word);
                    cout << "The length of your input is: " << sizeof(wordDouble);
                }
                else
                {
                    long double wordLdouble = stold(word);
                    cout << "The length of your input is: " << sizeof(wordLdouble);
                }
            }
            else
            {
                float wordFloat = stof(word);
                cout << "The length of your input is: " << sizeof(wordFloat);
            }
        }
        else 
        {
            if (word.find('-') != string::npos)
            {
                if (word.length() >= 1)
                {
                    if (word.length() >= 6)
                    {
                        if (word.length() >= 11 && word.length() <= 20)
                        {
                            long long wordLonglong = stoll(word);
                            cout << "The length of your input is: " << sizeof(wordLonglong);
                        }
                        else
                        {
                            int wordInt = stoi(word);
                            cout << "The length of your input is: " << sizeof(wordInt);
                        }
                    }
                    else
                    {
                        short wordShort = stoul(word);
                        cout << "The length of your input is: " << sizeof(wordShort);
                    }
                }
                else
                {
                    char wordChar = stoi(word);
                    cout << "The length of your input is: " << sizeof(wordChar);
                }
            }
            else
            {
                if (word.length() >= 1)
                {
                    if (word.length() >= 5)
                    {
                        if (word.length() >= 10 && word.length() <= 19)
                        {
                            unsigned long long wordUlongLong = stoull(word);
                            cout << "The length of your input is: " << sizeof(wordUlongLong);
                        }
                        else
                        {
                            unsigned int wordUint = stoul(word);
                            cout << "The length of your input is: " << sizeof(wordUint);
                        }
                    }
                    else
                    {
                        unsigned short wordUshort = stoul(word);
                        cout << "The length of your input is: " << sizeof(wordUshort);
                    }
                }
                else
                {
                    unsigned char wordUchar = stoul(word);
                    cout << "The length of your input is: " << sizeof(wordUchar);
                }
            }
        }
    }
    else
    {
        cout << "The length of your input is: " << word.length();
    }
}
