#include <iostream>
using namespace std;

class studentProfile
{
    private:
        string name;
        int grade;
        float studentNumber;

    public:
        void setInfo(string n, int g, int s)
        {
            name = n;
            grade = g;
            studentNumber = s;
        }

        void getInfo()
        {
            cout << name << grade << studentNumber;
        }
};

int main()
{
    studentProfile quinn;
    quinn.setInfo("Quinn", 11, 362698318);
    quinn.getInfo();
}