#include <iostream>
using namespace std;

class studentProfile
{
    public:
        string name;
        int grade;
        float studentNumber;
};

int main()
{
    studentProfile quinn = {"Quinn", 11, 362698318};
    cout << quinn.name;
    cout << quinn.grade;
    cout << quinn.studentNumber;
}