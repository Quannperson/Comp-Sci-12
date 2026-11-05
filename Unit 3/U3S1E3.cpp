#include "U3S1E3.hpp"

using namespace std;

int main()
{
    studentProfile quinn = {"Quinn", 11, 362698318, {98, 94, 97, 99}};
    cout << quinn.name;
    cout << quinn.grade;
    cout << quinn.studentNumber;
    for(const auto& grades : quinn.marks)
    {
        cout << grades << endl;
    }
}
