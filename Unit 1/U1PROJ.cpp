#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <string>
#include <fstream>
#include <limits>

using namespace std;

//Ask user for tasks until done is inputted
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

void menu(vector <string>& toDo, ofstream& saved, string timeOutput)
{
    string options;
    string remove;
    
    while (true)
    {
        cout << "What would you like to do next?\n [HOME-ADD-REMOVE-SAVE]\n";
        cin >> options;
        cin.ignore();

        if (options == "HOME")
        {
            break;
        }
        else if (options == "REMOVE")
        {
            while (true)
            {
                cout << "\n What would you like to remove? (type done once finished)\n";
                getline(cin, remove);

                if (remove == "done")
                    break;

                auto search = find(toDo.begin(), toDo.end(), remove);

                if (search != toDo.end())
                {
                    toDo.erase(search);
                    cout << "Removed: " << remove << endl;
                }
                else
                {
                    cout << "\nItem couldn't be found, try again\n";
                }
            }
        }
        else if (options == "ADD")
        {
            cout << "\nWhat needs to be done today?\n (type done once finished)\n";
            list(toDo);
        }
        else if (options == "SAVE")
        {
            saved << "[MY TODO-LIST]\n" << timeOutput;

            for (int i = 0; i < toDo.size(); i++)
            {
                saved << "-" << toDo[i] << endl;
            }

            break;
        }
        else
        {
            cout << "Invalid option. Try again.\n";
        }
    }
}

int main()
{
    while (true)
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
            cout << "Let's see your current to-do list!" << endl;
            cout << "[MY TODO-LIST]\n" << timeOutput;

            //output list
            for (int i = 0; i < toDo.size(); i++)
            {
                cout << toDo[i] << endl;
            }

            //call the menu function
            menu(toDo, saved, timeOutput);
        }

        cout << "\nWhat needs to be done today?\n (type done once finished)\n";

        //call list function
        list(toDo);

        cout << "\033[2J\033[1;1H";
        cout << "[MY TODO-LIST] \nDate/Time: " << timeOutput;

        //print inputted list
        for (int i = 0; i < toDo.size(); i++)
        {
            cout << "-" << toDo[i] << endl;
        }

        //call the menu function
        menu(toDo, saved, timeOutput);
    }
}