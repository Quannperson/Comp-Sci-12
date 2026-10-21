#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <string>
#include <fstream>
#include <limits>
#include <unordered_set>

using namespace std;

//Ask user for tasks until done is inputted
void list(vector <string>& toDo, vector <int>& priorityList)
{
    string variable;
    int priority;

    while (true)
    {
        cout << "Task name: ";
        getline(cin, variable);

        if (variable == "done")
            break;

        cout << "Priority: ";
        while (!(cin >> priority))
        {
            cout << "Invalid priority. Please enter a number: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); //clearing the weird buffer so my stuff outputs properly
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        //make set to check dupe priorities
        unordered_set<int> unique_elements(priorityList.begin(), priorityList.end());

        if (unique_elements.count(priority) > 0)
        {
            cout << "You have already used that priority number, please choose a different one.\n";
            continue;
        }

        toDo.push_back(variable);
        priorityList.push_back(priority);
    }
}

void sort(vector <string>& toDo, vector <int>& priorityList, string sorting) //sort list alphabetical or reverse
{
    int n = toDo.size();

    for (int i = 0; i < n; i++)
    {
        for (int m = 0; m < n - 1; m++)
        {
            bool swapNeeded = false;

            if (sorting == "alphabetical")
            {
                if (toDo[m] > toDo[m + 1])
                    swapNeeded = true;
            }
            else if (sorting == "reverse")
            {
                if (toDo[m] < toDo[m + 1])
                    swapNeeded = true;
            }

            if (swapNeeded)
            {
                string term = toDo[m];
                toDo[m] = toDo[m + 1];
                toDo[m + 1] = term;

                int tempPrio = priorityList[m];
                priorityList[m] = priorityList[m + 1];
                priorityList[m + 1] = tempPrio;
            }
        }
    }
}

void menu(vector <string>& toDo, vector<int>& priorityList, ofstream& saved, string timeOutput)
{
    string options;
    string sorting;
    string remove;
    
    while (true)
    {
        cout << "What would you like to do next?\n [HOME-ADD-REMOVE-SAVE-SORT]\n";
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
            list(toDo, priorityList);
        }
        else if (options == "SAVE")
        {
            saved << "[MY TODO-LIST]\n" << timeOutput;

            for (int i = 0; i < toDo.size(); i++)
            {
                saved << priorityList[i] << "-" << toDo[i] << endl;
            }

            cout << "Your list has been saved to U1PROJ.txt\n";
            break;
        }
        else if (options == "SORT")
        {
            cout << "How would you like to sort your list?\n [alphabetical/reverse]\n";
            cin >> sorting;
            sort(toDo, priorityList, sorting);
        }
        else
        {
            cout << "Invalid option. Try again.\n";
        }
    }
}

int main()
{
    //Variables
    vector <string> toDo;
    vector <int> priorityList;
    string variable;
    string viewCreate;
    string response;
    string options;
    string remove;
    string loopOrgo;

    //txt file
    ofstream saved("U1PROJ.txt", ios::trunc); //trunc clears file before outputs

    //Set time to EST
    time_t currentTime = time(nullptr);
    string timeOutput = ctime(&currentTime);

    //for looping
    bool back = true;

    while (back == true)
    {

        //Main
        cout << "Hello! Would you like to create a to-do list or view your current to-do list?" << endl;
        cin >> viewCreate;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (viewCreate == "create" || viewCreate == "view")
        {
            if (toDo.empty())
            {
                cout << "\nYou have no current to-do list! Would you like to get started with a new list (yes/no)" << endl;
                cin >> response;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                if (response == "yes")
                {
                    cout << "\nLets get started." << endl;
                    cout << "\033[2J\033[1;1H";

                    cout << "\nWhat needs to be done today?\n (type done once finished)\n";

                    //call list function
                    list(toDo, priorityList);

                    cout << "\033[2J\033[1;1H";
                    cout << "[MY TODO-LIST] \nDate/Time: " << timeOutput;

                    //print inputted list
                        for (int i = 0; i < toDo.size(); i++)
                        {
                            cout << priorityList[i] << "-" << toDo[i] << endl;
                        }

                    //call the menu function
                    menu(toDo, priorityList, saved, timeOutput);
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
                    cout << priorityList[i] << "-" << toDo[i] << endl;
                }

                //call the menu function
                menu(toDo, priorityList, saved, timeOutput);
            }
        }
        else
        {
            cout << "Hmm, that wasn't an option, try again!\n" << endl;
            continue;
        }
            
        cout << "Would you like to go back to view/create or will that be all?\n (return/finish)\n";
        cin >> loopOrgo;

        if (loopOrgo == "return")
        {
            back = true;
        }
        else if (loopOrgo == "finish")
        {
            back = false;
            cout << "Have a good day!";
        }
        else
        {
            cout << "Hmmm, invalid, lets go to the main menu.\n";
            back = true;
        }
    }
}