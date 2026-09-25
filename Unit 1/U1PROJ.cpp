#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <string>
#include <fstream>
#include <limits>

using namespace std;

void list(vector <string>& toDo)
{
    string variable;

    while (getline (cin, variable))
    {
        if (variable == "done")
        {
            break;
        }

        cout << "-";
        toDo.push_back(variable);
    }
}

int main()
{
    //txt file
    ofstream saved("U1PROJ.txt");

    //Variables
    vector <string> toDo;
    string variable;
    string viewCreate;
    string response;
    string options;
    string remove;

    //Set time to EST
    time_t currentTime = time(nullptr);
    string timeOutput = ctime(&currentTime);

    //Main
    cout << "Hello! Would you like to create a to-do list or view your current to-do list?" << endl;
    cin >> viewCreate;

    if (toDo.empty())
    {
        cout << "\nYou have no current to-do list! Would you like to get started with a new list (yes/no)" << endl;
        cin >> response;
        if (response == "yes")
        {
            cout << "\nLets get started." << endl;
            cout << "\033[2J\033[1;1H";
        }
        else
        {
            cout << "No worries, have a good day." << endl;
            return 0;
        }
    }
    else 
    {
        for (int i = 0; i < toDo.size(); i++)
        {
            cout << toDo[i] << endl;
        }
    }

    cout << "\nWhat needs to be done today?\n (type done once finished)\n";

    cin.ignore();
    list(toDo);

    cout << "\033[2J\033[1;1H";
    cout << "[MY TODO-LIST] \nDate/Time: " << timeOutput;

    for (int i = 0; i < toDo.size(); i++)
    {
        cout << "-" << toDo[i] << endl;
    }

    cout << "What would you like to do next?\n [HOME-ADD-REMOVE-SAVE]\n";
    cin >> options; 
    if (options == "REMOVE")
    {
        cout << "\n What would you like to remove?\n";
        cin >> remove;

        //auto infers context of vector <string> toDo by looking at argument
        auto search = find(toDo.begin(), toDo.end(), remove);
    }
    if (options == "ADD")
    {
        list(toDo);
    }
    if (options == "SAVE")
    {
         saved << "[MY TODO-LIST]\n" << timeOutput;

        for (int i = 0; i < toDo.size(); i++)
        {
            saved << "-" << toDo[i] << endl;
        }
    }

}