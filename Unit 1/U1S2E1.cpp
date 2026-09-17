#include <iostream>
#include <limits>

using namespace std;
int main ()
{
    //Variables
    int number = 0;
    unsigned int maxInt = number - 1;
    int minInt = std::numeric_limits<int>::min();
    unsigned short maxShort = maxInt;
    short minShort = std::numeric_limits<short>::min();
    unsigned long maxLong = number - 1;
    long minLong = std::numeric_limits<long>::min();
    //Trying to make variable go lower than min --> max, overflowing int --> short reaches short's max (divisible)

    //Main
    cout << "The minimum of int is: " << minInt;
    cout << "\nThe maximum of unsigned int is: " << maxInt << endl;

    cout << "\nThe minimum of short is: " << minShort;
    cout << "\nThe maximum of unsigned short is: " << maxShort << endl;

    cout << "\nThe minimum of long is: " << minLong;
    cout << "\nThe maximum of unsigned long is: " << maxLong;


}
