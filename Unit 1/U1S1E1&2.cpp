#include <iostream>

using namespace std;
int main( )
{
    //Variables
    string fullName;
    char section;
    float seat;
    double price;

    //Main
    cout << "Welcome to Quinn's Online Tickets, let's get started with purchasing a ticket for lil 'shaw's concert!" << endl;
    cout << "What is your name?" << endl;
    getline(cin, fullName);
    
    cout << "\nHello! " << fullName;
    cout << "\nWhat section would you like to be seated in tonight?\n (A, B, C, or D)\n";
    cin >> section;
    cout << "\nSection " << section << " it is";
    cout << "\033[2J\033[1;1H";

    cout << "\nWhat seat number would you like? \n (1-200)\n";
    cin >> seat;
    cout << "\nYou will be seated in seat " << seat << ", section " << section << ". Enjoy the concert " << fullName << "!";

    //Calc price
    price = section + 30;
    
    //Ouptut Receipt
    printf("\n|----------------------|\n");
    printf("|Name: %25s |\n", fullName.c_str()); 
    printf("|Seat Number: %25d |\n", seat);
    printf("|Section: %25c |\n", section);
    printf("|Price: %25f |\n", price);
    printf("|Thank you for your purchase! %25c |\n");
    printf("|----------------------|\n");
    //use printf to keep consistent spacing when formatting an output, %25 is max characters, s is variable type, c_str() converts string to char array

}