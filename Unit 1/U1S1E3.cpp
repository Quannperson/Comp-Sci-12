#include <iostream>
#include <cmath>

using namespace std;

int main() {
    
    //Variables
    string animal;
    float population;
    float projectedYear;
    
    //Main
    cout << "Welcome to Quinn's Animal Conservatory Tracker! What type of animal would you like to track?\n (wolf, bunny, deer, capybara)\n";
    cin >> animal;

    cout << "\nHow many " << animal << "s would you like to start with?\n";
    cin >> population;

    cout << "\nWhat year would you like to project the " << animal << " population to?\n";
    cin >> projectedYear;
    cout << "\033[2J\033[1;1H";

    cout << "computing..." << endl;

    //Math
    float projectedPopulation = population * pow(2, (projectedYear-2026));

    cout << "\nType of animal: " << animal << "\nStarting Population: " << population << "\nCurrent year: 2026" << "\nProjected year: " << projectedYear << "\nProjected population: " << projectedPopulation;
    
}

