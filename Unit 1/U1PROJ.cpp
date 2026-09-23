#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <string>

using namespace std;
int main()
{
    //Variables
    vector <string> toDo;
    string variable;
    string viewCreate;
    string response;

    //Main
    cout << "Hello! Would you like to create a to-do list or view your current to-do list?" << endl;
    cin >> viewCreate;

    if (toDo.empty())
    {
        cout << "You have no current to-do list! Would you like to get started with a new list (yes/no)" << endl;
        cin >> response;
        if (response == "Y")
        {
            cout << "Lets get started." << endl;
        }
        else
        {
            cout << "No worries, have a good day." << endl;
            return 0;
        }
    }
    else 
    {
        // show list here + other menu options
    }

    cout << "What needs to be done today?";
    while (cin >> variable)
    {
        toDo.push_back(variable);
    }

    for (int i = 0; i)

    
    // loop back after for view menu with other functions

}